using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.IO;
using System.Drawing;
using System.Threading;
using System.Collections;

namespace UIEditor.Public
{
	public struct RectNode
	{
		public Rectangle m_rect;
		public bool m_isAdd;
	}

	public struct ImageNestingPara
	{
		public string m_path;
		public string m_filter;
		public int m_deep;
	}

	class ImageTools
	{
		public static int getMaxHeight(List<RectNode> lstRectNode)
		{
			int maxHeight = 0;

			foreach (RectNode node in lstRectNode)
			{
				if (node.m_rect.Height > maxHeight)
				{
					maxHeight = node.m_rect.Height;
				}
			}

			return maxHeight;
		}
		public static int getMaxWidth(List<RectNode> lstRectNode)
		{
			int maxWidth = 0;

			foreach(RectNode node in lstRectNode)
			{
				if(node.m_rect.Width > maxWidth)
				{
					maxWidth = node.m_rect.Width;
				}
			}

			return maxWidth;
		}
		public static int getAreaSum(List<RectNode> lstRectNode)
		{
			int area = 0;

			foreach (RectNode node in lstRectNode)
			{
				area += node.m_rect.Width * node.m_rect.Height;
			}

			return area;
		}
		public static int getMaxPow(List<RectNode> lstRectNode)
		{
			double maxPow = 0;
			double hPow = Math.Log(getMaxHeight(lstRectNode), 2);
			double wPow = Math.Log(getMaxWidth(lstRectNode), 2);
			double areaPow = Math.Log(Math.Pow(getAreaSum(lstRectNode), 0.5), 2);

			if (hPow > wPow)
			{
				maxPow = hPow;
			}
			else
			{
				maxPow = wPow;
			}
			if (areaPow > maxPow)
			{
				maxPow = areaPow;
			}

			return (int)Math.Ceiling(maxPow);
		}

		public static void printString(string str)
		{
			MainWindow.s_pW.Dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Normal,
				(ThreadStart)delegate()
				{
					MainWindow.s_pW.mx_debug.Text += str;
				}
			);
		}
		public static void addFileToArr(string basicPath, string subPath, string filter, int deep, Dictionary<string, RectNode> mapRectNode)
		{
			DirectoryInfo di = new DirectoryInfo(basicPath + "\\" + subPath);
			FileInfo[] arrFileInfo = di.GetFiles(filter);
			DirectoryInfo[] arrDirInfo = di.GetDirectories();

			foreach(FileInfo fi in arrFileInfo)
			{
				RectNode rn = new RectNode();
				Image img = Image.FromFile(fi.FullName);

				rn.m_rect = new Rectangle(0, 0, img.Width, img.Height);
				rn.m_isAdd = false;
				mapRectNode.Add(subPath + "\\" + fi.Name, rn);
			}
			if(deep > 0)
			{
				deep--;
				foreach(DirectoryInfo dri in arrDirInfo)
				{
					addFileToArr(basicPath, subPath + "\\" + dri.Name, filter, deep, mapRectNode);
				}
			}
		}
		public static void initThread(object para)
		{
			ImageNestingPara np = (ImageNestingPara)para;

			printString("========================开始打包========================\r\n");
			pngToTgaRectNesting(np.m_path, np.m_filter, np.m_deep);
		}
		public static void pngToTgaRectNesting(string path, string filter = "*.png", int deep = 0)
		{
			int maxPow = 0;
			Dictionary<string, RectNode> mapRectNode = new Dictionary<string, RectNode>();

			addFileToArr(path, "", filter, deep, mapRectNode);

			//得到预期的2的整数次幂
			maxPow = getMaxPow(mapRectNode.Values.ToList());

			printString("<提示>png文件统计完成，文件数量:" + mapRectNode.Count() + "，tga图片预计尺寸:" + Math.Pow(2, maxPow) + "\r\n");

			if(!getRectNesting(mapRectNode, (int)Math.Pow(2, maxPow), (int)Math.Pow(2, maxPow)))
			{
				maxPow++;
				printString("<提示>该tga图片尺寸打包尝试失败，开始下一尺寸尝试\r\n" + "tga图片预计尺寸:" + Math.Pow(2, maxPow) +
					" 文件数量:" + mapRectNode.Count() + "\r\n");
				getRectNesting(mapRectNode, (int)Math.Pow(2, maxPow), (int)Math.Pow(2, maxPow));
			}
		}
		public static void crossInsertToGrid(ArrayList mapGrid, int i0, int j0, int di, int dj, int ws, int hs)
		{
			//十字插入
			int preWs = 0;
			int preHs = 0;
			for(int i = 0; i < di; i++)
			{
				for(int j = 0; j < dj; j++)
				{
					RectNode node = ((RectNode)(((ArrayList)mapGrid[i0 + i])[j0 + j]));

					node.m_isAdd = true;
					if(i == 0)
					{
						preHs += node.m_rect.Height;
					}
					if(j == 0)
					{
						preWs += node.m_rect.Width;
					}
				}
			}
			int dw = ws - preWs;
			int dh = hs - preHs;
			int ai = i0 + di;
			int aj = j0 + dj;
			ArrayList newArr = new ArrayList();

			((ArrayList)mapGrid).Insert(ai + 1, newArr);
			for(int j = 0; j < ((ArrayList)mapGrid[ai]).Count; j++)
			{
				//纵向插入
				RectNode node = ((RectNode)(((ArrayList)mapGrid[ai])[j]));
				RectNode newNode = new RectNode();

				newNode.m_isAdd = false;
				newNode.m_rect = new Rectangle(node.m_rect.X + dw, node.m_rect.Y, node.m_rect.Width - dw, node.m_rect.Height);
				((ArrayList)mapGrid[ai + 1]).Add(newNode);

				node.m_isAdd = true;
				node.m_rect.Width = dw;
			}

			for (int i = 0; i < mapGrid.Count; i++)
			{
				//横向插入
				RectNode node = ((RectNode)(((ArrayList)mapGrid[i])[aj]));
				RectNode newNode = new RectNode();

				newNode.m_isAdd = false;
				newNode.m_rect = new Rectangle(node.m_rect.X, node.m_rect.Y + dh, node.m_rect.Width, node.m_rect.Height - dh);
				((ArrayList)mapGrid[i]).Insert(aj + 1, newNode);

				node.m_isAdd = true;
				node.m_rect.Height = dh;
			}
		}
		public static bool getRectNesting(Dictionary<string, RectNode> mapRectNode, int width, int height)
		{
			var resultByHeight = from pair in mapRectNode orderby pair.Value.m_rect.Height select pair;
			printString("\t高度排列完成...\r\n");

			ArrayList mapGrid = new ArrayList();
			ArrayList firstArr = new ArrayList();
			RectNode firstNode = new RectNode();

			firstNode.m_rect = new Rectangle(0, 0, width, height);
			firstNode.m_isAdd = false;
			firstArr.Add(firstNode);
			mapGrid.Add(firstArr);
			
			foreach (KeyValuePair<string, RectNode> pair in resultByHeight)
			{
				int i = 0, j = 0;
				int wi = 0, hj = 0;
				int wSum = 0;
				int hSum = 0;

				for (i = 0; i < mapGrid.Count; i++)
				{
					for(j = 0; j < ((ArrayList)mapGrid[i]).Count; j++)
					{
						RectNode node = ((RectNode)(((ArrayList)mapGrid[i])[j]));

						wi = 0;
						hj = 0;
						wSum = node.m_rect.Width;
						hSum = node.m_rect.Height;

						if(node.m_isAdd == true)
						{
							continue;
						}
						if (node.m_rect.Width < pair.Value.m_rect.Width)
						{
							for (wi = 1; (i + wi) < mapGrid.Count; wi++)
							{
								RectNode wNode = ((RectNode)(((ArrayList)mapGrid[(i + wi)])[j]));

								if(wNode.m_isAdd == true)
								{
									goto ctn;
								}
								wSum += wNode.m_rect.Width;
								if(wSum >= pair.Value.m_rect.Width)
								{
									break;
								}
							}
						}
						if ((i + wi) < mapGrid.Count)
						{
							if(node.m_rect.Height < pair.Value.m_rect.Height)
							{
								for (hj = 1; (j + hj) < ((ArrayList)mapGrid[i]).Count; hj++)
								{
									RectNode hNode = ((RectNode)(((ArrayList)mapGrid[i])[(j + hj)]));

									if(hNode.m_isAdd == true)
									{
										goto ctn;
									}
									hSum += hNode.m_rect.Height;
									if(hSum >= pair.Value.m_rect.Height)
									{
										break;
									}
								}
							}
							if ((j + hj) < ((ArrayList)mapGrid[i]).Count)
							{
								goto found;
							}
						}
					ctn:
						;
					}
				}
				if(i >= mapGrid.Count)
				{
					return false;
				}
			found:
				//添加新的Grid
				crossInsertToGrid(mapGrid, i, j, wi, hj, pair.Value.m_rect.Height, pair.Value.m_rect.Width);
			}

			return true;
		}
	}
}

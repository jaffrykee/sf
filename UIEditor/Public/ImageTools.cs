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
using System.Xml;

namespace UIEditor.Public
{
	public class RectNode
	{
		public Rectangle m_rect;
		public bool m_isAdd;

		public RectNode(Rectangle rect, bool isAdd = false)
		{
			m_rect = rect;
			m_isAdd = false;
		}
	}

	public struct ImageNestingPara
	{
		public string m_path;
		public string m_filter;
		public int m_deep;
	}

	class ImageTools
	{
		public static int s_fileCount;

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

		public static void printString(string str, bool delLast = false)
		{
			MainWindow.s_pW.Dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Normal,
				(ThreadStart)delegate()
				{
					if(delLast)
					{
						MainWindow.s_pW.mx_debug.Text = MainWindow.s_pW.mx_debug.Text.Remove(MainWindow.s_pW.mx_debug.Text.LastIndexOf("\r\n"));
					}
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
				Image img = Image.FromFile(fi.FullName);
				RectNode rn = new RectNode(new Rectangle(0, 0, img.Width, img.Height), false);

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
			bool isFirst = true;
			Dictionary<string, RectNode> mapRectNode = new Dictionary<string, RectNode>();

			addFileToArr(path, "", filter, deep, mapRectNode);

			//得到预期的2的整数次幂
			maxPow = getMaxPow(mapRectNode.Values.ToList());
			s_fileCount = mapRectNode.Count;

			do
			{
				if (isFirst)
				{
					isFirst = false;
					printString("<提示>png文件统计完成，文件数量:" + mapRectNode.Count + "，tga图片预计尺寸:" + Math.Pow(2, maxPow) + "\r\n");
				}
				else
				{
					maxPow++;
					printString("<提示>打包尝试失败，尝试下一尺寸:" + mapRectNode.Count + "，tga图片预计尺寸:" + Math.Pow(2, maxPow) + "\r\n");
				}
			} while (!getRectNesting(mapRectNode, (int)Math.Pow(2, maxPow), (int)Math.Pow(2, maxPow)));

			if(path.Last() == '\\')
			{
				path = path.Remove(path.Length - 1);
				if (path.Last() == '\\')
				{
					path = path.Remove(path.Length - 1);
				}
			}

			string fileName = Path.GetFileName(path);
			XmlDocument docGrid = new XmlDocument();
			XmlElement xeRoot = docGrid.CreateElement("UIImageResource");

			docGrid.AppendChild(xeRoot);
			foreach(KeyValuePair<string, RectNode> pairRn in mapRectNode.ToList())
			{
				XmlElement xe = docGrid.CreateElement("Image");

				xe.SetAttribute("Name", Path.GetFileNameWithoutExtension(pairRn.Key));
				xe.SetAttribute("Width", pairRn.Value.m_rect.Width.ToString());
				xe.SetAttribute("Height", pairRn.Value.m_rect.Height.ToString());
				xe.SetAttribute("X", pairRn.Value.m_rect.X.ToString());
				xe.SetAttribute("Y", pairRn.Value.m_rect.Y.ToString());
				xeRoot.AppendChild(xe);
			}
			docGrid.Save(path + "\\..\\" + fileName + "_wpf.xml");
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

			RectNode firstNode = ((RectNode)(((ArrayList)mapGrid[ai])[aj]));
			if (firstNode.m_rect.Width != dw)
			{
				((ArrayList)mapGrid).Insert(ai + 1, newArr);
				for (int j = 0; j < ((ArrayList)mapGrid[ai]).Count; j++)
				{
					//纵向插入
					RectNode node = ((RectNode)(((ArrayList)mapGrid[ai])[j]));
					RectNode newNode = new RectNode(new Rectangle(node.m_rect.X + dw, node.m_rect.Y, node.m_rect.Width - dw, node.m_rect.Height), false);

					if (node.m_rect.Width - dw < 0)
					{

					}
					if (j >= j0 && j <= aj)
					{
						node.m_isAdd = true;
						newNode.m_isAdd = false;
					}
					else
					{
						newNode.m_isAdd = node.m_isAdd;
					}
					node.m_rect.Width = dw;
					((ArrayList)mapGrid[ai + 1]).Add(newNode);
				}
			}

			if (firstNode.m_rect.Height != dh)
			{
				for (int i = 0; i < mapGrid.Count; i++)
				{
					//横向插入
					RectNode node = ((RectNode)(((ArrayList)mapGrid[i])[aj]));
					RectNode newNode = new RectNode(new Rectangle(node.m_rect.X, node.m_rect.Y + dh, node.m_rect.Width, node.m_rect.Height - dh), false);

					if (i >= i0 && i <= ai)
					{
						node.m_isAdd = true;
						newNode.m_isAdd = false;
					}
					else
					{
						newNode.m_isAdd = node.m_isAdd;
					}
					node.m_rect.Height = dh;
					((ArrayList)mapGrid[i]).Insert(aj + 1, newNode);
				}
			}
		}
		public static bool getRectNesting(Dictionary<string, RectNode> mapRectNode, int width, int height)
		{
			var resultByHeight = from pair in mapRectNode orderby pair.Value.m_rect.Height descending select pair;
			printString("\t高度排列完成...\r\n");

			ArrayList mapGrid = new ArrayList();
			ArrayList firstArr = new ArrayList();
			RectNode firstNode = new RectNode(new Rectangle(0, 0, width, height), false);

			firstArr.Add(firstNode);
			mapGrid.Add(firstArr);

			foreach (KeyValuePair<string, RectNode> pair in resultByHeight)
			{
				for(int i = 0; i < mapGrid.Count; i++)
				{
					for (int j = 0; j < ((ArrayList)mapGrid[i]).Count; j++)
					{
						RectNode rn = (RectNode)((ArrayList)mapGrid[i])[j];
					}
				}
			}

			return true;
		}
	}
}

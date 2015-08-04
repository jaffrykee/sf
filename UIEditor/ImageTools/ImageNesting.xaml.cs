using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Xml;
using System.IO;
using System.Collections;
using System.Windows.Threading;
using System.Threading;

namespace UIEditor.ImageTools
{
	public class RectNode
	{
		public System.Drawing.Rectangle m_rect;
		public bool m_isAdd;
		public int m_packCount;

		public RectNode(System.Drawing.Rectangle rect, bool isAdd = false)
		{
			m_rect = rect;
			m_isAdd = false;
			m_packCount = 0;
		}
	}

	public partial class ImageNesting : Window
	{
		public static int s_fileCount;

		public string m_path;
		public string m_filter;
		public int m_deep;
		public bool m_isInit;

		public ImageNesting(string path, string filter = "*.png", int deep = 0)
		{
			m_path = path;
			m_filter = filter;
			m_deep = deep;
			m_isInit = false;
			InitializeComponent();
		}

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

			foreach (RectNode node in lstRectNode)
			{
				if (node.m_rect.Width > maxWidth)
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

		public void printString(string str, bool delLast = false)
		{
			if (delLast)
			{
				mx_imgDebug.Text = mx_imgDebug.Text.Remove(mx_imgDebug.Text.LastIndexOf("\r\n"));
			}
			mx_imgDebug.Text += str;
		}
		public static void addFileToArr(string basicPath, string subPath, string filter, int deep, Dictionary<string, RectNode> mapRectNode)
		{
			DirectoryInfo di = new DirectoryInfo(basicPath + "\\" + subPath);
			FileInfo[] arrFileInfo = di.GetFiles(filter);
			DirectoryInfo[] arrDirInfo = di.GetDirectories();

			foreach (FileInfo fi in arrFileInfo)
			{
				System.Drawing.Image img = System.Drawing.Image.FromFile(fi.FullName);
				//因为差值什么的，所以要+2。
				RectNode rn = new RectNode(new System.Drawing.Rectangle(0, 0, img.Width + 2, img.Height + 2), false);

				mapRectNode.Add(subPath + "\\" + fi.Name, rn);
			}
			if (deep > 0)
			{
				deep--;
				foreach (DirectoryInfo dri in arrDirInfo)
				{
					if (subPath != "")
					{
						addFileToArr(basicPath, subPath + "\\" + dri.Name, filter, deep, mapRectNode);
					}
					else
					{
						addFileToArr(basicPath, dri.Name, filter, deep, mapRectNode);
					}
				}
			}
		}
		public static void crossInsertToGrid(ArrayList mapGrid, int i0, int j0, int di, int dj, int dw, int dh)
		{
			//十字插入
			//左上描黑，di和dj最低可以为0，也就是只占了一个、一列或一行格子的情况，这种情况不需要描黑。
			if(dw == 0)
			{
				di++;
			}
			if(dh == 0)
			{
				dj++;
			}
			for (int i = 0; i < di; i++)
			{
				for (int j = 0; j < dj; j++)
				{
					RectNode node = ((RectNode)(((ArrayList)mapGrid[i0 + i])[j0 + j]));
					node.m_isAdd = true;
				}
			}

			if (dw > 0)
			{
				//纵向插入
				ArrayList newArr = new ArrayList();
				mapGrid.Insert(i0 + di + 1, newArr);
				for (int j = 0; j < ((ArrayList)mapGrid[i0 + di]).Count; j++)
				{
					RectNode node = ((RectNode)(((ArrayList)mapGrid[i0 + di])[j]));
					RectNode newNode = new RectNode(
						new System.Drawing.Rectangle(
							node.m_rect.X + dw,
							node.m_rect.Y,
							node.m_rect.Width - dw,
							node.m_rect.Height),
						false);

					node.m_rect.Width = dw;
					if (j >= j0 && j <= j0 + dj)
					{
						node.m_isAdd = true;
						newNode.m_isAdd = false;
					}
					else
					{
						newNode.m_isAdd = node.m_isAdd;
					}
					newArr.Add(newNode);
				}
			}

			if(dh > 0)
			{
				//横向插入
				for (int i = 0; i < mapGrid.Count; i++)
				{
					RectNode node = ((RectNode)(((ArrayList)mapGrid[i])[j0 + dj]));
					RectNode newNode = new RectNode(
						new System.Drawing.Rectangle(
							node.m_rect.X,
							node.m_rect.Y + dh,
							node.m_rect.Width,
							node.m_rect.Height - dh),
						false);

					node.m_rect.Height = dh;
					if (i >= i0 && i <= i0 + di)
					{
						node.m_isAdd = true;
						newNode.m_isAdd = false;
					}
					else
					{
						newNode.m_isAdd = node.m_isAdd;
					}
					((ArrayList)mapGrid[i]).Insert(j0 + dj + 1, newNode);
				}
			}
		}
		public static int getXFromGrid(ArrayList mapGrid, int di)
		{
			return getWidthFromGrid(mapGrid, 0, di);
		}
		public static int getYFromGrid(ArrayList mapGrid, int dj)
		{
			return getHeightFromGrid(mapGrid, 0, dj);
		}
		public static int getWidthFromGrid(ArrayList mapGrid, int i0, int di)
		{
			int sw = 0;

			for (int i = 0; i < di; i++)
			{
				sw += ((RectNode)((ArrayList)mapGrid[i0 + i])[0]).m_rect.Width;
			}

			return sw;
		}
		public static int getHeightFromGrid(ArrayList mapGrid, int j0, int dj)
		{
			int sh = 0;

			for (int j = 0; j < dj; j++)
			{
				sh += ((RectNode)((ArrayList)mapGrid[0])[j0 + j]).m_rect.Height;
			}

			return sh;
		}

		public bool enableToPutIn(ArrayList mapGrid, RectNode rNode)
		{
			//按照高度，从高到低寻找空格子
			for (int i = 0; i < mapGrid.Count; i++)
			{
				for (int j = 0; j < ((ArrayList)mapGrid[i]).Count; j++)
				{
					RectNode nodeFirst = (RectNode)((ArrayList)mapGrid[i])[j];
					int sW = 0;
					int sH = 0;
					int di = 0;
					int dj = 0;

					if (nodeFirst.m_rect.Width == 0 || nodeFirst.m_rect.Height == 0)
					{
						continue;
					}
					for (di = 0; (i + di) < mapGrid.Count; di++)
					{
						RectNode wRn = (RectNode)((ArrayList)mapGrid[i + di])[j];

						if (wRn.m_isAdd == true)
						{
							goto ctn;
						}
						sW += wRn.m_rect.Width;
						if (sW >= rNode.m_rect.Width)
						{
							goto hLoop;
						}
					}
					goto ctn;
				hLoop:
					for (dj = 0; (j + dj) < ((ArrayList)mapGrid[i]).Count; dj++)
					{
						RectNode hRn = (RectNode)((ArrayList)mapGrid[i])[j + dj];

						if (hRn.m_isAdd == true)
						{
							goto ctn;
						}
						sH += hRn.m_rect.Height;
						if (sH >= rNode.m_rect.Height)
						{
							goto lastNode;
						}
					}
					goto ctn;
				lastNode:
					RectNode rn = (RectNode)((ArrayList)mapGrid[i + di])[j + dj];
					if (rn.m_isAdd == true)
					{
						goto ctn;
					}
					else
					{
						rNode.m_rect.X = getXFromGrid(mapGrid, i);
						rNode.m_rect.Y = getYFromGrid(mapGrid, j);
						rNode.m_isAdd = true;
						crossInsertToGrid(
							mapGrid,
							i, j, di, dj,
							rn.m_rect.Width - sW + rNode.m_rect.Width,
							rn.m_rect.Height - sH + rNode.m_rect.Height);
						return true;
					}
				ctn:
					continue;
				}
			}
			return false;
		}
		public int getRectNestingByPreset(Dictionary<string, RectNode> mapRectNode, int width = 2048, int height = 2048)
		{
			var resultByWidth = from pair in mapRectNode orderby pair.Value.m_rect.Width descending select pair;

			int count = 0;
			ArrayList arrMapGrid = new ArrayList();
			ArrayList tmpMapGrid = new ArrayList();
			ArrayList tmpArr = new ArrayList();
			RectNode tmpNode = new RectNode(new System.Drawing.Rectangle(0, 0, width, height), false);
			int refreshCount = 0;

			tmpArr.Add(tmpNode);
			tmpMapGrid.Add(tmpArr);
			arrMapGrid.Add(tmpMapGrid);
			mx_canvas.Children.Clear();

			foreach (KeyValuePair<string, RectNode> pair in resultByWidth)
			{
				count++;
				for (int i = 0; true; i++)
				{
					if (!enableToPutIn((ArrayList)arrMapGrid[i], pair.Value))
					{
						if(i == arrMapGrid.Count - 1)
						{
							tmpMapGrid = new ArrayList();
							tmpArr = new ArrayList();
							tmpNode = new RectNode(new System.Drawing.Rectangle(0, 0, width, height), false);
							tmpArr.Add(tmpNode);
							tmpMapGrid.Add(tmpArr);
							arrMapGrid.Add(tmpMapGrid);
						}
					}
					else
					{
						pair.Value.m_packCount = i;
						break;
					}
				}
				printString("\r\n进度：" + count.ToString() + "/" + mapRectNode.Count.ToString() + "\n" + "包数：" + arrMapGrid.Count, true);
				drawRectNode(pair.Value, mx_canvas.ActualWidth / width / 4);
				refreshCount++;
				if (refreshCount % 17 == 0)
				{
					DoEvents();
				}
			}

			Dictionary<string, RectNode> lstMap = new Dictionary<string, RectNode>();

			foreach (KeyValuePair<string, RectNode> pair in mapRectNode)
			{

				if(pair.Value.m_packCount == arrMapGrid.Count - 1)
				{
					lstMap.Add(pair.Key, pair.Value);
				}
			}
			int maxPow = 0;

			//得到预期的2的整数次幂
			maxPow = getMaxPow(lstMap.Values.ToList());

			if (maxPow != 11)
			{
				maxPow--;
				do
				{
					maxPow++;
					clearChildGrid(arrMapGrid.Count - 1);
					printString("\r\n即将完成，开始尾包尺寸重定" + Math.Pow(2, maxPow), true);
				} while (!getRectNesting(lstMap, (int)Math.Pow(2, maxPow), (int)Math.Pow(2, maxPow), true));
			}
			printString("\r\n[完成]\r\n");

			return arrMapGrid.Count;
		}
		public bool getRectNesting(Dictionary<string, RectNode> mapRectNode, int width, int height, bool isPreset = false)
		{
			var resultByWidth = from pair in mapRectNode orderby pair.Value.m_rect.Width descending select pair;

			ArrayList mapGrid = new ArrayList();
			ArrayList firstArr = new ArrayList();
			RectNode firstNode = new RectNode(new System.Drawing.Rectangle(0, 0, width, height), false);
			int refreshCount = 0;

			firstArr.Add(firstNode);
			mapGrid.Add(firstArr);
			if (!isPreset)
			{
				mx_canvas.Children.Clear();
			}

			foreach (KeyValuePair<string, RectNode> pair in resultByWidth)
			{
				if (!enableToPutIn(mapGrid, pair.Value))
				{
					return false;
				}
				if (!isPreset)
				{
					printString("\r\n进度：" + mapGrid.Count.ToString() + "/" + (mapRectNode.Count + 1).ToString(), true);
					drawRectNode(pair.Value, mx_canvas.ActualWidth / width);
				}
				else
				{
					drawRectNode(pair.Value, mx_canvas.ActualWidth / 2048 / 4);
				}
				refreshCount++;
				if (refreshCount % 17 == 0)
				{
					DoEvents();
				}
			}
			if (!isPreset)
			{
				printString("[完成]\r\n");
			}

			return true;
		}
		public void pngToTgaRectNesting(string path, string filter = "*.png", int deep = 0, bool isPreset = false)
		{
			Dictionary<string, RectNode> mapRectNode = new Dictionary<string, RectNode>();

			printString("========开始打包========\r\n" + "路径：" + path + "\r\n");
			addFileToArr(path, "", filter, deep, mapRectNode);

			if (isPreset)
			{
				printString("模式：预设打包\r\n");
				getRectNestingByPreset(mapRectNode, 2048, 2048);
			}
			else
			{
				bool isFirst = true;
				int maxPow = 0;

				//得到预期的2的整数次幂
				maxPow = getMaxPow(mapRectNode.Values.ToList());
				s_fileCount = mapRectNode.Count;

				printString("模式：开发打包\r\n");
				do
				{
					if (isFirst)
					{
						isFirst = false;
						printString("文件数量:" + mapRectNode.Count + "\r\ntga图片预计尺寸:" + Math.Pow(2, maxPow) + "\r\n");
					}
					else
					{
						maxPow++;
						printString("本次尝试失败，尝试下一尺寸...\r\ntga图片预计尺寸:" + Math.Pow(2, maxPow) + "\r\n");
					}
				} while (!getRectNesting(mapRectNode, (int)Math.Pow(2, maxPow), (int)Math.Pow(2, maxPow)));
			}

			if (path.Last() == '\\')
			{
				path = path.Remove(path.Length - 1);
				if (path.Last() == '\\')
				{
					path = path.Remove(path.Length - 1);
				}
			}

			string fileName = System.IO.Path.GetFileName(path);
			XmlDocument docGrid = new XmlDocument();
			XmlElement xeRoot = docGrid.CreateElement("UIImageResource");

			docGrid.AppendChild(xeRoot);
			foreach (KeyValuePair<string, RectNode> pairRn in mapRectNode.ToList())
			{
				XmlElement xe = docGrid.CreateElement("Image");
				string name = pairRn.Key.Remove(pairRn.Key.LastIndexOf("."));
				
				if(name[0] == '\\')
				{
					name = name.Remove(0, 1);
				}
				xe.SetAttribute("Name", name);
				//因为差值什么的显示问题，所以要-2和+1。
				xe.SetAttribute("Width", (pairRn.Value.m_rect.Width - 2).ToString());
				xe.SetAttribute("Height", (pairRn.Value.m_rect.Height - 2).ToString());
				xe.SetAttribute("X", (pairRn.Value.m_rect.X + 1).ToString());
				xe.SetAttribute("Y", (pairRn.Value.m_rect.Y + 1).ToString());
				xeRoot.AppendChild(xe);
			}
			//docGrid.Save(path + "\\..\\" + fileName + "_wpf.xml");
			docGrid.Save(path + "\\..\\" + fileName + ".xml");
		}
		public void clearChildGrid(int num)
		{
			System.Windows.Shapes.Rectangle dRect = new Rectangle()
			{
				Width = mx_canvas.ActualWidth / 4,
				Height = mx_canvas.ActualHeight / 4,
				Margin = new Thickness(
					(mx_canvas.ActualWidth / 4) * (num % 4),
					(mx_canvas.ActualWidth / 4) * (num / 4),
					0, 0),
				Stroke = new SolidColorBrush(System.Windows.Media.Colors.White),
				StrokeThickness = 0,
			};
			dRect.Fill = new SolidColorBrush(System.Windows.Media.Colors.White);
			mx_canvas.Children.Add(dRect);
		}
		public void drawRectNode(RectNode node, double per = 1)
		{
			System.Windows.Shapes.Rectangle dRect = new Rectangle()
			{
				Width = node.m_rect.Width * per,
				Height = node.m_rect.Height * per,
				Margin = new Thickness(
					node.m_rect.X * per + (mx_canvas.ActualWidth / 4) * (node.m_packCount % 4),
					node.m_rect.Y * per + (mx_canvas.ActualHeight / 4) * (node.m_packCount / 4),
					0, 0),
				Stroke = new SolidColorBrush(System.Windows.Media.Color.FromArgb(0xff, 0x00, 0x00, 0x00)),
				StrokeThickness = 0,
			};
			if (node.m_isAdd)
			{
				dRect.Fill = new SolidColorBrush(System.Windows.Media.Color.FromArgb(0x88, 0x33, 0x99, 0xff));
			}
			else
			{
				dRect.Fill = new SolidColorBrush(System.Windows.Media.Color.FromArgb(0x00, 0x33, 0x99, 0xff));
			}
			mx_canvas.Children.Add(dRect);
		}
		public void refreshDrawGrid(ArrayList mapGrid, double per = 1)
		{
			mx_canvas.Children.Clear();
			for(int i = 0; i < mapGrid.Count; i++)
			{
				for(int j = 0; j < ((ArrayList)mapGrid[i]).Count; j++)
				{
					RectNode node = (RectNode)((ArrayList)mapGrid[i])[j];
					System.Windows.Shapes.Rectangle dRect = new Rectangle()
					{
						Width = node.m_rect.Width * per,
						Height = node.m_rect.Height * per,
						Margin = new Thickness(node.m_rect.X * per, node.m_rect.Y * per, 0, 0),
						Stroke = new SolidColorBrush(System.Windows.Media.Color.FromArgb(0xff, 0x00, 0x00, 0x00)),
						StrokeThickness = 0,
					};
					if(node.m_isAdd)
					{
						dRect.Fill = new SolidColorBrush(System.Windows.Media.Color.FromArgb(0x88, 0x33, 0x99, 0xff));
					}
					else
					{
						dRect.Fill = new SolidColorBrush(System.Windows.Media.Color.FromArgb(0x00, 0x33, 0x99, 0xff));
					}
					mx_canvas.Children.Add(dRect);
				}
			}
		}
		public static void DoEvents()
		{
			DispatcherFrame frame = new DispatcherFrame();

			Dispatcher.CurrentDispatcher.BeginInvoke(
				DispatcherPriority.Background,
				new DispatcherOperationCallback(
					delegate(object f)
					{
						((DispatcherFrame)f).Continue = false;

						return null;
					}
				),
				frame);
			Dispatcher.PushFrame(frame);
		}

		private void mx_start_Click(object sender, RoutedEventArgs e)
		{
			mx_start.IsEnabled = false;
			DoEvents();

			string path = MainWindow.s_pW.m_projPath;
			if(mx_rPreset.IsChecked == true)
			{
				mx_imgDebug.Text = "";
				if (Directory.Exists(path + "\\preset"))
				{
					pngToTgaRectNesting(path + "\\preset", m_filter, m_deep, true);
				}
				else
				{
					printString("<错误>没有找到预设图片目录，如想要进行预设图片打包，请新建preset目录。（"
						+ path + "\\preset" + "）\r\n");
				}
			}
			else if(mx_rDev.IsChecked == true)
			{
				DirectoryInfo di = new DirectoryInfo(path + "\\images");
				DirectoryInfo[] arrDirInfo = di.GetDirectories();

				foreach (DirectoryInfo dri in arrDirInfo)
				{
					mx_imgDebug.Text = "";
					pngToTgaRectNesting(dri.FullName, m_filter, m_deep, false);
				}
			}

			mx_start.IsEnabled = true;
		}
		private void mx_rPreset_Checked(object sender, RoutedEventArgs e)
		{
			if (!m_isInit)
			{
				m_isInit = true;
				mx_start.IsEnabled = true;
			}
		}
		private void mx_rDev_Checked(object sender, RoutedEventArgs e)
		{
			if (!m_isInit)
			{
				m_isInit = true;
				mx_start.IsEnabled = true;
			}
		}
	}
}

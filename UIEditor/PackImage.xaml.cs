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
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml;

namespace UIEditor
{
	/// <summary>
	/// PackImage.xaml 的交互逻辑
	/// </summary>
	public partial class PackImage : Grid
	{
		public XmlControl m_parent;
		public System.Drawing.Bitmap m_Bitmap;
		public System.Drawing.Bitmap m_tgaImg;
		public BitmapSource m_imgSource;
		public int m_imgHeight;
		public int m_imgWidth;
		public bool m_loaded;
		public Dictionary<string, System.Drawing.Rectangle> m_mapImgRect;

		public PackImage(XmlControl parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
			m_mapImgRect = new Dictionary<string, System.Drawing.Rectangle>();

			foreach (XmlNode xn in m_parent.m_xeRoot.SelectNodes("Image"))
			{
				if (xn.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xn;
					System.Drawing.Rectangle rt;

					if (xe.GetAttribute("Name") != "" && !m_mapImgRect.TryGetValue(xe.GetAttribute("Name"), out rt))
					{
						m_mapImgRect.Add(xe.GetAttribute("Name"),
							new System.Drawing.Rectangle(
								int.Parse(xe.GetAttribute("X")),
								int.Parse(xe.GetAttribute("Y")),
								int.Parse(xe.GetAttribute("Width")),
								int.Parse(xe.GetAttribute("Height"))
								)
							);
					}
				}
			}
		}
		public static bool addPicToGraphics(string path, System.Drawing.Rectangle rect, System.Drawing.Graphics g)
		{
			if (System.IO.File.Exists(path))
			{
				//拼图和延展1像素
				System.Drawing.Bitmap bmp = DevIL.DevIL.LoadBitmap(path);
				g.DrawImage(bmp,
					rect.X,
					rect.Y,
					rect.Width,
					rect.Height);
				g.DrawImage(bmp,
					new System.Drawing.Rectangle(rect.X - 1, rect.Y, 1, rect.Height),
					new System.Drawing.Rectangle(0, 0, 1, rect.Height),
					System.Drawing.GraphicsUnit.Pixel);
				g.DrawImage(bmp,
					new System.Drawing.Rectangle(rect.X, rect.Y - 1, rect.Width, 1),
					new System.Drawing.Rectangle(0, 0, rect.Width, 1),
					System.Drawing.GraphicsUnit.Pixel);
				g.DrawImage(bmp,
					new System.Drawing.Rectangle(rect.X + rect.Width, rect.Y, 1, rect.Height),
					new System.Drawing.Rectangle(rect.Width - 1, 0, 1, rect.Height),
					System.Drawing.GraphicsUnit.Pixel);
				g.DrawImage(bmp,
					new System.Drawing.Rectangle(rect.X, rect.Y + rect.Height, rect.Width, 1),
					new System.Drawing.Rectangle(0, rect.Height - 1, rect.Width, 1),
					System.Drawing.GraphicsUnit.Pixel);

				return true;
			}
			else
			{
				return false;
			}
		}
		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				IntPtr ip;

				m_imgWidth = 4096;
				m_imgHeight = 4096;
				m_parent.m_parent.itemFrame.Width = m_imgWidth;
				m_parent.m_parent.itemFrame.Height = m_imgHeight;
				mx_canvas.Width = m_imgWidth;
 				mx_canvas.Height = m_imgHeight;
				//mx_image.Source = m_imgSource;
				//mx_image.Stretch = Stretch.Uniform;

				m_tgaImg = new System.Drawing.Bitmap(m_imgWidth, m_imgHeight);
				System.Drawing.Graphics g = System.Drawing.Graphics.FromImage(m_tgaImg);
				g.Clear(System.Drawing.Color.FromArgb(0x00, 0x00, 0x00, 0x00));

				string tmpPath = System.IO.Path.GetFileNameWithoutExtension(m_parent.m_openedFile.m_path);

				if (tmpPath.LastIndexOf("_wpf") >= 0)
				{
					tmpPath = tmpPath.Remove(tmpPath.LastIndexOf("_wpf"));
				}
				foreach (KeyValuePair<string, System.Drawing.Rectangle> pairImgRect in m_mapImgRect)
				{
					addPicToGraphics(
						MainWindow.s_pW.m_projPath + "\\images\\" + tmpPath + 
							"\\" + pairImgRect.Key + ".png",
						pairImgRect.Value,
						g);
				}
				g.Dispose();
				DevIL.DevIL.SaveBitmap("E:\\tmp\\" + tmpPath + ".tga", m_tgaImg);
				ip = m_tgaImg.GetHbitmap();
				m_imgSource = System.Windows.Interop.Imaging.CreateBitmapSourceFromHBitmap(
					ip, IntPtr.Zero, Int32Rect.Empty,
					System.Windows.Media.Imaging.BitmapSizeOptions.FromEmptyOptions());
				MainWindow.DeleteObject(ip);

				System.Windows.Controls.Image cImg = new System.Windows.Controls.Image();
				cImg.Source = m_imgSource;
				cImg.Stretch = Stretch.Uniform;
				mx_canvas.Children.Insert(0, cImg);
				m_loaded = true;
			}
		}

		private void mx_canvas_MouseDown(object sender, MouseButtonEventArgs e)
		{
			int x = (int)Math.Round(e.GetPosition(mx_canvas).X);
			int y = (int)Math.Round(e.GetPosition(mx_canvas).Y);

			MainWindow.s_pW.mx_debug.Text += "<坐标>(" + e.GetPosition(mx_canvas).X.ToString() + "," + e.GetPosition(mx_canvas).Y.ToString() + ")\r\n";
			foreach (KeyValuePair<string, System.Drawing.Rectangle> pairImgRect in m_mapImgRect.ToList())
			{
				if(pairImgRect.Value.Contains(x, y))
				{
					mx_selPath.Visibility = System.Windows.Visibility.Visible;
					mx_selPath.Data = new RectangleGeometry(new Rect(
						pairImgRect.Value.X,
						pairImgRect.Value.Y,
						pairImgRect.Value.Width,
						pairImgRect.Value.Height
					));
					MainWindow.s_pW.mx_debug.Text += "<图片>Name:" + pairImgRect.Key + "\r\n";

					return;
				}
			}
			mx_selPath.Visibility = System.Windows.Visibility.Collapsed;
		}
		private void mx_canvas_MouseMove(object sender, MouseEventArgs e)
		{
			int x = (int)Math.Round(e.GetPosition(mx_canvas).X);
			int y = (int)Math.Round(e.GetPosition(mx_canvas).Y);

			foreach (KeyValuePair<string, System.Drawing.Rectangle> pairImgRect in m_mapImgRect.ToList())
			{
				if (pairImgRect.Value.Contains(x, y))
				{
					mx_overPath.Visibility = System.Windows.Visibility.Visible;
					mx_overPath.Data = new RectangleGeometry(new Rect(
						pairImgRect.Value.X,
						pairImgRect.Value.Y,
						pairImgRect.Value.Width,
						pairImgRect.Value.Height
					));

					return;
				}
			}
			mx_overPath.Visibility = System.Windows.Visibility.Collapsed;
		}
	}
}

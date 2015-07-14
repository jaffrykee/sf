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
		public BitmapSource m_imgSource;
		public int m_imgHeight;
		public int m_imgWidth;
		public bool m_loaded;
		public Dictionary<string, Rect> m_mapImgRect;

		public PackImage(XmlControl parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
			m_mapImgRect = new Dictionary<string, Rect>();
			foreach (XmlNode xn in m_parent.m_xeRoot.SelectNodes("Image"))
			{
				if (xn.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xn;
					Rect rt;

					if (xe.GetAttribute("Name") != "" && !m_mapImgRect.TryGetValue(xe.GetAttribute("Name"), out rt))
					{
						m_mapImgRect.Add(xe.GetAttribute("Name"),
							new Rect(
								Double.Parse(xe.GetAttribute("X")),
								Double.Parse(xe.GetAttribute("Y")),
								Double.Parse(xe.GetAttribute("Width")),
								Double.Parse(xe.GetAttribute("Height"))
								)
							);
					}
				}
			}
		}
		public static bool addPicToCanvas(string path, Rect rect, Canvas canvas)
		{
			if (System.IO.File.Exists(path))
			{
				System.Drawing.Bitmap bmp = DevIL.DevIL.LoadBitmap(path);
				IntPtr ip = bmp.GetHbitmap();
				BitmapSource ims = System.Windows.Interop.Imaging.CreateBitmapSourceFromHBitmap(
					ip, IntPtr.Zero, Int32Rect.Empty,
					System.Windows.Media.Imaging.BitmapSizeOptions.FromEmptyOptions());
				Image img = new Image();

				img.Source = ims;
				img.Stretch = Stretch.Uniform;
				img.Margin = new Thickness(rect.X, rect.Y, 0, 0);
				img.Width = rect.Width;
				img.Height = rect.Height;
				MainWindow.DeleteObject(ip);
				canvas.Children.Insert(0, img);

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
				string path = System.IO.Path.ChangeExtension(m_parent.m_openedFile.m_path, ".tga");

				if (System.IO.File.Exists(path))
				{
					m_Bitmap = DevIL.DevIL.LoadBitmap(path);
					IntPtr ip = m_Bitmap.GetHbitmap();
					m_imgSource = System.Windows.Interop.Imaging.CreateBitmapSourceFromHBitmap(
						ip, IntPtr.Zero, Int32Rect.Empty,
						System.Windows.Media.Imaging.BitmapSizeOptions.FromEmptyOptions());
					MainWindow.DeleteObject(ip);

					m_imgHeight = m_imgSource.PixelHeight;
					m_imgWidth = m_imgSource.PixelWidth;
					m_parent.m_parent.itemFrame.Height = m_imgHeight;
					m_parent.m_parent.itemFrame.Width = m_imgWidth;
 					mx_canvas.Height = m_imgHeight;
 					mx_canvas.Width = m_imgWidth;
					//mx_image.Source = m_imgSource;
					//mx_image.Stretch = Stretch.Uniform;
					foreach (KeyValuePair<string, Rect> pairImgRect in m_mapImgRect)
					{
						addPicToCanvas(
							MainWindow.s_pW.m_projPath + "\\images\\" + System.IO.Path.GetFileNameWithoutExtension(m_parent.m_openedFile.m_path) + 
								"\\" + pairImgRect.Key + ".png",
							pairImgRect.Value,
							mx_canvas);
					}
				}
				m_loaded = true;
			}
		}

		private void mx_canvas_MouseDown(object sender, MouseButtonEventArgs e)
		{
			double x = e.GetPosition(mx_canvas).X;
			double y = e.GetPosition(mx_canvas).Y;

			MainWindow.s_pW.mx_debug.Text += "<坐标>(" + e.GetPosition(mx_canvas).X.ToString() + "," + e.GetPosition(mx_canvas).Y.ToString() + ")\r\n";
			foreach(KeyValuePair<string, Rect> pairImgRect in m_mapImgRect.ToList())
			{
				if(pairImgRect.Value.Contains(x, y))
				{
					mx_selPath.Visibility = System.Windows.Visibility.Visible;
					mx_selPath.Data = new RectangleGeometry(pairImgRect.Value);
					MainWindow.s_pW.mx_debug.Text += "<图片>Name:" + pairImgRect.Key + "\r\n";

					return;
				}
			}
			mx_selPath.Visibility = System.Windows.Visibility.Collapsed;
		}
		private void mx_canvas_MouseMove(object sender, MouseEventArgs e)
		{
			double x = e.GetPosition(mx_canvas).X;
			double y = Math.Floor(e.GetPosition(mx_canvas).Y);

			foreach (KeyValuePair<string, Rect> pairImgRect in m_mapImgRect.ToList())
			{
				if (pairImgRect.Value.Contains(x, y))
				{
					mx_overPath.Visibility = System.Windows.Visibility.Visible;
					mx_overPath.Data = new RectangleGeometry(pairImgRect.Value);

					return;
				}
			}
			mx_overPath.Visibility = System.Windows.Visibility.Collapsed;
		}
	}
}

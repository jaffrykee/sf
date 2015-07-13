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

		public PackImage(XmlControl parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
		}
		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{

		}

		private void mx_imageLoaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				string path = System.IO.Path.ChangeExtension(m_parent.m_openedFile.m_path, ".tga");

				if(System.IO.File.Exists(path))
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
					mx_image.Source = m_imgSource;
					mx_image.Stretch = Stretch.Uniform;
				}
				m_loaded = true;
			}
		}
		private void mx_image_Unloaded(object sender, RoutedEventArgs e)
		{
		}
	}
}

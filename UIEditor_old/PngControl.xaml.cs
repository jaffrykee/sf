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
	/// PngControl.xaml 的交互逻辑
	/// </summary>
	public partial class PngControl : UserControl
	{
		public FileTabItem m_parent;
		public BitmapImage m_imgSource;
		public int m_imgHeight;
		public int m_imgWidth;
		public bool m_loaded;

		public PngControl(FileTabItem parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				string path = this.m_parent.m_filePath;

				m_imgSource = new BitmapImage();
				m_imgSource.BeginInit();
				m_imgSource.StreamSource = new System.IO.FileStream(path, System.IO.FileMode.Open);
				m_imgSource.EndInit();
				m_imgHeight = m_imgSource.PixelHeight;
				m_imgWidth = m_imgSource.PixelWidth;
				this.imageFrame.Height = m_imgHeight;
				this.imageFrame.Width = m_imgWidth;
				this.imageFrame.Source = m_imgSource;
				this.imageFrame.Stretch = Stretch.Uniform;
				m_loaded = true;
			}
		}

		private void imageFrame_Unloaded(object sender, RoutedEventArgs e)
		{
			if (m_imgSource != null)
			{
				m_imgSource.StreamSource.Dispose();
			}
		}
	}
}

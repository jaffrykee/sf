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

namespace UIEditor.BoloUI
{
	/// <summary>
	/// DrawImg.xaml 的交互逻辑
	/// </summary>
	public partial class DrawImg : UserControl
	{
		public BitmapImage m_imgSource;
		public int m_imgHeight;
		public int m_imgWidth;
		public bool m_loaded;

		public XmlElement m_xe;
		public TreeViewItem m_treeItem;
		public string m_path;

		public DrawImg(XmlElement xe, TreeViewItem treeItem)
		{
			InitializeComponent();
			m_xe = xe;
			m_treeItem = treeItem;
			m_loaded = false;
			m_path = "";


		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				MainWindow pW = Window.GetWindow(this) as MainWindow;
				string ImageName = m_xe.GetAttribute("ImageName");
				string fileName = ImageName.Substring(ImageName.LastIndexOf(".") + 1, (ImageName.Length - ImageName.LastIndexOf(".") - 1));
				string folderName = ImageName.Substring(ImageName.LastIndexOf("\\") + 1, (ImageName.LastIndexOf(".") - ImageName.LastIndexOf("\\") - 1));

				fileName += ".png";
				m_path = pW.m_rootPath + "\\" + "images" + "\\" + folderName + "\\" + fileName;

				string path = m_path;

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

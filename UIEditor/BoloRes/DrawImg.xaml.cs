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
using System.Data;

namespace UIEditor.BoloUI
{
	/// <summary>
	/// DrawImg.xaml 的交互逻辑
	/// </summary>
	public partial class DrawImg : UserControl
	{
		public double m_imgHeight;
		public double m_imgWidth;
		public bool m_loaded;

		public XmlElement m_xe;
		public TreeViewItem m_treeItem;
		public string m_path;

		public DrawImg(XmlElement xe, TreeViewItem treeItem, string rootPath)
		{
			InitializeComponent();
			m_xe = xe;
			m_treeItem = treeItem;
			m_loaded = false;
			m_path = "";

			string ImageName = m_xe.GetAttribute("ImageName");
			string fileName = ImageName.Substring(ImageName.LastIndexOf(".") + 1, (ImageName.Length - ImageName.LastIndexOf(".") - 1));
			string folderName = ImageName.Substring(ImageName.LastIndexOf("\\") + 1, (ImageName.LastIndexOf(".") - ImageName.LastIndexOf("\\") - 1));
			fileName += ".png";
			m_path = rootPath + "\\" + "images" + "\\" + folderName + "\\" + fileName;
		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				this.mx_imgFrame.ToolTip = m_path;

				MainWindow pW = Window.GetWindow(this) as MainWindow;
				double iH, iW;

				m_imgHeight = double.Parse(mx_imgHeight.ToolTip.ToString())*3/4;
				m_imgWidth = double.Parse(mx_imgWidth.ToolTip.ToString())*3/4;
				double perX = 1.0d, perY = 1.0d, perDx = 0.0d, perDy = 0.0d;

				if (m_xe.GetAttribute("Height") != null && m_xe.GetAttribute("Height") != "")
				{
					iH = double.Parse(m_xe.GetAttribute("Height"));

					this.mx_ctrR0.Height = new GridLength(iH);
					this.mx_ctrR0.MinHeight = iH;
				}
				else
				{
					iH = m_imgHeight;
					this.mx_ctrR0.Height = new GridLength(iH);
					this.mx_ctrR0.MinHeight = iH;
				}
				if (m_xe.GetAttribute("Width") != null && m_xe.GetAttribute("Width") != "")
				{
					iW = double.Parse(m_xe.GetAttribute("Width"));
					this.mx_ctrC0.Width = new GridLength(iW);
					this.mx_ctrC0.MinWidth = iW;
				}
				else
				{
					iW = m_imgWidth;
					this.mx_ctrC0.Width = new GridLength(iW);
					this.mx_ctrC0.MinWidth = iW;
				}
				if (m_xe.GetAttribute("NineGrid") != null)
				{
					if (m_xe.GetAttribute("NineGrid") == "true")
					{
						if (m_xe.GetAttribute("NGX") != null)
						{
							this.mx_ngc0.Width = new GridLength(double.Parse(m_xe.GetAttribute("NGX")));
							this.mx_ngc2.Width = new GridLength((double)m_imgWidth - double.Parse(m_xe.GetAttribute("NGX")));
							perX = double.Parse(m_xe.GetAttribute("NGX")) / (double)m_imgWidth;
							this.mx_gsChangeHeight.Visibility = System.Windows.Visibility.Visible;
						}
						else
						{
							this.mx_ngc0.Width = new GridLength((double)m_imgWidth);
							this.mx_gsChangeHeight.Visibility = System.Windows.Visibility.Collapsed;
						}
						if (m_xe.GetAttribute("NGY") != null)
						{
							this.mx_ngr0.Height = new GridLength(double.Parse(m_xe.GetAttribute("NGY")));
							this.mx_ngr2.Height = new GridLength((double)m_imgHeight - double.Parse(m_xe.GetAttribute("NGY")));
							perY = double.Parse(m_xe.GetAttribute("NGY")) / (double)m_imgHeight;
							this.mx_gsChangeWidth.Visibility = System.Windows.Visibility.Visible;
						}
						else
						{
							this.mx_ngr0.Height = new GridLength((double)m_imgHeight);
							this.mx_gsChangeWidth.Visibility = System.Windows.Visibility.Collapsed;
						}
						if (m_xe.GetAttribute("NGWidth") != null)
						{
							perDx = double.Parse(m_xe.GetAttribute("NGWidth")) / (double)m_imgWidth;
						}
						else
						{
						}
						if (m_xe.GetAttribute("NGHeight") != null)
						{
							perDy = double.Parse(m_xe.GetAttribute("NGHeight")) / (double)m_imgHeight;
						}
						else
						{
						}
					}
					else
					{
						this.mx_gsChangeHeight.Visibility = System.Windows.Visibility.Collapsed;
						this.mx_gsChangeWidth.Visibility = System.Windows.Visibility.Collapsed;
					}
				}
				else
				{
					this.mx_gsChangeHeight.Visibility = System.Windows.Visibility.Collapsed;
					this.mx_gsChangeWidth.Visibility = System.Windows.Visibility.Collapsed;
				}

				Rect[][] viewRect = new Rect[3][];
				viewRect[0] = new Rect[3];
				viewRect[1] = new Rect[3];
				viewRect[2] = new Rect[3];

				viewRect[0][0] = new Rect(0, 0, perX, perY);
				viewRect[0][1] = new Rect(perX, 0, perDx, perY);
				viewRect[0][2] = new Rect(perX, 0, 1 - perX, perY);
				viewRect[1][0] = new Rect(0, perY, perX, perDy);
				viewRect[1][1] = new Rect(perX, perY, perDx, perDy);
				viewRect[1][2] = new Rect(perX, perY, 1 - perX, perDy);
				viewRect[2][0] = new Rect(0, perY, perX, 1 - perY);
				viewRect[2][1] = new Rect(perX, perY, perDx, 1 - perY);
				viewRect[2][2] = new Rect(perX, perY, 1 - perX, 1 - perY);

				this.mx_ngBrush00.Viewbox = viewRect[0][0];
				this.mx_ngBrush01.Viewbox = viewRect[0][1];
				this.mx_ngBrush02.Viewbox = viewRect[0][2];
				this.mx_ngBrush10.Viewbox = viewRect[1][0];
				this.mx_ngBrush11.Viewbox = viewRect[1][1];
				this.mx_ngBrush12.Viewbox = viewRect[1][2];
				this.mx_ngBrush20.Viewbox = viewRect[2][0];
				this.mx_ngBrush21.Viewbox = viewRect[2][1];
				this.mx_ngBrush22.Viewbox = viewRect[2][2];

				m_loaded = true;
			}
		}

		private void imageFrame_Unloaded(object sender, RoutedEventArgs e)
		{
// 			if (m_imgSource != null)
// 			{
// 				m_imgSource.StreamSource.Dispose();
// 			}
		}
	}
}

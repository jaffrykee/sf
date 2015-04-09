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
	/// DrawText.xaml 的交互逻辑
	/// </summary>
	public partial class DrawText : Grid
	{
		public string m_text;
		public bool m_loaded;
		public XmlElement m_xe;
		public XmlControl m_rootControl;

		public DrawText(XmlElement xe, string rootPath, XmlControl rootControl, string text)
		{
			InitializeComponent();
			m_xe = xe;
			m_text = text;
			m_loaded = false;
			m_rootControl = rootControl;
		}

		private void isLoaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				m_loaded = true;
				mx_text.Content = m_text;
				if(m_xe.Name == "textShape")
				{

					foreach (XmlAttribute att in m_xe.Attributes)
					{
						switch (att.Name)
						{
							case "Height":
							case "Width":
							case "X":
							case "Y":
							case "Anchor":
							case "fontSize":
							case "Color":
							case "Color0":
								break;
							default:
								{
									m_rootControl.textContent.Text += ("attr:<name>" + att.Name + "\t<value>" + att.Value + "\r\n");
								}
								break;
						}
					}
					this.Width = ((Canvas)this.Parent).Width;
					this.Height = ((Canvas)this.Parent).Height;

					MainWindow pW = Window.GetWindow(this) as MainWindow;
					double iH = 0.0d, iW = 0.0d;
					double iX = 0.0d, iY = 0.0d;
					double fontSize = 0;

					if (m_xe.GetAttribute("fontSize") != "")
					{
						fontSize = double.Parse(m_xe.GetAttribute("fontSize"));
						this.mx_text.FontSize = fontSize;
					}
					if (m_xe.GetAttribute("Color0") != "")
					{
						this.mx_text.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#" + m_xe.GetAttribute("Color0")));
					}


					if (m_xe.GetAttribute("Height") != null && m_xe.GetAttribute("Height") != "")
					{
						iH = double.Parse(m_xe.GetAttribute("Height"));
						this.mx_text.Height = iH;
					}
					else
					{
						iH = this.mx_text.Height;
					}
					if (m_xe.GetAttribute("Width") != null && m_xe.GetAttribute("Width") != "")
					{
						iW = double.Parse(m_xe.GetAttribute("Width"));
						this.mx_text.Width = iW;
					}
					else
					{
						iW = this.mx_text.Width;
					}


					m_rootControl.textContent.Text += "iH:" + iH + "\tiW:" + iW + "\r\n";

					if (m_xe.GetAttribute("X") != "")
					{
						iX = double.Parse(m_xe.GetAttribute("X"));
					}
					else
					{
						iX = 0;
					}
					if (m_xe.GetAttribute("Y") != "")
					{
						iY = double.Parse(m_xe.GetAttribute("Y"));
					}
					else
					{
						iY = 0;
					}

					if (m_xe.GetAttribute("Anchor") != "")
					{
						int anchor = int.Parse(m_xe.GetAttribute("Anchor"));

						if ((anchor & 0x01) > 0)
						{
							//水平居中
							//iX = iX + (((Canvas)this.Parent).Width - curCanvasWidth) / 2;
							this.mx_text.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
						}
						if ((anchor & 0x02) > 0)
						{
							//垂直居中
							//iY = iY + (((Canvas)this.Parent).Height - curCanvasHeight) / 2;
							this.mx_text.VerticalAlignment = System.Windows.VerticalAlignment.Center;
						}
						if ((anchor & 0x04) > 0)
						{
							//左对齐
							this.mx_text.HorizontalAlignment = System.Windows.HorizontalAlignment.Left;
						}
						if ((anchor & 0x08) > 0)
						{
							//右对齐
							//iX = iX + (((Canvas)this.Parent).Width - curCanvasWidth);
							this.mx_text.HorizontalAlignment = System.Windows.HorizontalAlignment.Right;
						}
						if ((anchor & 0x10) > 0)
						{
							//上对齐
							this.mx_text.VerticalAlignment = System.Windows.VerticalAlignment.Top;
						}
						if ((anchor & 0x20) > 0)
						{
							//底部对齐
							//iY = iY + (((Canvas)this.Parent).Height - curCanvasHeight);
							this.mx_text.VerticalAlignment = System.Windows.VerticalAlignment.Bottom;
						}
					}
					Canvas.SetLeft(this, iX);
					Canvas.SetTop(this, iY);
				}
			}
		}
	}
}

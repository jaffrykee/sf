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
								break;
							default:
								{
									m_rootControl.textContent.Text += ("attr:<name>" + att.Name + "\t<value>" + att.Value + "\r\n");
								}
								break;
						}
					}

					MainWindow pW = Window.GetWindow(this) as MainWindow;
					double iH = 0.0d, iW = 0.0d;
					double iX = 0.0d, iY = 0.0d;

					if (m_xe.GetAttribute("Height") != null && m_xe.GetAttribute("Height") != "")
					{
						iH = double.Parse(m_xe.GetAttribute("Height"));
						this.Height = iH;
					}
					if (m_xe.GetAttribute("Width") != null && m_xe.GetAttribute("Width") != "")
					{
						iW = double.Parse(m_xe.GetAttribute("Width"));
						this.Width = iW;
					}
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
				}
			}
		}
	}
}

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
	/// Event.xaml 的交互逻辑
	/// </summary>
	public partial class Basic : TreeViewItem
	{
		public XmlControl m_rootControl;
		public XmlElement m_xe;
		public Canvas m_parentCanvas;
		public Canvas m_curCanvas;

		public Basic()
		{
			InitializeComponent();
		}

		public Basic(XmlElement xe, XmlControl rootControl, Canvas parentCanvas)
		{
			InitializeComponent();
			m_rootControl = rootControl;
			m_xe = xe;
			m_parentCanvas = parentCanvas;
		}

		protected void addChild()
		{
			drawSkin();

			XmlNodeList xnl = m_xe.ChildNodes;
			foreach (XmlNode xnf in xnl)
			{
				if (xnf.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xnf;

					switch (xe.Name)
					{
						case "event":
							{
								var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Event"), xe, m_rootControl) as TreeViewItem;
								this.Items.Add(treeChild);
							}
							break;
						default:
							if (Type.GetType("UIEditor.BoloUI." + xe.Name) != null)
							{
								var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI." + xe.Name), xe, m_rootControl, m_curCanvas) as TreeViewItem;
								this.Items.Add(treeChild);
							}
							else
							{
// 								var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), xe, m_rootControl) as TreeViewItem;
// 								this.Items.Add(treeChild);
								m_rootControl.textContent.Text += (xe.Name + ":" + xe.GetAttribute("Name") + "\r\n");
							}
							break;
					}
				}
			}
		}

		virtual protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			this.Header = this.GetType().Name;
			this.Header += ":" + m_xe.GetAttribute("name");
			this.Header += "(" + m_xe.GetAttribute("baseID") + ")";

			addChild();
		}

		protected void drawSkin()
		{
			object skinCanvas = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.SkinCanvas")) as Canvas;
			this.m_parentCanvas.Children.Add((Canvas)skinCanvas);
			this.m_curCanvas = (Canvas)skinCanvas;
			double dH = 0.0d, dW = 0.0d;
			double dX = 0.0d, dY = 0.0d;

			if (m_xe.GetAttribute("h") != "")
			{
				dH = double.Parse(m_xe.GetAttribute("h"));
			}
			else
			{
				dH = this.m_parentCanvas.Height;
			}

			if (m_xe.GetAttribute("w") != "")
			{
				dW = double.Parse(m_xe.GetAttribute("w"));
			}
			else
			{
				dW = this.m_parentCanvas.Width;
			}

			if (m_xe.GetAttribute("x") != "")
			{
				dX = double.Parse(m_xe.GetAttribute("x"));
			}
			else
			{
				dX = 0;
			}
			if (m_xe.GetAttribute("y") != "")
			{
				dY = double.Parse(m_xe.GetAttribute("y"));
			}
			else
			{
				dY = 0;
			}
			if (m_xe.GetAttribute("anchor") != "")
			{
				int anchor = int.Parse(m_xe.GetAttribute("anchor"));

				if ((anchor & 0x03) == 0x02)
				{
					//下
					dY = dY + (((Canvas)this.m_parentCanvas).Height - dH);
				}

				if ((anchor & 0x0c) == 0x08)
				{
					//右
					dX = dX + (((Canvas)this.m_parentCanvas).Width - dW);
				}
			}

			if (m_xe.GetAttribute("dock") != "")
			{
				int dock = int.Parse(m_xe.GetAttribute("dock"));

				switch (dock)
				{
					case 0:
						dX = 0;
						dY = 0;
						dW = this.m_parentCanvas.Width;
						break;
					case 1:
						dX = 0;
						dY = this.m_parentCanvas.Height - dH;
						dW = this.m_parentCanvas.Width;
						break;
					case 2:
						dX = 0;
						dY = 0;
						dH = this.m_parentCanvas.Height;
						break;
					case 3:
						dX = this.m_parentCanvas.Width - dW;
						dY = 0;
						dH = this.m_parentCanvas.Height;
						break;
					case 4:
						dX = 0;
						dY = 0;
						dW = this.m_parentCanvas.Width;
						dH = this.m_parentCanvas.Height;
						break;
					case 5:
					default:
						break;
				}
			}
			
			this.m_curCanvas.Height = dH;
			this.m_curCanvas.Width = dW;
			Canvas.SetLeft(this.m_curCanvas, dX);
			Canvas.SetTop(this.m_curCanvas, dY);

			this.m_curCanvas.Background = new SolidColorBrush((Color)Color.FromArgb(20, 0, 0, 0));

			MainWindow pW = Window.GetWindow(this) as MainWindow;
			XmlElement xe;
			DrawSkin_T drawData;

			drawData.frame = m_curCanvas;
			drawData.path = pW.m_rootPath;
			drawData.rootControl = m_rootControl;

			if (m_xe.GetAttribute("skin") != "" && pW.m_mapStrSkin.TryGetValue(m_xe.GetAttribute("skin"), out xe))
			{
				drawData.xe = xe;
				resBasic.drawApperanceById(drawData, "0");
			}
		}
	}
}

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
			#region 检验是否有未知的BoloUI属性
			foreach (XmlAttribute att in m_xe.Attributes)
			{
				switch (att.Name)
				{
					case "baseID":
					case "name":
					case "visible":
					case "skin":
					case "w":
					case "h":
					case "x":
					case "y":
					case "anchor":
					case "anchorSelf":
					case "dock":

					//上边都是已经解析的，下边都是已知的未解析的。

					case "text":
					case "value":

					case "showStyle":
					case "vStyle":
					case "fillHeadTailShowType":

					case "autoSize":
					case "leftBorder":
					case "rightBorder":
					case "lineHeight":

					case "sliderHeight":
					case "sliderLeftFill":
					case "sliderWidth":

					case "blinkTextAreaH":
					case "blinkTextAreaW":
					case "blinkTextAreaX":
					case "blinktimes":
					case "pressedEndBlink":

					case "hours":
					case "minutes":
					case "seconds":
					case "start":
					case "changeSpeed":
					case "backTime":
					case "movieLayer":
					case "movieSpe":

					case "canSelectByKey":
					case "canFocus":
					case "isEnableScroll":

					case "cel":
					case "docklayer":
					case "countType":
					case "fingerpadr":
					case "pf":

					case "appendOri":
					case "ori":
						break;
					default:
						{
							m_rootControl.textContent.Text += ("UIattr:<name>" + att.Name + "\t<value>" + att.Value + "\r\n");
						}
						break;
				}
			}
			#endregion

			bool visible = drawSkin();

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

		protected bool drawSkin()
		{
			if (m_xe.GetAttribute("visible") == "false" || m_parentCanvas == null)
			{
				this.m_curCanvas = null;

				return false;
			}

			object skinCanvas = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.SkinCanvas")) as Canvas;
			this.m_parentCanvas.Children.Add((Canvas)skinCanvas);
			this.m_curCanvas = (Canvas)skinCanvas;
			double dH = 0.0d, dW = 0.0d;
			double dX = 0.0d, dY = 0.0d;

			#region h w x & y
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
			#endregion

			#region anchor
			if (m_xe.GetAttribute("anchor") != "")
			{
				int anchor = int.Parse(m_xe.GetAttribute("anchor"));

				switch(anchor & 0x03)
				{
					case 0x01:
						//上
						break;
					case 0x02:
						//下
						dY = dY + (this.m_parentCanvas.Height);
						break;
					case 0x03:
						//中
						dY = dY + (this.m_parentCanvas.Height)/2;
						break;
					default:
						break;
				}
				switch (anchor & 0x0c)
				{
					case 0x04:
						//左
						break;
					case 0x08:
						//右
						dX = dX + (this.m_parentCanvas.Width);
						break;
					case 0x0c:
						//中
						dX = dX + (this.m_parentCanvas.Width)/2;
						break;
					default:
						break;
				}
			}
			#endregion

			if (m_xe.GetAttribute("baseID") == "soulitemLP")
			{
				int a = 0;
			}

			#region anchorSelf
			if (m_xe.GetAttribute("anchorSelf") != "")
			{
				int anchorSelf = int.Parse(m_xe.GetAttribute("anchorSelf"));

				switch (anchorSelf & 0x03)
				{
					case 0x01:
						//上
						break;
					case 0x02:
						//下
						dY = dY - dH;
						break;
					case 0x03:
						//中
						dY = dY - dH / 2;
						break;
					default:
						break;
				}
				switch (anchorSelf & 0x0c)
				{
					case 0x04:
						//左
						break;
					case 0x08:
						//右
						dX = dX - dW;
						break;
					case 0x0c:
						//中
						dX = dX - dW / 2;
						break;
					default:
						break;
				}
			}
			#endregion

			#region dock
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
			#endregion

			this.m_curCanvas.Height = dH;
			this.m_curCanvas.Width = dW;
			Canvas.SetLeft(this.m_curCanvas, dX);
			Canvas.SetTop(this.m_curCanvas, dY);

			this.m_curCanvas.Background = new SolidColorBrush((Color)Color.FromArgb(0, 0, 0, 0));

			MainWindow pW = Window.GetWindow(this) as MainWindow;
			XmlElement xe;
			DrawSkin_T drawData;

			drawData.frame = m_curCanvas;
			drawData.path = pW.m_rootPath;
			drawData.rootControl = m_rootControl;

			if (m_xe.GetAttribute("skin") != "" && pW.m_mapStrSkin.TryGetValue(m_xe.GetAttribute("skin"), out xe))
			{
				drawData.xe = xe;

				resBasic.drawApperanceById(drawData, "0", m_xe.GetAttribute("text"));
			}

			return true;
		}
	}
}

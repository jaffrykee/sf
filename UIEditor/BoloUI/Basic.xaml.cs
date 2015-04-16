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
		public Dictionary<string, AttrRow> m_mapStrNormalAttr;
		public Dictionary<string, AttrRow> m_mapStrViewAttr;
		public Dictionary<string, AttrRow> m_mapStrOtherAttr;

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
			m_mapStrNormalAttr = new Dictionary<string, AttrRow>
			{
				#region
				{"baseID",null},
				{"name", null},
				{"visible", null},
				#endregion
			};
			m_mapStrViewAttr = new Dictionary<string, AttrRow>
			{
				#region
				{"skin",null},
				{"w", null},
				{"h", null},
				{"x", null},
				{"y", null},
				{"anchor", null},
				{"anchorSelf", null},
				{"dock", null}
				#endregion
			};
			m_mapStrOtherAttr = new Dictionary<string, AttrRow>
			{
				#region
				{"text",null},
				{"value",null},

				{"showStyle",null},
				{"vStyle",null},
				{"fillHeadTailShowType",null},

				{"autoSize",null},
				{"leftBorder",null},
				{"rightBorder",null},
				{"lineHeight",null},

				{"sliderHeight",null},
				{"sliderLeftFill",null},
				{"sliderWidth",null},

				{"blinkTextAreaH",null},
				{"blinkTextAreaW",null},
				{"blinkTextAreaX",null},
				{"blinktimes",null},
				{"pressedEndBlink",null},

				{"hours",null},
				{"minutes",null},
				{"seconds",null},
				{"start",null},
				{"changeSpeed",null},
				{"backTime",null},
				{"movieLayer",null},
				{"movieSpe",null},

				{"canSelectByKey",null},
				{"canFocus",null},
				{"isEnableScroll",null},

				{"cel",null},
				{"docklayer",null},
				{"countType",null},
				{"fingerpadr",null},
				{"pf",null},

				{"appendOri",null},
				{"ori",null}
				#endregion
			};
		}

		protected void addChild()
		{
			MainWindow pW = Window.GetWindow(this) as MainWindow;

			#region 检验是否有未知的BoloUI属性
			foreach (XmlAttribute att in m_xe.Attributes)
			{
				AttrRow nullPtr;

				if(m_mapStrNormalAttr.TryGetValue(att.Name, out nullPtr))
				{
				}
				else if(m_mapStrViewAttr.TryGetValue(att.Name, out nullPtr))
				{
				}
				else if (m_mapStrOtherAttr.TryGetValue(att.Name, out nullPtr))
				{
				}
				else
				{
					m_rootControl.textContent.Text += ("UIattr:<name>" + att.Name + "\t<value>" + att.Value + "\r\n");
					m_mapStrOtherAttr.Add(att.Name, null);
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

		protected void initHeader()
		{
			mx_text.Content = this.GetType().Name;
			mx_text.Content += ":" + m_xe.GetAttribute("name");
			mx_text.Content += "(" + m_xe.GetAttribute("baseID") + ")";
		}

		virtual protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			initHeader();
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

		private void mx_text_MouseDown(object sender, MouseButtonEventArgs e)
		{
			MainWindow pW = Window.GetWindow(this) as MainWindow;
			AttrRow nullPtr;
			AttrList normalAttrList;
			AttrList viewAttrList;
			AttrList otherAttrList;

			if (pW.m_mapStrAttrList.TryGetValue("normal", out normalAttrList))
			{
				normalAttrList.mx_frame.Children.Clear();
			}
			if (pW.m_mapStrAttrList.TryGetValue("view", out viewAttrList))
			{
				viewAttrList.mx_frame.Children.Clear();
			}
			if (pW.m_mapStrAttrList.TryGetValue("other", out otherAttrList))
			{
				otherAttrList.mx_frame.Children.Clear();
			}

			if (pW.m_mapStrAttrList.TryGetValue("normal", out normalAttrList))
			{
				List<KeyValuePair<string, AttrRow>> lstStrAttrRow = m_mapStrNormalAttr.ToList();

				foreach (KeyValuePair<string, AttrRow> row in lstStrAttrRow)
				{
					if (m_xe.GetAttribute(row.Key) == "")
					{
					}
					else
					{
					}
					m_mapStrNormalAttr[row.Key] = new AttrRow(row.Key, m_xe.GetAttribute(row.Key));
					normalAttrList.mx_frame.Children.Add(m_mapStrNormalAttr[row.Key]);
				}
			}
			if (pW.m_mapStrAttrList.TryGetValue("view", out viewAttrList))
			{
				List<KeyValuePair<string, AttrRow>> lstStrAttrRow = m_mapStrViewAttr.ToList();

				foreach (KeyValuePair<string, AttrRow> row in lstStrAttrRow)
				{
					if (m_xe.GetAttribute(row.Key) == "")
					{
					}
					else
					{
					}
					m_mapStrViewAttr[row.Key] = new AttrRow(row.Key, m_xe.GetAttribute(row.Key));
					viewAttrList.mx_frame.Children.Add(m_mapStrViewAttr[row.Key]);
				}
			}
			if (pW.m_mapStrAttrList.TryGetValue("other", out otherAttrList))
			{
				List<KeyValuePair<string, AttrRow>> lstStrAttrRow = m_mapStrOtherAttr.ToList();

				foreach (KeyValuePair<string, AttrRow> row in lstStrAttrRow)
				{
					if (m_xe.GetAttribute(row.Key) == "")
					{
					}
					else
					{
					}
					m_mapStrOtherAttr[row.Key] = new AttrRow(row.Key, m_xe.GetAttribute(row.Key));
					otherAttrList.mx_frame.Children.Add(m_mapStrOtherAttr[row.Key]);
				}
			}
			
			foreach (XmlAttribute att in m_xe.Attributes)
			{
				if (m_mapStrNormalAttr.TryGetValue(att.Name, out nullPtr))
				{
				}
				else if (m_mapStrViewAttr.TryGetValue(att.Name, out nullPtr))
				{
				}
				else if (m_mapStrOtherAttr.TryGetValue(att.Name, out nullPtr))
				{
				}
				else
				{
					if (pW.m_mapStrAttrList.TryGetValue("other", out otherAttrList))
					{
						otherAttrList.mx_frame.Children.Add(new AttrRow(att.Name, m_xe.GetAttribute(att.Name)));
					}
					m_rootControl.textContent.Text += ("UIattr:<name>" + att.Name + "\t<value>" + att.Value + "\r\n");
				}
			}
		}
	}
}

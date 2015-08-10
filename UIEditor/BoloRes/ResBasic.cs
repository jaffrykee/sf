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

namespace UIEditor.BoloRes
{
	public class ResBasic : UIEditor.XmlItem
	{
		public MainWindow.SkinDef_T m_curDeepDef;

		public ResBasic(XmlElement xe, XmlControl rootControl, MainWindow.SkinDef_T deepDef) : base(xe, rootControl)
		{
			m_type = "Skin";
			InitializeComponent();
			m_isCtrl = false;
			m_curDeepDef = deepDef;

			if (m_curDeepDef != null)
			{
				if (m_xe.Name == "skin" || m_xe.Name == "publicskin")
				{
					ResBasic nullPtr;
					if (!m_rootControl.m_mapSkin.TryGetValue(m_xe.GetAttribute("Name"), out nullPtr))
					{
						m_rootControl.m_mapSkin[m_xe.GetAttribute("Name")] = this;
					}
				}
				addChild();
			}
		}
		protected override void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			Dictionary<string, MainWindow.SkinDef_T> mapSkinDef;

			initHeader();
			if (m_setFocus)
			{
				this.Focus();
				m_setFocus = false;
			}

			mx_addNode.Items.Clear();
			if(m_xe.Name == "BoloUI")
			{
				mapSkinDef = m_pW.m_mapSkinResDef;
			}
			else
			{
				mapSkinDef = m_curDeepDef.m_mapEnChild;
			}
			if (mapSkinDef != null)
			{
				foreach (KeyValuePair<string, MainWindow.SkinDef_T> pairSkinDef in mapSkinDef.ToList())
				{
					MenuItem skinMenuItem = new MenuItem();

					StringDic.getNameAndTip(skinMenuItem, pairSkinDef.Key, StringDic.m_mapStrNode);
					skinMenuItem.Click += insertSkinItem_Click;
					mx_addNode.Items.Add(skinMenuItem);
				}
				mx_addNode.IsEnabled = true;
			}
			else
			{
				mx_addNode.IsEnabled = false;
			}
		}

		void insertSkinItem_Click(object sender, RoutedEventArgs e)
		{
			if (sender.GetType().ToString() == "System.Windows.Controls.MenuItem")
			{
				MenuItem ctrlItem = (MenuItem)sender;
				XmlElement newXe = m_xe.OwnerDocument.CreateElement(ctrlItem.ToolTip.ToString());
				ResBasic treeChild;
				if(m_xe.Name == "BoloUI")
				{
					treeChild = new ResBasic(newXe, m_rootControl, m_pW.m_mapSkinResDef[newXe.Name]);
				}
				else
				{
					treeChild = new ResBasic(newXe, m_rootControl, m_curDeepDef.m_mapEnChild[newXe.Name]);
				}

				m_rootControl.m_openedFile.m_lstOpt.addOperation(new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, m_xe));
			}
			//throw new NotImplementedException();
		}

		override protected void addChild()
		{
			XmlNodeList xnl = m_xe.ChildNodes;
			foreach (XmlNode xnf in xnl)
			{
				if (xnf.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xnf;
					MainWindow.SkinDef_T skinPtr;

					if (m_curDeepDef.m_mapEnChild != null)
					{
						if (m_curDeepDef.m_mapEnChild.TryGetValue(xe.Name, out skinPtr))
						{
							if (skinPtr != null)
							{
								var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloRes.ResBasic"), xe, m_rootControl, skinPtr) as TreeViewItem;
								this.Items.Add(treeChild);
							}
						}
					}
				}
			}
		}
		public override void initHeader()
		{
			if(m_curDeepDef != null)
			{
				string ctrlTip;
				string name = "";
				//string id = "";

				if (StringDic.m_mapStrNode.TryGetValue(m_xe.Name, out ctrlTip))
				{
					mx_root.Header = "<" + ctrlTip + ">";
					mx_root.ToolTip = m_xe.Name;
				}
				else
				{
					mx_root.Header = "<" + m_xe.Name + ">";
				}
				if (m_curDeepDef.m_mapAttrDef != null)
				{
					name = m_xe.GetAttribute(m_curDeepDef.m_mapAttrDef.ToList().First().Key);
				}

				mx_root.Header += name;
			}
		}
		public override void changeSelectItem(object obj = null)
		{
			m_pW.m_curItem = this;
			if(m_xe.Name != "BoloUI")
			{
				BoloUI.Basic ctrlUI;
				m_pW.mx_leftToolFrame.SelectedItem = m_pW.mx_skinFrame;
				m_pW.hiddenAllAttr();

				if (obj != null && obj.GetType().ToString() == "UIEditor.BoloUI.Basic")
				{
					ctrlUI = (BoloUI.Basic)obj;
				}
				else
				{
					if (m_rootControl.m_skinViewCtrlUI != null)
					{
						ctrlUI = m_rootControl.m_skinViewCtrlUI;
					}
					else
					{
						ctrlUI = null;
					}
				}
				if (m_pW.m_otherAttrList == null)
				{
					m_pW.m_otherAttrList = new AttrList("基本", m_pW);
					m_pW.mx_toolArea.Children.Add(m_pW.m_otherAttrList);
				}
				if (m_curDeepDef.m_mapAttrDef != null)
				{
					foreach (KeyValuePair<string, MainWindow.AttrDef_T> pairAttrDef in m_curDeepDef.m_mapAttrDef.ToList())
					{
						pairAttrDef.Value.m_attrRowUI = new AttrRow(pairAttrDef.Value, pairAttrDef.Key, m_xe.GetAttribute(pairAttrDef.Key), m_pW.m_otherAttrList);
						m_pW.m_otherAttrList.mx_frame.Children.Add(pairAttrDef.Value.m_attrRowUI);
					}
				}
				m_pW.m_otherAttrList.refreshRowVisible();
				m_pW.m_otherAttrList.m_xmlCtrl = m_rootControl;
				m_pW.m_otherAttrList.m_basic = this;
				m_pW.m_otherAttrList.m_xe = m_xe;

				//预览皮肤
				XmlElement xeSkin = null;
				XmlElement xeTmp = m_xe;

				for (int i = 0; i < 7 && xeSkin == null && xeTmp != null; i++)
				{
					if (xeTmp.Name == "skin" || xeTmp.Name == "publicskin")
					{
						xeSkin = xeTmp;
					}
					else
					{
						if (xeTmp.ParentNode.GetType().ToString() == "System.Xml.XmlElement")
						{
							xeTmp = (XmlElement)xeTmp.ParentNode;
						}
						else
						{
							xeTmp = null;
						}
					}
				}
				if (xeSkin != null)
				{
					if (m_rootControl.m_isOnlySkin)
					{
						XmlElement xeView;

						if (ctrlUI == null && m_rootControl.m_skinViewCtrlUI == null)
						{
							xeView = m_pW.m_xeTest;
							((XmlElement)xeView).SetAttribute("skin", xeSkin.GetAttribute("Name"));
							m_pW.updateXmlToGL(m_rootControl, xeView, false);
						}
						else
						{
							if (ctrlUI != null)
							{
								m_rootControl.m_skinViewCtrlUI = ctrlUI;
							}
							xeView = m_rootControl.m_skinViewCtrlUI.m_xe;
							m_rootControl.m_skinViewCtrlUI.m_rootControl.m_openedFile.m_lstOpt.addOperation(
								new XmlOperation.HistoryNode(
									xeView,
									"skin",
									m_rootControl.m_skinViewCtrlUI.m_xe.GetAttribute("skin"),
									xeSkin.GetAttribute("Name")
								)
							);
							m_pW.updateXmlToGL(m_rootControl, xeView, true);
						}
					}
					//todo 更改皮肤预览
				}
			}
			if(!this.Focus())
			{
				m_setFocus = true;
			}
			BringIntoView(new Rect(0, 0, 50, 20));
		}
	}
}

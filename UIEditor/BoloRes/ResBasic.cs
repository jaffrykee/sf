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

			Dictionary<string, MainWindow.SkinDef_T> mapSkinDef;

			initHeader();

			mx_addNode.Items.Clear();
			if (m_xe.Name == "BoloUI")
			{
				mapSkinDef = MainWindow.s_pW.m_mapSkinTreeDef;
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

					MainWindow.s_pW.m_strDic.getNameAndTip(skinMenuItem, StringDic.conf_ctrlTipDic, pairSkinDef.Key);
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

		public void addResItem(XmlElement newXe)
		{
			ResBasic treeChild;
			if (m_xe.Name == "BoloUI")
			{
				treeChild = new ResBasic(newXe, m_rootControl, MainWindow.s_pW.m_mapSkinTreeDef[newXe.Name]);
			}
			else
			{
				treeChild = new ResBasic(newXe, m_rootControl, m_curDeepDef.m_mapEnChild[newXe.Name]);
			}

			m_rootControl.m_openedFile.m_lstOpt.addOperation(new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, m_xe));
		}
		void insertSkinItem_Click(object sender, RoutedEventArgs e)
		{
			if (sender.GetType().ToString() == "System.Windows.Controls.MenuItem")
			{
				MenuItem ctrlItem = (MenuItem)sender;
				XmlElement newXe = m_xe.OwnerDocument.CreateElement(ctrlItem.ToolTip.ToString());

				addResItem(newXe);
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
				string ctrlName = MainWindow.s_pW.m_strDic.getWordByKey(m_xe.Name);
				string ctrlTip = MainWindow.s_pW.m_strDic.getWordByKey(m_xe.Name, StringDic.conf_ctrlTipDic);
				string name = "";
				string tmpCon = "";

				if (ctrlName != "")
				{
					tmpCon = "<" + ctrlName + ">";
				}
				else
				{
					tmpCon = "<" + m_xe.Name + ">";
				}

				if (ctrlTip != "")
				{
					mx_radio.ToolTip = ctrlTip;
				}
				else
				{
					mx_radio.ToolTip = m_xe.Name;
				}

				if (m_curDeepDef.m_mapAttrDef != null && m_curDeepDef.m_mapAttrDef.ToList().Count > 0)
				{
					name = m_xe.GetAttribute(m_curDeepDef.m_mapAttrDef.ToList().First().Key);
				}

				tmpCon += name;
				mx_radio.Content = tmpCon.Replace("_", "__");
			}
		}
		public override void changeSelectItem(object obj = null)
		{
			MainWindow.s_pW.m_curItem = this;
			if(m_xe.Name != "BoloUI")
			{
				BoloUI.Basic ctrlUI;
				MainWindow.s_pW.mx_leftToolFrame.SelectedItem = MainWindow.s_pW.mx_skinFrame;
				MainWindow.s_pW.hiddenAllAttr();

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
				if (MainWindow.s_pW.m_otherAttrList == null)
				{
					MainWindow.s_pW.m_otherAttrList = new AttrList("基本");
					MainWindow.s_pW.mx_toolArea.Children.Add(MainWindow.s_pW.m_otherAttrList);
				}
				if (m_curDeepDef.m_mapAttrDef != null)
				{
					foreach (KeyValuePair<string, MainWindow.AttrDef_T> pairAttrDef in m_curDeepDef.m_mapAttrDef.ToList())
					{
						pairAttrDef.Value.m_attrRowUI = new AttrRow(pairAttrDef.Value, pairAttrDef.Key, m_xe.GetAttribute(pairAttrDef.Key), MainWindow.s_pW.m_otherAttrList);
						MainWindow.s_pW.m_otherAttrList.mx_frame.Children.Add(pairAttrDef.Value.m_attrRowUI);
					}
				}
				MainWindow.s_pW.m_otherAttrList.refreshRowVisible();
				MainWindow.s_pW.m_otherAttrList.m_xmlCtrl = m_rootControl;
				MainWindow.s_pW.m_otherAttrList.m_basic = this;
				MainWindow.s_pW.m_otherAttrList.m_xe = m_xe;

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
							xeView = MainWindow.s_pW.m_xeTest;
						}
						else
						{
							if (ctrlUI != null)
							{
								m_rootControl.m_skinViewCtrlUI = ctrlUI;
							}
							xeView = m_rootControl.m_xmlDoc.CreateElement(m_rootControl.m_skinViewCtrlUI.m_xe.Name);

							xeView.SetAttribute("dock", "4");
							xeView.SetAttribute("baseID", "selSkinTestCtrl");
							if(m_rootControl.m_skinViewCtrlUI.m_xe.GetAttribute("text") != "")
							{
								xeView.SetAttribute("text", m_rootControl.m_skinViewCtrlUI.m_xe.GetAttribute("text"));
							}
						}
						((XmlElement)xeView).SetAttribute("skin", xeSkin.GetAttribute("Name"));
						MainWindow.s_pW.updateXmlToGL(m_rootControl, xeView, false);
					}
					//todo 更改皮肤预览
				}
			}
			mx_radio.IsChecked = true;
			BringIntoView(new Rect(0, 0, 50, 20));
		}
	}
}

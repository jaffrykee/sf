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

		public ResBasic(XmlElement xe, XmlControl rootControl, MainWindow.SkinDef_T deepDef)
			: base(xe, rootControl)
		{
			InitializeComponent();
			m_curDeepDef = deepDef;
			if(m_xe.Name == "skin" || m_xe.Name == "publicskin")
			{
				ResBasic nullPtr;
				if(!m_rootControl.m_mapSkin.TryGetValue(m_xe.GetAttribute("Name"), out nullPtr))
				{
					m_rootControl.m_mapSkin[m_xe.GetAttribute("Name")] = this;
				}
			}
			addChild();
		}
		override protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			initHeader();
			if (m_setFocus)
			{
				this.Focus();
				m_setFocus = false;
			}
		}

		protected void addChild()
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
		public void initHeader()
		{
			string ctrlTip;
			string name = "";
			//string id = "";

			if (StringDic.m_mapStrNode.TryGetValue(m_xe.Name, out ctrlTip))
			{
				mx_text.Content = "<" + ctrlTip + ">";
				mx_text.ToolTip = m_xe.Name;
			}
			else
			{
				mx_text.Content = "<" + m_xe.Name + ">";
			}
			if (m_curDeepDef.m_mapAttrDef != null)
			{
				name = m_xe.GetAttribute(m_curDeepDef.m_mapAttrDef.ToList().First().Key);
			}

			mx_text.Content += name;
			mx_text.Content = mx_text.Content.ToString().Replace("_", "__"); 
		}
		public override void changeSelectItem(object obj = null)
		{
			BoloUI.Basic ctrlUI;
			m_pW.mx_leftToolFrame.SelectedItem = m_pW.mx_skinFrame;
			m_pW.m_curRes = this;
			m_pW.hiddenAllAttr();

			if (obj != null && obj.GetType().ToString() == "UIEditor.BoloUI.Basic")
			{
				ctrlUI = (BoloUI.Basic)obj;
			}
			else
			{
				ctrlUI = null;
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
								m_rootControl.m_skinViewCtrlUI,
								"skin",
								m_rootControl.m_skinViewCtrlUI.m_xe.GetAttribute("skin"),
								xeSkin.GetAttribute("Name")
							)
						);
					}
					m_pW.updateXmlToGL(m_rootControl.m_openedFile.m_path, m_rootControl.m_xmlDoc, xeView);
				}
				//todo 更改皮肤预览
			}
			if(!this.Focus())
			{
				m_setFocus = true;
			}
		}

		private void mx_text_MouseDown(object sender, MouseButtonEventArgs e)
		{
			changeSelectItem();
		}
		private void mx_text_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			if (m_xe.Name == "skingroup")
			{
				string path = m_pW.m_skinPath + "\\" + m_xe.GetAttribute("Name") + ".xml";

				m_pW.openFileByPath(path);
			}
		}
		private void mx_root_Selected(object sender, RoutedEventArgs e)
		{
		}
		private void mx_root_Unselected(object sender, RoutedEventArgs e)
		{
		}
	}
}

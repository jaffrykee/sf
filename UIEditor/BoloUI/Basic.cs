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
	public class Basic : UIEditor.XmlItem
	{
		public int m_selX;
		public int m_selY;
		public int m_selW;
		public int m_selH;
		public string m_vId;

		public Basic(XmlElement xe, XmlControl rootControl, bool isRoot = false) : base(xe, rootControl)
		{
			m_type = "CtrlUI";
			InitializeComponent();
			MainWindow.CtrlDef_T ctrlDef;

			if (isRoot == false)
			{
				if (m_pW.m_mapCtrlDef.TryGetValue(m_xe.Name, out ctrlDef) && ctrlDef != null)
				{
					m_isCtrl = true;
				}
				else
				{
					m_isCtrl = false;
				}
				if (m_xe.Name != "event")
				{
					m_vId = System.Guid.NewGuid().ToString().Substring(10);
					m_rootControl.m_mapCtrlUI[m_vId] = this;
				}
				else
				{
					m_vId = "";
				}
				addChild();
			}
		}
		override protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			initHeader();
		}

		override protected void addChild()
		{
			XmlNodeList xnl = m_xe.ChildNodes;
			foreach (XmlNode xnf in xnl)
			{
				if (xnf.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xnf;
					MainWindow.CtrlDef_T ctrlPtr;

					if (m_pW.m_mapCtrlDef.TryGetValue(xe.Name, out ctrlPtr))
					{
						var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), xe, m_rootControl, false) as TreeViewItem;
						this.Items.Add(treeChild);

						if (xe.Name != "event")
						{
							this.IsExpanded = true;
						}
					}
					else
					{
						switch (xe.Name)
						{
							default:
								break;
						}
					}
				}
			}
		}
		public override void initHeader()
		{
			if(m_xe.Name != "BoloUI")
			{
				string ctrlTip;
				string name = "", id = "";

				if (StringDic.m_mapStrControl.TryGetValue(m_xe.Name, out ctrlTip))
				{
					mx_radio.Content = "<" + ctrlTip + ">";
					mx_radio.ToolTip = m_xe.Name;
				}
				else
				{
					mx_radio.Content = "<" + m_xe.Name + ">";
				}
				if (m_isCtrl && m_xe.Name != "event")
				{
					name = m_xe.GetAttribute("name");
					id = m_xe.GetAttribute("baseID");
				}
				else
				{
					mx_radio.Content = "<" + m_xe.Name + ">";
					if (m_xe.GetAttribute("Name") != "")
					{
						name = m_xe.GetAttribute("Name");
					}
					else if (m_xe.GetAttribute("type") != "")
					{
						name = m_xe.GetAttribute("type");
					}

					if (m_xe.GetAttribute("id") != "")
					{
						id = m_xe.GetAttribute("id");
					}
					else if (m_xe.GetAttribute("function") != "")
					{
						id = m_xe.GetAttribute("function");
					}
				}

				if (m_pW.m_vCtrlName)
				{
					mx_radio.Content += name;
				}
				if (m_pW.m_vCtrlId)
				{
					mx_radio.Content += "(" + id + ")";
				}
			}
		}
		public override void changeSelectItem(object obj = null)
		{
			m_pW.mx_leftToolFrame.SelectedItem = m_pW.mx_ctrlFrame;
			if (m_vId != "")
			{
				m_pW.m_curFile = m_rootControl.m_openedFile.m_path;
				m_pW.mx_workTabs.SelectedItem = m_rootControl.m_openedFile.m_tab;
				m_pW.updateGL(
					StringDic.getFileNameWithoutPath(m_rootControl.m_openedFile.m_path) + ":" + m_vId,
					W2GTag.W2G_SELECT_UI
				);
			}

			bool tmp = m_pW.m_attrBinding;
			m_pW.m_attrBinding = false;

			m_pW.m_curItem = this;
			m_pW.hiddenAllAttr();
			MainWindow.CtrlDef_T ctrlDef;

			if (m_pW.m_mapCtrlDef.TryGetValue(m_xe.Name, out ctrlDef))
			{
				if (m_xe.Name != "event")
				{
					m_pW.m_mapCtrlDef["basic"].m_attrListUI.Visibility = Visibility.Visible;
					m_pW.m_mapCtrlDef["basic"].m_attrListUI.clearRowValue();
				}
				ctrlDef.m_attrListUI.Visibility = Visibility.Visible;
				ctrlDef.m_attrListUI.clearRowValue();
			}

			foreach (XmlAttribute attr in m_xe.Attributes)
			{
				bool isOther = false;

				if (m_isCtrl)
				{
					MainWindow.AttrDef_T attrDef;
					if (m_pW.m_mapCtrlDef["basic"].m_mapAttrDef.TryGetValue(attr.Name, out attrDef))
					{
						attrDef.m_attrRowUI.m_value = attr.Value;
					}
					else if (ctrlDef.m_mapAttrDef.TryGetValue(attr.Name, out attrDef))
					{
						attrDef.m_attrRowUI.m_value = attr.Value;
					}
					else
					{
						isOther = true;
					}
				}
				else
				{
					isOther = true;
				}

				if (isOther)
				{
					if (m_pW.m_otherAttrList == null)
					{
						m_pW.m_otherAttrList = new AttrList("other", m_pW);
						m_pW.mx_toolArea.Children.Add(m_pW.m_otherAttrList);
					}
					m_pW.m_otherAttrList.mx_frame.Children.Add(new AttrRow("string", attr.Name, attr.Value, m_pW.m_otherAttrList));
				}
			}
			if (m_isCtrl)
			{
				m_pW.m_mapCtrlDef["basic"].m_attrListUI.refreshRowVisible();
				m_pW.m_mapCtrlDef["basic"].m_attrListUI.m_xmlCtrl = m_rootControl;
				m_pW.m_mapCtrlDef["basic"].m_attrListUI.m_basic = this;
				m_pW.m_mapCtrlDef["basic"].m_attrListUI.m_xe = m_xe;
				ctrlDef.m_attrListUI.refreshRowVisible();
				ctrlDef.m_attrListUI.m_xmlCtrl = m_rootControl;
				ctrlDef.m_attrListUI.m_basic = this;
				ctrlDef.m_attrListUI.m_xe = m_xe;
			}
			if (m_pW.m_otherAttrList != null)
			{
				m_pW.m_otherAttrList.refreshRowVisible();
				m_pW.m_otherAttrList.Visibility = Visibility.Visible;
				m_pW.m_otherAttrList.m_xmlCtrl = m_rootControl;
				m_pW.m_otherAttrList.m_basic = this;
				m_pW.m_otherAttrList.m_xe = m_xe;
			}

			m_pW.m_attrBinding = tmp;
			mx_radio.IsChecked = true;
			BringIntoView(new Rect(0, 0, 50, 20));

			SelButton selBn;

			if (m_pW.m_mapXeSel != null && m_pW.m_mapXeSel.TryGetValue(m_xe, out selBn) && selBn != null)
			{
				selBn.mx_radio.IsChecked = true;
				selBn.m_isVcheck = true;
			}
		}
		public bool checkPointInFence(int x, int y)
		{
			if(x >= m_selX && y >= m_selY)
			{
				if(x <= m_selX + m_selW && y <= m_selY + m_selH)
				{
					return true;
				}
			}
			return false;
		}
	}
}

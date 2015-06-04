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
		public MainWindow m_pW;
		public bool m_isCtrl;

		public Basic()
		{
			InitializeComponent();
		}

		public Basic(XmlElement xe, XmlControl rootControl)
		{
			InitializeComponent();
			m_rootControl = rootControl;
			m_xe = xe;
			m_isCtrl = false;
		}

		virtual protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			m_pW = Window.GetWindow(this) as MainWindow;
			initHeader();
			addChild();
		}

		protected void addChild()
		{
			XmlNodeList xnl = m_xe.ChildNodes;
			foreach (XmlNode xnf in xnl)
			{
				if (xnf.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xnf;

					switch (xe.Name)
					{
						default:
							var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), xe, m_rootControl) as TreeViewItem;
							this.Items.Add(treeChild);
							break;
					}
				}
			}
		}

		public void initHeader(bool isUpdate = false)
		{
			string ctrlTip;
			string name = "", id = "";
			MainWindow.CtrlDef_T ctrlDef;

			if (m_pW.m_mapCtrlDef.TryGetValue(m_xe.Name, out ctrlDef))
			{
				m_isCtrl = true;
			}
			StringDic.m_control.TryGetValue(m_xe.Name, out ctrlTip);
			if (ctrlTip != null && ctrlTip != "")
			{
				mx_text.Content = "<" + ctrlTip + ">";
				mx_text.ToolTip = m_xe.Name;
			}
			else
			{
				mx_text.Content = "<" + m_xe.Name + ">";
			}
			if (m_isCtrl && m_xe.Name != "event")
			{
				if (m_xe.GetAttribute("name") != "")
				{
					name = m_xe.GetAttribute("name");
				}
				if (m_xe.GetAttribute("baseID") == "")
				{
					//m_xe.SetAttribute("baseID", StringDic.getRandString());
					m_xe.SetAttribute("baseID", System.Guid.NewGuid().ToString().Substring(32/2));
					m_pW.mx_debug.Text += "<警告>baseID没有赋值，已经将其替换为随机值：" + m_xe.GetAttribute("baseID") + "\r\n";
				}

				if(isUpdate == false)
				{
					Basic ctrl;
					id = m_xe.GetAttribute("baseID");
					if (m_rootControl.m_mapCtrlUI.TryGetValue(id, out ctrl))
					{
						//baseId重复了
						m_xe.SetAttribute("baseID", System.Guid.NewGuid().ToString().Substring(32 / 2));
						m_pW.mx_debug.Text += "<警告>baseID(" + id + ")重复，已经将其替换为随机值：" + m_xe.GetAttribute("baseID") + "\r\n";
					}
				}
				else
				{
					id = m_xe.GetAttribute("baseID");
				}
				m_rootControl.m_mapCtrlUI[id] = this;

				id = m_xe.GetAttribute("baseID");
			}
			else
			{
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
			mx_text.Content += name;
			mx_text.Content += "(" + id + ")";
		}

		private void mx_text_MouseDown(object sender, MouseButtonEventArgs e)
		{
			bool tmp = m_pW.m_attrBinding;
			m_pW.m_attrBinding = false;

			m_pW.hiddenAllAttr();
			MainWindow.CtrlDef_T ctrlDef;

			if(m_pW.m_mapCtrlDef.TryGetValue(m_xe.Name, out ctrlDef))
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
						attrDef.m_attrRowUI.m_elmUI = this;
					}
					else if (ctrlDef.m_mapAttrDef.TryGetValue(attr.Name, out attrDef))
					{
						attrDef.m_attrRowUI.m_value = attr.Value;
						attrDef.m_attrRowUI.m_elmUI = this;
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

				if(isOther)
				{
					if (m_pW.m_otherAttrList == null)
					{
						m_pW.m_otherAttrList = new AttrList("other");
						m_pW.mx_toolArea.Children.Add(m_pW.m_otherAttrList);
					}
					m_pW.m_otherAttrList.mx_frame.Children.Add(new AttrRow("string", attr.Name, attr.Value, this));
				}
			}
			if (m_isCtrl)
			{
				m_pW.m_mapCtrlDef["basic"].m_attrListUI.refreshRowVisible();
				ctrlDef.m_attrListUI.refreshRowVisible();
			}
			if (m_pW.m_otherAttrList != null)
			{
				m_pW.m_otherAttrList.refreshRowVisible();
				m_pW.m_otherAttrList.Visibility = Visibility.Visible;
			}

			m_pW.m_attrBinding = tmp;
		}
	}
}

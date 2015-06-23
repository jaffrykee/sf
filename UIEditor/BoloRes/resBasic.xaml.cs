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
	public partial class ResBasic : TreeViewItem
	{
		public XmlControl m_rootControl;
		public XmlElement m_xe;
		public MainWindow m_pW;
		public MainWindow.SkinDef_T m_curDeepDef;

		public ResBasic(XmlElement xe, XmlControl rootControl, MainWindow.SkinDef_T deepDef)
		{
			InitializeComponent();
			m_rootControl = rootControl;
			m_xe = xe;
			m_pW = rootControl.m_pW;
			m_curDeepDef = deepDef;
			addChild();
		}
		virtual protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			initHeader();
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
		}
		public void changeSelectSkin()
		{
			m_pW.mx_leftToolFrame.SelectedItem = m_pW.mx_skinFrame;
			m_pW.hiddenAllAttr();

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
		}

		private void mx_text_MouseDown(object sender, MouseButtonEventArgs e)
		{
			changeSelectSkin();
		}
		private void mx_root_Selected(object sender, RoutedEventArgs e)
		{
		}
		private void mx_root_Unselected(object sender, RoutedEventArgs e)
		{
		}
	}
}

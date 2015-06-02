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
		public Dictionary<string, AttrList> m_mapAttrList;
		public Dictionary<string, Dictionary<string, AttrRow>> m_mapAttrRow;

		public Basic()
		{
			InitializeComponent();
		}

		public Basic(XmlElement xe, XmlControl rootControl)
		{
			InitializeComponent();
			m_rootControl = rootControl;
			m_xe = xe;
			m_mapAttrList = new Dictionary<string, AttrList>();
			m_mapAttrRow = new Dictionary<string, Dictionary<string, AttrRow>>();
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

		protected void initHeader()
		{
			mx_text.Content = m_xe.Name;
			string name = "", id = "";
			if (m_xe.GetAttribute("name") != "")
			{
				name = m_xe.GetAttribute("name");
			}
			else if (m_xe.GetAttribute("Name") != "")
			{
				name = m_xe.GetAttribute("Name");
			}
			else if (m_xe.GetAttribute("type") != "")
			{
				name = m_xe.GetAttribute("type");
			}
			mx_text.Content += ":" + name;
			if (m_xe.GetAttribute("baseID") != "")
			{
				id = m_xe.GetAttribute("baseID");
			}
			else if(m_xe.GetAttribute("id") != "")
			{
				id = m_xe.GetAttribute("id");
			}
			else if (m_xe.GetAttribute("function") != "")
			{
				id = m_xe.GetAttribute("function");
			}
			mx_text.Content += "(" + id + ")";
		}

		virtual protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			Dictionary<string, MainWindow.AttrDef_T> AttrDefPtr;
			string ctrlName;
			bool isHad = false;
			m_pW = Window.GetWindow(this) as MainWindow;

			ctrlName = m_xe.Name;
			if (m_pW.m_mapCtrlDef.TryGetValue(ctrlName, out AttrDefPtr))
			{
				isHad = true;
				m_mapAttrList.Add(ctrlName, new AttrList(ctrlName));
				m_mapAttrRow.Add(ctrlName, new Dictionary<string, AttrRow>());
				List<KeyValuePair<string, MainWindow.AttrDef_T>> lstAttrDef = AttrDefPtr.ToList();
				foreach (KeyValuePair<string, MainWindow.AttrDef_T> attrPair in lstAttrDef)
				{
					m_mapAttrRow[ctrlName][attrPair.Key] = new AttrRow(attrPair.Key);
				}
			}

			if (isHad && m_xe.Name != "event")
			{
				ctrlName = "basic";
				if (m_pW.m_mapCtrlDef.TryGetValue(ctrlName, out AttrDefPtr))
				{
					m_mapAttrList.Add(ctrlName, new AttrList(ctrlName));
					m_mapAttrRow.Add(ctrlName, new Dictionary<string, AttrRow>());
					List<KeyValuePair<string, MainWindow.AttrDef_T>> lstAttrDef = AttrDefPtr.ToList();
					foreach (KeyValuePair<string, MainWindow.AttrDef_T> attrPair in lstAttrDef)
					{
						m_mapAttrRow[ctrlName][attrPair.Key] = new AttrRow(attrPair.Key);
					}
				}
			}

			ctrlName = "other";
			m_mapAttrList.Add(ctrlName, new AttrList(ctrlName));
			m_mapAttrRow.Add(ctrlName, new Dictionary<string, AttrRow>());

			ctrlName = m_xe.Name;
			foreach (XmlAttribute att in m_xe.Attributes)
			{
				AttrRow attrRow;

				if (isHad && m_xe.Name != "event")
				{
					if (m_mapAttrRow["basic"].TryGetValue(att.Name, out attrRow))
					{
						attrRow.m_value = att.Value;
					}
					else
					{
						if (m_mapAttrRow[ctrlName].TryGetValue(att.Name, out attrRow))
						{
							attrRow.m_value = att.Value;
						}
						else
						{
							m_mapAttrRow["other"][att.Name] = new AttrRow(att.Name, att.Value);
						}
					}
				}
				else if (m_xe.Name == "event")
				{
					if (m_mapAttrRow[ctrlName].TryGetValue(att.Name, out attrRow))
					{
						attrRow.m_value = att.Value;
					}
					else
					{
						m_mapAttrRow["other"][att.Name] = new AttrRow(att.Name, att.Value);
					}
				}
				else
				{
					m_mapAttrRow["other"][att.Name] = new AttrRow(att.Name, att.Value);
				}
			}

			List<KeyValuePair<string, AttrRow>> lstAttrRow;

			if(isHad && m_xe.Name != "event")
			{
				ctrlName = "basic";
				lstAttrRow = m_mapAttrRow[ctrlName].ToList();
				foreach(KeyValuePair<string, AttrRow> attrRowPair in lstAttrRow)
				{
					m_mapAttrList[ctrlName].mx_frame.Children.Add(attrRowPair.Value);
				}
			}

			if (isHad)
			{
				ctrlName = m_xe.Name;
				lstAttrRow = m_mapAttrRow[ctrlName].ToList();
				foreach (KeyValuePair<string, AttrRow> attrRowPair in lstAttrRow)
				{
					m_mapAttrList[ctrlName].mx_frame.Children.Add(attrRowPair.Value);
				}
			}

			ctrlName = "other";
			lstAttrRow = m_mapAttrRow[ctrlName].ToList();
			foreach (KeyValuePair<string, AttrRow> attrRowPair in lstAttrRow)
			{
				m_mapAttrList[ctrlName].mx_frame.Children.Add(attrRowPair.Value);
			}

			initHeader();
			addChild();
		}

		private void mx_text_MouseDown(object sender, MouseButtonEventArgs e)
		{
			m_pW.mx_toolArea.Children.Clear();
			foreach(KeyValuePair<string, AttrList> attrListPair in m_mapAttrList.ToList())
			{
				m_pW.mx_toolArea.Children.Add(attrListPair.Value);
			}
		}
	}
}

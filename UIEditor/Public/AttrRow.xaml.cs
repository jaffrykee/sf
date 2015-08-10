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

namespace UIEditor
{
	/// <summary>
	/// AttrRow.xaml 的交互逻辑
	/// </summary>

	public partial class AttrRow : Grid
	{
		private string mt_name;
		private string mt_value;
		private string mt_type;
		public MainWindow m_pW;
		public AttrList m_parent;
		public string m_name
		{
			get { return mt_name; }
			set
			{
				mt_name = value;

				string outStr;
				if(StringDic.m_mapStrAttr.TryGetValue(value, out outStr) && outStr != "")
				{
					mx_name.Content = outStr;
					mx_name.ToolTip = value;
				}
				else
				{
					mx_name.Content = value;
					mx_name.ToolTip = "";
				}
				if(m_name == "skin")
				{
					mx_skinFrame.Visibility = System.Windows.Visibility.Visible;
				}
				else
				{
					mx_skinFrame.Visibility = System.Windows.Visibility.Collapsed;
				}
			}
		}
		public string m_value
		{
			get { return mt_value; }
			set
			{
				if (m_type == "bool")
				{
					if (value == "")
					{
						mx_defaultBool.IsChecked = true;
					}
					else
					{
						mx_defaultBool.IsChecked = false;
						switch (value)
						{
							case "true":
								mx_valueBool.IsChecked = true;
								break;
							case "false":
								mx_valueBool.IsChecked = false;
								break;
							default:
								//todo 这里是非法值的处理，还没有想好机制
								mx_defaultBool.IsChecked = true;
								break;
						}
					}
				}
				XmlItem curItem = m_pW.m_curItem;

				if (m_pW.m_attrBinding && m_parent != null && m_parent.m_xmlCtrl != null && m_parent.m_xe != null && mt_value != value)
				{
					m_parent.m_xmlCtrl.m_openedFile.m_lstOpt.addOperation(new XmlOperation.HistoryNode(m_parent.m_basic.m_xe, m_name, mt_value, value));
				}

				mt_value = value;
				mx_value.Text = value;
			}
		}
		public string m_type
		{
			get{return mt_type;}
			set
			{
				mt_type = value;
				if(!m_isEnum)
				{
					switch (value)
					{
						case "bool":
							{
								mx_boolFrame.Visibility = Visibility.Visible;
								mx_normalFrame.Visibility = Visibility.Collapsed;
								mx_enumFrame.Visibility = Visibility.Collapsed;
							}
							break;
						default:
							{
								mx_boolFrame.Visibility = Visibility.Collapsed;
								mx_normalFrame.Visibility = Visibility.Visible;
								mx_enumFrame.Visibility = Visibility.Collapsed;
							}
							break;
					}
				}
				else
				{
					mx_boolFrame.Visibility = Visibility.Collapsed;
					mx_normalFrame.Visibility = Visibility.Collapsed;
					mx_enumFrame.Visibility = Visibility.Visible;
				}
			}
		}
		public bool m_isEnum;
		public List<string> m_lstEnumValue;

		public AttrRow(string type = "string", string name = "", string value = "", AttrList parent = null)
		{
			InitializeComponent();
			mt_name = name;
			mt_value = value;
			mt_type = type;
			m_parent = parent;
			m_isEnum = false;
			m_lstEnumValue = null;
		}
		public AttrRow(MainWindow.AttrDef_T attrDef, string name = "", string value = "", AttrList parent = null)
		{
			InitializeComponent();
			mt_name = name;
			mt_value = value;
			mt_type = attrDef.m_type;
			m_parent = parent;
			m_isEnum = attrDef.m_isEnum;
			m_lstEnumValue = attrDef.m_lstEnumValue;
		}
		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{
			m_pW = Window.GetWindow(this) as MainWindow;
			m_name = mt_name;
			m_value = mt_value;
			m_type = mt_type;
			//todo & totest
// 			this.mx_name.Content = m_name;
// 			this.mx_value.Text = m_value;
		}

		private void mx_value_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (mx_value.Text == "")
			{
				mx_valueDef.Visibility = Visibility.Visible;
				mx_link.Visibility = Visibility.Collapsed;
			}
			else
			{
				mx_valueDef.Visibility = Visibility.Hidden;
				mx_link.Visibility = Visibility.Visible;
			}
			m_value = mx_value.Text;
		}
		private void mx_defaultBool_Unchecked(object sender, RoutedEventArgs e)
		{
			mx_valueBool.IsEnabled = true;

			if(mx_valueBool.IsChecked == true)
			{
				m_value = "true";
			}
			else
			{
				m_value = "false";
			}
		}
		private void mx_defaultBool_Checked(object sender, RoutedEventArgs e)
		{
			mx_valueBool.IsEnabled = false;
			m_value = "";
		}
		private void mx_valueBool_Checked(object sender, RoutedEventArgs e)
		{
			m_value = "true";
		}
		private void mx_valueBool_Unchecked(object sender, RoutedEventArgs e)
		{
			m_value = "false";
		}
		private void mx_valueBool_IsEnabledChanged(object sender, DependencyPropertyChangedEventArgs e)
		{
		}
		private void mx_valueEnum_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			//((ComboBox)sender).SelectedItem
		}
		private void mx_link_Click(object sender, RoutedEventArgs e)
		{
			if (m_parent.m_basic != null && m_parent.m_basic.GetType().ToString() == "UIEditor.BoloUI.Basic")
			{
				m_parent.m_xmlCtrl.findSkinAndSelect(mx_value.Text, (BoloUI.Basic)m_parent.m_basic);
			}
		}
		private void mx_sel_Click(object sender, RoutedEventArgs e)
		{
			if (m_parent.m_basic != null && m_parent.m_basic.GetType().ToString() == "UIEditor.BoloUI.Basic")
			{
				BoloUI.SelSkin winSkin = new BoloUI.SelSkin(m_parent.m_xmlCtrl.m_openedFile.m_path, m_parent.m_basic.m_xe.OuterXml, this);

				winSkin.ShowDialog();

				BoloUI.SelSkin.s_pW.m_GLSkinHost.m_process.Kill();
				BoloUI.SelSkin.s_isRun = false;
				BoloUI.SelSkin.s_pW = null;
			}
		}
	}
}

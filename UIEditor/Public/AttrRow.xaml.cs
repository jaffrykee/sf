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
				mx_name.Content = value;
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
				BoloUI.Basic elmUI = m_pW.m_curCtrl;
				if (m_pW.m_attrBinding && elmUI != null && elmUI.m_xe != null)
				{
					if (mt_value != value)
					{
						bool isWrong = false;

						if (m_name == "baseID")
						{
							BoloUI.Basic ctrl;

							if (elmUI.m_rootControl.m_mapCtrlUI.TryGetValue(value, out ctrl))
							{
								isWrong = true;
							}
							else
							{
								if (elmUI.m_rootControl.m_mapCtrlUI.TryGetValue(mt_value, out ctrl))
								{
									elmUI.m_rootControl.m_mapCtrlUI.Remove(mt_value);
									//elmUI.m_rootControl.m_mapCtrlUI[value] = ctrl;
								}
							}
						}
						if (isWrong == false)
						{
							if (mt_value != "" && value == "")
							{
								elmUI.m_xe.RemoveAttribute(m_name);
							}
							else
							{
								elmUI.m_xe.SetAttribute(m_name, value);
							}
							BoloUI.Basic.checkBaseId(elmUI, true);
							elmUI.initHeader();

							string buffer = elmUI.m_xe.OwnerDocument.InnerXml;
							m_pW.updateGL(elmUI.m_rootControl.m_openedFile.m_path, MainWindow.SendTag.SEND_NORMAL_NAME);
							m_pW.updateXmlToGL(elmUI.m_xe.OwnerDocument);
						}
						else
						{
							//todo 其它错误也在这里显示
							m_pW.mx_debug.Text += "<警告>baseID不可重复\r\n";
						}
					}
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
				if (value == "bool")
				{
					mx_boolFrame.Visibility = Visibility.Visible;
					mx_normalFrame.Visibility = Visibility.Hidden;
				}
				else
				{
					mx_boolFrame.Visibility = Visibility.Hidden;
					mx_normalFrame.Visibility = Visibility.Visible;
				}
			}
		}

		public AttrRow(string type = "string", string name = "", string value = "", AttrList parent = null)
		{
			InitializeComponent();
			mt_name = name;
			mt_value = value;
			mt_type = type;
			m_parent = parent;
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
			}
			else
			{
				mx_valueDef.Visibility = Visibility.Hidden;
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
			if(mx_valueBool.IsEnabled == true)
			{
				mx_valueBool.Foreground = new SolidColorBrush(Color.FromArgb(0xff, 0xff, 0xff, 0xff));
			}
			else
			{
				mx_valueBool.Foreground = new SolidColorBrush(Color.FromArgb(0xff, 0xbb, 0xbb, 0xbb));
			}
		}
	}
}

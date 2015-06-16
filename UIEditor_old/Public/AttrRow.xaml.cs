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
		public string m_name;
		public string m_value;

		public AttrRow(string name = "", string value = "")
		{
			m_name = name;
			m_value = value;
			InitializeComponent();
		}

		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{
			this.mx_name.Content = m_name;
			this.mx_value.Text = m_value;
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
		}
	}
}

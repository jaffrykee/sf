using System;
using System.Collections.Generic;
using System.Text;
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
	/// AttrList.xaml 的交互逻辑
	/// </summary>
	public partial class AttrList : Grid
	{
		public string m_name;

		public AttrList(string name = "")
		{
			m_name = name;
			this.InitializeComponent();
		}

		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{
			mx_title.Content = m_name;
		}
	}
}
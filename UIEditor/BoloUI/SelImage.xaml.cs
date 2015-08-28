using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace UIEditor.BoloUI
{
	/// <summary>
	/// SelImage.xaml 的交互逻辑
	/// </summary>
	public partial class SelImage : Window
	{
		public AttrRow m_rowSkin;

		static public SelImage s_pW;

		public SelImage(AttrRow rowSkin)
		{
			s_pW = this;
			m_rowSkin = rowSkin;
			InitializeComponent();
			this.Owner = MainWindow.s_pW;
		}
		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{

		}
		private void mx_root_Unloaded(object sender, RoutedEventArgs e)
		{
			s_pW = null;
		}

		private void mx_search_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (mx_search.Text != "")
			{
				MainWindow.refreshSearch(mx_rootItem, null);
				MainWindow.refreshSearch(mx_rootItem, mx_search.Text.ToString());
			}
			else
			{
				MainWindow.refreshSearch(mx_rootItem, null);
			}
		}
		private void mx_ok_Click(object sender, RoutedEventArgs e)
		{

		}
		private void mx_cancel_Click(object sender, RoutedEventArgs e)
		{

		}
	}
}

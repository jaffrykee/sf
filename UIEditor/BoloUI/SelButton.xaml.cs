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

namespace UIEditor.BoloUI
{
	/// <summary>
	/// SelButton.xaml 的交互逻辑
	/// </summary>
	public partial class SelButton : Grid
	{
		public MainWindow m_pW;
		public Basic m_ctrlUI;

		public SelButton(MainWindow pW, Basic ctrl)
		{
			InitializeComponent();
			m_pW = pW;
			m_ctrlUI = ctrl;
		}

		private void mx_radio_Checked(object sender, RoutedEventArgs e)
		{
			m_ctrlUI.changeSelectItem();
			mx_root.Background = new SolidColorBrush(Color.FromArgb(0xff, 0x33, 0x99, 0xff));
			mx_radio.Foreground = new SolidColorBrush(Color.FromArgb(0xff, 0xff, 0xff, 0xff));
		}
		private void mx_radio_Unchecked(object sender, RoutedEventArgs e)
		{
			mx_root.Background = new SolidColorBrush(Color.FromArgb(0x33, 0x33, 0x33, 0x33));
			mx_radio.Foreground = new SolidColorBrush(Color.FromArgb(0xff, 0x00, 0x00, 0x00));
		}
		private void mx_root_MouseDown(object sender, MouseButtonEventArgs e)
		{
			mx_radio.IsChecked = true;
		}
	}
}

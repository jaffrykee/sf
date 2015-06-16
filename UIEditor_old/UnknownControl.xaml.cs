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
	/// UnknownControl.xaml 的交互逻辑
	/// </summary>
	public partial class UnknownControl : UserControl
	{
		FileTabItem m_parent;

		public UnknownControl(FileTabItem parent)
		{
			InitializeComponent();
			m_parent = parent;
		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
		}

		private void closeFileTab(object sender, RoutedEventArgs e)
		{
		}
	}
}

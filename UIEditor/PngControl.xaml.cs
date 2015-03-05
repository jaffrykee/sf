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
	/// PngControl.xaml 的交互逻辑
	/// </summary>
	public partial class PngControl : UserControl
	{
		public PngControl()
		{
			InitializeComponent();
		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
			Image frame = (Image)sender;
			string path = ((ToolTip)((TabItem)this.Parent).ToolTip).Content.ToString();

			frame.Source = new BitmapImage(new Uri(@path, UriKind.Relative));
		}
	}
}

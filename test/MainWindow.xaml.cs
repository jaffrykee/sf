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
using System.Windows.Interop;
using System.Runtime.InteropServices; 

namespace test
{
	/// <summary>
	/// MainWindow.xaml 的交互逻辑
	/// </summary>
	public partial class MainWindow : Window
	{

		[DllImport("SharpInterface.dll", EntryPoint = "Add", ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
		public static extern int createWin(IntPtr hwnd);

		public MainWindow()
		{
			InitializeComponent();

		}

		private void WinLoaded(object sender, RoutedEventArgs e)
		{
			var tabContent = Activator.CreateInstance(Type.GetType("test.open")) as UserControl;
			mx_openFrame.Children.Add(tabContent);

			IntPtr handle;
			HwndSource hwndSource = PresentationSource.FromVisual(tabContent) as HwndSource;

			if (hwndSource != null)
			{
				handle = hwndSource.Handle;
				this.mx_poi.Text = handle.ToString();
				createWin(handle);
			}
		}
		
	}
}

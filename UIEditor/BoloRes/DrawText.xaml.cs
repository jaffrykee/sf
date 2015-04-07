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
using System.Data;

namespace UIEditor.BoloUI
{
	/// <summary>
	/// DrawText.xaml 的交互逻辑
	/// </summary>
	public partial class DrawText : Grid
	{
		public string m_text;

		public DrawText(XmlElement xe, string rootPath, XmlControl rootControl, string text)
		{
			InitializeComponent();
			m_text = text;
		}

		private void isLoaded(object sender, RoutedEventArgs e)
		{
			mx_text.Content = m_text;
		}
	}
}

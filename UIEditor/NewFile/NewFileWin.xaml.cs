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
using System.Windows.Shapes;

namespace UIEditor.NewFile
{
	/// <summary>
	/// NewFile.xaml 的交互逻辑
	/// </summary>
	public partial class NewFileWin : Window
	{
		public string m_tmplPath;
		public RadioButton m_curFileType;

		public NewFileWin(string path)
		{
			m_curFileType = null;
			m_tmplPath = path;
			InitializeComponent();
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
			mx_fileTypeFrame.Children.Add(new FileTypeRadio("a", "fileTypeFrame"));
		}

		private void mx_ok_Click(object sender, RoutedEventArgs e)
		{

		}
		private void mx_cancel_Click(object sender, RoutedEventArgs e)
		{

		}
		private void mx_fileName_TextChanged(object sender, TextChangedEventArgs e)
		{
			if(mx_fileName.Text != "")
			{
				mx_fileName.Background = new SolidColorBrush(Color.FromArgb(0xff, 0xff, 0xff, 0xff));

				if (!mx_ok.IsEnabled && m_curFileType != null)
				{
					mx_ok.IsEnabled = true;
				}
			}
			else
			{
				mx_fileName.Background = new SolidColorBrush(Color.FromArgb(0, 0, 0, 0));
				mx_ok.IsEnabled = false;
			}
		}
		private void mx_fileName_GotFocus(object sender, RoutedEventArgs e)
		{
			mx_fileName.Background = new SolidColorBrush(Color.FromArgb(0xff, 0xff, 0xff, 0xff));
		}
	}
}

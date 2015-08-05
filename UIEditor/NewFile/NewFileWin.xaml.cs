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
using System.IO;
using System.Xml;

namespace UIEditor.NewFile
{
	/// <summary>
	/// NewFile.xaml 的交互逻辑
	/// </summary>
	public partial class NewFileWin : Window
	{
		public string m_tmplPath;
		public FileTypeRadio m_curFileType;

		public NewFileWin(string path)
		{
			m_curFileType = null;
			InitializeComponent();
			if (Directory.Exists(path))
			{
				m_tmplPath = path;
				refreshFolder(m_tmplPath, mx_treeRootItem, true, true, addTmplToRadioGroup);
				mx_treeRootItem.Header = "模板";
			}
			//mx_fileTypeFrame.Children.Add(new FileTypeRadio(this, "a", "fileTypeFrame"));
		}

		static public void refreshFolder(
			string path,
			TreeViewItem rootItem,
			bool onlyFolder = false,
			bool isExpanded = true,
			MouseButtonEventHandler clickHandler = null)
		{
			rootItem.Items.Clear();
			rootItem.IsExpanded = isExpanded;

			int i = 0;
			int j = 0;

			DirectoryInfo di = new DirectoryInfo(path);
			foreach (var dri in di.GetDirectories())
			{
				TreeViewItem treeUIChild = new TreeViewItem();
				ToolTip treeTip = new ToolTip();

				i++;
				treeTip.Content = path + "\\" + dri.Name;
				treeUIChild.ToolTip = path + "\\" + dri.Name;
				treeUIChild.Header = dri.Name;
				rootItem.Items.Add(treeUIChild);
				if (clickHandler != null)
				{
					treeUIChild.PreviewMouseLeftButtonDown += clickHandler;
				}

				refreshFolder(path + "\\" + dri.Name, treeUIChild, onlyFolder, isExpanded, clickHandler);
			}
			if (!onlyFolder)
			{
				foreach (var dri in di.GetFiles("*"))
				{
					TreeViewItem treeUIChild = new TreeViewItem();
					ToolTip treeTip = new ToolTip();

					j++;
					treeTip.Content = path + "\\" + dri.Name;
					treeUIChild.ToolTip = path + "\\" + dri.Name;
					treeUIChild.Header = dri.Name;
					if (clickHandler != null)
					{
						treeUIChild.PreviewMouseLeftButtonDown += clickHandler;
					}
					rootItem.Items.Add(treeUIChild);
				}
			}
		}

		private void addTmplToRadioGroup(object sender, RoutedEventArgs e)//打开工程
		{
			mx_fileTypeFrame.Children.Clear();
			if(sender.GetType().ToString() == "System.Windows.Controls.TreeViewItem")
			{
				string path = ((TreeViewItem)sender).ToolTip.ToString();
				if(Directory.Exists(path))
				{
					DirectoryInfo di = new DirectoryInfo(path);
					foreach (var fileInfo in di.GetFiles("*"))
					{
						FileTypeRadio ftr = new FileTypeRadio(this, System.IO.Path.GetFileNameWithoutExtension(fileInfo.Name), di.Name);
						ToolTip treeTip = new ToolTip();

						treeTip.Content = path + "\\" + fileInfo.Name;
						ftr.ToolTip = treeTip.Content;
						mx_fileTypeFrame.Children.Add(ftr);
					}
				}
			}
		}

		private void mx_ok_Click(object sender, RoutedEventArgs e)
		{
			string tmplPath = m_curFileType.ToolTip.ToString();
			string type = System.IO.Path.GetExtension(m_curFileType.ToolTip.ToString());
			string path = MainWindow.s_pW.m_projPath;

			if(type == ".bur")
			{
				path = path + "\\skin";
			}
			path = path + "\\" + mx_fileName.Text.ToString() + ".xml";

			if(File.Exists(path))
			{
				MessageBox.Show("该文件名已经存在(" + path + ")，请重新输入文件名。", "文件名重复", MessageBoxButton.OK, MessageBoxImage.Warning);
			}
			else
			{
				File.Copy(tmplPath, path, false);
				MainWindow.s_pW.refreshProjTree(MainWindow.s_pW.m_projPath, MainWindow.s_pW.mx_treePro, true);
				this.Close();
			}
		}
		private void mx_cancel_Click(object sender, RoutedEventArgs e)
		{
			this.Close();
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

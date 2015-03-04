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
using System.Windows.Forms;
using System.IO;

namespace UIEditor
{
	/// <summary>
	/// MainWindow.xaml 的交互逻辑
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		private void openProj(object sender, RoutedEventArgs e)
		{
//			 OpenFileDialog openFileDialog = new OpenFileDialog();
//			 openFileDialog.Title = "选择文件";
//			 openFileDialog.Filter = "ryrp文件|*.ryrp|所有文件|*.*";
//			 openFileDialog.FileName = string.Empty;
//			 openFileDialog.FilterIndex = 1;
//			 openFileDialog.RestoreDirectory = true;
//			 openFileDialog.DefaultExt = "ryrp";
//			 DialogResult result = openFileDialog.ShowDialog();
//			 if (result == System.Windows.Forms.DialogResult.Cancel)
//			 {
//				 return;
//			 }
//			 string fileName = openFileDialog.FileName;
//			 this.pro.Content = fileName;
//			 //this.textBox1.Text = fileName;
			FolderBrowserDialog openFolderDialog = new FolderBrowserDialog();
			openFolderDialog.Description = "选择UI所在文件夹";
			openFolderDialog.SelectedPath = "E:\\mmo2013001\\artist\\version_backup\\ResourceDsKr_dev\\ui\\free";
			DialogResult result = openFolderDialog.ShowDialog();
			if (result == System.Windows.Forms.DialogResult.Cancel)
			{
				return;
			}
			string path = openFolderDialog.SelectedPath;
			int i = 0;
			int j = 0;

			DirectoryInfo di = new DirectoryInfo(path);
			foreach (var dri in di.GetDirectories())
			{
				i++;
				TreeViewItem treeUIChild = new TreeViewItem();
				treeUIChild.Header = dri.Name;
				this.treePro.Items.Add(treeUIChild);

				DirectoryInfo di2 = new DirectoryInfo(path + "\\" + dri.Name);
				foreach (var dri2 in di2.GetDirectories())
				{
					TreeViewItem treeUIChild2 = new TreeViewItem();
					treeUIChild2.Header = dri2.Name;
					treeUIChild.Items.Add(treeUIChild2);
				}
				foreach (var dri2 in di2.GetFiles("*"))
				{
					TreeViewItem treeUIChild2 = new TreeViewItem();
					treeUIChild2.Header = dri2.Name;
					treeUIChild.Items.Add(treeUIChild2);
				}
			}
			foreach (var dri in di.GetFiles("*"))
			{
				j++;
				TreeViewItem treeUIChild = new TreeViewItem();
				treeUIChild.Header = dri.Name;
				this.treePro.Items.Add(treeUIChild);
			}
			this.treePro.IsExpanded = true;
			this.treePro.Header = "UI工程目录(" + i + "个目录和" + j + "个项目)";
		}
	}
}

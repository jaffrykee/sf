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
using System.IO;

namespace UIEditor
{
	/// <summary>
	/// MainWindow.xaml 的交互逻辑
	/// </summary>
	public partial class MainWindow : Window
	{
		public string m_rootPath;
		public Dictionary<string, TabItem> m_mapFileTabs;

		public MainWindow()
		{
			m_rootPath = "";
			m_mapFileTabs = new Dictionary<string, TabItem>();
			InitializeComponent();
		}

		private void openProj(object sender, RoutedEventArgs e)
		{
			/*
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.Title = "选择文件";
			openFileDialog.Filter = "ryrp文件|*.ryrp|所有文件|*.*";
			openFileDialog.FileName = string.Empty;
			openFileDialog.FilterIndex = 1;
			openFileDialog.RestoreDirectory = true;
			openFileDialog.DefaultExt = "ryrp";
			DialogResult result = openFileDialog.ShowDialog();
			if (result == System.Windows.Forms.DialogResult.Cancel)
			{
				return;
			}
			string fileName = openFileDialog.FileName;
			this.pro.Content = fileName;
			//this.textBox1.Text = fileName;
			*/
			System.Windows.Forms.FolderBrowserDialog openFolderDialog = new System.Windows.Forms.FolderBrowserDialog();
			openFolderDialog.Description = "选择UI所在文件夹";
			openFolderDialog.SelectedPath = "E:\\mmo2013001\\artist\\version_backup\\ResourceDsKr_dev\\ui\\free";
			System.Windows.Forms.DialogResult result = openFolderDialog.ShowDialog();

			if (result == System.Windows.Forms.DialogResult.Cancel)
			{
				return;
			}
			string path = openFolderDialog.SelectedPath;

			m_rootPath = path;
			refreshProjTree(path, this.treePro, true);
		}

		private void refreshProjTree(string path, TreeViewItem rootItem, bool rootNode)
		{
			int i = 0;
			int j = 0;

			DirectoryInfo di = new DirectoryInfo(path);
			foreach (var dri in di.GetDirectories())
			{
				TreeViewItem treeUIChild = new TreeViewItem();
				ToolTip treeTip = new ToolTip();

				i++;
				treeTip.Content = path + "\\" + dri.Name;
				treeUIChild.ToolTip = treeTip;
				treeUIChild.Header = dri.Name;
				rootItem.Items.Add(treeUIChild);

				refreshProjTree(path + "\\" + dri.Name, treeUIChild, false);
			}
			foreach (var dri in di.GetFiles("*"))
			{
				TreeViewItem treeUIChild = new TreeViewItem();
				ToolTip treeTip = new ToolTip();

				j++;
				treeTip.Content = path + "\\" + dri.Name;
				treeUIChild.ToolTip = treeTip;
				treeUIChild.Header = dri.Name;
				treeUIChild.MouseDoubleClick += new MouseButtonEventHandler(openFileTab);
				rootItem.Items.Add(treeUIChild);
			}
			ToolTip rootTip = new ToolTip();

			if (rootNode == true)
			{
				rootTip.Content = path;
				rootItem.ToolTip = rootTip;
				rootItem.IsExpanded = false;
				rootItem.Header = "UI工程目录(" + i + "个目录和" + j + "个项目)";
			}
		}

		private void openFileTab(object sender, MouseEventArgs e)
		{
			TreeViewItem treeUI = (TreeViewItem)sender;
			TabItem tabItem;
			string tabPath = ((ToolTip)treeUI.ToolTip).Content.ToString();
			string fileType = tabPath.Substring(tabPath.LastIndexOf(".") + 1, (tabPath.Length - tabPath.LastIndexOf(".") - 1));   //扩展名

			if (m_mapFileTabs.TryGetValue(tabPath, out tabItem))
			{
				this.workTabs.SelectedItem = tabItem;
			}
			else
			{
				ToolTip tabTip = new ToolTip();
				Button close = new Button();

				tabItem = new TabItem();
				tabTip.Content = tabPath;
				tabItem.Header = treeUI.Header.ToString();
				tabItem.ToolTip = tabTip;

				var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.FileTabItem")) as UserControl;
				tabItem.Content = tabContent;

				this.workTabs.Items.Add(tabItem);
				m_mapFileTabs[tabPath] = tabItem;
				this.workTabs.SelectedItem = tabItem;
			}
		}
	}
}

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
using System.Xml;

namespace UIEditor
{
	/// <summary>
	/// MainWindow.xaml 的交互逻辑
	/// </summary>
	public struct OpenedFile
	{
		public string m_path;
		public TabItem m_tab;
		public TreeViewItem m_treeUI;
		public XmlDocument m_xmlDoc;

	}

	public partial class MainWindow : Window
	{
		public string m_rootPath;
		public Dictionary<string, OpenedFile> m_mapOpenedFiles;
		public Dictionary<string, XmlDocument> m_mapStrSkinGroup;
		public Dictionary<string, XmlElement> m_mapStrSkin;
		public float m_dpiSysX;
		public float m_dpiSysY;

		private int m_dep;

		public MainWindow()
		{
			m_rootPath = "";
			m_mapOpenedFiles = new Dictionary<string, OpenedFile>();
			InitializeComponent();
			m_mapStrSkinGroup = new Dictionary<string, XmlDocument>();
			m_mapStrSkin = new Dictionary<string, XmlElement>();
			m_dpiSysX = 96.0f;
			m_dpiSysY = 96.0f;
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
			openFolderDialog.SelectedPath = "E:\\mmo2013001\\artist\\clinet_onDev\\ui\\free";
			System.Windows.Forms.DialogResult result = openFolderDialog.ShowDialog();

			if (result == System.Windows.Forms.DialogResult.Cancel)
			{
				return;
			}
			string path = openFolderDialog.SelectedPath;

			m_rootPath = path;
			m_dep = 0;
			m_mapStrSkinGroup.Clear();
			m_mapStrSkin.Clear();
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

				m_dep++;
				refreshProjTree(path + "\\" + dri.Name, treeUIChild, false);
				m_dep--;
			}
			if (m_dep == 1 && rootItem.Header.ToString() == "skin")
			{
				foreach (var dri in di.GetFiles("*.xml"))
				{
					//皮肤组们
					TreeViewItem treeUIChild = new TreeViewItem();
					ToolTip treeTip = new ToolTip();

					XmlDocument xmlDoc = new XmlDocument();
					xmlDoc = new XmlDocument();
					xmlDoc.Load(path + "\\" + dri.Name);
					XmlNode xn = xmlDoc.SelectSingleNode("BoloUI");

					if (xn != null)
					{
						j++;
						treeTip.Content = path + "\\" + dri.Name;
						treeUIChild.ToolTip = treeTip;
						treeUIChild.Header = dri.Name;
						treeUIChild.MouseDoubleClick += new MouseButtonEventHandler(openFileTab);
						rootItem.Items.Add(treeUIChild);

						XmlNodeList xnl = xn.ChildNodes;
						string frontName = dri.Name.Substring(dri.Name.LastIndexOf("\\") + 1, (dri.Name.LastIndexOf(".") - dri.Name.LastIndexOf("\\") - 1));
						m_mapStrSkinGroup[frontName] = xmlDoc;

						foreach (XmlNode xnf in xnl)
						{
							//皮肤们
							if (xnf.NodeType == XmlNodeType.Element)
							{
								XmlElement xe = (XmlElement)xnf;

								switch (xe.Name)
								{
									case "publicskin":
										#region
										{
											m_mapStrSkin[xe.GetAttribute("Name")] = xe;
										}
										#endregion
										break;
									case "skin":
										#region
										{
											m_mapStrSkin[xe.GetAttribute("Name")] = xe;
										}
										#endregion
										break;
									default:
										break;
								}
							}
						}
					}
					else
					{
					}
				}
			}
			else
			{
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

				if (rootNode == true)
				{
					ToolTip rootTip = new ToolTip();
					rootTip.Content = path;
					rootItem.ToolTip = rootTip;
					rootItem.IsExpanded = false;
					rootItem.Header = "UI工程目录(" + i + "个目录和" + j + "个项目)";
				}
			}
		}

		private void openFileTab(object sender, MouseEventArgs e)
		{
			TreeViewItem treeUI = (TreeViewItem)sender;
			OpenedFile openedFile;
			string tabPath = ((ToolTip)treeUI.ToolTip).Content.ToString();
			string fileType = tabPath.Substring(tabPath.LastIndexOf(".") + 1, (tabPath.Length - tabPath.LastIndexOf(".") - 1));   //扩展名

			if (m_mapOpenedFiles.TryGetValue(tabPath, out openedFile))
			{
				this.workTabs.SelectedItem = openedFile.m_tab;
			}
			else
			{
				ToolTip tabTip = new ToolTip();
				Button close = new Button();

				openedFile.m_tab = new TabItem();
				tabTip.Content = tabPath;
				openedFile.m_tab.Header = treeUI.Header.ToString();
				openedFile.m_tab.ToolTip = tabTip;

				var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.FileTabItem")) as UserControl;
				openedFile.m_tab.Content = tabContent;
				openedFile.m_path = tabPath;
				openedFile.m_treeUI = treeUI;

				this.workTabs.Items.Add(openedFile.m_tab);
				m_mapOpenedFiles[tabPath] = openedFile;
				this.workTabs.SelectedItem = openedFile.m_tab;
			}
		}
	}
}

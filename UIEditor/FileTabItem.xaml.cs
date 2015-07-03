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
	/// FileTabItem.xaml 的交互逻辑
	/// </summary>
	public partial class FileTabItem : UserControl
	{
		public string m_filePath;
		public string m_fileType;
		public object m_child;

		public FileTabItem()
		{
			InitializeComponent();
			m_filePath = "";
		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
			if (m_filePath == "")
			{
				UserControl tabContent;
				MainWindow parentWindow = Window.GetWindow(this) as MainWindow;

				m_filePath = ((ToolTip)((TabItem)this.Parent).ToolTip).Content.ToString();
				this.filePath.Text = m_filePath;

				m_fileType = StringDic.getFileType(m_filePath).ToLower();
				switch(m_fileType)
				{
					case "bmp":
					case "cut":
					case "dcx":
					case "dds":
					case "ico":
					case "gif":
					case "jpg":
					case "lbm":
					case "lif":
					case "mdl":
					case "pcd":
					case "pcx":
					case "pic":
					case "png":
					case "pnm":
					case "psd":
					case "psp":
					case "raw":
					case "sgi":
					case "tga":
					case "tif":
					case "wal":
					case "act":
					case "pal":
						tabContent = Activator.CreateInstance(Type.GetType("UIEditor.PngControl"), this) as UserControl;
						break;
					case "xml":
						tabContent = Activator.CreateInstance(Type.GetType("UIEditor.XmlControl"), this) as UserControl;
						break;
					default:
						tabContent = Activator.CreateInstance(Type.GetType("UIEditor.UnknownControl"), this) as UserControl;
						break;
				}
				this.itemFrame.Children.Clear();
				this.itemFrame.Children.Add(tabContent);
				m_child = tabContent;
			}
		}

		private void closeFileTab(object sender, RoutedEventArgs e)
		{
			TabItem tabItem = (TabItem)this.Parent;
			string tabPath = ((ToolTip)tabItem.ToolTip).Content.ToString();
			MainWindow pW = Window.GetWindow(this) as MainWindow;

			if(pW.m_mapOpenedFiles[pW.m_curFile].haveDiffToFile())
			{
				MessageBoxResult ret = MessageBox.Show("是否将更改保存到 " + tabPath, "UIEditor", MessageBoxButton.YesNoCancel);
				switch (ret)
				{
					case MessageBoxResult.Yes:
						{
							((XmlControl)pW.m_mapOpenedFiles[m_filePath].m_frame).m_xmlDoc.Save(m_filePath);
							pW.m_mapOpenedFiles[m_filePath].m_lstOpt.m_saveNode = pW.m_mapOpenedFiles[m_filePath].m_lstOpt.m_curNode;
							pW.m_mapOpenedFiles[m_filePath].updateSaveStatus();
						}
						break;
					case MessageBoxResult.No:
						break;
					case MessageBoxResult.Cancel:
					default:
						return;
				}
			}
			pW.updateGL(m_filePath, MainWindow.W2GTag.W2G_NORMAL_NAME);
			pW.m_mapOpenedFiles.Remove(tabPath);
			pW.mx_workTabs.Items.Remove(tabItem);
			if(pW.mx_workTabs.Items.Count == 0)
			{
				pW.mx_treeCtrlFrame.Items.Clear();
				pW.mx_treeSkinFrame.Items.Clear();
			}
			pW.hiddenAllAttr();
		}
	}
}

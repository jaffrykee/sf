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

				m_filePath = ((ToolTip)((TabItem)this.Parent).ToolTip).Content.ToString();
				this.filePath.Text = m_filePath;

				m_fileType = m_filePath.Substring(m_filePath.LastIndexOf(".") + 1, (m_filePath.Length - m_filePath.LastIndexOf(".") - 1));
				if (m_fileType == "png")
				{
					tabContent = Activator.CreateInstance(Type.GetType("UIEditor.PngControl"), this) as UserControl;
				}
				else if (m_fileType == "xml")
				{
					tabContent = Activator.CreateInstance(Type.GetType("UIEditor.XmlControl"), this) as UserControl;
				}
				else
				{
					tabContent = Activator.CreateInstance(Type.GetType("UIEditor.UnknownControl"), this) as UserControl;
				}
				this.itemFrame.Child = tabContent;
				m_child = tabContent;
			}
		}

		private void closeFileTab(object sender, RoutedEventArgs e)
		{
			TabItem tabItem = (TabItem)this.Parent;
			string tabPath = ((ToolTip)tabItem.ToolTip).Content.ToString();
			MainWindow parentWindow = Window.GetWindow(this) as MainWindow;

			parentWindow.m_mapOpenedFiles.Remove(tabPath);
			parentWindow.mx_workTabs.Items.Remove(tabItem);
		}
	}
}

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
using System.Runtime.InteropServices;
using System.Windows.Interop;
using System.Text.RegularExpressions;
using UIEditor.XmlOperation;

namespace UIEditor
{
	public class OpenedFile
	{
		public string m_path;
		public TabItem m_tab;
		public TreeViewItem m_treeUI;
		public UserControl m_frame;
		public string m_fileType;
		public XmlOperationList m_lstOpt;

		public OpenedFile(TreeViewItem treeUI)
		{
			MainWindow pW = Window.GetWindow(treeUI) as MainWindow;

			m_path = ((ToolTip)treeUI.ToolTip).Content.ToString();
			m_fileType = StringDic.getFileType(m_path);
			m_tab = new TabItem();
			m_treeUI = treeUI;

			m_tab.Unloaded += new RoutedEventHandler(pW.eventCloseFile);
			ToolTip tabTip = new ToolTip();
			Button close = new Button();
			tabTip.Content = m_path;
			m_tab.Header = treeUI.Header.ToString();
			m_tab.ToolTip = tabTip;
			var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.FileTabItem")) as UserControl;
			m_tab.Content = tabContent;

			pW.mx_workTabs.Items.Add(m_tab);
			pW.mx_workTabs.SelectedItem = m_tab;

			m_lstOpt = new XmlOperationList(pW, this, 50);
		}
	}
}

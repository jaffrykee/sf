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
		public TreeViewItem m_treeSkin;
		public UserControl m_frame;
		public string m_fileType;
		public HistoryList m_lstOpt;

		public string m_preViewBaseId;
		public string m_preViewSkinName;
		public BoloUI.Basic m_prePlusCtrlUI;

		public OpenedFile(TreeView treeUIFrame, TreeView treeSkinFrame, string path)
		{
			MainWindow pW = Window.GetWindow(treeUIFrame) as MainWindow;

			m_path = path;
			m_fileType = StringDic.getFileType(m_path);
			m_tab = new TabItem();
			m_treeUI = new TreeViewItem();
			m_treeSkin = new TreeViewItem();

			m_tab.Unloaded += new RoutedEventHandler(pW.eventCloseFile);
			ToolTip tabTip = new ToolTip();
			tabTip.Content = m_path;
			m_tab.Header = StringDic.getFileNameWithoutPath(path);
			m_tab.ToolTip = tabTip;
			var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.FileTabItem")) as UserControl;
			m_tab.Content = tabContent;

			pW.mx_workTabs.Items.Add(m_tab);
			pW.mx_workTabs.SelectedItem = m_tab;

			treeUIFrame.Items.Add(m_treeUI);
			m_treeUI.Header = StringDic.getFileNameWithoutPath(path);
			m_treeUI.ToolTip = tabTip;
			m_treeUI.IsExpanded = true;
			treeSkinFrame.Items.Add(m_treeSkin);
			m_treeSkin.Header = StringDic.getFileNameWithoutPath(path);
			m_treeSkin.ToolTip = tabTip;
			m_treeSkin.IsExpanded = true;
		}

		public bool frameIsXmlCtrl()
		{
			if (m_frame != null)
			{
				if (m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		public bool haveDiffToFile()
		{
			if (frameIsXmlCtrl())
			{
				if (m_lstOpt.m_saveNode == m_lstOpt.m_curNode)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else
			{
				return false;
			}
		}
		public void updateSaveStatus()
		{
			string ec = m_tab.Header.ToString().Substring(m_tab.Header.ToString().Length - 1, 1);
			if (haveDiffToFile())
			{
				//加上*
				if (ec != "*")
				{
					m_tab.Header = m_tab.Header.ToString() + "*";
				}
			}
			else
			{
				//去掉*
				if (ec == "*")
				{
					m_tab.Header = m_tab.Header.ToString().Substring(0, m_tab.Header.ToString().Length - 1);
				}
			}
		}
	}
}

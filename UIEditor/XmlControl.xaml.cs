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
	/// XmlControl.xaml 的交互逻辑
	/// </summary>
	public partial class XmlControl : UserControl
	{
		public FileTabItem m_parent;
		public bool m_loaded;
		public MainWindow m_parentWindow;
		public OpenedFile m_openedFile;
		//以baseID为索引的UI们
		public Dictionary<string, BoloUI.Basic> m_mapCtrlUI;

		public XmlControl(FileTabItem parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
			m_mapCtrlUI = new Dictionary<string, BoloUI.Basic>();
		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				m_parentWindow = Window.GetWindow(this) as MainWindow;
				m_openedFile = m_parentWindow.m_mapOpenedFiles[m_parent.m_filePath];
				m_openedFile.m_frame = this;
				m_openedFile.m_treeUI.Items.Clear();

				m_parentWindow.mx_debug.Text += "=====" + m_openedFile.m_path + "=====\r\n";

				XmlNode xn = m_openedFile.m_xmlDoc.SelectSingleNode("BoloUI");
				if (xn != null)
				{
					XmlNodeList xnl = xn.ChildNodes;
					TreeViewItem publicresFolder = new TreeViewItem();
					TreeViewItem publicskinFolder = new TreeViewItem();
					TreeViewItem resFolder = new TreeViewItem();
					TreeViewItem skinFolder = new TreeViewItem();
					TreeViewItem BoloUIEventFolder = new TreeViewItem();
					TreeViewItem skingroupFolder = new TreeViewItem();

					this.textContent.Text += ("未被解析的项目：\r\n");
					foreach (XmlNode xnf in xnl)
					{
						if (xnf.NodeType == XmlNodeType.Element)
						{
							XmlElement xe = (XmlElement)xnf;

							switch (xe.Name)
							{
								case "publicresource":
								case "publicskin":
								case "resource":
								case "skin":
								case "skingroup":
								case "BoloUIEvent":
								case "panel":
									var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), xe, this) as TreeViewItem;
									this.m_openedFile.m_treeUI.Items.Add(treeChild);
									break;
								default:
									{
										this.textContent.Text += (xe.Name + ":" + xe.GetAttribute("Name") + "\r\n");
									}
									break;
							}
						}
					}
				}
				else
				{
					this.textContent.Text += ("这不是一个有效的BoloUI文件。" + "\r\n");
				}
				/*
					using (StreamReader sr = new StreamReader(path, Encoding.UTF8))
					{
						int lineCount = 0;
						while (sr.Peek() > 0)
						{
							lineCount++;
							string temp = sr.ReadLine();
							this.textContent.Text += (temp + "\r\n");
						}
					}
				 */

				m_loaded = true;
			}
		}
	}
}

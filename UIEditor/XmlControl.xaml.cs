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

		public XmlControl(FileTabItem parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				string path = this.m_parent.m_filePath;
				XmlDocument xmlDoc = new XmlDocument();
				xmlDoc.Load(path);
				XmlNode xn = xmlDoc.SelectSingleNode("BoloUI");

				m_parentWindow = Window.GetWindow(this) as MainWindow;
				m_openedFile = m_parentWindow.m_mapOpenedFiles[m_parent.m_filePath];
				//清空上次打开遗留的TreeViewItem
				this.m_openedFile.m_treeUI.Items.Clear();
				if (xn != null)
				{
					XmlNodeList xnl = xn.ChildNodes;
					TreeViewItem publicresFolder = new TreeViewItem();
					TreeViewItem publicskinFolder = new TreeViewItem();
					TreeViewItem resFolder = new TreeViewItem();
					TreeViewItem skinFolder = new TreeViewItem();
					TreeViewItem BoloUIEventFolder = new TreeViewItem();
					TreeViewItem panelFolder = new TreeViewItem();
					bool had_publicresource = false;
					bool had_publicskin = false;
					bool had_resource = false;
					bool had_skin = false;
					bool had_BoloUIEvent = false;
					bool had_panel = false;

					foreach (XmlNode xnf in xnl)
					{
						if (xnf.NodeType == XmlNodeType.Element)
						{
							XmlElement xe = (XmlElement)xnf;

							switch (xe.Name)
							{
								case "publicresource":
									#region
									{
										if(had_publicresource == false)
										{
											publicresFolder.Header = "publicresource";
											this.m_openedFile.m_treeUI.Items.Add(publicresFolder);
											had_publicresource = true;
										}
										TreeViewItem node = new TreeViewItem();
										node.Header = xe.GetAttribute("name");
										publicresFolder.Items.Add(node);
									}
									#endregion
									break;
								case "publicskin":
									#region
									{
										if(had_publicskin == false)
										{
											publicskinFolder.Header = "publicskin";
											this.m_openedFile.m_treeUI.Items.Add(publicskinFolder);
											had_publicskin = true;
										}
										TreeViewItem node = new TreeViewItem();
										node.Header = xe.GetAttribute("Name");
										publicskinFolder.Items.Add(node);
									}
									#endregion
									break;
								case "resource":
									#region
									{
										if (had_resource == false)
										{
											resFolder.Header = "resource";
											this.m_openedFile.m_treeUI.Items.Add(resFolder);
											had_resource = true;
										}
										TreeViewItem node = new TreeViewItem();
										node.Header = xe.GetAttribute("name");
										resFolder.Items.Add(node);
									}
									#endregion
									break;
								case "skin":
									#region
									{
										if (had_skin == false)
										{
											skinFolder.Header = "skin";
											this.m_openedFile.m_treeUI.Items.Add(skinFolder);
											had_skin = true;
										}
										TreeViewItem node = new TreeViewItem();
										node.Header = xe.GetAttribute("Name");
										skinFolder.Items.Add(node);
									}
									#endregion
									break;
								case "BoloUIEvent":
									#region
									{
										if (had_BoloUIEvent == false)
										{
											BoloUIEventFolder.Header = "BoloUIEvent";
											this.m_openedFile.m_treeUI.Items.Add(BoloUIEventFolder);
											had_BoloUIEvent = true;
										}
										TreeViewItem node = new TreeViewItem();
										node.Header = xe.GetAttribute("function");
										BoloUIEventFolder.Items.Add(node);
									}
									#endregion
									break;
								case "panel":
									#region
									{
										if (had_panel == false)
										{
											panelFolder.Header = "panel";
											this.m_openedFile.m_treeUI.Items.Add(panelFolder);
											had_panel = true;
										}
										TreeViewItem node = new TreeViewItem();
										node.Header = xe.GetAttribute("name");
										panelFolder.Items.Add(node);
									}
									#endregion
									break;
								default:
									{
									}
									break;
							}
							this.textContent.Text += (xe.Name + ":" + xe.GetAttribute("Name") + "\r\n");
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

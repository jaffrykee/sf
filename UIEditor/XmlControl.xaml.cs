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
				m_openedFile.m_xmlDoc = new XmlDocument();
				m_openedFile.m_xmlDoc.Load(path);
				XmlNode xn = m_openedFile.m_xmlDoc.SelectSingleNode("BoloUI");

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
					TreeViewItem skingroupFolder = new TreeViewItem();
					bool had_publicresource = false;
					bool had_publicskin = false;
					bool had_resource = false;
					bool had_skin = false;
					bool had_BoloUIEvent = false;
					bool had_skingroup = false;

					this.textContent.Text += ("未被解析的项目：" + "\r\n");
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
										var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.PublicResource"), xe, this) as TreeViewItem;
										publicresFolder.Items.Add(treeChild);
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
										var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.PublicSkin"), xe, this) as TreeViewItem;
										publicskinFolder.Items.Add(treeChild);
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
										var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Resource"), xe, this) as TreeViewItem;
										resFolder.Items.Add(treeChild);
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
										var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Skin"), xe, this) as TreeViewItem;
										skinFolder.Items.Add(treeChild);
									}
									#endregion
									break;
								case "skingroup":
									#region
									{
										if (had_skingroup == false)
										{
											skingroupFolder.Header = "skingroup";
											this.m_openedFile.m_treeUI.Items.Add(skingroupFolder);
											had_skingroup = true;
										}
										var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.SkinGroup"), xe, this) as TreeViewItem;
										skingroupFolder.Items.Add(treeChild);
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
										XmlNodeList xnl1 = xe.ChildNodes;
										foreach (XmlNode xnf1 in xnl1)
										{
											XmlElement xe1 = (XmlElement)xnf1;
											switch(xe1.Name)
											{
												case "event":
													#region
													{
														var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Event"), xe1, this) as TreeViewItem;
														BoloUIEventFolder.Items.Add(treeChild);
													}
													#endregion
													break;
												default:
													this.textContent.Text += (xe1.Name + ":" + xe1.GetAttribute("Name") + "\r\n");
													break;
											}
										}
									}
									#endregion
									break;
								case "panel":
									#region
									{
										var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.panel"), xe, this) as TreeViewItem;
										this.m_openedFile.m_treeUI.Items.Add(treeChild);
									}
									#endregion
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

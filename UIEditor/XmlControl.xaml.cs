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
	public partial class XmlControl : UserControl
	{
		public FileTabItem m_parent;
		public bool m_loaded;
		public MainWindow m_pW;
		public OpenedFile m_openedFile;
		//以baseID为索引的UI们
		public Dictionary<string, BoloUI.Basic> m_mapCtrlUI;
		public Dictionary<string, string> m_mapSkinLink;
		public Dictionary<string, BoloRes.ResBasic> m_mapSkin;
		public Dictionary<XmlElement, XmlItem> m_mapXeItem;
		public XmlDocument m_xmlDoc;
		public XmlElement m_xeRootCtrl;
		public XmlElement m_xeRootBolo;
		public bool m_isOnlySkin;
		public BoloUI.Basic m_skinViewCtrlUI;

		public BoloUI.Basic m_treeUI;
		public BoloRes.ResBasic m_treeSkin;

		public XmlControl(FileTabItem parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
			m_mapCtrlUI = new Dictionary<string, BoloUI.Basic>();
			m_mapSkinLink = new Dictionary<string, string>();
			m_mapSkin = new Dictionary<string, BoloRes.ResBasic>();
			m_mapXeItem = new Dictionary<XmlElement, XmlItem>();
			m_isOnlySkin = true;
			m_skinViewCtrlUI = null;
		}

		public void deleteBaseId(XmlNode xn)
		{
			if (xn != null)
			{
				if (xn.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xn;

					MainWindow.CtrlDef_T ctrlDef;

					if (xe.Name != "event" && m_pW.m_mapCtrlDef.TryGetValue(xe.Name, out ctrlDef))
					{
						if (xe.GetAttribute("baseID") != "")
						{
							m_mapCtrlUI.Remove(xe.GetAttribute("baseID"));
						}
					}
				}

				XmlNodeList xnl = xn.ChildNodes;
				foreach (XmlNode xnf in xnl)
				{
					deleteBaseId(xnf);
				}
			}
		}
		public void checkBaseId(XmlNode xn)
		{
			if (xn != null)
			{
				if (xn.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xn;

					MainWindow.CtrlDef_T ctrlDef;

					if (xe.Name != "event" && m_pW.m_mapCtrlDef.TryGetValue(xe.Name, out ctrlDef))
					{
						if (xe.GetAttribute("baseID") == "")
						{
							xe.SetAttribute("baseID", System.Guid.NewGuid().ToString().Substring(32 / 2));
							m_pW.mx_debug.Text += "<警告>baseID没有赋值，已经将其替换为随机值：" + xe.GetAttribute("baseID") + "\r\n";
							//m_openedFile.updateSaveStatus();
						}

						BoloUI.Basic tmpNull;
						string id = xe.GetAttribute("baseID");

						if (m_mapCtrlUI.TryGetValue(id, out tmpNull))
						{
							//baseId重复了
							xe.SetAttribute("baseID", System.Guid.NewGuid().ToString().Substring(32 / 2));
							m_pW.mx_debug.Text += "<警告>baseID(" + id + ")重复，已经将其替换为随机值：" + xe.GetAttribute("baseID") + "\r\n";
							id = xe.GetAttribute("baseID");
							//m_openedFile.updateSaveStatus();
						}
						m_mapCtrlUI[id] = null;
					}
				}

				XmlNodeList xnl = xn.ChildNodes;
				foreach (XmlNode xnf in xnl)
				{
					checkBaseId(xnf);
				}
			}
		}
		
		static public void changeSelectCtrlAndFile(MainWindow pW, string path, string baseId)
		{
			if (File.Exists(path))
			{
				//todo
			}
			else
			{
				pW.mx_debug.Text += "<警告>文件：\"" + path + "\"不存在，请检查路径。\r\n";
			}
		}
		static public void changeSelectSkinAndFile(MainWindow pW, string path, string skinName, BoloUI.Basic ctrlUI = null)
		{
			if (File.Exists(path))
			{
				OpenedFile skinFile;

				pW.openFileByPath(path);
				if(pW.m_mapOpenedFiles.TryGetValue(path, out skinFile))
				{
					if (skinFile.m_frame != null)
					{
						if (skinFile.m_frame.GetType().ToString() == "UIEditor.XmlControl")
						{
							XmlControl xmlCtrl = (XmlControl)skinFile.m_frame;
							BoloRes.ResBasic skinBasic;

							if(xmlCtrl.m_mapSkin.TryGetValue(skinName, out skinBasic))
							{
								skinBasic.changeSelectItem(ctrlUI);
							}
							else
							{
								pW.mx_debug.Text += "<警告>然而，并没有这个皮肤。(" + skinName + ")\r\n";
							}
						}
					}
					else
					{
						skinFile.m_preViewSkinName = skinName;
						skinFile.m_prePlusCtrlUI = ctrlUI;
					}
				}
			}
			else
			{
				pW.mx_debug.Text += "<警告>文件：\"" + path + "\"不存在，请检查路径。\r\n";
			}
		}
		public bool findSkinAndSelect(string skinName, BoloUI.Basic ctrlUI = null)
		{
			string groupName;

			if (m_mapSkinLink.TryGetValue(skinName, out groupName))
			{
				string path = m_pW.m_skinPath + "\\" + groupName + ".xml";

				changeSelectSkinAndFile(m_pW, path, skinName, ctrlUI);
			}
			else
			{
				m_pW.mx_debug.Text += "<警告>然而，并没有这个皮肤。(" + skinName + ")\r\n";
			}
			return false;
		}
		public void refreshBoloUIView(bool changeItem = false)
		{
			if (m_isOnlySkin)
			{
				m_pW.mx_leftToolFrame.SelectedItem = m_pW.mx_skinFrame;
				m_pW.mx_ctrlFrame.IsEnabled = false;
				m_pW.mx_skinFrame.IsEnabled = true;
			}
			else
			{
				if (changeItem)
				{
					m_pW.mx_leftToolFrame.SelectedItem = m_pW.mx_ctrlFrame;
				}
				m_pW.mx_ctrlFrame.IsEnabled = true;
				m_pW.mx_skinFrame.IsEnabled = true;
			}
		}
		public void refreshVRect()
		{
			string msgData = "";

			foreach(KeyValuePair<string, BoloUI.Basic> pairCtrlUI in m_mapCtrlUI.ToList())
			{
				msgData += pairCtrlUI.Key + ":";
			}
			m_pW.updateGL(msgData, MainWindow.W2GTag.W2G_UI_VRECT);
		}
		public void refreshSkinDic(string skinGroupName)
		{
			string path = m_pW.m_skinPath + "\\" + skinGroupName + ".xml";

			if (File.Exists(path))
			{
				XmlDocument skinDoc = new XmlDocument();
				skinDoc.Load(path);
				XmlNode xn = skinDoc.SelectSingleNode("BoloUI");

				if (xn != null)
				{
					XmlNodeList xnlSkin = xn.ChildNodes;

					foreach (XmlNode xnfSkin in xnlSkin)
					{
						if (xnfSkin.NodeType == XmlNodeType.Element)
						{
							XmlElement xeSkin = (XmlElement)xnfSkin;

							if (xeSkin.Name == "skin" || xeSkin.Name == "publicskin")
							{
								if(xeSkin.GetAttribute("Name") != "")
								{
									string nullStr;
									if (!m_mapSkinLink.TryGetValue(xeSkin.GetAttribute("Name"), out nullStr))
									{
										m_mapSkinLink.Add(xeSkin.GetAttribute("Name"), skinGroupName);
									}
									else
									{
										m_pW.mx_debug.Text += "<错误>文件:\"" + path + "\"中，存在重复Name的皮肤(" + 
											xeSkin.GetAttribute("Name") + ")，后一个同名的皮肤将不能正确显示。\r\n";
									}
								}
							}
						}
					}
				}
			}
			else
			{
				//不存在
				m_pW.mx_debug.Text += "<警告>皮肤组：\"" + skinGroupName + "\"不存在，请检查路径：\"" + path + "\"。\r\n";
			}
		}
		public void refreshControl()
		{
			m_pW = Window.GetWindow(this) as MainWindow;

			m_openedFile = m_pW.m_mapOpenedFiles[m_parent.m_filePath];
			m_openedFile.m_frame = this;
			m_openedFile.m_lstOpt = new XmlOperation.HistoryList(m_pW, this, 65535);

			m_pW.mx_debug.Text += "=====" + m_openedFile.m_path + "=====\r\n";

			m_xmlDoc = new XmlDocument();
			m_xmlDoc.Load(m_openedFile.m_path);
			m_xeRootBolo = (XmlElement)m_xmlDoc.SelectSingleNode("BoloUI");

			m_treeUI = new BoloUI.Basic(m_xeRootBolo, this, true);
			m_treeSkin = new BoloRes.ResBasic(m_xeRootBolo, this, null);

			m_pW.mx_treeCtrlFrame.Items.Add(m_treeUI);
			m_treeUI.Header = StringDic.getFileNameWithoutPath(m_openedFile.m_path);
			m_treeUI.ToolTip = m_openedFile.m_path;
			m_treeUI.IsExpanded = true;
			m_pW.mx_treeSkinFrame.Items.Add(m_treeSkin);
			m_treeSkin.Header = StringDic.getFileNameWithoutPath(m_openedFile.m_path);
			m_treeSkin.ToolTip = m_openedFile.m_path;
			m_treeSkin.IsExpanded = true;

			m_treeUI.Items.Clear();
			m_treeSkin.Items.Clear();
			if (m_xeRootBolo != null)
			{
				XmlNodeList xnl = m_xeRootBolo.ChildNodes;

				checkBaseId(m_xeRootBolo);
				//m_pW.mx_debug.Text += ("未被解析的项目：\r\n");
				foreach (XmlNode xnf in xnl)
				{
					if (xnf.NodeType == XmlNodeType.Element)
					{
						XmlElement xe = (XmlElement)xnf;
						MainWindow.CtrlDef_T ctrlPtr;
						MainWindow.SkinDef_T skinPtr;

						if (m_pW.m_mapCtrlDef.TryGetValue(xe.Name, out ctrlPtr))
						{
							var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), xe, this, false) as TreeViewItem;
							m_treeUI.Items.Add(treeChild);
							m_isOnlySkin = false;
							m_xeRootCtrl = xe;
						}
						else if (m_pW.m_mapSkinResDef.TryGetValue(xe.Name, out skinPtr))
						{
							var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloRes.ResBasic"), xe, this, skinPtr) as TreeViewItem;
							m_treeSkin.Items.Add(treeChild);
							treeChild.IsExpanded = false;
							if (xe.Name == "skingroup")
							{
								refreshSkinDic(xe.GetAttribute("Name"));
							}
						}
					}
				}
				refreshSkinDic("publicskin");
				refreshBoloUIView(true);
			}
			else
			{
				m_pW.mx_debug.Text += ("这不是一个有效的BoloUI文件。" + "\r\n");
			}
			m_pW.updateXmlToGL(m_openedFile.m_path, m_xmlDoc);
			m_loaded = true;
			if (m_openedFile.m_preViewSkinName != null && m_openedFile.m_preViewSkinName != "")
			{
				BoloRes.ResBasic skinBasic;

				if(m_mapSkin.TryGetValue(m_openedFile.m_preViewSkinName, out skinBasic))
				{
					skinBasic.changeSelectItem(m_openedFile.m_prePlusCtrlUI);
				}
				else
				{
					m_pW.mx_debug.Text += "<警告>然而，并没有这个皮肤。(" + m_openedFile.m_preViewSkinName + ")\r\n";
				}
			}
		}

		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				refreshControl();
			}
		}
		private void mx_root_Unloaded(object sender, RoutedEventArgs e)
		{
			m_pW.mx_selCtrlLstFrame.Children.Clear();
			if (m_pW.mx_treeCtrlFrame.Items.Count > 0 && m_pW.mx_treeCtrlFrame.Items[0] != null)
			{
				TreeViewItem firstItem = (TreeViewItem)m_pW.mx_treeCtrlFrame.Items[0];

				if(firstItem.Header.ToString() == StringDic.getFileNameWithoutPath(m_openedFile.m_path))
				{
					m_pW.mx_treeCtrlFrame.Items.Clear();
					m_pW.mx_treeSkinFrame.Items.Clear();
				}
			}
		}
	}
}

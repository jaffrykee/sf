﻿using System;
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
		public XmlDocument m_xmlDoc;
		public TreeViewItem m_treeCtrl;
		public bool m_isOnlySkin;

		public XmlControl(FileTabItem parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
			m_mapCtrlUI = new Dictionary<string, BoloUI.Basic>();
			m_isOnlySkin = true;
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

		public void refreshBoloUIView(bool changeItem = false)
		{
			if (m_isOnlySkin)
			{
				m_pW.mx_leftToolFrame.SelectedItem = m_pW.mx_skinFrame;
				m_pW.mx_ctrlFrame.IsEnabled = false;
				if (m_pW.Resources["CKForeDis"] != null &&
					m_pW.Resources["CKForeDis"].GetType().ToString() == "System.Windows.Media.Color")
				{
					m_pW.mx_ctrlFrame.Foreground = new SolidColorBrush((Color)m_pW.Resources["CKForeDis"]);
				}
			}
			else
			{
				if (changeItem)
				{
					m_pW.mx_leftToolFrame.SelectedItem = m_pW.mx_ctrlFrame;
				}
				m_pW.mx_ctrlFrame.IsEnabled = true;
				if (m_pW.Resources["CKFore"] != null &&
					m_pW.Resources["CKFore"].GetType().ToString() == "System.Windows.Media.Color")
				{
					m_pW.mx_ctrlFrame.Foreground = new SolidColorBrush((Color)m_pW.Resources["CKFore"]);
				}
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
		public void refreshControl()
		{
			m_pW = Window.GetWindow(this) as MainWindow;
			m_openedFile = m_pW.m_mapOpenedFiles[m_parent.m_filePath];
			m_openedFile.m_frame = this;
			m_openedFile.m_lstOpt = new XmlOperation.HistoryList(m_pW, this, 50);
			m_openedFile.m_treeUI.Items.Clear();
			m_openedFile.m_treeSkin.Items.Clear();

			m_pW.mx_debug.Text += "=====" + m_openedFile.m_path + "=====\r\n";

			m_xmlDoc = new XmlDocument();
			m_xmlDoc.Load(m_openedFile.m_path);
			XmlNode xn = m_xmlDoc.SelectSingleNode("BoloUI");
			if (xn != null)
			{
				XmlNodeList xnl = xn.ChildNodes;

				checkBaseId(xn);
				this.textContent.Text += ("未被解析的项目：\r\n");
				foreach (XmlNode xnf in xnl)
				{
					if (xnf.NodeType == XmlNodeType.Element)
					{
						XmlElement xe = (XmlElement)xnf;
						MainWindow.CtrlDef_T ctrlPtr;
						MainWindow.SkinDef_T skinPtr;

						if (m_pW.m_mapCtrlDef.TryGetValue(xe.Name, out ctrlPtr))
						{
							var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), xe, this) as TreeViewItem;
							this.m_openedFile.m_treeUI.Items.Add(treeChild);
							m_isOnlySkin = false;
						}
						else if (m_pW.m_mapSkinResDef.TryGetValue(xe.Name, out skinPtr))
						{
							var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloRes.ResBasic"), xe, this, skinPtr) as TreeViewItem;
							this.m_openedFile.m_treeSkin.Items.Add(treeChild);
						}
					}
				}
				refreshBoloUIView(true);
			}
			else
			{
				this.textContent.Text += ("这不是一个有效的BoloUI文件。" + "\r\n");
			}
			m_pW.updateXmlToGL(m_openedFile.m_path, m_xmlDoc);
			m_loaded = true;
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
			if (m_pW.mx_treeCtrlFrame.Items[0] != null)
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

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
using System.Xml;

namespace UIEditor
{
	public partial class XmlItem : TreeViewItem
	{
		public XmlControl m_rootControl;
		public MainWindow m_pW;
		public XmlElement m_xe;
		public bool m_setFocus;
		public bool m_isCtrl;
		public string m_type;

		public XmlItem()
		{

		}
		public XmlItem(XmlElement xe, XmlControl rootControl)
		{
			InitializeComponent();
			m_rootControl = rootControl;
			m_xe = xe;
			m_pW = rootControl.m_pW;
			m_rootControl.m_mapXeItem[xe] = this;
		}

		protected virtual void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{

		}
		public virtual void changeSelectItem(object obj = null)
		{

		}
		public virtual void initHeader()
		{

		}
		protected virtual void addChild()
		{

		}

		private void mx_root_DragEnter(object sender, DragEventArgs e)
		{

		}
		private void mx_root_DragLeave(object sender, DragEventArgs e)
		{

		}
		private void mx_root_DragOver(object sender, DragEventArgs e)
		{

		}
		private void mx_root_Drop(object sender, DragEventArgs e)
		{

		}

		private void mx_text_MouseDown(object sender, MouseButtonEventArgs e)
		{
			changeSelectItem();
		}
		private void mx_root_Selected(object sender, RoutedEventArgs e)
		{
		}
		private void mx_root_Unselected(object sender, RoutedEventArgs e)
		{
		}

		public void refreshItemMenu()
		{
			switch(m_type)
			{
				case "CtrlUI":
					{
						#region
						mx_addCtrl.Visibility = System.Windows.Visibility.Visible;
						mx_addNode.Visibility = System.Windows.Visibility.Collapsed;
						if (m_xe.Name == "BoloUI")
						{
							MainWindow.CtrlDef_T panelCtrlDef;

							mx_cut.IsEnabled = false;
							mx_copy.IsEnabled = false;
							mx_delete.IsEnabled = false;
							mx_moveUp.IsEnabled = false;
							mx_moveDown.IsEnabled = false;
							if (m_pW.m_xePaste != null)
							{
								if (m_pW.m_mapPanelCtrlDef.TryGetValue(m_pW.m_xePaste.Name, out panelCtrlDef))
								{
									mx_paste.IsEnabled = true;
								}
								else
								{
									mx_paste.IsEnabled = false;
								}
							}
							else
							{
								mx_paste.IsEnabled = false;
							}
						}
						else
						{
							mx_cut.IsEnabled = true;
							mx_copy.IsEnabled = true;
							mx_delete.IsEnabled = true;
							mx_moveUp.IsEnabled = true;
							mx_moveDown.IsEnabled = true;
							if (m_pW.m_xePaste != null)
							{
								mx_paste.IsEnabled = true;
							}
							else
							{
								mx_paste.IsEnabled = false;
							}
						}
						#endregion
					}
					break;
				case "Skin":
					{
						#region
						mx_addCtrl.Visibility = System.Windows.Visibility.Collapsed;
						mx_addNode.Visibility = System.Windows.Visibility.Visible;
						if (m_xe.Name == "BoloUI")
						{
							mx_delete.IsEnabled = false;
							mx_moveUp.IsEnabled = false;
							mx_moveDown.IsEnabled = false;
							mx_cut.IsEnabled = false;
							mx_copy.IsEnabled = false;
						}
						else
						{
							mx_delete.IsEnabled = true;
							mx_moveUp.IsEnabled = true;
							mx_moveDown.IsEnabled = true;
							mx_cut.IsEnabled = true;
							mx_copy.IsEnabled = true;
						}
						if (m_pW.m_xePaste != null)
						{
							mx_paste.IsEnabled = true;
						}
						else
						{
							mx_paste.IsEnabled = false;
						}
						#endregion
					}
					break;
				default:
					break;
			}
		}
		private void mx_menu_Loaded(object sender, RoutedEventArgs e)
		{
			refreshItemMenu();
		}
		private void mx_menu_Unloaded(object sender, RoutedEventArgs e)
		{
		}

		public bool canCut()
		{
			refreshItemMenu();
			if(mx_cut.IsEnabled == true && mx_cut.Visibility == System.Windows.Visibility.Visible)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		public bool canCopy()
		{
			refreshItemMenu();
			if (mx_copy.IsEnabled == true && mx_copy.Visibility == System.Windows.Visibility.Visible)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		public bool canPaste()
		{
			refreshItemMenu();
			if (mx_paste.IsEnabled == true && mx_paste.Visibility == System.Windows.Visibility.Visible)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		public bool canDelete()
		{
			refreshItemMenu();
			if (mx_delete.IsEnabled == true && mx_delete.Visibility == System.Windows.Visibility.Visible)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		public bool canMoveUp()
		{
			refreshItemMenu();
			if (mx_moveUp.IsEnabled == true && mx_delete.Visibility == System.Windows.Visibility.Visible)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		public bool canMoveDown()
		{
			refreshItemMenu();
			if (mx_moveDown.IsEnabled == true && mx_delete.Visibility == System.Windows.Visibility.Visible)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		public void cutItem()
		{
			m_pW.m_xePaste = (XmlElement)m_xe.CloneNode(true);
			m_rootControl.m_openedFile.m_lstOpt.addOperation(
				new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_DELETE, m_xe)
				);
		}
		public void copyItem()
		{
			m_pW.m_xePaste = (XmlElement)m_xe.CloneNode(true);
		}
		public void pasteItem()
		{
			XmlElement xeCopy;

			if (m_pW.m_xePaste != null)
			{
				MainWindow.CtrlDef_T ctrlPtr;
				MainWindow.SkinDef_T skinPtr;
				XmlItem treeChild = null;

				xeCopy = m_xe.OwnerDocument.CreateElement("tmp");
				xeCopy.InnerXml = m_pW.m_xePaste.OuterXml;
				xeCopy = (XmlElement)xeCopy.FirstChild;

				if (m_pW.m_mapCtrlDef.TryGetValue(xeCopy.Name, out ctrlPtr))
				{
					treeChild = new BoloUI.Basic(xeCopy, m_rootControl);
				}
				else if (m_pW.m_mapAllResDef.TryGetValue(xeCopy.Name, out skinPtr))
				{
					treeChild = new BoloRes.ResBasic(xeCopy, m_rootControl, skinPtr);
				}
				if (treeChild != null)
				{
					if (xeCopy.Name == "event")
					{
						m_rootControl.m_openedFile.m_lstOpt.addOperation(
							new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, m_xe)
							);
					}
					else
					{
						if(m_type == "CtrlUI")
						{
							MainWindow.CtrlDef_T panelCtrlDef;

							if (m_xe.Name == "BoloUI" && m_pW.m_mapPanelCtrlDef.TryGetValue(treeChild.m_xe.Name, out panelCtrlDef))
							{
								m_rootControl.m_openedFile.m_lstOpt.addOperation(
									new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, m_xe)
									);
							}
							else if (m_pW.m_mapPanelCtrlDef.TryGetValue(m_xe.Name, out panelCtrlDef))
							{
								m_rootControl.m_openedFile.m_lstOpt.addOperation(
									new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, m_xe)
									);
							}
							else
							{
								if (m_xe.ParentNode != null && m_xe.ParentNode.ParentNode == null && m_xe.ParentNode.ParentNode.NodeType == XmlNodeType.Element)
								{
									m_rootControl.m_openedFile.m_lstOpt.addOperation(
										new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, (XmlElement)m_xe.ParentNode)
										);
								}
							}
						}
						else if(m_type == "Skin")
						{
							MainWindow.SkinDef_T skinDef;
							if(m_pW.m_mapAllResDef.TryGetValue(m_xe.Name, out skinDef))
							{
								MainWindow.SkinDef_T skinChildDef;
								if(skinDef.m_mapEnChild != null && skinDef.m_mapEnChild.Count > 0
									&& skinDef.m_mapEnChild.TryGetValue(treeChild.m_xe.Name, out skinChildDef))
								{
									m_rootControl.m_openedFile.m_lstOpt.addOperation(
										new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, m_xe)
										);
								}
								else
								{
									if(m_xe.ParentNode.NodeType == XmlNodeType.Element)
									{
										if (((XmlElement)m_xe.ParentNode).Name == "BoloUI")
										{
											if (m_pW.m_mapSkinResDef.TryGetValue(treeChild.m_xe.Name, out skinChildDef))
											{
												m_rootControl.m_openedFile.m_lstOpt.addOperation(
													new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, ((XmlElement)m_xe.ParentNode))
													);
											}
										}
										else
										{
											if (m_pW.m_mapAllResDef.TryGetValue(((XmlElement)m_xe.ParentNode).Name, out skinDef))
											{
												if (skinDef.m_mapEnChild.TryGetValue(treeChild.m_xe.Name, out skinChildDef))
												{
													m_rootControl.m_openedFile.m_lstOpt.addOperation(
														new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, ((XmlElement)m_xe.ParentNode))
														);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		public void deleteItem()
		{
			m_rootControl.m_openedFile.m_lstOpt.addOperation(
				new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_DELETE, m_xe)
				);
		}
		public void moveDownItem()
		{
			if (m_xe.ParentNode.LastChild != m_xe)
			{
				m_rootControl.m_openedFile.m_lstOpt.addOperation(
					new XmlOperation.HistoryNode(
						XmlOperation.XmlOptType.NODE_MOVE,
						m_xe,
						(XmlElement)m_xe.ParentNode,
						XmlOperation.HistoryNode.getXeIndex(m_xe) + 1
					)
				);
			}
		}
		public void moveUpItem()
		{
			if (m_xe.ParentNode.FirstChild != m_xe)
			{
				m_rootControl.m_openedFile.m_lstOpt.addOperation(
					new XmlOperation.HistoryNode(
						XmlOperation.XmlOptType.NODE_MOVE,
						m_xe,
						(XmlElement)m_xe.ParentNode,
						XmlOperation.HistoryNode.getXeIndex(m_xe) - 1
					)
				);
			}
		}

		private void mx_cut_Click(object sender, RoutedEventArgs e)
		{
			cutItem();
		}
		private void mx_copy_Click(object sender, RoutedEventArgs e)
		{
			copyItem();
		}
		private void mx_paste_Click(object sender, RoutedEventArgs e)
		{
			pasteItem();
		}
		private void mx_delete_Click(object sender, RoutedEventArgs e)
		{
			deleteItem();
		}
		private void mx_moveDown_Click(object sender, RoutedEventArgs e)
		{
			moveDownItem();
		}
		private void mx_moveUp_Click(object sender, RoutedEventArgs e)
		{
			moveUpItem();
		}

		private void mx_text_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			if (m_xe.Name == "skingroup")
			{
				string path = m_pW.m_skinPath + "\\" + m_xe.GetAttribute("Name") + ".xml";

				m_pW.openFileByPath(path);
			}
		}
		private void showTmpl(MenuItem ctrlMenuItem, XmlElement xeTmpls, string addStr)
		{
			if(ctrlMenuItem.Items.Count == 0)
			{
				MenuItem emptyCtrl = new MenuItem();

				emptyCtrl.Header = "空节点";
				emptyCtrl.ToolTip = addStr;
				emptyCtrl.Click += insertCtrlItem_Click;
				ctrlMenuItem.Items.Add(emptyCtrl);
				ctrlMenuItem.Items.Add(new Separator());
			}

			XmlNodeList xlstTmpl = xeTmpls.SelectNodes("row");
			if (xlstTmpl.Count == 0)
			{
				MenuItem disTmpl = new MenuItem();

				disTmpl.Header = "<没有模板>";
				disTmpl.IsEnabled = false;
				ctrlMenuItem.Items.Add(disTmpl);
			}
			else
			{
				foreach (XmlNode xn in xlstTmpl)
				{
					if (xn.NodeType == XmlNodeType.Element)
					{
						XmlElement xeRow = (XmlElement)xn;
						BoloUI.CtrlTemplate rowTmpl = new BoloUI.CtrlTemplate();

						rowTmpl.Header = xeRow.GetAttribute("name");
						rowTmpl.ToolTip = xeRow.InnerXml;
						ctrlMenuItem.Items.Add(rowTmpl);
						rowTmpl.Click += insertCtrlItem_Click;
					}
				}
			}
		}
		public void showTmplGroup(string addStr)
		{
			MainWindow.CtrlDef_T ctrlDef;

			if (m_pW.m_mapCtrlDef.TryGetValue(addStr, out ctrlDef) && ctrlDef != null)
			{
				MenuItem ctrlMenuItem = new MenuItem();
				bool isNull = true;

				StringDic.getNameAndTip(ctrlMenuItem, addStr, StringDic.m_mapStrControl);
				if (m_pW.m_docConf.SelectSingleNode("Config").SelectSingleNode("template") != null &&
					m_pW.m_docConf.SelectSingleNode("Config").SelectSingleNode("template").SelectSingleNode(addStr + "Tmpls") != null)
				{
					isNull = false;
					XmlElement xeTmpls = (XmlElement)m_pW.m_docConf.SelectSingleNode("Config").SelectSingleNode("template").SelectSingleNode(addStr + "Tmpls");

					showTmpl(ctrlMenuItem, xeTmpls, addStr);
				}

				if (m_pW.m_docProj.SelectSingleNode("BoloUIProj").SelectSingleNode("template") != null &&
					m_pW.m_docProj.SelectSingleNode("BoloUIProj").SelectSingleNode("template").SelectSingleNode(addStr + "Tmpls") != null)
				{
					if (!isNull)
					{
						ctrlMenuItem.Items.Add(new Separator());
					}
					isNull = false;

					XmlElement xeTmpls = (XmlElement)m_pW.m_docProj.SelectSingleNode("BoloUIProj").SelectSingleNode("template").SelectSingleNode(addStr + "Tmpls");

					showTmpl(ctrlMenuItem, xeTmpls, addStr);
				}

				if (isNull)
				{
					ctrlMenuItem.Click += insertCtrlItem_Click;
				}
				mx_addCtrl.Items.Add(ctrlMenuItem);
			}
		}
		private void mx_addCtrl_Loaded(object sender, RoutedEventArgs e)
		{
			MainWindow.CtrlDef_T panelCtrlDef;

			mx_addCtrl.Items.Clear();
			if (m_pW.m_mapPanelCtrlDef.TryGetValue(m_xe.Name, out panelCtrlDef))
			{
				foreach (string addStr in StringDic.m_lstAddControl)
				{
					if (addStr == "Separator")
					{
						mx_addCtrl.Items.Add(new Separator());
					}
					else
					{
						showTmplGroup(addStr);
					}
				}
			}
			else
			{
				if (m_xe.Name == "BoloUI")
				{
					foreach (KeyValuePair<string, MainWindow.CtrlDef_T> pairCtrl in m_pW.m_mapPanelCtrlDef.ToList())
					{
						MenuItem ctrlItem = new MenuItem();

						ctrlItem.ToolTip = pairCtrl.Key;
						if (StringDic.m_mapStrControl[pairCtrl.Key] == null || StringDic.m_mapStrControl[pairCtrl.Key] == "")
						{
							ctrlItem.Header = pairCtrl.Key;
						}
						else
						{
							ctrlItem.Header = StringDic.m_mapStrControl[pairCtrl.Key];
						}
						ctrlItem.Click += insertCtrlItem_Click;
						mx_addCtrl.Items.Add(ctrlItem);
					}
				}
				else if (m_xe.Name != "event")
				{
					showTmplGroup("event");
					/*
						正则替换："E:\clientlib\DsBoloUIEditor\src\boloUI\BoloEvent.java" 到 "E:\clienttools\UI编辑器2\conf.xml" -->
						[\t a-z_=]*("[a-zA-Z]*")[; \t\/\/]*([\/\u4e00-\u9fa5 a-zA-Z（）]*)
						\t<row name=$1 tip="$2">\r\n\t\t<event type=$1/>\r\n\t</row>
					*/
				}
				else
				{
					mx_addCtrl.IsEnabled = false;
				}
			}
		}
		void insertCtrlItem_Click(object sender, RoutedEventArgs e)
		{
			switch(sender.GetType().ToString())
			{
				case "System.Windows.Controls.MenuItem":
				{
					MenuItem ctrlItem = (MenuItem)sender;
					XmlElement newXe = m_xe.OwnerDocument.CreateElement(ctrlItem.ToolTip.ToString());
					BoloUI.Basic treeChild = new BoloUI.Basic(newXe, m_rootControl);

					m_rootControl.m_openedFile.m_lstOpt.addOperation(new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, m_xe));
				}
				break;
				case "UIEditor.BoloUI.CtrlTemplate":
				{
					BoloUI.CtrlTemplate ctrlItem = (BoloUI.CtrlTemplate)sender;
					XmlDocument newDoc = new XmlDocument();
					XmlElement newXe = m_xe.OwnerDocument.CreateElement("tmp");

					if (ctrlItem.ToolTip.ToString() != "")
					{
						newXe.InnerXml = ctrlItem.ToolTip.ToString();
						if(newXe.FirstChild.NodeType == XmlNodeType.Element)
						{
							BoloUI.Basic treeChild = new BoloUI.Basic((XmlElement)newXe.FirstChild, m_rootControl);
							m_rootControl.m_openedFile.m_lstOpt.addOperation(new XmlOperation.HistoryNode(XmlOperation.XmlOptType.NODE_INSERT, treeChild.m_xe, m_xe));
						}
					}
				}
				break;
			}
		}
		private void mx_addTmpl_Click(object sender, RoutedEventArgs e)
		{
			TemplateCreate winAddtmpl = new TemplateCreate(m_xe);
			winAddtmpl.ShowDialog();
		}
	}
}

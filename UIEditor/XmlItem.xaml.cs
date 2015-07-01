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
	}
}

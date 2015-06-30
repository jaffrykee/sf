﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Xml;

namespace UIEditor.XmlOperation
{
	public class HistoryNode
	{
		public XmlOptType m_optType;
		public XmlElement m_dstXe;
		public XmlElement m_srcXe;
		public int m_oldIndex;
		public int m_newIndex;
		public XmlElement m_newSrcXe;

		public string m_attrName;
		public string m_oldValue;
		public string m_newValue;
		public XmlDocument m_oldDoc;
		public XmlDocument m_newDoc;

		public static int getXeIndex(XmlElement xe)
		{
			int iXe = 0;

			foreach (XmlNode xn in xe.ParentNode.ChildNodes)
			{
				if (xn.NodeType == XmlNodeType.Element)
				{
					XmlElement xec = (XmlElement)xn;

					if (xec == xe)
					{
						break;
					}
					iXe++;
				}
			}

			return iXe;
		}

		public HistoryNode(XmlOptType optType, XmlElement dstXe, XmlElement srcXe = null, int newIndex = 0)
		{

			m_optType = optType;
			m_dstXe = dstXe;
			switch (optType)
			{
				case XmlOptType.NODE_DELETE:
					m_srcXe = (XmlElement)m_dstXe.ParentNode;
					m_oldIndex = getXeIndex(m_dstXe);
					break;
				case XmlOptType.NODE_INSERT:
					m_srcXe = srcXe;
					m_newIndex = newIndex;
					break;
				case XmlOptType.NODE_MOVE:
					m_srcXe = (XmlElement)m_dstXe.ParentNode;
					m_newSrcXe = srcXe;
					m_newIndex = newIndex;
					m_oldIndex = getXeIndex(m_dstXe);
					break;
				default:
					break;
			}
		}
		public HistoryNode(XmlElement dstXe, string attrName, string oldValue, string newValue)
		{
			//NODE_UPDATE
			m_optType = XmlOptType.NODE_UPDATE;
			m_attrName = attrName;
			m_oldValue = oldValue;
			m_newValue = newValue;
			m_dstXe = dstXe;
		}
		public HistoryNode(XmlOptType optType, XmlDocument oldDoc, XmlDocument newDoc)
		{
			//todo TEXT
			m_optType = optType;
			m_oldDoc = oldDoc;
			m_newDoc = newDoc;
		}

		static public bool deleteItemByXe(MainWindow pW, string path, XmlElement dstXe)
		{
			OpenedFile fileT;

			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
					MainWindow.CtrlDef_T nullCtrlDef;
					XmlItem dstItem;

					if (xmlCtrl.m_mapXeItem.TryGetValue(dstXe, out dstItem))
					{
						if (dstItem != null)
						{
							xmlCtrl.m_mapXeItem.Remove(dstXe);
							if (dstItem.Parent != null)
							{
								((TreeViewItem)dstItem.Parent).Items.Remove(dstItem);
								if (pW.m_mapCtrlDef.TryGetValue(dstXe.Name, out nullCtrlDef) &&
									dstXe.Name != "event")
								{
									//仅Ctrl
									BoloUI.Basic uiCtrl;

									if (xmlCtrl.m_mapCtrlUI.TryGetValue(dstXe.GetAttribute("baseID"), out uiCtrl))
									{
										xmlCtrl.deleteBaseId(uiCtrl.m_xe);

										return true;
									}
								}
							}
						}
					}
				}
			}

			return false;
		}
		static public bool insertItemByXe(MainWindow pW, string path, XmlElement dstXe, XmlElement srcXe, int index = 0)
		{
			MainWindow.CtrlDef_T nullCtrlDef;
			OpenedFile fileT;

			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
					TreeViewItem treeChild;
					MainWindow.SkinDef_T skinPtr;

					if (pW.m_mapCtrlDef.TryGetValue(dstXe.Name, out nullCtrlDef) &&
						dstXe.Name != "event")
					{
						xmlCtrl.checkBaseId((XmlNode)dstXe);
					}
					if (pW.m_mapCtrlDef.TryGetValue(dstXe.Name, out nullCtrlDef))
					{
						treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), dstXe, xmlCtrl, false) as System.Windows.Controls.TreeViewItem;
					}
					else if (pW.m_mapSkinResDef.TryGetValue(dstXe.Name, out skinPtr))
					{
						treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloRes.ResBasic"), dstXe, xmlCtrl, skinPtr) as System.Windows.Controls.TreeViewItem;
					}
					else
					{
						return false;
					}

					XmlItem srcItem;

					if(xmlCtrl.m_mapXeItem.TryGetValue(srcXe, out srcItem))
					{
						if(srcItem != null)
						{
							srcItem.Items.Insert(index, treeChild);
							treeChild.Focus();
						}
					}

					return true;
				}
			}

			return false;
		}
		//直接和xml打交道的处理和部分对于显示的刷新。
		//把dstXe加到srcXe里
		static public bool insertXmlNode(MainWindow pW, string path, XmlElement dstXe, XmlElement srcXe, int index = 0)
		{
			XmlElement tmpXe1 = dstXe.OwnerDocument.CreateElement("tmp1");
			XmlElement tmpXe2 = dstXe.OwnerDocument.CreateElement("tmp2");

			if(index < (srcXe.ChildNodes.Count + 1) / 2)
			{
				srcXe.PrependChild(tmpXe1);
				XmlElement iXe = tmpXe1;
				for (int i = 0; i < index; i++)
				{
					XmlElement nextXe = (XmlElement)iXe.NextSibling;

					srcXe.ReplaceChild(tmpXe2, nextXe);
					srcXe.ReplaceChild(nextXe, tmpXe1);
					srcXe.ReplaceChild(tmpXe1, tmpXe2);
					iXe = tmpXe1;
				}
				srcXe.ReplaceChild(dstXe, tmpXe1);
			}
			else
			{
				srcXe.AppendChild(tmpXe1);
				XmlElement iXe = tmpXe1;
				for (int i = srcXe.ChildNodes.Count - 1; i > index; i--)
				{
					XmlElement prevXe = (XmlElement)iXe.PreviousSibling;

					srcXe.ReplaceChild(tmpXe2, prevXe);
					srcXe.ReplaceChild(prevXe, tmpXe1);
					srcXe.ReplaceChild(tmpXe1, tmpXe2);
					iXe = tmpXe1;
				}
				srcXe.ReplaceChild(dstXe, tmpXe1);
			}
			insertItemByXe(pW, path, dstXe, srcXe, index);

			return false;
		}
		static public bool deleteXmlNode(MainWindow pW, string path, XmlElement dstXe)
		{
			if (dstXe.ParentNode != null)
			{
				dstXe.ParentNode.RemoveChild(dstXe);
			}
			deleteItemByXe(pW, path, dstXe);

			return false;
		}
		static public bool updateXmlNode(MainWindow pW, string path, XmlElement dstXe, string attrName, string newValue)
		{
			OpenedFile fileT;
			string oldValue = dstXe.GetAttribute(attrName);

			if (newValue != "")
			{
				dstXe.SetAttribute(attrName, newValue);
			}
			else
			{
				dstXe.RemoveAttribute(attrName);
			}
			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					//仅Ctrl
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
					BoloUI.Basic uiCtrl;

					if (attrName == "baseID")
					{
						if (xmlCtrl.m_mapCtrlUI.TryGetValue(oldValue, out uiCtrl))
						{
							xmlCtrl.checkBaseId((XmlNode)dstXe);
							xmlCtrl.m_mapCtrlUI.Remove(oldValue);
							xmlCtrl.m_mapCtrlUI[newValue] = uiCtrl;
							uiCtrl.Focus();
						}
					}

					return true;
				}
			}

			return false;
		}
	}
}
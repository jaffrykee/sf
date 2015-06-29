using System;
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
		public XmlItem m_dstItem;
		public XmlItem m_srcItem;
		public int m_oldIndex;
		public int m_newIndex;
		public XmlItem m_newSrcItem;

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

		public HistoryNode(XmlOptType optType, XmlItem dstItem, XmlItem srcItem = null, int newIndex = 0)
		{

			m_optType = optType;
			m_dstItem = dstItem;
			switch (optType)
			{
				case XmlOptType.NODE_DELETE:
					if (m_dstItem.Parent.GetType().ToString() == "UIEditor.XmlItem" ||
						m_dstItem.Parent.GetType().BaseType.ToString() == "UIEditor.XmlItem" ||
						m_dstItem.Parent.GetType().BaseType.BaseType.ToString() == "UIEditor.XmlItem")
					{
						m_srcItem = (XmlItem)m_dstItem.Parent;
						m_oldIndex = getXeIndex(m_dstItem.m_xe);
					}
					break;
				case XmlOptType.NODE_INSERT:
					m_srcItem = srcItem;
					m_newIndex = newIndex;
					break;
				case XmlOptType.NODE_MOVE:
					if (m_dstItem.Parent.GetType().ToString() == "UIEditor.XmlItem" ||
						m_dstItem.Parent.GetType().BaseType.ToString() == "UIEditor.XmlItem" ||
						m_dstItem.Parent.GetType().BaseType.BaseType.ToString() == "UIEditor.XmlItem")
					{
						m_srcItem = (XmlItem)m_dstItem.Parent;
						m_newSrcItem = srcItem;
						m_newIndex = newIndex;
						m_oldIndex = getXeIndex(m_dstItem.m_xe);
					}
					break;
				default:
					break;
			}
		}
		public HistoryNode(XmlItem dstItem, string attrName, string oldValue, string newValue)
		{
			//NODE_UPDATE
			m_optType = XmlOptType.NODE_UPDATE;
			m_attrName = attrName;
			m_oldValue = oldValue;
			m_newValue = newValue;
			m_dstItem = dstItem;
		}
		public HistoryNode(XmlOptType optType, XmlDocument oldDoc, XmlDocument newDoc)
		{
			//todo TEXT
			m_optType = optType;
			m_oldDoc = oldDoc;
			m_newDoc = newDoc;
		}

		static public bool deleteItemWithXmlItem(MainWindow pW, string path, XmlItem dstItem)
		{
			OpenedFile fileT;

			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					MainWindow.CtrlDef_T nullCtrlDef;

					((TreeViewItem)dstItem.Parent).Items.Remove(dstItem);
					if (dstItem.GetType().ToString() == "UIEditor.BoloUI.Basic" &&
						pW.m_mapCtrlDef.TryGetValue(dstItem.m_xe.Name, out nullCtrlDef) &&
						dstItem.m_xe.Name != "event")
					{
						//仅Ctrl
						XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
						BoloUI.Basic uiCtrl;

						if (xmlCtrl.m_mapCtrlUI.TryGetValue(dstItem.m_xe.GetAttribute("baseID"), out uiCtrl))
						{
							xmlCtrl.deleteBaseId(uiCtrl.m_xe);

							return true;
						}
					}
				}
			}

			return false;
		}
		static public bool insertItemWithXmlItem(MainWindow pW, string path, XmlItem dstItem, XmlItem srcItem, int index = 0)
		{
			MainWindow.CtrlDef_T nullCtrlDef;
			OpenedFile fileT;

			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;

					if (dstItem.GetType().ToString() == "UIEditor.BoloUI.Basic" &&
						pW.m_mapCtrlDef.TryGetValue(dstItem.m_xe.Name, out nullCtrlDef) &&
						dstItem.m_xe.Name != "event")
					{
						xmlCtrl.checkBaseId((XmlNode)dstItem.m_xe);
					}
					//var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), dstItem.m_xe, xmlCtrl) as System.Windows.Controls.TreeViewItem;
					srcItem.Items.Insert(index, dstItem);
					dstItem.Focus();

					return true;
				}
			}

			return false;
		}
		//直接和xml打交道的处理和部分对于显示的刷新。
		//把dstXe加到srcXe里
		static public bool insertXmlNode(MainWindow pW, string path, XmlItem dstItem, XmlItem srcItem, int index = 0)
		{
			XmlElement tmpXe1 = dstItem.m_xe.OwnerDocument.CreateElement("tmp1");
			XmlElement tmpXe2 = dstItem.m_xe.OwnerDocument.CreateElement("tmp2");

			if(index < (srcItem.m_xe.ChildNodes.Count + 1) / 2)
			{
				srcItem.m_xe.PrependChild(tmpXe1);
				XmlElement iXe = tmpXe1;
				for (int i = 0; i < index; i++)
				{
					XmlElement nextXe = (XmlElement)iXe.NextSibling;

					srcItem.m_xe.ReplaceChild(tmpXe2, nextXe);
					srcItem.m_xe.ReplaceChild(nextXe, tmpXe1);
					srcItem.m_xe.ReplaceChild(tmpXe1, tmpXe2);
					iXe = tmpXe1;
				}
				srcItem.m_xe.ReplaceChild(dstItem.m_xe, tmpXe1);
			}
			else
			{
				srcItem.m_xe.AppendChild(tmpXe1);
				XmlElement iXe = tmpXe1;
				for (int i = srcItem.m_xe.ChildNodes.Count - 1; i > index; i--)
				{
					XmlElement prevXe = (XmlElement)iXe.PreviousSibling;

					srcItem.m_xe.ReplaceChild(tmpXe2, prevXe);
					srcItem.m_xe.ReplaceChild(prevXe, tmpXe1);
					srcItem.m_xe.ReplaceChild(tmpXe1, tmpXe2);
					iXe = tmpXe1;
				}
				srcItem.m_xe.ReplaceChild(dstItem.m_xe, tmpXe1);
			}
			insertItemWithXmlItem(pW, path, dstItem, srcItem, index);

			return false;
		}
		static public bool deleteXmlNode(MainWindow pW, string path, XmlItem dstItem)
		{
			if (dstItem.m_xe.ParentNode != null)
			{
				dstItem.m_xe.ParentNode.RemoveChild(dstItem.m_xe);
			}
			deleteItemWithXmlItem(pW, path, dstItem);

			return false;
		}
		static public bool updateXmlNode(MainWindow pW, string path, XmlItem dstItem, string attrName, string newValue)
		{
			OpenedFile fileT;
			string oldValue = dstItem.m_xe.GetAttribute(attrName);

			if (newValue != "")
			{
				dstItem.m_xe.SetAttribute(attrName, newValue);
			}
			else
			{
				dstItem.m_xe.RemoveAttribute(attrName);
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
							xmlCtrl.checkBaseId((XmlNode)dstItem.m_xe);
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

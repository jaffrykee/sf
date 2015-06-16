using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Xml;

namespace UIEditor.XmlOperation
{
	public class XmlOperationNode
	{
		private XmlDocument m_tmpDoc;

		public XmlOptType m_optType;
		public XmlElement m_dstElm;
		public XmlElement m_srcElm;
		public string m_dstCtrlId;
		public string m_srcCtrlId;
		public string m_attrName;
		public string m_oldValue;
		public string m_newValue;
		public XmlDocument m_oldDoc;
		public XmlDocument m_newDoc;

		public XmlOperationNode(XmlOptType optType, XmlElement dstXe, XmlElement srcXe = null)
		{
			//NODE_INSERT, NODE_REPLACE, NODE_DELETE
			m_optType = optType;
			switch(optType)
			{
				case XmlOptType.NODE_INSERT:
					{
						m_dstCtrlId = dstXe.GetAttribute("baseID");
						m_srcCtrlId = srcXe.GetAttribute("baseID");
						m_tmpDoc = new XmlDocument();
						m_tmpDoc.LoadXml(srcXe.InnerText);
						m_srcElm = m_tmpDoc.DocumentElement;
					}
					break;
				case XmlOptType.NODE_REPLACE:
					{
						if (srcXe != null)
						{
							m_dstCtrlId = dstXe.GetAttribute("baseID");
							m_srcCtrlId = srcXe.GetAttribute("baseID");
						}
						else
						{
							m_dstCtrlId = "";
							m_srcCtrlId = dstXe.GetAttribute("baseID");
						}
					}
					break;
				case XmlOptType.NODE_DELETE:
					{
						m_tmpDoc = new XmlDocument();
						m_tmpDoc.LoadXml(dstXe.InnerText);
						m_dstElm = m_tmpDoc.DocumentElement;
						m_dstCtrlId = dstXe.GetAttribute("baseID");
						m_srcCtrlId = ((XmlElement)dstXe.ParentNode).GetAttribute("baseID");
					}
					break;
				default:
					break;
			}
		}
		public XmlOperationNode(XmlElement dstXe, string attrName, string oldValue, string newValue)
		{
			//ATTR_INSERT, ATTR_DELETE, ATTR_UPDATE
			if (oldValue == "")
			{
				m_optType = XmlOptType.ATTR_INSERT;
			}
			else if (newValue == "")
			{
				m_optType = XmlOptType.ATTR_DELETE;
			}
			else
			{
				m_optType = XmlOptType.ATTR_UPDATE;
			}
			switch (m_optType)
			{
				case XmlOptType.ATTR_INSERT:
					{
						m_dstCtrlId = dstXe.GetAttribute("baseID");
						m_attrName = attrName;
						m_newValue = newValue;
					}
					break;
				case XmlOptType.ATTR_DELETE:
					{
						m_dstCtrlId = dstXe.GetAttribute("baseID");
						m_attrName = attrName;
						m_oldValue = oldValue;
					}
					break;
				case XmlOptType.ATTR_UPDATE:
					{
						m_dstCtrlId = dstXe.GetAttribute("baseID");
						m_attrName = attrName;
						m_oldValue = oldValue;
						m_newValue = newValue;
					}
					break;
				default:
					break;
			}
		}
		public XmlOperationNode(XmlOptType optType, XmlDocument oldDoc, XmlDocument newDoc)
		{
			//todo TEXT
			m_optType = optType;
		}

		//直接和xml打交道的处理和部分对于显示的刷新。
		static public bool insertXmlNode(MainWindow pW, string path, string dstCtrlId, XmlElement srcXe)
		{
			MainWindow.CtrlDef_T ctrlPtr;
			OpenedFile fileT;

			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
					BoloUI.Basic uiCtrl;

					if (xmlCtrl.m_mapCtrlUI.TryGetValue(dstCtrlId, out uiCtrl))
					{
						uiCtrl.m_xe.AppendChild(srcXe);
						xmlCtrl.checkBaseId((XmlNode)srcXe);
						if (pW.m_mapCtrlDef.TryGetValue(srcXe.Name, out ctrlPtr))
						{
							var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), srcXe, xmlCtrl) as System.Windows.Controls.TreeViewItem;
							uiCtrl.Items.Add(treeChild);
							return true;
						}
					}
				}
			}
			return false;
		}
		static public bool deleteXmlNode(MainWindow pW, string path, string dstCtrlId)
		{
			OpenedFile fileT;

			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
					BoloUI.Basic uiCtrl;

					if (xmlCtrl.m_mapCtrlUI.TryGetValue(dstCtrlId, out uiCtrl))
					{
						xmlCtrl.deleteBaseId(uiCtrl.m_xe);
						((TreeViewItem)uiCtrl.Parent).Items.Remove(uiCtrl);
						return true;
					}
				}
			}
			return false;
		}
		static public bool setXmlAttr(MainWindow pW, string path, string dstCtrlId, string attrName, string newValue)
		{
			OpenedFile fileT;

			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
					BoloUI.Basic uiCtrl;

					if (xmlCtrl.m_mapCtrlUI.TryGetValue(dstCtrlId, out uiCtrl))
					{
						uiCtrl.m_xe.SetAttribute(attrName, newValue);
						return true;
					}
				}
			}
			return false;
		}
		static public bool insertXmlAttr(MainWindow pW, string path, string dstCtrlId, string attrName, string newValue)
		{
			return setXmlAttr(pW, path, dstCtrlId, attrName, newValue);
		}
		static public bool deleteXmlAttr(MainWindow pW, string path, string dstCtrlId, string attrName)
		{
			OpenedFile fileT;

			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
					BoloUI.Basic uiCtrl;

					if (xmlCtrl.m_mapCtrlUI.TryGetValue(dstCtrlId, out uiCtrl))
					{
						uiCtrl.m_xe.RemoveAttribute(attrName);
						if (uiCtrl == pW.m_curCtrl)
						{
							uiCtrl.changeSelectCtrl();
							return true;
						}
					}
				}
			}
			return false;
		}
	}
}

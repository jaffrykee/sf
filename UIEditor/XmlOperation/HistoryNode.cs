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
		public XmlElement m_dstElm;
		public XmlElement m_srcElm;
		public string m_attrName;
		public string m_oldValue;
		public string m_newValue;
		public XmlDocument m_oldDoc;
		public XmlDocument m_newDoc;

		public HistoryNode(XmlOptType optType, XmlElement dstXe, XmlElement srcXe = null)
		{
			//NODE_INSERT, NODE_REPLACE, NODE_DELETE
			m_optType = optType;
			m_dstElm = dstXe;
			if (srcXe == null)
			{
				m_srcElm = (XmlElement)m_dstElm.ParentNode;
			}
			else
			{
				m_srcElm = srcXe;
			}
		}
		public HistoryNode(XmlElement dstXe, string attrName, string oldValue, string newValue)
		{
			//NODE_UPDATE
			m_optType = XmlOptType.NODE_UPDATE;
			m_dstElm = dstXe;
			m_attrName = attrName;
			m_oldValue = oldValue;
			m_newValue = newValue;
		}
		public HistoryNode(XmlOptType optType, XmlDocument oldDoc, XmlDocument newDoc)
		{
			//todo TEXT
			m_optType = optType;
			m_oldDoc = oldDoc;
			m_newDoc = newDoc;
		}

		//直接和xml打交道的处理和部分对于显示的刷新。
		//把dstXe加到srcXe里
		static public bool insertXmlNode(MainWindow pW, string path, XmlElement dstXe, XmlElement srcXe)
		{
			MainWindow.CtrlDef_T ctrlPtr;
			OpenedFile fileT;

			srcXe.AppendChild(dstXe);
			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
					BoloUI.Basic uiCtrl;

					if (srcXe.GetAttribute("baseID") != "")
					{
						//仅Ctrl
						if (xmlCtrl.m_mapCtrlUI.TryGetValue(srcXe.GetAttribute("baseID"), out uiCtrl))
						{
							xmlCtrl.checkBaseId((XmlNode)dstXe);
							if (pW.m_mapCtrlDef.TryGetValue(dstXe.Name, out ctrlPtr))
							{
								var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), dstXe, xmlCtrl) as System.Windows.Controls.TreeViewItem;
								uiCtrl.Items.Add(treeChild);

								return true;
							}
						}
					}
				}
			}

			return false;
		}
		static public bool deleteXmlNode(MainWindow pW, string path, XmlElement dstXe)
		{
			OpenedFile fileT;

			if (dstXe.ParentNode != null)
			{
				dstXe.ParentNode.RemoveChild(dstXe);
			}
			if (pW.m_mapOpenedFiles.TryGetValue(path, out fileT))
			{
				if (fileT.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					XmlControl xmlCtrl = (XmlControl)fileT.m_frame;
					BoloUI.Basic uiCtrl;

					if (xmlCtrl.m_mapCtrlUI.TryGetValue(dstXe.GetAttribute("baseID"), out uiCtrl))
					{
						//仅Ctrl
						xmlCtrl.deleteBaseId(uiCtrl.m_xe);
						((TreeViewItem)uiCtrl.Parent).Items.Remove(uiCtrl);

						return true;
					}
				}
			}

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
						}
					}
					return true;
				}
			}

			return false;
		}
	}
}

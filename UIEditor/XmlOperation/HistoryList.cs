using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;


namespace UIEditor.XmlOperation
{
	public enum XmlOptType
	{
		NODE_INSERT,
		NODE_DELETE,
		NODE_REPLACE,
		NODE_UPDATE,
		TEXT,
	}

	public class HistoryList
	{
		public MainWindow m_pW;
		public XmlControl m_xmlCtrl;
		public int m_maxSize;
		public LinkedList<HistoryNode> m_lstOpt;
		public LinkedListNode<HistoryNode> m_curNode;
		public LinkedListNode<HistoryNode> m_headNode;
		public LinkedListNode<HistoryNode> m_saveNode;

		public HistoryList(MainWindow pW, XmlControl xmlCtrl, int maxSize = 10)
		{
			m_pW = pW;
			m_xmlCtrl = xmlCtrl;
			m_maxSize = maxSize;
			m_lstOpt = new LinkedList<HistoryNode>();
			m_curNode = new LinkedListNode<HistoryNode>(null);
			m_saveNode = m_curNode;
			m_headNode = m_curNode;
			m_lstOpt.AddLast(m_curNode);
		}

		public void addOperation(HistoryNode optNode)
		{
			for (LinkedListNode<HistoryNode> iNode = m_curNode.Next; iNode != m_headNode && iNode != null; iNode = m_curNode.Next)
			{
				iNode.List.Remove(iNode);
			}
			if (m_lstOpt.Count() >= m_maxSize)
			{
				m_headNode = m_headNode.Next;
				m_headNode.List.Remove(m_headNode.Previous);
			}
			m_curNode = new LinkedListNode<HistoryNode>(optNode);
			m_lstOpt.AddLast(m_curNode);
			redoOperation(true);
			m_xmlCtrl.m_openedFile.updateSaveStatus();
		}
		public void redoOperation(bool isAddOpt = false)
		{
			BoloUI.Basic ctrlUI = null;

			switch (m_curNode.Value.m_optType)
			{
				case XmlOptType.NODE_INSERT:
					{
						HistoryNode.insertXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstElm,
							m_curNode.Value.m_srcElm);
					}
					break;
				case XmlOptType.NODE_DELETE:
					{
						HistoryNode.deleteXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstElm);
					}
					break;
				case XmlOptType.NODE_REPLACE:
					{
						//todo
					}
					break;
				case XmlOptType.NODE_UPDATE:
					{
						if (HistoryNode.updateXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstElm,
							m_curNode.Value.m_attrName,
							m_curNode.Value.m_newValue))
						{
							if (!isAddOpt)
							{
								if (m_curNode.Value.m_attrName != "baseID")
								{
									m_xmlCtrl.m_mapCtrlUI.TryGetValue(m_curNode.Value.m_dstElm.GetAttribute("baseID"), out ctrlUI);
								}
								else
								{
									m_xmlCtrl.m_mapCtrlUI.TryGetValue(m_curNode.Value.m_newValue, out ctrlUI);
								}
							}
						}
					}
					break;
				case XmlOptType.TEXT:
					{
						//todo
					}
					break;
				default:
					return;
			}
			m_pW.updateXmlToGL(m_xmlCtrl.m_openedFile.m_path, m_xmlCtrl.m_xmlDoc);
			if (ctrlUI != null)
			{
				ctrlUI.changeSelectCtrl();
				if(m_curNode.Value.m_attrName == "baseID" || m_curNode.Value.m_attrName == "name")
				{
					m_pW.refreshAllCtrlUIHeader();
				}
			}
		}
		public void undoOperation()
		{
			BoloUI.Basic ctrlUI = null;

			switch (m_curNode.Value.m_optType)
			{
				case XmlOptType.NODE_INSERT:
					{
						HistoryNode.deleteXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstElm);
					}
					break;
				case XmlOptType.NODE_DELETE:
					{
						HistoryNode.insertXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstElm,
							m_curNode.Value.m_srcElm);
					}
					break;
				case XmlOptType.NODE_REPLACE:
					{
						//todo
					}
					break;
				case XmlOptType.NODE_UPDATE:
					{
						if (HistoryNode.updateXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstElm,
							m_curNode.Value.m_attrName,
							m_curNode.Value.m_oldValue))
						{
							if (m_curNode.Value.m_attrName != "baseID")
							{
								m_xmlCtrl.m_mapCtrlUI.TryGetValue(m_curNode.Value.m_dstElm.GetAttribute("baseID"), out ctrlUI);
							}
							else
							{
								m_xmlCtrl.m_mapCtrlUI.TryGetValue(m_curNode.Value.m_oldValue, out ctrlUI);
							}
						}
					}
					break;
				case XmlOptType.TEXT:
					{
						//todo
					}
					break;
				default:
					return;
			}
			m_pW.updateXmlToGL(m_xmlCtrl.m_openedFile.m_path, m_xmlCtrl.m_xmlDoc);
			if(ctrlUI != null)
			{
				ctrlUI.changeSelectCtrl();
				if (m_curNode.Value.m_attrName == "baseID" || m_curNode.Value.m_attrName == "name")
				{
					m_pW.refreshAllCtrlUIHeader();
				}
			}
		}
		public void undo()
		{
			if (m_curNode.Previous != null && m_curNode != null && m_curNode != m_headNode)
			{
				undoOperation();
				m_curNode = m_curNode.Previous;
				m_xmlCtrl.m_openedFile.updateSaveStatus();
			}
		}
		public void redo()
		{
			if (m_curNode.Next != null && m_curNode != null && m_curNode.Next != m_headNode)
			{
				m_curNode = m_curNode.Next;
				redoOperation();
				m_xmlCtrl.m_openedFile.updateSaveStatus();
			}
		}
	}
}

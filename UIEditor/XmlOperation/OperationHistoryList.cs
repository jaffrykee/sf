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
		//NODE_UPDATE,
		ATTR_INSERT,
		ATTR_DELETE,
		ATTR_UPDATE,
		TEXT,
	}

	public class XmlOperationList
	{
		public MainWindow m_pW;
		public XmlControl m_xmlCtrl;
		public int m_maxSize;
		public LinkedList<XmlOperationNode> m_lstOpt;
		public LinkedListNode<XmlOperationNode> m_curNode;
		public LinkedListNode<XmlOperationNode> m_headNode;
		public LinkedListNode<XmlOperationNode> m_saveNode;

		public XmlOperationList(MainWindow pW, XmlControl xmlCtrl, int maxSize = 10)
		{
			m_pW = pW;
			m_xmlCtrl = xmlCtrl;
			m_maxSize = maxSize;
			m_lstOpt = new LinkedList<XmlOperationNode>();
			m_curNode = new LinkedListNode<XmlOperationNode>(null);
			m_saveNode = m_curNode;
			m_headNode = m_curNode;
			m_lstOpt.AddLast(m_curNode);
		}

		public void addOperation(XmlOperationNode optNode)
		{
			for (LinkedListNode<XmlOperationNode> iNode = m_curNode.Next; iNode != m_headNode && iNode != null; iNode = m_curNode.Next)
			{
				iNode.List.Remove(iNode);
			}
			if (m_lstOpt.Count() >= m_maxSize)
			{
				m_headNode = m_headNode.Next;
				m_headNode.List.Remove(m_headNode.Previous);
			}
			m_curNode = new LinkedListNode<XmlOperationNode>(optNode);
			m_lstOpt.AddLast(m_curNode);
			redoOperation();
			m_xmlCtrl.m_openedFile.updateSaveStatus();
		}

		public void redoOperation()
		{
			switch (m_curNode.Value.m_optType)
			{
				case XmlOptType.NODE_INSERT:
					{
						XmlOperationNode.insertXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstCtrlId,
							m_curNode.Value.m_srcElm);
					}
					break;
				case XmlOptType.NODE_DELETE:
					{
						XmlOperationNode.deleteXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstCtrlId);
					}
					break;
				case XmlOptType.NODE_REPLACE:
					{
						//todo
					}
					break;
				case XmlOptType.ATTR_INSERT:
					{
						XmlOperationNode.insertXmlAttr(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstCtrlId,
							m_curNode.Value.m_attrName,
							m_curNode.Value.m_newValue);
					}
					break;
				case XmlOptType.ATTR_DELETE:
					{
						XmlOperationNode.deleteXmlAttr(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstCtrlId,
							m_curNode.Value.m_attrName);
					}
					break;
				case XmlOptType.ATTR_UPDATE:
					{
						XmlOperationNode.setXmlAttr(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstCtrlId,
							m_curNode.Value.m_attrName,
							m_curNode.Value.m_newValue);
					}
					break;
				case XmlOptType.TEXT:
					{
						//todo
					}
					break;
				default:
					return;
					break;
			}
			m_pW.updateXmlToGL(m_xmlCtrl.m_openedFile.m_path, m_xmlCtrl.m_xmlDoc);
		}
		public void undoOperation()
		{
			switch (m_curNode.Value.m_optType)
			{
				case XmlOptType.NODE_INSERT:
					{
						XmlOperationNode.deleteXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_srcCtrlId);
					}
					break;
				case XmlOptType.NODE_DELETE:
					{
						XmlOperationNode.insertXmlNode(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_srcCtrlId,
							m_curNode.Value.m_dstElm);
					}
					break;
				case XmlOptType.NODE_REPLACE:
					{
						//todo
					}
					break;
				case XmlOptType.ATTR_INSERT:
					{
						XmlOperationNode.deleteXmlAttr(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstCtrlId,
							m_curNode.Value.m_attrName);
					}
					break;
				case XmlOptType.ATTR_DELETE:
					{
						XmlOperationNode.insertXmlAttr(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstCtrlId,
							m_curNode.Value.m_attrName,
							m_curNode.Value.m_oldValue);
					}
					break;
				case XmlOptType.ATTR_UPDATE:
					{
						XmlOperationNode.setXmlAttr(
							m_pW,
							m_xmlCtrl.m_openedFile.m_path,
							m_curNode.Value.m_dstCtrlId,
							m_curNode.Value.m_attrName,
							m_curNode.Value.m_oldValue);
					}
					break;
				case XmlOptType.TEXT:
					{
						//todo
					}
					break;
				default:
					return;
					break;
			}
			m_pW.updateXmlToGL(m_xmlCtrl.m_openedFile.m_path, m_xmlCtrl.m_xmlDoc);
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

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
		NODE_UPDATE,
		ATTR_INSERT,
		ATTR_DELETE,
		ATTR_UPDATE,
		TEXT,
	}

	public class XmlOperationList
	{
		public MainWindow m_pW;
		public OpenedFile m_openedFile;
		public LinkedList<XmlDocument> m_lstDoc;
		public LinkedListNode<XmlDocument> m_curNode;
		public LinkedListNode<XmlDocument> m_headNode;
		public int m_maxSize;
		//public List<XmlOperationNode> m_lstOpt;
		//public XmlOperationNode m_curNode;

		public XmlOperationList(MainWindow pW, OpenedFile openedFile, int maxSize = 10)
		{
			m_pW = pW;
			m_lstDoc = new LinkedList<XmlDocument>();
			m_curNode = null;
			m_maxSize = 10;
			m_openedFile = openedFile;
		}

		public void addOperation(XmlDocument newDoc)
		{
			if(m_curNode == null)
			{
				m_curNode = new LinkedListNode<XmlDocument>(newDoc);
				m_headNode = m_curNode;
				m_lstDoc.AddLast(m_curNode);
			}
			else
			{
				for (LinkedListNode<XmlDocument> iNode = m_curNode.Next; iNode != m_headNode && iNode != null; iNode = iNode.Next)
				{
					iNode.List.Remove(iNode);
				}
				if (m_lstDoc.Count() >= m_maxSize)
				{
					m_headNode = m_headNode.Next;
					m_headNode.List.Remove(m_headNode.Previous);
				}
				m_curNode = new LinkedListNode<XmlDocument>(newDoc);
				m_lstDoc.AddLast(m_curNode);
			}
		}

		public XmlDocument undo()
		{
			if (m_curNode != null && m_curNode != m_headNode && m_curNode.Previous != null)
			{
				m_curNode = m_curNode.Previous;
				m_pW.updateXmlToGL(m_openedFile.m_path, m_curNode.Value, false);

				return m_curNode.Value;
			}

			return null;
		}

		public XmlDocument redo()
		{
			if (m_curNode != null && m_curNode.Next != m_headNode && m_curNode.Next != null)
			{
				m_curNode = m_curNode.Next;

				return m_curNode.Value;
			}

			return null;
		}

		public void addOperationEX(XmlOptType type, XmlNode xeDst, XmlNode xeNew, string dstAttrName, string oldValue, string newValue)
		{
			//todo
			switch(type)
			{
				case XmlOptType.ATTR_INSERT:
					break;
				case XmlOptType.ATTR_DELETE:
					break;
				case XmlOptType.ATTR_UPDATE:
					break;
				default:
					break;
			}
		}
	}
}

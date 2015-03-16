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
using System.IO;
using System.Xml;

namespace UIEditor.BoloUI
{
	public partial class resBasic : TreeViewItem
	{
		public XmlControl m_rootControl;
		public XmlElement m_xe;
		public Dictionary<string, string> m_mapNode;
		public bool m_loaded;

		public resBasic(XmlElement xe, XmlControl rootControl)
		{
			InitializeComponent();
			m_rootControl = rootControl;
			m_xe = xe;
			m_mapNode = new Dictionary<string,string>();
			m_loaded = false;
		}

		protected void addChild()
		{
			if(m_loaded == false)
			{
				XmlNodeList xnl = m_xe.ChildNodes;
				foreach (XmlNode xnf in xnl)
				{
					if (xnf.NodeType == XmlNodeType.Element)
					{
						string nodeType = "";
						XmlElement xe = (XmlElement)xnf;

						if (m_mapNode.TryGetValue(xe.Name, out nodeType))
						{
							var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI." + nodeType), xe, m_rootControl) as TreeViewItem;
							this.Items.Add(treeChild);
						}
						else
						{
							m_rootControl.textContent.Text += (xe.Name + ":" + xe.GetAttribute("Name") + "\r\n");
						}
					}
				}
				m_loaded = true;
			}
		}

		public void eventDrawImg(object sender, MouseEventArgs e)
		{
			this.Header = "img:" + m_xe.GetAttribute("ImageName");
			MainWindow pW = (MainWindow)Window.GetWindow(this);

			drawImg(m_rootControl.workSpace.Content,);

			var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.DrawImg"), m_xe, pW.m_rootPath) as UserControl;
			m_rootControl.workSpace.Content = tabContent;

			addChild();
		}

		public void drawImg(System.Windows.Controls.ContentControl frame, XmlElement xe, string path)
		{
			this.Header = "img:" + m_xe.GetAttribute("ImageName");
			MainWindow pW = (MainWindow)Window.GetWindow(this);

			var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.DrawImg"), m_xe, (TreeViewItem)this, pW.m_rootPath) as UserControl;
			m_rootControl.workSpace.Content = tabContent;

			addChild();
		}

		virtual protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			this.Header = this.GetType().Name;
			addChild();
		}
	}
}

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
			MainWindow pW = (MainWindow)Window.GetWindow(this);

			m_rootControl.workSpace.Children.Clear();
			drawImg(m_rootControl.workSpace, m_xe, pW.m_rootPath);
		}

		public void eventDrawApperance(object sender, MouseEventArgs e)
		{
			MainWindow pW = (MainWindow)Window.GetWindow(this);

			m_rootControl.workSpace.Children.Clear();
			drawApperance(m_rootControl.workSpace, m_xe, pW.m_rootPath);
		}
		public void eventDrawAnimation(object sender, MouseEventArgs e)
		{
			MainWindow pW = (MainWindow)Window.GetWindow(this);

			m_rootControl.workSpace.Children.Clear();
			drawAnimation(m_rootControl.workSpace, m_xe, pW.m_rootPath);
		}

		public void drawImg(object frame, XmlElement xe, string path)
		{
			var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.DrawImg"), xe, path) as Grid;
			if (frame.GetType().BaseType.ToString() == "System.Windows.Controls.ContentControl")
			{
				(frame as ContentControl).Content = tabContent;
			}
			else if (frame.GetType().BaseType.ToString() == "System.Windows.Controls.Panel")
			{
				(frame as Panel).Children.Add(tabContent);
			}
		}

		public void drawApperance(object frame, XmlElement xe, string path)
		{
			XmlNodeList xnl = m_xe.ChildNodes;

			if (frame.GetType().BaseType.ToString() == "System.Windows.Controls.ContentControl" ||
				frame.GetType().BaseType.ToString() == "System.Windows.Controls.Panel")
			{
				foreach (XmlNode xnf in xnl)
				{
					if (xnf.NodeType == XmlNodeType.Element)
					{
						XmlElement xeImg = (XmlElement)xnf;

						if (xeImg.Name == "imageShape")
						{
							drawImg(frame, xeImg, path);
						}
					}
				}
			}
		}

		public void drawAnimation(object frame, XmlElement xe, string path)
		{
		}

		virtual protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			this.Header = this.GetType().Name;
			addChild();
		}
	}
}

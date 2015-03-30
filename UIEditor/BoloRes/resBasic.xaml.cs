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
	public struct DrawSkin_T
	{
		public object frame;
		public XmlElement xe;
		public string path;
		public XmlControl rootControl;
	}

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
			DrawSkin_T drawData;

			drawData.frame = m_rootControl.mx_workSpace;
			drawData.xe = m_xe;
			drawData.path = pW.m_rootPath;
			drawData.rootControl = m_rootControl;

			m_rootControl.mx_workSpace.Children.Clear();
			drawImg(drawData);
		}

		public void eventDrawApperance(object sender, MouseEventArgs e)
		{
			MainWindow pW = (MainWindow)Window.GetWindow(this);
			DrawSkin_T drawData;

			drawData.frame = m_rootControl.mx_workSpace;
			drawData.xe = m_xe;
			drawData.path = pW.m_rootPath;
			drawData.rootControl = m_rootControl;

			m_rootControl.mx_workSpace.Children.Clear();
			drawApperance(drawData);
		}

		public void eventDrawAnimation(object sender, MouseEventArgs e)
		{
			MainWindow pW = (MainWindow)Window.GetWindow(this);

			m_rootControl.mx_workSpace.Children.Clear();
			drawAnimation(m_rootControl.mx_workSpace, m_xe, pW.m_rootPath);
		}

		static public void drawImg(DrawSkin_T drawData)
		{
			var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.DrawImg"), drawData.xe, drawData.path, drawData.rootControl) as Grid;
			if (drawData.frame.GetType().BaseType.ToString() == "System.Windows.Controls.ContentControl" ||
				drawData.frame.GetType().BaseType.BaseType.ToString() == "System.Windows.Controls.ContentControl")
			{
				(drawData.frame as ContentControl).Content = tabContent;
			}
			else if (drawData.frame.GetType().BaseType.ToString() == "System.Windows.Controls.Panel" ||
				drawData.frame.GetType().BaseType.BaseType.ToString() == "System.Windows.Controls.Panel")
			{
				(drawData.frame as Panel).Children.Add(tabContent);
			}
		}

		static public void drawApperance(DrawSkin_T drawData)
		{
			if(drawData.xe != null)
			{
				XmlNodeList xnl = drawData.xe.ChildNodes;

				if (drawData.frame.GetType().BaseType.ToString() == "System.Windows.Controls.ContentControl" ||
					drawData.frame.GetType().BaseType.ToString() == "System.Windows.Controls.Panel" ||
					drawData.frame.GetType().BaseType.BaseType.ToString() == "System.Windows.Controls.ContentControl" ||
					drawData.frame.GetType().BaseType.BaseType.ToString() == "System.Windows.Controls.Panel")
				{
					foreach (XmlNode xnf in xnl)
					{
						if (xnf.NodeType == XmlNodeType.Element)
						{
							XmlElement xeImg = (XmlElement)xnf;

							if (xeImg.Name == "imageShape")
							{
								drawData.xe = xeImg;
								drawImg(drawData);
							}
						}
					}
				}
			}
		}

		static public bool drawApperanceById(DrawSkin_T drawData, string appId)
		{
			if(drawData.xe != null)
			{
				XmlElement xeSkin = drawData.xe;
				XmlNodeList xnl = xeSkin.ChildNodes;

				foreach (XmlNode xnf in xnl)
				{
					if (xnf.NodeType == XmlNodeType.Element)
					{
						XmlElement xeApp = (XmlElement)xnf;

						if (xeApp.Name == "apperance")
						{
							if (xeApp.GetAttribute("id") != "" && xeApp.GetAttribute("id") == appId)
							{
								drawData.xe = xeApp;
								drawApperance(drawData);

								return true;
							}
						}
					}
				}

				return false;
			}
			else
			{
				return false;
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

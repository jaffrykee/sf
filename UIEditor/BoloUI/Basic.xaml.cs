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
using System.Xml;

namespace UIEditor.BoloUI
{
	/// <summary>
	/// Event.xaml 的交互逻辑
	/// </summary>
	public partial class Basic : TreeViewItem
	{
		public XmlControl m_rootControl;
		public XmlElement m_xe;

		public Basic()
		{
			InitializeComponent();
		}

		public Basic(XmlElement xe, XmlControl rootControl)
		{
			InitializeComponent();
			m_rootControl = rootControl;
			m_xe = xe;
		}

		protected void addChild()
		{
			XmlNodeList xnl = m_xe.ChildNodes;
			foreach (XmlNode xnf in xnl)
			{
				if (xnf.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xnf;

					switch (xe.Name)
					{
						case "event":
							{
								var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Event"), xe, m_rootControl) as TreeViewItem;
								this.Items.Add(treeChild);
							}
							break;
						default:
							if (Type.GetType("UIEditor.BoloUI." + xe.Name) != null)
							{
								var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI." + xe.Name), xe, m_rootControl) as TreeViewItem;
								this.Items.Add(treeChild);
							}
							else
							{
// 								var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), xe, m_rootControl) as TreeViewItem;
// 								this.Items.Add(treeChild);
								m_rootControl.textContent.Text += (xe.Name + ":" + xe.GetAttribute("Name") + "\r\n");
							}
							break;
					}
				}
			}
		}

		private void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			this.Header = this.GetType().Name;
			this.Header += ":" + m_xe.GetAttribute("name");
			this.Header += "(" + m_xe.GetAttribute("baseID") + ")";

			addChild();
		}
	}
}

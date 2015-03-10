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
	/// <summary>
	/// PublicSkin.xaml 的交互逻辑
	/// </summary>
	public partial class PublicSkin : TreeViewItem
	{
		XmlControl m_rootControl;
		XmlElement m_xe;

		public PublicSkin(XmlElement xe, XmlControl rootControl)
		{
			InitializeComponent();
			m_rootControl = rootControl;
			m_xe = xe;
		}

		private void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			this.Header = m_xe.GetAttribute("Name");

			XmlNodeList xnl = m_xe.ChildNodes;
			foreach (XmlNode xnf in xnl)
			{
				if (xnf.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xnf;

					switch (xe.Name)
					{
						case "apperance":
							{

							}
							break;
						default:
							{
								m_rootControl.textContent.Text += (xe.Name + ":" + xe.GetAttribute("Name") + "\r\n");
							}
							break;
					}
				}
			}
// 			var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.DrawSkin"), m_xe, this) as UserControl;
		}
	}
}

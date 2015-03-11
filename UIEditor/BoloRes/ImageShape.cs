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
	public class ImageShape : resBasic
	{
		public ImageShape(XmlElement xe, XmlControl rootControl):base(xe, rootControl)
		{
			m_mapNode.Add("animation", "Animation");
		}

		override protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			this.Header = "img:" + m_xe.GetAttribute("ImageName");

			addChild();
		}
	}
}

﻿using System;
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
	public class apartPanel : Basic
	{
		public apartPanel(XmlElement xe, XmlControl rootControl, Canvas parentCanvas)
			: base(xe, rootControl, parentCanvas)
		{
		}

		override protected void TreeViewItem_Loaded(object sender, RoutedEventArgs e)
		{
			this.Header = this.GetType().Name;
			this.Header += ":" + m_xe.GetAttribute("name");
			this.Header += "(" + m_xe.GetAttribute("baseID") + ")";

			addChild();

			double widthCount = 0;
			int i = 0;
			foreach(TreeViewItem treeChild in this.Items)
			{
				if(i == this.Items.Count - 1)
				{
					((UIEditor.BoloUI.Basic)treeChild).m_curCanvas.Width = m_curCanvas.Width - widthCount;
				}
				else
				{
					widthCount += ((UIEditor.BoloUI.Basic)treeChild).m_curCanvas.Width;
				}
				i++;
			}
		}
	}
}
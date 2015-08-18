﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
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

namespace UIEditor
{
	public enum AttrType
	{
		boloCtrl,
		boloRes
	};
	public partial class AttrList : Grid
	{
		public string m_name;
		public MainWindow m_pW;
		public XmlElement m_xe;
		public XmlControl m_xmlCtrl;
		public XmlItem m_basic;

		public AttrList(string name = "", MainWindow pW = null)
		{
			m_name = name;
			m_pW = pW;
			this.InitializeComponent();
		}

		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{
			m_pW = Window.GetWindow(this) as MainWindow;

			MainWindow.CtrlDef_T ctrlDef;
			if (m_pW.m_mapCtrlDef.TryGetValue(m_name, out ctrlDef))
			{
				foreach (KeyValuePair<string, MainWindow.AttrDef_T> pairAttrDef in ctrlDef.m_mapAttrDef.ToList())
				{
					pairAttrDef.Value.m_attrRowUI = new AttrRow(pairAttrDef.Value, pairAttrDef.Key, "", this);
					mx_frame.Children.Add(pairAttrDef.Value.m_attrRowUI);
				}
			}
			else
			{
				//todo
			}

			mx_title.Content = m_name;
		}

		public void clearRowValue()
		{
			foreach (object row in mx_frame.Children)
			{
				if (row.GetType() == Type.GetType("UIEditor.AttrRow"))
				{
					((AttrRow)row).m_preValue = "";
				}
			}
		}

		public void refreshRowVisible()
		{
			bool onlySetted;
			bool onlyCommon;

			if (mx_onlySetted != null && mx_onlySetted.IsChecked == true)
			{
				onlySetted = true;
			}
			else
			{
				onlySetted = false;
			}
			if (mx_onlyCommon != null && mx_onlyCommon.IsChecked == true)
			{
				onlyCommon = true;
			}
			else
			{
				onlyCommon = false;
			}
			foreach (object row in mx_frame.Children)
			{
				if (row.GetType() == Type.GetType("UIEditor.AttrRow"))
				{
					((AttrRow)row).mx_root.Visibility = Visibility.Visible;
				}
			}
			if(onlySetted)
			{
				foreach (object row in mx_frame.Children)
				{
					if (row.GetType() == Type.GetType("UIEditor.AttrRow"))
					{
						if (((AttrRow)row).m_preValue == "")
						{
							((AttrRow)row).mx_root.Visibility = Visibility.Collapsed;
						}
					}
				}
			}
			if (onlyCommon)
			{
				foreach (object row in mx_frame.Children)
				{
					if (row.GetType() == Type.GetType("UIEditor.AttrRow"))
					{
						if (((AttrRow)row).m_isCommon == false)
						{
							((AttrRow)row).mx_root.Visibility = Visibility.Collapsed;
						}
					}
				}
			}
			m_pW.mx_toolScroll.ScrollToRightEnd();
		}

		private void mx_onlySetted_Checked(object sender, RoutedEventArgs e)
		{
			refreshRowVisible();
		}
		private void mx_onlySetted_Unchecked(object sender, RoutedEventArgs e)
		{
			refreshRowVisible();
		}
		private void mx_onlyCommon_Checked(object sender, RoutedEventArgs e)
		{
			refreshRowVisible();
		}
		private void mx_onlyCommon_Unchecked(object sender, RoutedEventArgs e)
		{
			refreshRowVisible();
		}
	}
}
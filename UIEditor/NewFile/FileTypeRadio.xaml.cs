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

namespace UIEditor.NewFile
{
	/// <summary>
	/// FileTypeRadio.xaml 的交互逻辑
	/// </summary>
	public partial class FileTypeRadio : Grid
	{
		public FileTypeRadio(string text,string groupName)
		{
			InitializeComponent();
			mx_radio.Content = text;
			mx_radio.GroupName = groupName;
		}

		private void mx_radio_MouseEnter(object sender, MouseEventArgs e)
		{

		}
		private void mx_radio_MouseLeave(object sender, MouseEventArgs e)
		{

		}
		private void mx_radio_Checked(object sender, RoutedEventArgs e)
		{

		}
		private void mx_radio_Unchecked(object sender, RoutedEventArgs e)
		{

		}
	}
}

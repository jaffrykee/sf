using System;
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
using System.Windows.Shapes;
using System.Xml;
using System.IO;

namespace UIEditor.BoloUI
{
	/// <summary>
	/// SelImage.xaml 的交互逻辑
	/// </summary>
	public partial class SelImage : Window
	{
		public AttrRow m_rowSkin;
		public Dictionary<string, TreeViewItem> m_mapLocalRes;
		public Dictionary<string, TreeViewItem> m_mapOtherRes;

		static public SelImage s_pW;

		public SelImage(AttrRow rowSkin)
		{
			s_pW = this;
			m_rowSkin = rowSkin;
			m_mapLocalRes = new Dictionary<string, TreeViewItem>();
			m_mapOtherRes = new Dictionary<string, TreeViewItem>();
			InitializeComponent();
			this.Owner = MainWindow.s_pW;

			ImageIndex.refreshImageIndex();
			refreshResMap();
			refreshResTree();
		}
		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{

		}
		private void mx_root_Unloaded(object sender, RoutedEventArgs e)
		{
			s_pW = null;
		}

		public void refreshImageItem(TreeViewItem viewItem, string resName)
		{
			string resPath = MainWindow.s_pW.m_imagePath + "\\" + resName + ".xml";

			viewItem.ToolTip = resPath;
			if(System.IO.File.Exists(resPath))
			{
				XmlDocument docRes = new XmlDocument();

				try
				{
					docRes.Load(resPath);
				}
				catch
				{
					return;
				}
				foreach(XmlNode xnImage in docRes.DocumentElement)
				{
					if(xnImage.NodeType == XmlNodeType.Element)
					{
						XmlElement xeImage = (XmlElement)xnImage;


					}
				}
			}
		}
		public void refreshResMap()
		{
			if (m_rowSkin != null && m_rowSkin.m_parent != null && m_rowSkin.m_parent.m_xmlCtrl != null &&
				m_rowSkin.m_parent.m_xmlCtrl.m_xmlDoc != null)
			{
				XmlDocument doc = m_rowSkin.m_parent.m_xmlCtrl.m_xmlDoc;
				XmlElement xeRoot = doc.DocumentElement;

				if (xeRoot.Name == "BoloUI")
				{
					foreach (XmlNode xn in xeRoot.ChildNodes)
					{
						if (xn.NodeType == XmlNodeType.Element)
						{
							XmlElement xe = (XmlElement)xn;

							if (xe.Name == "resource" || xe.Name == "publicresource")
							{
								string resName = xe.GetAttribute("name");

								if (resName != "")
								{
									TreeViewItem viewItem;

									if (!m_mapLocalRes.TryGetValue(resName, out viewItem))
									{
										m_mapLocalRes.Add(resName, new TreeViewItem());
									}
								}
							}
						}
					}
				}
			}
			foreach (KeyValuePair<string, ImageIndex> pairImageIndex in MainWindow.s_pW.m_mapImageIndex.ToList())
			{
				TreeViewItem tmpItem;
				string groupName = System.IO.Path.GetFileNameWithoutExtension(pairImageIndex.Key);

				if (!m_mapLocalRes.TryGetValue(groupName, out tmpItem) &&
					!m_mapOtherRes.TryGetValue(groupName, out tmpItem))
				{
					m_mapOtherRes.Add(groupName, new TreeViewItem());
				}
			}
		}
		public void refreshResTree()
		{
			foreach (KeyValuePair<string, TreeViewItem> pairItem in m_mapLocalRes.ToList())
			{
				pairItem.Value.Header = pairItem.Key;
				mx_localRes.Items.Add(pairItem.Value);
			}
			foreach (KeyValuePair<string, TreeViewItem> pairItem in m_mapOtherRes.ToList())
			{
				pairItem.Value.Header = pairItem.Key;
				mx_otherRes.Items.Add(pairItem.Value);
			}
		}

		private void mx_search_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (mx_search.Text != "")
			{
				MainWindow.refreshSearch(mx_rootItem, null);
				MainWindow.refreshSearch(mx_rootItem, mx_search.Text.ToString());
			}
			else
			{
				MainWindow.refreshSearch(mx_rootItem, null);
			}
		}
		private void mx_ok_Click(object sender, RoutedEventArgs e)
		{

		}
		private void mx_cancel_Click(object sender, RoutedEventArgs e)
		{

		}
	}
}

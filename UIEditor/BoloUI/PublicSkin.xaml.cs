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
	public partial class PublicSkin : UserControl
	{
		public FileTabItem m_parent;
		public bool m_loaded;

		public PublicSkin(FileTabItem parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
		}
	}
}

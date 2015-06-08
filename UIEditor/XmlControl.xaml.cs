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

namespace UIEditor
{
	/// <summary>
	/// XmlControl.xaml 的交互逻辑
	/// </summary>
	public partial class XmlControl : UserControl
	{
		public FileTabItem m_parent;
		public bool m_loaded;
		public MainWindow m_pW;
		public OpenedFile m_openedFile;
		//以baseID为索引的UI们
		public Dictionary<string, BoloUI.Basic> m_mapCtrlUI;
		public XmlDocument m_xmlDoc;

		public XmlControl(FileTabItem parent)
		{
			InitializeComponent();
			m_parent = parent;
			m_loaded = false;
			m_mapCtrlUI = new Dictionary<string, BoloUI.Basic>();
		}

		public void checkBaseId(XmlNode xn)
		{
			if (xn != null)
			{
				XmlNodeList xnl = xn.ChildNodes;
				foreach (XmlNode xnf in xnl)
				{
					if (xnf.NodeType == XmlNodeType.Element)
					{
						XmlElement xe = (XmlElement)xnf;

						MainWindow.CtrlDef_T ctrlDef;

						if(xe.Name != "event" && m_pW.m_mapCtrlDef.TryGetValue(xe.Name, out ctrlDef))
						{
							if(xe.GetAttribute("baseID") == "")
							{
								xe.SetAttribute("baseID", System.Guid.NewGuid().ToString().Substring(32 / 2));
								m_pW.mx_debug.Text += "<警告>baseID没有赋值，已经将其替换为随机值：" + xe.GetAttribute("baseID") + "\r\n";
							}

							BoloUI.Basic tmpNull;
							string id = xe.GetAttribute("baseID");

							if (m_mapCtrlUI.TryGetValue(id, out tmpNull))
							{
								//baseId重复了
								xe.SetAttribute("baseID", System.Guid.NewGuid().ToString().Substring(32 / 2));
								m_pW.mx_debug.Text += "<警告>baseID(" + id + ")重复，已经将其替换为随机值：" + xe.GetAttribute("baseID") + "\r\n";
								id = xe.GetAttribute("baseID");
							}
							m_mapCtrlUI[id] = null;
							checkBaseId(xnf);
						}
					}
				}
			}
		}

		private void tabFrameLoaded(object sender, RoutedEventArgs e)
		{
			if (m_loaded == false)
			{
				m_pW = Window.GetWindow(this) as MainWindow;
				m_openedFile = m_pW.m_mapOpenedFiles[m_parent.m_filePath];
				m_openedFile.m_frame = this;
				m_openedFile.m_treeUI.Items.Clear();
				string firstName = m_openedFile.m_path.Substring(0, m_openedFile.m_path.LastIndexOf("."));
				string fileName = m_openedFile.m_path.Substring(
					m_openedFile.m_path.LastIndexOf("\\") + 1,
					(m_openedFile.m_path.Length - m_openedFile.m_path.LastIndexOf("\\") - 1)
				);

				m_pW.mx_debug.Text += "=====" + m_openedFile.m_path + "=====\r\n";

				m_xmlDoc = new XmlDocument();
				m_xmlDoc.Load(m_openedFile.m_path);
				XmlNode xn = m_xmlDoc.SelectSingleNode("BoloUI");
				if (xn != null)
				{
					XmlNodeList xnl = xn.ChildNodes;

					checkBaseId(xn);
					this.textContent.Text += ("未被解析的项目：\r\n");
					foreach (XmlNode xnf in xnl)
					{
						if (xnf.NodeType == XmlNodeType.Element)
						{
							XmlElement xe = (XmlElement)xnf;

							switch (xe.Name)
							{
								case "publicresource":
								case "publicskin":
								case "resource":
								case "skin":
								case "skingroup":
								case "BoloUIEvent":
								case "panel":
								default:
									var treeChild = Activator.CreateInstance(Type.GetType("UIEditor.BoloUI.Basic"), xe, this) as TreeViewItem;
									this.m_openedFile.m_treeUI.Items.Add(treeChild);
									break;
							}
						}
					}
				}
				else
				{
					this.textContent.Text += ("这不是一个有效的BoloUI文件。" + "\r\n");
				}
				m_pW.updateGL(fileName, MainWindow.SendTag.SEND_NORMAL_NAME);
				m_pW.updateXmlToGL(m_xmlDoc);
				m_loaded = true;
			}
		}
	}
}

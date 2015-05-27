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
using System.Runtime.InteropServices;
using System.Windows.Interop;

namespace UIEditor
{
	/// <summary>
	/// MainWindow.xaml 的交互逻辑
	/// </summary>

	public struct OpenedFile
	{
		public string m_path;
		public TabItem m_tab;
		public TreeViewItem m_treeUI;
		public XmlDocument m_xmlDoc;
	}

	public partial class MainWindow : Window
	{
		public string m_rootPath;
		public Dictionary<string, OpenedFile> m_mapOpenedFiles;
		public Dictionary<string, XmlDocument> m_mapStrSkinGroup;
		public Dictionary<string, XmlElement> m_mapStrSkin;
		public Dictionary<string, AttrList> m_mapStrAttrList;
		public float m_dpiSysX;
		public float m_dpiSysY;
		public IntPtr m_hwndGLParent;
		public IntPtr m_hwndGL;

		private int m_dep;

		public MainWindow()
		{
			m_rootPath = "";
			m_hwndGL = IntPtr.Zero;
			m_hwndGLParent = IntPtr.Zero;
			m_mapOpenedFiles = new Dictionary<string, OpenedFile>();
			InitializeComponent();
			m_mapStrSkinGroup = new Dictionary<string, XmlDocument>();
			m_mapStrSkin = new Dictionary<string, XmlElement>();
			m_mapStrAttrList = new Dictionary<string, AttrList>();
			m_dpiSysX = 96.0f;
			m_dpiSysY = 96.0f;
		}

		private void openProj(object sender, RoutedEventArgs e)
		{
			/*
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.Title = "选择文件";
			openFileDialog.Filter = "ryrp文件|*.ryrp|所有文件|*.*";
			openFileDialog.FileName = string.Empty;
			openFileDialog.FilterIndex = 1;
			openFileDialog.RestoreDirectory = true;
			openFileDialog.DefaultExt = "ryrp";
			DialogResult result = openFileDialog.ShowDialog();
			if (result == System.Windows.Forms.DialogResult.Cancel)
			{
				return;
			}
			string fileName = openFileDialog.FileName;
			this.pro.Content = fileName;
			//this.textBox1.Text = fileName;
			*/
			System.Windows.Forms.FolderBrowserDialog openFolderDialog = new System.Windows.Forms.FolderBrowserDialog();
			openFolderDialog.Description = "选择UI所在文件夹";
			openFolderDialog.SelectedPath = @"E:\mmo2013001\artist\client_resouce\ui\free";
			System.Windows.Forms.DialogResult result = openFolderDialog.ShowDialog();

			if (result == System.Windows.Forms.DialogResult.Cancel)
			{
				return;
			}
			string path = openFolderDialog.SelectedPath;

			refreshProjTree(path, this.mx_treePro, true);
		}

		private void refreshProjTree(string path, TreeViewItem rootItem, bool rootNode)
		{
			m_rootPath = path;
			m_dep = 0;
			m_mapStrSkinGroup.Clear();
			m_mapStrSkin.Clear();
			rootItem.Items.Clear();

			int i = 0;
			int j = 0;

			DirectoryInfo di = new DirectoryInfo(path);
			foreach (var dri in di.GetDirectories())
			{
				TreeViewItem treeUIChild = new TreeViewItem();
				ToolTip treeTip = new ToolTip();

				i++;
				treeTip.Content = path + "\\" + dri.Name;
				treeUIChild.ToolTip = treeTip;
				treeUIChild.Header = dri.Name;
				rootItem.Items.Add(treeUIChild);

				m_dep++;
				refreshProjTree(path + "\\" + dri.Name, treeUIChild, false);
				m_dep--;
			}
			if (m_dep == 1 && rootItem.Header.ToString() == "skin")
			{
				foreach (var dri in di.GetFiles("*.xml"))
				{
					//皮肤组们
					TreeViewItem treeUIChild = new TreeViewItem();
					ToolTip treeTip = new ToolTip();

					XmlDocument xmlDoc = new XmlDocument();
					xmlDoc = new XmlDocument();
					xmlDoc.Load(path + "\\" + dri.Name);
					XmlNode xn = xmlDoc.SelectSingleNode("BoloUI");

					if (xn != null)
					{
						j++;
						treeTip.Content = path + "\\" + dri.Name;
						treeUIChild.ToolTip = treeTip;
						treeUIChild.Header = dri.Name;
						treeUIChild.MouseDoubleClick += new MouseButtonEventHandler(openFileTab);
						rootItem.Items.Add(treeUIChild);

						XmlNodeList xnl = xn.ChildNodes;
						string frontName = dri.Name.Substring(dri.Name.LastIndexOf("\\") + 1, (dri.Name.LastIndexOf(".") - dri.Name.LastIndexOf("\\") - 1));
						m_mapStrSkinGroup[frontName] = xmlDoc;

						foreach (XmlNode xnf in xnl)
						{
							//皮肤们
							if (xnf.NodeType == XmlNodeType.Element)
							{
								XmlElement xe = (XmlElement)xnf;

								switch (xe.Name)
								{
									case "publicskin":
										#region
										{
											m_mapStrSkin[xe.GetAttribute("Name")] = xe;
										}
										#endregion
										break;
									case "skin":
										#region
										{
											m_mapStrSkin[xe.GetAttribute("Name")] = xe;
										}
										#endregion
										break;
									default:
										break;
								}
							}
						}
					}
					else
					{
					}
				}
			}
			else
			{
				foreach (var dri in di.GetFiles("*"))
				{
					TreeViewItem treeUIChild = new TreeViewItem();
					ToolTip treeTip = new ToolTip();

					j++;
					treeTip.Content = path + "\\" + dri.Name;
					treeUIChild.ToolTip = treeTip;
					treeUIChild.Header = dri.Name;
					treeUIChild.MouseDoubleClick += new MouseButtonEventHandler(openFileTab);
					rootItem.Items.Add(treeUIChild);
				}

				if (rootNode == true)
				{
					ToolTip rootTip = new ToolTip();
					rootTip.Content = path;
					rootItem.ToolTip = rootTip;
					rootItem.IsExpanded = false;
					rootItem.Header = "UI工程目录(" + i + "个目录和" + j + "个项目)";
				}
			}
		}

		private void openFileTab(object sender, MouseEventArgs e)
		{
			TreeViewItem treeUI = (TreeViewItem)sender;
			OpenedFile openedFile;
			string tabPath = ((ToolTip)treeUI.ToolTip).Content.ToString();
			string fileType = tabPath.Substring(tabPath.LastIndexOf(".") + 1, (tabPath.Length - tabPath.LastIndexOf(".") - 1));   //扩展名

			if (m_mapOpenedFiles.TryGetValue(tabPath, out openedFile))
			{
				this.mx_workTabs.SelectedItem = openedFile.m_tab;
			}
			else
			{
				ToolTip tabTip = new ToolTip();
				Button close = new Button();

				openedFile.m_tab = new TabItem();
				tabTip.Content = tabPath;
				openedFile.m_tab.Header = treeUI.Header.ToString();
				openedFile.m_tab.ToolTip = tabTip;

				var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.FileTabItem")) as UserControl;
				openedFile.m_tab.Content = tabContent;
				openedFile.m_path = tabPath;
				openedFile.m_treeUI = treeUI;

				this.mx_workTabs.Items.Add(openedFile.m_tab);
				m_mapOpenedFiles[tabPath] = openedFile;
				this.mx_workTabs.SelectedItem = openedFile.m_tab;
			}
		}




//============================================================


		int selectedItem;
		IntPtr hwndListBox;
		ControlHost listControl;
		Application app;
		Window myWindow;

		const int WM_COPYDATA = 0x004A;
		
		public struct COPYDATASTRUCT_SEND
		{
			public IntPtr dwData;
			public int cbData;
			[MarshalAs(UnmanagedType.LPStr)]
			public string lpData;
		}

		public struct COPYDATASTRUCT_SENDEX
		{
			public IntPtr dwData;
			public int cbData;
			public IntPtr lpData;
		}

		public void updateGL(string buffer)
		{
			if (mx_hwndDebug.Text != "")
			{
				m_hwndGL = (IntPtr)long.Parse(mx_hwndDebug.Text);
			}
			unsafe
			{
				byte[] utfArr = Encoding.UTF8.GetBytes(buffer);
				int lenUtf8 = utfArr.Length;
				COPYDATASTRUCT_SENDEX msgData;

				fixed (byte* tmpBuff = utfArr)
				{
					msgData.dwData = (IntPtr)100;
					msgData.lpData = (IntPtr)tmpBuff;
					msgData.cbData = lenUtf8 + 1;
					SendMessage(m_hwndGL, WM_COPYDATA, 0, ref msgData);
				}

			}
		}

		private void On_UIReady(object sender, EventArgs e)
		{
			app = System.Windows.Application.Current;
			myWindow = app.MainWindow;
			//myWindow.SizeToContent = SizeToContent.WidthAndHeight;
			//listControl = new ControlHost(ControlHostElement.ActualHeight, ControlHostElement.ActualWidth);
			listControl = new ControlHost(ControlHostElement.ActualHeight, ControlHostElement.ActualWidth);
			ControlHostElement.Child = listControl;
			listControl.MessageHook += new HwndSourceHook(ControlMsgFilter);

			HwndSource source = PresentationSource.FromVisual(this) as HwndSource;

			if (source != null)
			{
				source.AddHook(WndProc);
			}
		}

		private IntPtr ControlMsgFilter(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
		{
			int textLength;

			handled = false;
			switch (msg)
			{
				case WM_COMMAND:
					switch ((uint)wParam.ToInt32() >> 16 & 0xFFFF) //extract the HIWORD
					{
						case LBN_SELCHANGE: //Get the item text and display it
							selectedItem = SendMessage(listControl.hwndListBox, LB_GETCURSEL, IntPtr.Zero, IntPtr.Zero);
							textLength = SendMessage(listControl.hwndListBox, LB_GETTEXTLEN, IntPtr.Zero, IntPtr.Zero);
							StringBuilder itemText = new StringBuilder();
							SendMessage(hwndListBox, LB_GETTEXT, selectedItem, itemText);
							handled = true;
							break;
					}
					break;
				case WM_COPYDATA:
					unsafe
					{
						COPYDATASTRUCT msgData = *(COPYDATASTRUCT*)lParam;
						if ((int)((COPYDATASTRUCT*)lParam)->dwData == SEND_HWND)
						{
							m_hwndGL = wParam;
						}
					}
					break;
				default:
					break;
			}

			return IntPtr.Zero;
		}

		public struct COPYDATASTRUCT
		{
			public IntPtr dwData;
			public int cbData;
			[MarshalAs(UnmanagedType.LPStr)]
			public IntPtr lpData;
		}

		private IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
		{
			switch (msg)
			{
				case WM_COPYDATA:
					COPYDATASTRUCT msgData = (COPYDATASTRUCT)Marshal.PtrToStructure(lParam, typeof(COPYDATASTRUCT));
					string strData = Marshal.PtrToStringAnsi(msgData.lpData, msgData.cbData);
					if ((int)msgData.dwData == SEND_HWND)
					{
						this.m_hwndGL = hwnd;
					}
					break;
				case WM_CLOSE:
					SendMessage(m_hwndGL, WM_QUIT, IntPtr.Zero, IntPtr.Zero);
					break;
				default:
					break;
			}

			return hwnd;
		}

		internal const int
		  SEND_HWND = 0x00000000,

		  WM_CLOSE = 0x0010,
		  WM_QUIT = 0x0012,
		  WM_COMMAND = 0x00000111,

		  LBN_SELCHANGE = 0x00000001,
		  LB_GETCURSEL = 0x00000188,
		  LB_GETTEXTLEN = 0x0000018A,
		  LB_ADDSTRING = 0x00000180,
		  LB_GETTEXT = 0x00000189,
		  LB_DELETESTRING = 0x00000182,
		  LB_GETCOUNT = 0x0000018B;

		[DllImport("user32.dll", EntryPoint = "SendMessage", CharSet = CharSet.Unicode)]
		internal static extern int SendMessage(IntPtr hwnd,
											   int msg,
											   IntPtr wParam,
											   IntPtr lParam);

		[DllImport("user32.dll", EntryPoint = "SendMessage", CharSet = CharSet.Unicode)]
		internal static extern int SendMessage(IntPtr hwnd,
											   int msg,
											   int wParam,
											   [MarshalAs(UnmanagedType.LPWStr)] StringBuilder lParam);

		[DllImport("user32.dll", EntryPoint = "SendMessage", CharSet = CharSet.Unicode)]
		internal static extern IntPtr SendMessage(IntPtr hwnd,
												  int msg,
												  IntPtr wParam,
												  String lParam);

		[DllImport("User32.dll")]
		public static extern int SendMessage(
			IntPtr hwnd,
			int msg,
			int wParam,
			ref COPYDATASTRUCT IParam);

		[DllImport("User32.dll")]
		public static extern int SendMessage(
			IntPtr hwnd,
			int msg,
			int wParam,
			ref COPYDATASTRUCT_SEND IParam);

		[DllImport("User32.dll")]
		public static extern int SendMessage(
			IntPtr hwnd,
			int msg,
			int wParam,
			ref COPYDATASTRUCT_SENDEX IParam);

		private void mx_workTabs_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if(((TabItem)mx_workTabs.SelectedItem) != null)
			{
				if(((ToolTip)((TabItem)mx_workTabs.SelectedItem).ToolTip) != null)
				{
					string tabPath = ((ToolTip)((TabItem)mx_workTabs.SelectedItem).ToolTip).Content.ToString();
					string fileType = tabPath.Substring(tabPath.LastIndexOf(".") + 1, (tabPath.Length - tabPath.LastIndexOf(".") - 1));

					if(fileType == "xml")
					{
						XmlDocument xmlDoc = new XmlDocument();
						xmlDoc.Load(tabPath);
						string buffer = xmlDoc.InnerXml;
						this.updateGL(buffer);
					}
				}
			}
		}
	}
}

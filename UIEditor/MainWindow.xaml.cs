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


	public class OpenedFile
	{
		public string m_path;
		public TabItem m_tab;
		public TreeViewItem m_treeUI;
		public XmlDocument m_xmlDoc;
		public UserControl m_frame;

		public OpenedFile(TreeViewItem treeUI)
		{
			MainWindow pW = Window.GetWindow(treeUI) as MainWindow;
			string fileType;

			m_path = ((ToolTip)treeUI.ToolTip).Content.ToString();
			fileType = m_path.Substring(m_path.LastIndexOf(".") + 1, (m_path.Length - m_path.LastIndexOf(".") - 1));   //扩展名
			m_tab = new TabItem();
			m_treeUI = treeUI;

			if (fileType == "xml")
			{
				m_xmlDoc = new XmlDocument();
				m_xmlDoc.Load(m_path);
				string buffer = m_xmlDoc.InnerXml;
				string firstName = m_path.Substring(0, m_path.LastIndexOf("."));
				string fileName = m_path.Substring(m_path.LastIndexOf("\\") + 1, (m_path.Length - m_path.LastIndexOf("\\") - 1));

				pW.updateGL(fileName, MainWindow.SendTag.SEND_NORMAL_NAME);
				pW.updateGL(buffer, MainWindow.SendTag.SEND_NORMAL_DATA);
			}

			m_tab.Unloaded += new RoutedEventHandler(pW.eventCloseFile);
			ToolTip tabTip = new ToolTip();
			Button close = new Button();
			tabTip.Content = m_path;
			m_tab.Header = treeUI.Header.ToString();
			m_tab.ToolTip = tabTip;
			var tabContent = Activator.CreateInstance(Type.GetType("UIEditor.FileTabItem")) as UserControl;
			m_tab.Content = tabContent;

			pW.mx_workTabs.Items.Add(m_tab);
			pW.mx_workTabs.SelectedItem = m_tab;
		}
	}

	public partial class MainWindow : Window
	{
		public string m_rootPath;
		public Dictionary<string, OpenedFile> m_mapOpenedFiles;
		public string m_curFile;
		public Dictionary<string, XmlDocument> m_mapStrSkinGroup;
		public Dictionary<string, XmlElement> m_mapStrSkin;
		public Dictionary<string, CtrlDef_T> m_mapCtrlDef;
		public float m_dpiSysX;
		public float m_dpiSysY;
		public IntPtr m_hwndGLParent;
		public IntPtr m_hwndGL;
		public AttrList m_otherAttrList;
		public bool m_attrBinding;		//xml属性绑定用，上锁和解锁必须成对出现

		private int m_dep;

		public MainWindow()
		{
			m_rootPath = "";
			m_hwndGL = IntPtr.Zero;
			m_hwndGLParent = IntPtr.Zero;
			m_mapOpenedFiles = new Dictionary<string, OpenedFile>();
			m_attrBinding = true;
			InitializeComponent();
			m_mapStrSkinGroup = new Dictionary<string, XmlDocument>();
			m_mapStrSkin = new Dictionary<string, XmlElement>();
			m_dpiSysX = 96.0f;
			m_dpiSysY = 96.0f;
			m_curFile = "";
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

			sendPathToGL(path);
			initXmlValueDef();
			//refreshImage(path + "\\images");
			refreshSkin(path + "\\skin");
			refreshProjTree(path, this.mx_treePro, true);
		}

		private void sendPathToGL(string path)
		{
			updateGL(path, SendTag.SEND_PATH);
		}

		private void refreshImage(string path)
		{
			//todo
			DirectoryInfo di = new DirectoryInfo(path);

			foreach (var dri in di.GetFiles("*.xml"))
			{
				XmlDocument xmlDoc = new XmlDocument();
				xmlDoc.Load(path + "\\" + dri.Name);
				string buffer = xmlDoc.InnerXml;

				updateGL(buffer, SendTag.SEND_IMGRES_DATA);
			}
		}

		private void refreshSkin(string path)
		{
			XmlDocument xmlDoc = new XmlDocument();
			xmlDoc.Load(path + "\\publicskin.xml");
			XmlNode xn = xmlDoc.SelectSingleNode("BoloUI");

			if (xn != null)
			{
				string buffer = xmlDoc.InnerXml;
				updateGL("publicskin.xml", SendTag.SEND_SKIN_NAME);
				updateGL(buffer, SendTag.SEND_SKIN_DATA);
			}
// 			DirectoryInfo di = new DirectoryInfo(path);
// 
// 			foreach (var dri in di.GetFiles("*.xml"))
// 			{
// 				XmlDocument xmlDoc = new XmlDocument();
// 				xmlDoc.Load(path + "\\" + dri.Name);
// 				XmlNode xn = xmlDoc.SelectSingleNode("BoloUI");
// 
// 				if (xn != null)
// 				{
// 					string buffer = xmlDoc.InnerXml;
// 					//string firstName = dri.Name.Substring(0, dri.Name.LastIndexOf("."));
// 					updateGL(dri.Name, SendTag.SEND_SKIN_NAME);
// 					updateGL(buffer, SendTag.SEND_SKIN_DATA);
// 				}
// 			}
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
				m_mapOpenedFiles[tabPath] = new OpenedFile(treeUI);
			}
		}

		public void eventCloseFile(object sender, RoutedEventArgs e)
		{
		}

		private void mx_workTabs_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (((TabItem)mx_workTabs.SelectedItem) != null)
			{
				if (((ToolTip)((TabItem)mx_workTabs.SelectedItem).ToolTip) != null)
				{
					string tabPath = ((ToolTip)((TabItem)mx_workTabs.SelectedItem).ToolTip).Content.ToString();
					string fileType = tabPath.Substring(tabPath.LastIndexOf(".") + 1, (tabPath.Length - tabPath.LastIndexOf(".") - 1));

					if (fileType == "xml")
					{
						string fileName = tabPath.Substring(tabPath.LastIndexOf("\\") + 1, (tabPath.Length - tabPath.LastIndexOf("\\") - 1));

						OpenedFile openFile;
						if (m_mapOpenedFiles.TryGetValue(tabPath, out openFile))
						{
							updateGL(fileName, SendTag.SEND_NORMAL_TURN);
						}
						ControlHostElement.Visibility = System.Windows.Visibility.Visible;
					}
					else
					{
						ControlHostElement.Visibility = System.Windows.Visibility.Collapsed;
					}
				}
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

		public enum SendTag
		{
			SEND_PATH = 0x0000,
			SEND_NORMAL_NAME = 0x0001,
			SEND_NORMAL_DATA = 0x0011,
			SEND_NORMAL_TURN = 0x0101,
			SEND_SKIN_NAME = 0x0002,
			SEND_SKIN_DATA = 0x0012,
			SEND_IMGRES_NAME = 0x0003,
			SEND_IMGRES_DATA = 0x0013,
		};

		public void updateGL(string buffer, SendTag msgTag = SendTag.SEND_NORMAL_DATA)
		{
			ControlHostElement.Visibility = System.Windows.Visibility.Visible;
			if (mx_hwndDebug.Text != "")
			{
				m_hwndGL = (IntPtr)long.Parse(mx_hwndDebug.Text);
			}
			unsafe
			{
				int len;
				byte[] charArr;
				COPYDATASTRUCT_SENDEX msgData;

				if (msgTag == SendTag.SEND_PATH)
				{
					charArr = Encoding.Default.GetBytes(buffer);
					len = charArr.Length;
				}
				else
				{
					charArr = Encoding.UTF8.GetBytes(buffer);
					len = charArr.Length;
				}

				fixed (byte* tmpBuff = charArr)
				{
					msgData.dwData = (IntPtr)msgTag;
					msgData.lpData = (IntPtr)tmpBuff;
					msgData.cbData = len + 1;
					SendMessage(m_hwndGL, WM_COPYDATA, 0, ref msgData);
				}
			}
		}

		private void On_UIReady(object sender, EventArgs e)
		{
			app = System.Windows.Application.Current;
			myWindow = app.MainWindow;
			listControl = new ControlHost();
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
						if ((int)((COPYDATASTRUCT*)lParam)->dwData == GET_HWND)
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
					if ((int)msgData.dwData == GET_HWND)
					{
						this.m_hwndGL = hwnd;
					}
					break;
				case WM_CLOSE:
					SendMessage(m_hwndGL, WM_QUIT, IntPtr.Zero, IntPtr.Zero);
					break;
				case WM_QUIT:
					SendMessage(m_hwndGL, WM_QUIT, IntPtr.Zero, IntPtr.Zero);
					break;
				case WM_DESTROY:
					SendMessage(m_hwndGL, WM_QUIT, IntPtr.Zero, IntPtr.Zero);
					break;
				default:
					break;
			}

			return hwnd;
		}

		internal const int
		  GET_HWND = 0x0000,


		  WM_DESTROY = 0x0002,
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

		#region xml控件名、属性名、默认值、取值范围等。
		public class AttrDef_T
		{
			public AttrRow m_attrRowUI;
			public string m_type;
			public string m_defValue;
			public bool m_isEnum;
			public List<string> m_enumValue;

			public AttrDef_T(string type = "int", string defValue = null, AttrRow rowUI = null)
			{
				m_attrRowUI = rowUI;
				m_type = type;
				m_defValue = defValue;
				m_isEnum = false;
				m_enumValue = null;
			}
		}

		public class CtrlDef_T
		{
			public Dictionary<string, AttrDef_T> m_mapAttrDef;
			public AttrList m_attrListUI;

			public CtrlDef_T(Dictionary<string, AttrDef_T> mapAttrDef, AttrList attrListUI)
			{
				m_mapAttrDef = mapAttrDef;
				m_attrListUI = attrListUI;
			}
		}


		Dictionary<string, AttrDef_T> conf_mapBaseAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region Base
				{"name", new AttrDef_T("string")},
				{"baseID", new AttrDef_T("string")},
				{"text", new AttrDef_T("string")},
				{"alpha", new AttrDef_T("int")},
				{"x", new AttrDef_T("int")},
				{"y", new AttrDef_T("int")},
				{"w", new AttrDef_T("int")},
				{"h", new AttrDef_T("int")},
				{"maxWidth", new AttrDef_T("int")},
				{"maxHeight", new AttrDef_T("int")},
				{"minWidth", new AttrDef_T("int")},
				{"minHeight", new AttrDef_T("int")},
				{"leftBorder", new AttrDef_T("int")},
				{"rightBorder", new AttrDef_T("int")},
				{"topBorder", new AttrDef_T("int")},
				{"bottomBorder", new AttrDef_T("int")},
				{"visible", new AttrDef_T("bool")},
				{"enable", new AttrDef_T("bool")},
				{"dock", new AttrDef_T("int")},
				{"docklayer", new AttrDef_T("int")},
				{"anchor", new AttrDef_T("int")},
				{"anchorSelf", new AttrDef_T("int")},
				{"canFocus", new AttrDef_T("bool")},
				{"skin", new AttrDef_T("string")},
				{"tips", new AttrDef_T("bool")},
				{"tipCx", new AttrDef_T("int")},
				{"tipCy", new AttrDef_T("int")},
				{"tipMaxWidth", new AttrDef_T("int")},
				{"tipText", new AttrDef_T("string")},
				{"showStyle", new AttrDef_T("int")},
				{"movieSpe", new AttrDef_T("int")},
				{"angle", new AttrDef_T("int")},
				{"rotateType", new AttrDef_T("int")},
				{"movieLayer", new AttrDef_T("int")},
				{"scalePerX", new AttrDef_T("int")},
				{"scalePerY", new AttrDef_T("int")},
				{"onSelectByKey", new AttrDef_T("bool")},
				{"canSelectByKey", new AttrDef_T("bool")},
				{"canAutoBuildTopKey", new AttrDef_T("bool")},
				{"canAutoBuildLeftKey", new AttrDef_T("bool")},
				{"assignTopKeyBaseID", new AttrDef_T("string")},
				{"assignBottomKeyBaseID", new AttrDef_T("string")},
				{"assignLeftKeyBaseID", new AttrDef_T("string")},
				{"assignRightKeyBaseID", new AttrDef_T("string")},
				{"scrollBorder", new AttrDef_T("int")},
				{"hScrollHeight", new AttrDef_T("int")},
				{"vScrollWidth", new AttrDef_T("int")},
				{"vScrollSliderHeight", new AttrDef_T("int")},
				{"hScrollSliderWidth", new AttrDef_T("int")},
				{"scrollSliderBorder", new AttrDef_T("int")},
				{"scrollSliderAutosize", new AttrDef_T("bool")},
				{"scrollDecay", new AttrDef_T("int")},
				{"scrollPickupInterval", new AttrDef_T("int")},
				{"scrollSpeed", new AttrDef_T("int")},
				{"scrollInitPos", new AttrDef_T("int")},
				{"rememberScrollPos", new AttrDef_T("bool")},
				{"scrollParentLayerWhenGetFocus", new AttrDef_T("int")},
				{"isMaskAreaByKey", new AttrDef_T("bool")},
				{"ownEvt", new AttrDef_T("bool")},
				{"isEffectParentAutosize", new AttrDef_T("bool")},
				{"canUsedEvent", new AttrDef_T("bool")},
				{"canHandleEvent", new AttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapPanelAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region Panel
				{"isEnableScroll", new AttrDef_T("bool")},
				{"own", new AttrDef_T("bool")},
				{"autoSize", new AttrDef_T("bool")},
				{"backSpeed", new AttrDef_T("int")},
				{"bkH_T", new AttrDef_T("int")},
				{"bkH_B", new AttrDef_T("int")},
				{"bkW_L", new AttrDef_T("int")},
				{"bkW_R", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapLabelAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region Label
				{"bgColor", new AttrDef_T("intx16")},
				{"speed", new AttrDef_T("int")},
				{"autoSize", new AttrDef_T("bool")},
				{"autoFontSize", new AttrDef_T("bool")},
				{"scrollcountType", new AttrDef_T("int")},
				{"scrollTime", new AttrDef_T("int")},
				{"scrollRate", new AttrDef_T("int")},
				{"scrollRateHalf", new AttrDef_T("int")},
				{"scrollTimeMax", new AttrDef_T("int")},
				{"startXPer", new AttrDef_T("int")},
				{"defaultMsgTime", new AttrDef_T("int")},
				{"nextUIevent", new AttrDef_T("bool")},
				{"nextUIeventType", new AttrDef_T("int")},
				{"drawType", new AttrDef_T("int")},
				{"ellipsisWhenTooLong", new AttrDef_T("bool")},
				{"reelScrollDerection", new AttrDef_T("int")},
				{"reelScrollSpeed", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapButtonAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region Button
				{"wordWhole", new AttrDef_T("bool")},
				{"interval", new AttrDef_T("int")},
				{"blinktimes", new AttrDef_T("int")},
				{"blinkTextAreaX", new AttrDef_T("int")},
				{"blinkTextAreaY", new AttrDef_T("int")},
				{"blinkTextAreaW", new AttrDef_T("int")},
				{"blinkTextAreaH", new AttrDef_T("int")},
				{"slideOri", new AttrDef_T("int")},
				{"pressedEndBlink", new AttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapSkillButtonAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region SkillButton
				{"cdStyle", new AttrDef_T("int")},
				{"cdTime", new AttrDef_T("int")},
				{"cdRange", new AttrDef_T("int")},
				{"cdRGB", new AttrDef_T("intx16")},
				{"cdEx", new AttrDef_T("int")},
				{"cdEy", new AttrDef_T("int")},
				{"cdExN", new AttrDef_T("int")},
				{"cdEyN", new AttrDef_T("int")},
				{"showCdTime", new AttrDef_T("bool")},
				{"clockwiseRad", new AttrDef_T("int")},
				{"clockwiseOffsetx", new AttrDef_T("int")},
				{"clockwiseOffsety", new AttrDef_T("int")},
				{"clockwiseAngle", new AttrDef_T("int")},
				{"clockwiseOriginAngle", new AttrDef_T("int")},
				{"progressIncrease", new AttrDef_T("bool")},
				{"disableWhenBeginCold", new AttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapProgressAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region Progress
				{"min", new AttrDef_T("int")},
				{"max", new AttrDef_T("int")},
				{"value", new AttrDef_T("int")},
				{"ori", new AttrDef_T("int")},
				{"track", new AttrDef_T("bool")},
				{"sliderWidth", new AttrDef_T("int")},
				{"sliderHeight", new AttrDef_T("int")},
				{"changeSpeed", new AttrDef_T("int")},
				{"changeRate", new AttrDef_T("int")},
				{"clockwiseRad", new AttrDef_T("int")},
				{"clockwiseOffsetx", new AttrDef_T("int")},
				{"clockwiseOffsety", new AttrDef_T("int")},
				{"clockwiseAngle", new AttrDef_T("int")},
				{"clockwiseOriginAngle", new AttrDef_T("int")},
				{"sliderShowType", new AttrDef_T("int")},
				{"fillHeadTailShowType", new AttrDef_T("int")},
				{"preGrowthValue", new AttrDef_T("int")},
				{"decaySpeed", new AttrDef_T("int")},
				{"beginDecay", new AttrDef_T("bool")},
				{"sliderLeftFill", new AttrDef_T("bool")},
				{"delayValueRate", new AttrDef_T("int")},
				{"gridValue", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapRadioAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region Radio
				{"select", new AttrDef_T("bool")},
				{"ntw", new AttrDef_T("int")},
				{"wordWhole", new AttrDef_T("bool")},
				{"checkLayer", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapCheckAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region Check
				{"select", new AttrDef_T("bool")},
				{"ntw", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapListPanelAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region ListPanel
				{"lineHeight", new AttrDef_T("int")},
				{"own", new AttrDef_T("bool")},
				{"cel", new AttrDef_T("int")},
				{"celCountMax", new AttrDef_T("int")},
				{"select", new AttrDef_T("int")},
				{"autoSize", new AttrDef_T("bool")},
				{"maxSize", new AttrDef_T("int")},
				{"bkH_T", new AttrDef_T("int")},
				{"bkH_B", new AttrDef_T("int")},
				{"backSpeed", new AttrDef_T("int")},
				{"appendOri", new AttrDef_T("int")},
				{"lineSpace", new AttrDef_T("int")},
				{"removeExceedFromHead", new AttrDef_T("bool")},
				{"onBottomEventPercent", new AttrDef_T("int")},
				{"middleSelect", new AttrDef_T("int")},
				{"isMiddleCardList", new AttrDef_T("bool")},
				{"middleCardBorder", new AttrDef_T("int")},
				{"middleCardZoomValue", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapTabPanelAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region TabPanel
				{"cascadeOrder", new AttrDef_T("int")},
				{"alignment", new AttrDef_T("int")},
				{"tabIndent", new AttrDef_T("int")},
				{"tabInterval", new AttrDef_T("int")},
				{"tabPageSpacing", new AttrDef_T("int")},
				{"tabWidth", new AttrDef_T("int")},
				{"tabHeight", new AttrDef_T("int")},
				{"own", new AttrDef_T("bool")},
				{"duiqi", new AttrDef_T("int")},
				{"wordWhole", new AttrDef_T("bool")},
				{"tabChangeTime", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapPagePanelAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region PagePanel
				{"speed", new AttrDef_T("int")},
				{"own", new AttrDef_T("bool")},
				{"switchType", new AttrDef_T("int")},
				{"controlRotateType", new AttrDef_T("int")},
				{"turnEnable", new AttrDef_T("bool")},
				{"switchPageNeedlen", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapVirtualPadAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region VirtualPad
				{"vStyle", new AttrDef_T("int")},
				{"fingerpadr", new AttrDef_T("int")},
				{"pf", new AttrDef_T("int")},
				{"areaMaxWidthPer", new AttrDef_T("int")},
				{"areaMaxHeightPer", new AttrDef_T("int")},
				{"setAx", new AttrDef_T("int")},
				{"setAy", new AttrDef_T("int")},
				{"backTime", new AttrDef_T("int")},
				{"clickTime", new AttrDef_T("int")},
				{"interval", new AttrDef_T("int")},
				{"blinktimes", new AttrDef_T("int")},
				{"padToFingerDistanceMax", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapRichTextAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region RichText
				{"maxLength", new AttrDef_T("int")},
				{"maxLine", new AttrDef_T("int")},
				{"readOnly", new AttrDef_T("bool")},
				{"passwordChar", new AttrDef_T("bool")},
				{"wrodWrap", new AttrDef_T("bool")},
				{"vScrollBoarder", new AttrDef_T("int")},
				{"lineSpacing", new AttrDef_T("int")},
				{"speed", new AttrDef_T("int")},
				{"wordWhole", new AttrDef_T("bool")},
				{"autoSize", new AttrDef_T("bool")},
				{"richTips", new AttrDef_T("string")},
				{"convertIndex", new AttrDef_T("int")},
				{"inputType", new AttrDef_T("int")},
				{"bkH_T", new AttrDef_T("int")},
				{"bkH_B", new AttrDef_T("int")},
				{"beforeSkins", new AttrDef_T("string")},
				{"scrollTime", new AttrDef_T("int")},
				{"scrollTextSpeed", new AttrDef_T("int")},
				{"scrollText", new AttrDef_T("bool")},
				{"scrollcountType", new AttrDef_T("int")},
				{"backSpeed", new AttrDef_T("int")},
				{"textAnchorType", new AttrDef_T("int")},
				{"independentDrawSub", new AttrDef_T("bool")},
				{"alignBottomText", new AttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapPageTextAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region PageText
				{"pressedWidth", new AttrDef_T("int")},
				{"pressedHeight", new AttrDef_T("int")},
				{"PageNumHeight", new AttrDef_T("int")},
				{"PageNumWidth", new AttrDef_T("int")},
				{"PageNumIndent", new AttrDef_T("int")},
				{"lineSpacing", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapScriptPanelAttrDef = new Dictionary<string, AttrDef_T>
		{
		};

		Dictionary<string, AttrDef_T> conf_mapCountDownAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region CountDown
				{"start", new AttrDef_T("bool")},
				{"unit", new AttrDef_T("int")},
				{"days", new AttrDef_T("int")},
				{"hours", new AttrDef_T("int")},
				{"minutes", new AttrDef_T("int")},
				{"seconds", new AttrDef_T("int")},
				{"milliseconds", new AttrDef_T("int")},
				{"countType", new AttrDef_T("int")},
				{"timeout", new AttrDef_T("int")},
				{"countChangeRate", new AttrDef_T("float")},
				{"autoShowLength", new AttrDef_T("int")},
				{"timePreset", new AttrDef_T("time")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapApartPanelAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region ApartPanel
				{"own", new AttrDef_T("bool")},
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapDraggedPanelAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region DraggedPanel
				{"canDraggedCopy", new AttrDef_T("bool")},
				{"getInfoIndex", new AttrDef_T("int")},
				{"copyTime", new AttrDef_T("int")},
				{"own", new AttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapTurnTableAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region TurnTable
				{"tableCount", new AttrDef_T("int")},
				{"resultIndexString", new AttrDef_T("string")},
				{"interval", new AttrDef_T("int")},
				{"turnTime", new AttrDef_T("int")},
				{"maxTurntime", new AttrDef_T("int")},
				{"turnType", new AttrDef_T("int")},
				{"defaultRun", new AttrDef_T("bool")},
				{"maxSpeed", new AttrDef_T("int")},
				{"runAcceleration", new AttrDef_T("int")},
				{"backAcceleration", new AttrDef_T("int")},
				{"tableInterval", new AttrDef_T("int")},
				{"lineSpace", new AttrDef_T("int")},
				{"backTime", new AttrDef_T("int")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapDrawModelAttrDef = new Dictionary<string, AttrDef_T>
		{
		};

		Dictionary<string, AttrDef_T> conf_mapDropListAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region DropList
				{"appendOri", new AttrDef_T("int")},
				{"packWidth", new AttrDef_T("int")},
				{"packHeight", new AttrDef_T("int")},
				{"expansionWidth", new AttrDef_T("int")},
				{"expansionHeight", new AttrDef_T("int")},
				{"lineSpace", new AttrDef_T("int")},
				{"ignoreParentClip", new AttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapEventAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region Event
				{"type", new AttrDef_T("string")},
				{"function", new AttrDef_T("string")},
				{"sound", new AttrDef_T("string")}
				#endregion
			};

		Dictionary<string, AttrDef_T> conf_mapToolTipAttrDef = new Dictionary<string, AttrDef_T>
		{
		};

		public void initXmlValueDef()
		{
			m_mapCtrlDef = new Dictionary<string, CtrlDef_T>
			{
				#region boloUIControls
				{ "basic", new CtrlDef_T(conf_mapBaseAttrDef, null)},
				{ "panel", new CtrlDef_T(conf_mapPanelAttrDef, null)},
				{ "label", new CtrlDef_T(conf_mapLabelAttrDef, null)},
				{ "button", new CtrlDef_T(conf_mapButtonAttrDef, null)},
				{ "skillbutton", new CtrlDef_T(conf_mapSkillButtonAttrDef, null)},
				{ "progress", new CtrlDef_T(conf_mapProgressAttrDef, null)},
				{ "radio", new CtrlDef_T(conf_mapRadioAttrDef, null)},
				{ "check", new CtrlDef_T(conf_mapCheckAttrDef, null)},
				{ "listPanel", new CtrlDef_T(conf_mapListPanelAttrDef, null)},
				{ "tabPanel", new CtrlDef_T(conf_mapTabPanelAttrDef, null)},
				{ "pagePanel", new CtrlDef_T(conf_mapPagePanelAttrDef, null)},
				{ "virtualpad", new CtrlDef_T(conf_mapVirtualPadAttrDef, null)},
				{ "richText", new CtrlDef_T(conf_mapRichTextAttrDef, null)},
				{ "pageText", new CtrlDef_T(conf_mapPageTextAttrDef, null)},
				{ "scriptPanel", new CtrlDef_T(conf_mapScriptPanelAttrDef, null)},
				{ "countDown", new CtrlDef_T(conf_mapCountDownAttrDef, null)},
				{ "apartPanel", new CtrlDef_T(conf_mapApartPanelAttrDef, null)},
				{ "draggedPanel", new CtrlDef_T(conf_mapDraggedPanelAttrDef, null)},
				{ "turnTable", new CtrlDef_T(conf_mapTurnTableAttrDef, null)},
				{ "drawModel", new CtrlDef_T(conf_mapDrawModelAttrDef, null)},
				{ "dropList", new CtrlDef_T(conf_mapDropListAttrDef, null)},
				{ "event", new CtrlDef_T(conf_mapEventAttrDef, null)},
				{ "tooltip", new CtrlDef_T(conf_mapToolTipAttrDef, null)}
				#endregion
			};

			foreach(KeyValuePair<string, CtrlDef_T> pairCtrlDef in m_mapCtrlDef.ToList())
			{
				mx_toolArea.Children.Add(m_mapCtrlDef[pairCtrlDef.Key].m_attrListUI = new AttrList(pairCtrlDef.Key));
				m_mapCtrlDef[pairCtrlDef.Key].m_attrListUI.Visibility = Visibility.Collapsed;
			}
		}

		public void hiddenAllAttr()
		{
			if (m_otherAttrList != null)
			{
				mx_toolArea.Children.Remove(m_otherAttrList);
				m_otherAttrList = null;
			}
			foreach(AttrList attrList in mx_toolArea.Children)
			{
				attrList.Visibility = Visibility.Collapsed;
			}
		}
		#endregion

		private void mx_bClearDebug_Click(object sender, RoutedEventArgs e)
		{
			mx_debug.Text = "";
		}

		private void mx_debug_TextChanged(object sender, TextChangedEventArgs e)
		{
			mx_debug.ScrollToEnd();
		}
	}
}

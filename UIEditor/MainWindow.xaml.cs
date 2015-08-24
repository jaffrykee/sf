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
using System.Text.RegularExpressions;

namespace UIEditor
{
	#region 通讯结构
	public enum W2GTag
	{
		W2G_PATH = 0x0000,
		W2G_NORMAL_NAME = 0x0001,
		W2G_NORMAL_DATA = 0x0011,
		W2G_NORMAL_UPDATE = 0x0021,
		W2G_NORMAL_TURN = 0x0101,
		W2G_SKIN_NAME = 0x0002,
		W2G_SKIN_DATA = 0x0012,
		W2G_SELECT_UI = 0x0003,
		W2G_UI_VRECT = 0x0004,
		W2G_DRAWRECT = 0x0014,
		W2G_VIEWMODE = 0x0005
	};
	public enum G2WTag
	{
		G2W_HWND = 0x0000,
		G2W_EVENT = 0x0003,
		G2W_UI_VRECT = 0x0004,
	};
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
	public struct COPYDATASTRUCT
	{
		public IntPtr dwData;
		public int cbData;
		[MarshalAs(UnmanagedType.LPStr)]
		public IntPtr lpData;
	}
	#endregion

	#region 皮肤属性文本
	public enum ApprSuf
	{
		NORMAL = 0,					//正常状态
		PRESSED = 1,				//按下状态
		DISABLED = 2,				//禁用状态
		CHECKED_NORMAL = 3,			//选中 - 正常状态
		CHECKED_PRESSED = 4,		//选中 - 按下状态
		CHECKED_DISABLED = 5,		//选中 - 禁用状态
		NORMAL_BORDER = 6,			//正常边框
		NORMAL_FILLED = 7,			//正常填充
		NORMAL_BACKGROUND = 8,		//正常背景
		NORMAL_FILLEDHEAD = 9,		//正常填充头
		NORMAL_FILLEDTAIL = 10,		//正常填充尾
		SELECT = 11,				//选中
		NORMAL_FILLEDSLIDER = 12,	//正常填充滑块
		TIPS = 13,					//tips
		MESSAGE_TIPS_NORMAL = 14,	//消息提示正常
		MESSAGE_TIPS_LIGHT = 15,	//消息提示亮
		NORMAL_PRE_GROWTH = 16,		//预增长
		KEYSELECT_NOMAL = 17,		//按键选中
		KEYSELECT_CHECK = 18,		//按键选中 - 选中
		MAX
	};
	#endregion

	public partial class MainWindow : Window
	{
		public static MainWindow s_pW;

		public string m_skinPath;
		public string m_projPath;
		public string m_projName;
		public XmlDocument m_docProj;
		public Dictionary<string, OpenedFile> m_mapOpenedFiles;
		public Dictionary<string, XmlDocument> m_mapStrSkinGroup;
		public Dictionary<string, XmlElement> m_mapStrSkin;

		public Dictionary<string, CtrlDef_T> m_mapCtrlDef;
		public Dictionary<string, CtrlDef_T> m_mapPanelCtrlDef;
		public Dictionary<string, CtrlDef_T> m_mapBasicCtrlDef;
		public Dictionary<string, CtrlDef_T> m_mapHasBasicCtrlDef;
		public Dictionary<string, CtrlDef_T> m_mapEnInsertCtrlDef;
		public Dictionary<string, CtrlDef_T> m_mapEnInsertAllCtrlDef;

		public Dictionary<string, SkinDef_T> m_mapSkinTreeDef;
		public Dictionary<string, SkinDef_T> m_mapSkinAllDef;
		public Dictionary<string, Dictionary<string, AttrDef_T>> m_mapSkinAttrDef;

		public Dictionary<XmlElement, BoloUI.SelButton> m_mapXeSel;
		public float m_dpiSysX;
		public float m_dpiSysY;
		public IntPtr m_hwndGLFrame;
		public IntPtr m_hwndGLParent;
		public IntPtr m_hwndGL;
		public AttrList m_otherAttrList;
		public bool m_vCtrlName;
		public bool m_vCtrlId;

		public XmlDocument m_xdTest;
		public XmlElement m_xeTest;
		public string m_strTestXml;

		public string m_curFile;	//todo
		public XmlItem m_curItem;

		public XmlElement m_xePaste;

		public bool m_isMouseDown;
		public bool m_isCtrlMoved;
		public int m_downX;
		public int m_downY;
		public string m_pasteFilePath;
		public StringDic m_strDic;

		ControlHost mx_GLHost;
		public string m_curLang;

		public const string conf_pathGlApp = @".\dsuieditor.exe";
		public const string conf_pathConf = @".\conf.xml";
		public const string conf_pathPlugInBoloUI = @".\data\PlugIn\BoloUI\";
		public const string conf_pathStringDic = @".\data\Lang\";
		public XmlDocument m_docConf;
		public bool m_isDebug;

		public MainWindow()
		{
			s_pW = this;
			m_skinPath = "";
			m_projPath = "";
			m_hwndGL = IntPtr.Zero;
			m_hwndGLParent = IntPtr.Zero;
			m_mapOpenedFiles = new Dictionary<string, OpenedFile>();
			m_strDic = new StringDic("zh-CN", conf_pathStringDic);
			InitializeComponent();
			m_mapStrSkinGroup = new Dictionary<string, XmlDocument>();
			m_mapStrSkin = new Dictionary<string, XmlElement>();
			m_mapSkinAllDef = new Dictionary<string, SkinDef_T>();
			m_dpiSysX = 96.0f;
			m_dpiSysY = 96.0f;
			m_curFile = "";
			m_vCtrlName = true;
			m_vCtrlId = true;
			m_xePaste = null;
			m_mapXeSel = new Dictionary<XmlElement, BoloUI.SelButton>();

			m_xdTest = new XmlDocument();
			// w=\"400\" h=\"300\"
			m_strTestXml = "<label w=\"960\" h=\"640\" baseID=\"testCtrl\" text=\"测试Test\"/>";

			m_xdTest.LoadXml(m_strTestXml);
			m_xeTest = m_xdTest.DocumentElement;

			m_docConf = new XmlDocument();
			if(!File.Exists(conf_pathConf))
			{
				string initConfXml = "<Config><runMode>release</runMode><ProjHistory>E:\\mmo2013001\\artist\\client_resouce\\ui\\free</ProjHistory></Config>";

				m_docConf.LoadXml(initConfXml);
				m_docConf.Save(conf_pathConf);
			}
			else
			{
				m_docConf.Load(conf_pathConf);
			}

			if (m_docConf.SelectSingleNode("Config").SelectSingleNode("runMode") != null)
			{
				if (m_docConf.SelectSingleNode("Config").SelectSingleNode("runMode").InnerXml == "debug")
				{
					m_isDebug = true;
				}
				else
				{
					m_isDebug = false;
				}
			}
			else
			{
				XmlElement xe = m_docConf.CreateElement("runMode");

				xe.InnerXml = "release";
				m_docConf.SelectSingleNode("Config").AppendChild(xe);
				m_docConf.Save(conf_pathConf);

				m_isDebug = false;
			}

			// hook keyboard
			IntPtr hModule = GetModuleHandle(IntPtr.Zero);
			hookProc = new LowLevelKeyboardProcDelegate(LowLevelKeyboardProc);
			hHook = SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, hModule, 0);
			if (hHook == IntPtr.Zero)
			{
				MessageBox.Show("Failed to set hook, error = " + Marshal.GetLastWin32Error());
			}
		}
		private void mx_root_Loaded(object sender, RoutedEventArgs e)
		{

			HwndSource source = PresentationSource.FromVisual(this) as HwndSource;

			if (source != null)
			{
				source.AddHook(WndProc);
			}
			mx_GLHost = new ControlHost();
			mx_GLCtrl.Child = mx_GLHost;
			mx_GLHost.MessageHook += new HwndSourceHook(ControlMsgFilter);
			if (m_isDebug)
			{
				mx_debugTools.Visibility = System.Windows.Visibility.Visible;
			}
			else
			{
				mx_debugTools.Visibility = System.Windows.Visibility.Collapsed;
			}
			mx_drawFrame.Visibility = System.Windows.Visibility.Collapsed;
		}

		public void openProjByPath(string projPath, string projName)
		{
			m_projPath = projPath;
			m_projName = projName;

			if (System.IO.Path.GetExtension(m_projName) == ".ryrp")
			{
				m_projName = System.IO.Path.ChangeExtension(m_projName, ".bup");
				if (!File.Exists(m_projPath + "\\" + m_projName))
				{
					string initProjXml = "<BoloUIProj><template></template></BoloUIProj>";

					m_docProj = new XmlDocument();
					m_docProj.LoadXml(initProjXml);
					m_docProj.Save(m_projPath + "\\" + m_projName);
				}
				else
				{
					m_docProj = new XmlDocument();
					m_docProj.Load(m_projPath + "\\" + m_projName);
				}
			}
			else if (System.IO.Path.GetExtension(m_projName) == ".bup")
			{
				m_docProj = new XmlDocument();
				m_docProj.Load(m_projPath + "\\" + m_projName);
			}
			else
			{
				return;
			}

			m_docConf.SelectSingleNode("Config").SelectSingleNode("ProjHistory").InnerXml = m_projPath;
			m_docConf.Save(conf_pathConf);
			sendPathToGL(m_projPath);
			initXmlValueDef();
			//refreshImage(path + "\\images");
			m_skinPath = m_projPath + "\\skin";
			if (Directory.Exists(m_skinPath))
			{
				if (File.Exists(m_skinPath + "\\publicskin.xml"))
				{
					refreshSkin(m_skinPath);
				}
				refreshProjTree(m_projPath, this.mx_treePro, true);
				mx_root.Title = m_projPath + "\\" + m_projName + " - UI编辑器";
				mx_toolNew.IsEnabled = true;
			}
			else
			{
				MessageBox.Show(
					"没有找到皮肤目录：" + m_skinPath + "，请检查项目路径。",
					m_projPath + "\\" + m_projName + " - UI编辑器",
					MessageBoxButton.OK,
					MessageBoxImage.Error
				);
			}
		}
		public void openProjSelectBox(string projPath = null)
		{
			if(projPath == null)
			{
				projPath = m_docConf.SelectSingleNode("Config").SelectSingleNode("ProjHistory").InnerXml;
			}

			System.Windows.Forms.OpenFileDialog openFileDialog = new System.Windows.Forms.OpenFileDialog();
			openFileDialog.Title = "选择BoloUI工程文件";
			openFileDialog.Filter = "BoloUI工程文件|*.bup|BoloUI工程文件(旧)|*.ryrp";
			openFileDialog.FileName = string.Empty;
			openFileDialog.FilterIndex = 1;
			openFileDialog.RestoreDirectory = true;
			openFileDialog.DefaultExt = "bup";
			openFileDialog.InitialDirectory = projPath;
			System.Windows.Forms.DialogResult result = openFileDialog.ShowDialog();
			if (result == System.Windows.Forms.DialogResult.Cancel)
			{
				return;
			}
			openProjByPath(System.IO.Path.GetDirectoryName(openFileDialog.FileName), System.IO.Path.GetFileName(openFileDialog.FileName));
		}
		private void openProj(object sender, RoutedEventArgs e)//打开工程
		{
			openProjSelectBox();
		}
		private void sendPathToGL(string path)//告知GL端工程根目录
		{
			updateGL(path, W2GTag.W2G_PATH);
		}
		private void refreshSkin(string path)
		{
			XmlDocument xmlDoc = new XmlDocument();
			xmlDoc.Load(path + "\\publicskin.xml");
			XmlNode xn = xmlDoc.SelectSingleNode("BoloUI");

			if (xn != null)
			{
				string buffer = xmlDoc.InnerXml;
				updateGL("publicskin.xml", W2GTag.W2G_SKIN_NAME);
				updateGL(buffer, W2GTag.W2G_SKIN_DATA);
			}
		}
		public void refreshProjTree(string path, TreeViewItem rootItem, bool rootNode)
		{
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

				refreshProjTree(path + "\\" + dri.Name, treeUIChild, false);
			}
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
				rootItem.IsExpanded = true;
				rootItem.Header = "UI工程目录(" + i + "个目录和" + j + "个项目)";
			}
		}

		public void openFileByPath(string path)
		{
			OpenedFile openedFile;
			string fileType = StringDic.getFileType(path);

			if (m_mapOpenedFiles.TryGetValue(path, out openedFile))
			{
				mx_workTabs.SelectedItem = openedFile.m_tab;
			}
			else
			{
				if (File.Exists(path))
				{
					m_curFile = path;
					m_mapOpenedFiles[path] = new OpenedFile(path);
				}
				else
				{
					//不存在
					mx_debug.Text += "<错误>文件：\"" + path + "\"不存在，请检查路径。\r\n";
				}
			}
		}
		private void openFileTab(object sender, MouseEventArgs e)
		{
			TreeViewItem fileItem = (TreeViewItem)sender;
			string tabPath = ((ToolTip)fileItem.ToolTip).Content.ToString();

			openFileByPath(tabPath);
		}
		public void eventCloseFile(object sender, RoutedEventArgs e)
		{
			if(m_mapOpenedFiles.Count == 0)
			{
				m_curItem = null;
				hiddenGLAttr();
			}
		}
		public void hiddenGLAttr()
		{
			foreach (object attrList in mx_toolArea.Children)
			{
				if (attrList.GetType().ToString() == "UIEditor.AttrList")
				{
					((UIEditor.AttrList)attrList).Visibility = System.Windows.Visibility.Collapsed;
				}
			}
			mx_drawFrame.Visibility = System.Windows.Visibility.Collapsed;
			mx_ctrlFrame.IsEnabled = false;
			mx_skinFrame.IsEnabled = false;
			mx_leftToolFrame.SelectedItem = mx_proFrame;
		}
		private void mx_workTabs_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			m_curItem = null;
			mx_treeCtrlFrame.Items.Clear();
			mx_treeSkinFrame.Items.Clear();
			if (((TabItem)mx_workTabs.SelectedItem) != null)
			{
				if (((ToolTip)((TabItem)mx_workTabs.SelectedItem).ToolTip) != null)
				{
					string tabPath = ((ToolTip)((TabItem)mx_workTabs.SelectedItem).ToolTip).Content.ToString();
					string fileType = StringDic.getFileType(tabPath);

					m_curFile = tabPath;
					if (fileType == "xml")
					{
						string fileName = StringDic.getFileNameWithoutPath(tabPath);

						OpenedFile openFile;
						if (m_mapOpenedFiles.TryGetValue(tabPath, out openFile))
						{
							updateGL(fileName, W2GTag.W2G_NORMAL_TURN);
							mx_treeCtrlFrame.Items.Add(((XmlControl)m_mapOpenedFiles[tabPath].m_frame).m_treeUI);
							mx_treeSkinFrame.Items.Add(((XmlControl)m_mapOpenedFiles[tabPath].m_frame).m_treeSkin);
							((XmlControl)openFile.m_frame).refreshBoloUIView(true);
							if (((XmlControl)openFile.m_frame).m_showGL)
							{
								mx_drawFrame.Visibility = System.Windows.Visibility.Visible;
							}
							else
							{
								hiddenGLAttr();
							}
						}
					}
					else
					{
						hiddenGLAttr();
					}
				}
			}
		}
		private void mx_root_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			List<OpenedFile> lstChangedFiles = new List<OpenedFile>();
			string strMsg = "是否将更改保存到：\r\n";

			foreach (KeyValuePair<string, OpenedFile> pairFile in m_mapOpenedFiles.ToList())
			{
				if (pairFile.Value != null)
				{
					if (pairFile.Value.haveDiffToFile())
					{
						lstChangedFiles.Add(pairFile.Value);
						strMsg += pairFile.Value.m_path + "\r\n";
					}
				}
			}
			if (lstChangedFiles != null && lstChangedFiles.Count > 0)
			{

				MessageBoxResult ret = MessageBox.Show(strMsg, "保存确认", MessageBoxButton.YesNoCancel, MessageBoxImage.Asterisk);
				switch (ret)
				{
					case MessageBoxResult.Yes:
						{
							foreach (OpenedFile fileDef in lstChangedFiles)
							{
								((XmlControl)fileDef.m_frame).m_xmlDoc.Save(fileDef.m_path);
								fileDef.m_lstOpt.m_saveNode = fileDef.m_lstOpt.m_curNode;
								fileDef.updateSaveStatus();
							}
						}
						break;
					case MessageBoxResult.No:
						break;
					case MessageBoxResult.Cancel:
					default:
						e.Cancel = true;
						return;
				}
			}

			UnhookWindowsHookEx(hHook); // release keyboard hook
		}

		//============================================================

		#region WIN32消息相关

		#region WIN32预定义
		internal const int
			WM_DESTROY = 0x0002,
			WM_CLOSE = 0x0010,
			WM_QUIT = 0x0012,
			WM_COPYDATA = 0x004A,
			WM_COMMAND = 0x0111,

			WM_KEYDOWN = 0x0100,

			WM_MOUSEFIRST = 0x0200,
			WM_MOUSEMOVE = 0x0200,
			WM_LBUTTONDOWN = 0x0201,
			WM_LBUTTONUP = 0x0202,
			WM_LBUTTONDBLCLK = 0x0203,
			WM_RBUTTONDOWN = 0x0204,
			WM_RBUTTONUP = 0x0205,
			WM_RBUTTONDBLCLK = 0x0206,
			WM_MBUTTONDOWN = 0x0207,
			WM_MBUTTONUP = 0x0208,
			WM_MBUTTONDBLCLK = 0x0209,

			LBN_SELCHANGE = 0x0001,
			LB_GETCURSEL = 0x0188,
			LB_GETTEXTLEN = 0x018A,
			LB_ADDSTRING = 0x0180,
			LB_GETTEXT = 0x0189,
			LB_DELETESTRING = 0x0182,
			LB_GETCOUNT = 0x018B,

			VK_PRIOR = 0x21,
			VK_NEXT = 0x22,
			VK_LEFT = 0x25,
			VK_UP = 0x26,
			VK_RIGHT = 0x27,
			VK_DOWN = 0x28,
			VK_DELETE = 0x2E,

			VK_OEM_PLUS = 0xBB,
			VK_OEM_MINUS = 0xBD,

			VK_A = 0x41,
			VK_B = 0x42,
			VK_C = 0x43,
			VK_D = 0x44,
			VK_E = 0x45,
			VK_F = 0x46,
			VK_G = 0x47,
			VK_H = 0x48,
			VK_I = 0x49,
			VK_J = 0x4A,
			VK_K = 0x4B,
			VK_L = 0x4C,
			VK_M = 0x4D,
			VK_N = 0x4E,
			VK_O = 0x4F,
			VK_P = 0x50,
			VK_Q = 0x51,
			VK_R = 0x52,
			VK_S = 0x53,
			VK_T = 0x54,
			VK_U = 0x55,
			VK_V = 0x56,
			VK_W = 0x57,
			VK_X = 0x58,
			VK_Y = 0x59,
			VK_Z = 0x5A,

			//WM_NCHITTEST消息处理返回值
			HTERROR = -2,
			HTTRANSPARENT = -1,
			HTNOWHERE = 0,
			HTCLIENT = 1,
			HTCAPTION = 2,
			HTSYSMENU = 3,
			HTGROWBOX = 4,
			HTSIZE = HTGROWBOX,
			HTMENU = 5,
			HTHSCROLL = 6,
			HTVSCROLL = 7,
			HTMINBUTTON = 8,
			HTMAXBUTTON = 9,
			HTLEFT = 10,
			HTRIGHT = 11,
			HTTOP = 12,
			HTTOPLEFT = 13,
			HTTOPRIGHT = 14,
			HTBOTTOM = 15,
			HTBOTTOMLEFT = 16,
			HTBOTTOMRIGHT = 17,
			HTBORDER = 18,
			HTREDUCE = HTMINBUTTON,
			HTZOOM = HTMAXBUTTON,
			HTSIZEFIRST = HTLEFT,
			HTSIZELAST = HTBOTTOMRIGHT,
			HTOBJECT = 19,
			HTCLOSE = 20,
			HTHELP = 21;
		#endregion

		#region SendMessage函数接口
		[DllImport("gdi32")]
		public static extern int DeleteObject(IntPtr o);

		[DllImport("user32.dll", EntryPoint = "SendMessage", CharSet = CharSet.Unicode)]
		internal static extern int SendMessage(
			IntPtr hwnd,
			int msg,
			IntPtr wParam,
			IntPtr lParam);

		[DllImport("user32.dll", EntryPoint = "SendMessage", CharSet = CharSet.Unicode)]
		internal static extern int SendMessage(
			IntPtr hwnd,
			int msg,
			int wParam,
			[MarshalAs(UnmanagedType.LPWStr)] StringBuilder lParam);

		[DllImport("user32.dll", EntryPoint = "SendMessage", CharSet = CharSet.Unicode)]
		internal static extern IntPtr SendMessage(
			IntPtr hwnd,
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
		#endregion

		#endregion

		private struct KBDLLHOOKSTRUCT
		{
			public int vkCode;
			int scanCode;
			public int flags;
			int time;
			int dwExtraInfo;
		}

		private delegate int LowLevelKeyboardProcDelegate(int nCode, int wParam, ref KBDLLHOOKSTRUCT lParam);
		[DllImport("user32.dll")]
		private static extern IntPtr SetWindowsHookEx(int idHook, LowLevelKeyboardProcDelegate lpfn, IntPtr hMod, int dwThreadId);
		[DllImport("user32.dll")]
		private static extern bool UnhookWindowsHookEx(IntPtr hHook);
		[DllImport("user32.dll")]
		private static extern int CallNextHookEx(int hHook, int nCode, int wParam, ref KBDLLHOOKSTRUCT lParam);
		[DllImport("kernel32.dll")]
		private static extern IntPtr GetModuleHandle(IntPtr path);

		private IntPtr hHook;
		LowLevelKeyboardProcDelegate hookProc; // prevent gc
		const int WH_KEYBOARD_LL = 13;

		public void updateGL(string buffer, W2GTag msgTag = W2GTag.W2G_NORMAL_DATA)
		{
			if (mx_hwndDebug.Text != "")
			{
				m_hwndGL = (IntPtr)long.Parse(mx_hwndDebug.Text);
			}
			unsafe
			{
				int len;
				byte[] charArr;
				COPYDATASTRUCT_SENDEX msgData;

				if (msgTag == W2GTag.W2G_PATH)
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
					if(len != 0)
					{
						msgData.lpData = (IntPtr)tmpBuff;
					}
					else
					{
						msgData.lpData = (IntPtr)0;
					}
					msgData.cbData = len + 1;
					SendMessage(m_hwndGL, WM_COPYDATA, (int)m_hwndGLParent, ref msgData);
				}
			}
		}
		private IntPtr ControlMsgFilter(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)//响应主逻辑
		{
			handled = false;
			switch (msg)
			{
				case WM_MOUSEMOVE:
					#region WM_MOUSEMOVE
					{
						if ((System.Windows.Forms.Control.ModifierKeys & System.Windows.Forms.Keys.Control) == System.Windows.Forms.Keys.Control)
						{
							if (m_isMouseDown)
							{
								int pX = (int)lParam & 0xFFFF;
								int pY = ((int)lParam >> 16) & 0xFFFF;

								if (m_isCtrlMoved == false)
								{
									if (System.Math.Abs(pX - m_downX) > 10 || System.Math.Abs(pY - m_downY) > 10)
									{
										m_isCtrlMoved = true;
									}
								}
								else
								{
									if (m_curItem != null && m_curItem.m_type == "CtrlUI")
									{
										BoloUI.Basic selItem = (BoloUI.Basic)m_curItem;
										string msgData;

										msgData = (selItem.m_selX + (pX - m_downX)).ToString() + ":" + (selItem.m_selY + (pY - m_downY)).ToString() + ":" + 
											selItem.m_selW.ToString() + ":" + selItem.m_selH.ToString() + ":";
										updateGL(msgData, W2GTag.W2G_DRAWRECT);
									}
								}
							}
						}
					}
					#endregion
					break;
				case WM_LBUTTONDOWN:
					#region WM_LBUTTONDOWN
					{
						if (m_curFile != null && m_curFile != "")
						{
							OpenedFile fileDef;

							if(m_mapOpenedFiles.TryGetValue(m_curFile, out fileDef))
							{
								if(fileDef.m_frame.GetType().ToString() == "UIEditor.XmlControl")
								{
									((XmlControl)fileDef.m_frame).refreshVRect();
								}
							}
						}
						int pX = (int)lParam & 0xFFFF;
						int pY = ((int)lParam >> 16) & 0xFFFF;

						m_isMouseDown = true;
						m_isCtrlMoved = false;
						m_downX = pX;
						m_downY = pY;
					}
					#endregion
					break;
				case WM_LBUTTONUP:
					#region WM_LBUTTONUP
					{
						if(m_isMouseDown == true)
						{
							int pX = (int)lParam & 0xFFFF;
							int pY = ((int)lParam >> 16) & 0xFFFF;
							if(m_isCtrlMoved == false)
							{
								List<BoloUI.Basic> lstSelCtrl = new List<BoloUI.Basic>();
								BoloUI.Basic selCtrl = null;
								BoloUI.Basic lastCtrl = null;

								mx_selCtrlLstFrame.Children.Clear();
								m_mapXeSel.Clear();
								foreach (KeyValuePair<string, BoloUI.Basic> pairCtrlDef in
									((XmlControl)m_mapOpenedFiles[m_curFile].m_frame).m_mapCtrlUI.ToList())
								{
									if (pairCtrlDef.Value.checkPointInFence(pX, pY))
									{
										lstSelCtrl.Add(pairCtrlDef.Value);
										if (m_curItem == pairCtrlDef.Value)
										{
											selCtrl = lastCtrl;
										}
										lastCtrl = pairCtrlDef.Value;

										BoloUI.SelButton selCtrlButton = new BoloUI.SelButton(this, pairCtrlDef.Value);
										selCtrlButton.mx_radio.Content = pairCtrlDef.Value.mx_radio.Content;
										mx_selCtrlLstFrame.Children.Add(selCtrlButton);
										m_mapXeSel.Add(pairCtrlDef.Value.m_xe, selCtrlButton);
									}
								}
								if (lstSelCtrl.Count > 0)
								{
									if (selCtrl == null)
									{
										selCtrl = lstSelCtrl.Last();
									}
									selCtrl.changeSelectItem();
								}
							}
							else
							{
								if ((System.Windows.Forms.Control.ModifierKeys & System.Windows.Forms.Keys.Control) ==
									System.Windows.Forms.Keys.Control)
								{
									if (m_curItem != null && m_curItem.m_type == "CtrlUI")
									{
										BoloUI.Basic selItem = (BoloUI.Basic)m_curItem;
										int x, y;

										if (selItem.m_xe.GetAttribute("x") == "")
										{
											x = 0;
										}
										else
										{
											x = int.Parse(selItem.m_xe.GetAttribute("x"));
										}
										x += pX - m_downX;
										selItem.m_rootControl.m_openedFile.m_lstOpt.addOperation(
											new XmlOperation.HistoryNode(selItem.m_xe, "x", selItem.m_xe.GetAttribute("x"), x.ToString())
											);
										if (selItem.m_xe.GetAttribute("y") == "")
										{
											y = 0;
										}
										else
										{
											y = int.Parse(selItem.m_xe.GetAttribute("y"));
										}
										y += pY - m_downY;
										selItem.m_rootControl.m_openedFile.m_lstOpt.addOperation(
											new XmlOperation.HistoryNode(selItem.m_xe, "y", selItem.m_xe.GetAttribute("y"), y.ToString())
											);
										selItem.changeSelectItem();
									}
								}
							}
						}
						m_isMouseDown = false;
						m_isCtrlMoved = false;
					}
					#endregion
					break;
				case WM_LBUTTONDBLCLK:
					break;
				case WM_RBUTTONDOWN:
					break;
				case WM_RBUTTONUP:
					break;
				case WM_RBUTTONDBLCLK:
					break;
				case WM_MBUTTONDOWN:
					break;
				case WM_MBUTTONUP:
					break;
				case WM_MBUTTONDBLCLK:
					break;
				case WM_COPYDATA:
					#region WM_COPYDATA
					unsafe
					{
						COPYDATASTRUCT msgData = *(COPYDATASTRUCT*)lParam;
						string strData = Marshal.PtrToStringAnsi(msgData.lpData, msgData.cbData);
						switch ((G2WTag)((COPYDATASTRUCT*)lParam)->dwData)
						{
							case G2WTag.G2W_HWND:
								m_hwndGL = wParam;
								break;
							case G2WTag.G2W_EVENT:
								{
									string[] sArray = Regex.Split(strData, ":", RegexOptions.IgnoreCase);
									if (sArray.Length >= 2)
									{
										string id = sArray[0];
										string ent = sArray[1];

										switch(ent)
										{
											case "click":
												BoloUI.Basic tmpCtrl;
												if (((XmlControl)m_mapOpenedFiles[m_curFile].m_frame).m_mapCtrlUI.TryGetValue(id, out tmpCtrl))
												{
													tmpCtrl.changeSelectItem();
													tmpCtrl.IsSelected = true;
												}
												break;
											default:
												break;
										}
									}
								}
								break;
							case G2WTag.G2W_UI_VRECT:
								{
									string[] sArray = Regex.Split(strData, ":", RegexOptions.IgnoreCase);
									for(int i = 5; i < sArray.Length; i+=5)
									{
										string baseId = sArray[i - 5];
										BoloUI.Basic curCtrl = ((XmlControl)m_mapOpenedFiles[m_curFile].m_frame).m_mapCtrlUI[baseId];
										curCtrl.m_selX = int.Parse(sArray[i - 4]);
										curCtrl.m_selY = int.Parse(sArray[i - 3]);
										curCtrl.m_selW = int.Parse(sArray[i - 2]);
										curCtrl.m_selH = int.Parse(sArray[i - 1]);
									}
								}
								break;
							default:
								break;
						}
					}
					#endregion
					break;
				default:
					break;
			}

			return IntPtr.Zero;
		}
		private static int LowLevelKeyboardProc(int nCode, int wParam, ref KBDLLHOOKSTRUCT lParam)//底层相应，用于屏蔽系统和WPF控件默认事件
		{
			if (nCode >= 0)
				switch (wParam)
				{
					case WM_KEYDOWN:
						if (s_pW != null)
						{
							if ((System.Windows.Forms.Control.ModifierKeys & System.Windows.Forms.Keys.Control) == System.Windows.Forms.Keys.Control)
							{
								switch (lParam.vkCode)
								{
									case VK_PRIOR:
										viewPrevFile(s_pW);
										return 1;
									case VK_NEXT:
										viewNextFile(s_pW);
										return 1;
									case VK_UP:
										if (s_pW.m_curItem != null)
										{
											if (s_pW.m_curItem.canMoveUp())
											{
												s_pW.m_curItem.moveUpItem();
											}
										}
										return 1;
									case VK_DOWN:
										if (s_pW.m_curItem != null)
										{
											if (s_pW.m_curItem.canMoveDown())
											{
												s_pW.m_curItem.moveDownItem();
											}
										}
										return 1;
									case VK_Y:
										s_pW.curFileRedo();
										if (Keyboard.FocusedElement.GetType().ToString() == "System.Windows.Controls.TextBox")
										{
											TextBox tb = (TextBox)Keyboard.FocusedElement;

											tb.SelectionStart = tb.Text.Length;
										}
										return 1;
									case VK_Z:
										s_pW.curFileUndo();
										if (Keyboard.FocusedElement.GetType().ToString() == "System.Windows.Controls.TextBox")
										{
											TextBox tb = (TextBox)Keyboard.FocusedElement;

											tb.SelectionStart = tb.Text.Length;
										}
										return 1;
									default:
										break;
								}
							}
						}
						break;
				}
			return CallNextHookEx(0, nCode, wParam, ref lParam);
		}
		private IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)//根窗体消息响应
		{
			switch (msg)
			{
				case WM_COPYDATA:
					break;
				case WM_CLOSE:
					//因为有保存确认，这里不向GL端发送关闭消息。
					//SendMessage(m_hwndGL, WM_QUIT, m_hwndGLParent, IntPtr.Zero);
					break;
				case WM_QUIT:
					//规避GL端报错窗口，因为也没有什么要保存的。
					if (!mx_GLHost.m_process.HasExited)
					{
						mx_GLHost.m_process.Kill();
					}
					break;
				case WM_DESTROY:
					if (!mx_GLHost.m_process.HasExited)
					{
						mx_GLHost.m_process.Kill();
					}
					break;
				case WM_KEYDOWN:
					#region WM_KEYDOWN
					if (m_curItem != null)
					{
						if ((System.Windows.Forms.Control.ModifierKeys & System.Windows.Forms.Keys.Control) == System.Windows.Forms.Keys.Control)
						{
							switch ((int)wParam)
							{
								case VK_X:
									if (m_curItem.canCut())
									{
										m_curItem.cutItem();
									}
									break;
								case VK_C:
									//需要简化下
									if
									(
										(
											(
												Keyboard.FocusedElement.GetType().ToString() == "System.Windows.Controls.TreeViewItem" ||
												Keyboard.FocusedElement.GetType().BaseType.ToString() == "System.Windows.Controls.TreeViewItem"
											)
										) &&
										((TreeViewItem)Keyboard.FocusedElement).Parent != null &&
										(
											((TreeViewItem)Keyboard.FocusedElement).Parent == mx_treePro ||
											(
												(
													((TreeViewItem)Keyboard.FocusedElement).Parent.GetType().ToString() == "System.Windows.Controls.TreeViewItem" ||
													((TreeViewItem)Keyboard.FocusedElement).Parent.GetType().BaseType.ToString() == "System.Windows.Controls.TreeViewItem"
												) &&
												((TreeViewItem)((TreeViewItem)Keyboard.FocusedElement).Parent).Parent != null &&
												((TreeViewItem)((TreeViewItem)Keyboard.FocusedElement).Parent).Parent == mx_treePro
											)
										)
									)
									{
										m_pasteFilePath = ((TreeViewItem)Keyboard.FocusedElement).ToolTip.ToString();
									}
									else
									{
										if (m_curItem.canCopy())
										{
											m_curItem.copyItem();
										}
									}
									break;
								case VK_V:
									//需要简化下
									if
									(
										(
											(
												Keyboard.FocusedElement.GetType().ToString() == "System.Windows.Controls.TreeViewItem" ||
												Keyboard.FocusedElement.GetType().BaseType.ToString() == "System.Windows.Controls.TreeViewItem"
											)
										) &&
										((TreeViewItem)Keyboard.FocusedElement).Parent != null &&
										(
											((TreeViewItem)Keyboard.FocusedElement).Parent == mx_treePro ||
											(
												(
													((TreeViewItem)Keyboard.FocusedElement).Parent.GetType().ToString() == "System.Windows.Controls.TreeViewItem" ||
													((TreeViewItem)Keyboard.FocusedElement).Parent.GetType().BaseType.ToString() == "System.Windows.Controls.TreeViewItem"
												) &&
												((TreeViewItem)((TreeViewItem)Keyboard.FocusedElement).Parent).Parent != null &&
												((TreeViewItem)((TreeViewItem)Keyboard.FocusedElement).Parent).Parent == mx_treePro
											)
										)
									)
									{
										if (m_pasteFilePath != null && m_pasteFilePath != "")
										{
											
										}
									}
									else
									{
										if (m_curItem.canPaste())
										{
											m_curItem.pasteItem();
										}
									}
									break;
								case VK_DELETE:
									if (m_curItem.canDelete())
									{
										m_curItem.deleteItem();
									}
									break;
								default:
									break;
							}
						}
						switch ((int)wParam)
						{
							case VK_DELETE:
								if (m_curItem.canDelete())
								{
									m_curItem.deleteItem();
								}
								break;
						}
					}
					if ((System.Windows.Forms.Control.ModifierKeys & System.Windows.Forms.Keys.Control) == System.Windows.Forms.Keys.Control)
					{
						switch ((int)wParam)
						{
							case VK_W:
								{
									OpenedFile fileDef;

									if (s_pW.m_mapOpenedFiles.TryGetValue(s_pW.m_curFile, out fileDef) && fileDef != null && fileDef.m_tabItem != null)
									{
										fileDef.m_tabItem.closeFile();
									}
								}
								break;
							case VK_O:
								{
									openProjSelectBox();
								}
								break;
							default:
								break;
						}
					}
					#endregion
					break;
				default:
					break;
			}

			return hwnd;
		}
		public void addVidToMsgXml(XmlElement srcXe, XmlElement dstXe, XmlDocument dstDoc, XmlControl xmlCtrl)
		{
			foreach (XmlAttribute attr in srcXe.Attributes)
			{
				dstXe.SetAttribute(attr.Name, attr.Value);
			}
			foreach (XmlNode xn in srcXe.ChildNodes)
			{
				if(xn.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xn;
					XmlItem item;
					XmlElement newXe = dstDoc.CreateElement(xe.Name);

					addVidToMsgXml(xe, newXe, dstDoc, xmlCtrl);

					if(xmlCtrl.m_mapXeItem.TryGetValue(xe, out item))
					{
						if(item.GetType().ToString() == "UIEditor.BoloUI.Basic")
						{
							BoloUI.Basic uiCtrl = (BoloUI.Basic)item;

							if(uiCtrl.m_vId != null && uiCtrl.m_vId != "")
							{
								newXe.SetAttribute("baseID", uiCtrl.m_vId);
							}
						}
					}
					dstXe.AppendChild(newXe);
				}
			}
		}
		public void updateXmlToGL(XmlControl xmlCtrl, XmlElement xePlus = null, bool isCtrlUI = false)
		{
			string path = xmlCtrl.m_openedFile.m_path;
			XmlDocument doc = xmlCtrl.m_xmlDoc;
			XmlDocument newDoc = new XmlDocument();
			string fileName = StringDic.getFileNameWithoutPath(path);

			XmlElement newRootXe = newDoc.CreateElement(doc.DocumentElement.Name);
			addVidToMsgXml(doc.DocumentElement, newRootXe, newDoc, xmlCtrl);
			newDoc.AppendChild(newRootXe);

			XmlNodeList nodeList;

			if (xePlus != null)
			{
				if(isCtrlUI == false)
				{
					string strTmp = "<panel dock=\"4\" w=\"960\" h=\"640\" name=\"background\" skin=\"BackPure\"></panel>";

					XmlElement xeTmp = newDoc.CreateElement("tmp");
					xeTmp.InnerXml = strTmp;
					//xePlus.OuterXml
					xeTmp.FirstChild.InnerXml = xePlus.OuterXml;
					newRootXe.AppendChild(xeTmp.FirstChild);
				}
				else
				{
					XmlNode xn;
					XmlElement xe;

					for (xn = xePlus; xn.ParentNode != null && xn.ParentNode.NodeType == XmlNodeType.Element && xn.ParentNode.Name != "BoloUI"; xn = xn.ParentNode)
					{
						
					}
					if(xn.ParentNode != null && xn.ParentNode.NodeType == XmlNodeType.Element && xn.ParentNode.Name == "BoloUI")
					{
						xe = (XmlElement)xn;

						string strTmp = xe.OuterXml;

						XmlElement xeTmp = newDoc.CreateElement("tmp");
						xeTmp.InnerXml = strTmp;
						newRootXe.AppendChild(xeTmp.FirstChild);
					}
				}
			}
			//去掉所有事件(<event>)
			nodeList = newRootXe.SelectNodes("descendant::event");

			foreach(XmlNode xnEvent in nodeList)
			{
				xnEvent.ParentNode.RemoveChild(xnEvent);
			}

			string buffer = newDoc.InnerXml;
			updateGL(fileName, W2GTag.W2G_NORMAL_NAME);
			updateGL(buffer, W2GTag.W2G_NORMAL_DATA);
			xmlCtrl.refreshVRect();
		}
		private void addTmpEvent(XmlDocument doc, XmlElement xeParent)
		{
			XmlNodeList xnl = xeParent.ChildNodes;

			foreach (XmlNode xnf in xnl)
			{
				if (xnf.NodeType == XmlNodeType.Element)
				{
					XmlElement xe = (XmlElement)xnf;
					CtrlDef_T ctrlDef;

					if (xe.Name != "event")
					{
						if (m_mapCtrlDef.TryGetValue(xe.Name, out ctrlDef))
						{
							XmlElement elemEvent = doc.CreateElement("event");

							elemEvent.SetAttribute("function", "clickUI");
							//用于让GL端的UI相应事件的脚本
							elemEvent.SetAttribute("type", "onClick");
							xe.AppendChild(elemEvent);
							addTmpEvent(doc, xe);
						}
					}
				}
			}
		}

		#region 资源读取
		public class AttrDef_T
		{
			//右侧属性工具栏的UI
			public AttrRow m_attrRowUI;
			//数据类型
			public string m_type;
			//子类型
			public string m_subType;
			//默认值(废弃)
			public string m_defValue;
			//枚举
			public bool m_isEnum;
			//常用项
			public bool m_isCommon;
			//枚举列表
			public Dictionary<string, ComboBoxItem> m_mapEnum;

			public AttrDef_T(string type = "int", string defValue = null, AttrRow rowUI = null, bool isEnum = false, Dictionary<string, ComboBoxItem> mapEnum = null)
			{
				m_attrRowUI = rowUI;
				m_type = type;
				m_defValue = defValue;
				m_isEnum = isEnum;
				m_mapEnum = mapEnum;
			}
		}
		public class CtrlDef_T
		{
			public Dictionary<string, AttrDef_T> m_mapAttrDef;
			public AttrList m_attrListUI;
			public Dictionary<string, string> m_mapApprSuffix;
			public bool m_isFrame;
			public bool m_isBasic;
			public bool m_hasBasic;
			public bool m_enInsert;
			public bool m_enInsertAll;

			public CtrlDef_T(Dictionary<string, AttrDef_T> mapAttrDef, AttrList attrListUI, Dictionary<string, string> mapApprSuffix = null)
			{
				m_mapAttrDef = mapAttrDef;
				m_attrListUI = attrListUI;
				if (mapApprSuffix != null)
				{
					m_mapApprSuffix = mapApprSuffix;
				}
				else
				{
					m_mapApprSuffix = new Dictionary<string, string>();
				}
			}
		}
		public class SkinDef_T
		{
			public Dictionary<string, SkinDef_T> m_mapEnChild;
			public Dictionary<string, AttrDef_T> m_mapAttrDef;

			public SkinDef_T(Dictionary<string, SkinDef_T> mapChild, Dictionary<string, AttrDef_T> mapAttrDef)
			{
				m_mapEnChild = mapChild;
				m_mapAttrDef = mapAttrDef;
			}
		}
		public void initResMap(Dictionary<string, SkinDef_T> mapResDef)
		{
			foreach (KeyValuePair<string, SkinDef_T> pairSkinDef in mapResDef.ToList())
			{
				SkinDef_T skinDef;
				if (!m_mapSkinAllDef.TryGetValue(pairSkinDef.Key, out skinDef))
				{
					m_mapSkinAllDef.Add(pairSkinDef.Key, pairSkinDef.Value);
					if (pairSkinDef.Value.m_mapEnChild != null && pairSkinDef.Value.m_mapEnChild.Count > 0)
					{
						initResMap(pairSkinDef.Value.m_mapEnChild);
					}
				}
			}
		}
		void loadSkinApprSuf(XmlDocument docConf, Dictionary<string, string> mapStrDic, string ctrlName, Dictionary<string, string> mapSufStr)
		{

		}
		bool refreshSkinApprSuf()
		{
			string confPath = conf_pathPlugInBoloUI + @"SkinApprSuf.xml";
			XmlDocument docConf = new XmlDocument();

			docConf.Load(confPath);

			if(docConf.DocumentElement.Name == "SkinApprSuf")
			{
				XmlElement xeRoot = docConf.DocumentElement;

				foreach(XmlNode xnCtrl in xeRoot.ChildNodes)
				{
					if (xnCtrl.NodeType == XmlNodeType.Element)
					{
						XmlElement xeCtrl = (XmlElement)xnCtrl;

						if(xeCtrl.Name == "CtrlConf")
						{
							if(xeCtrl.GetAttribute("key") != "")
							{
								string ctrlKey = xeCtrl.GetAttribute("key");
								CtrlDef_T ctrlDef;

								if(m_mapCtrlDef.TryGetValue(ctrlKey, out ctrlDef))
								{
									ctrlDef.m_mapApprSuffix = new Dictionary<string, string>();
									foreach(XmlNode xnRow in xeCtrl.ChildNodes)
									{
										if(xnRow.NodeType == XmlNodeType.Element)
										{
											XmlElement xeRow = (XmlElement)xnRow;

											if(xeRow.Name == "intRow" && xeRow.InnerText != "")
											{
												ctrlDef.m_mapApprSuffix.Add(xeRow.InnerText, m_strDic.getWordByKey(xeRow.InnerText, "SkinApprSuf"));
											}
										}
									}
								}
							}
						}
					}
				}
			}

			return false;
		}
		public void addAttrConf(XmlElement xe, Dictionary<string, AttrDef_T> mapAttrDef)
		{
			foreach (XmlNode xnAttr in xe.ChildNodes)
			{
				if (xnAttr.NodeType == XmlNodeType.Element)
				{
					XmlElement xeAttr = (XmlElement)xnAttr;

					if (xeAttr.Name == "AttrDef")
					{
						string keyAttr = xeAttr.GetAttribute("key");

						if (keyAttr != "")
						{
							AttrDef_T attrDef;

							if (!mapAttrDef.TryGetValue(keyAttr, out attrDef))
							{
								attrDef = new AttrDef_T();
								if (xeAttr.GetAttribute("type") != "")
								{
									attrDef.m_type = xeAttr.GetAttribute("type");
								}
								else
								{
									attrDef.m_type = "string";
								}
								if (xeAttr.GetAttribute("isEnum") == "true")
								{
									attrDef.m_isEnum = true;
									attrDef.m_mapEnum = new Dictionary<string, ComboBoxItem>();
									foreach (XmlNode xnEnum in xeAttr.ChildNodes)
									{
										if (xnEnum.NodeType == XmlNodeType.Element)
										{
											XmlElement xeEnum = (XmlElement)xnEnum;

											if (xeEnum.Name == "row")
											{
												attrDef.m_mapEnum.Add(xeEnum.InnerText, null);
											}
										}
									}
								}
								else
								{
									attrDef.m_isEnum = false;
								}
								if (xeAttr.GetAttribute("isCommon") == "true")
								{
									attrDef.m_isCommon = true;
								}
								else
								{
									attrDef.m_isCommon = false;
								}
								attrDef.m_subType = xeAttr.GetAttribute("subType");
								mapAttrDef.Add(keyAttr, attrDef);
							}
						}
					}
				}
			}
		}
		public bool initCtrlDef()
		{
			string confPath = conf_pathPlugInBoloUI + @"CtrlAttrDef.xml";
			XmlDocument docDef = new XmlDocument();

			docDef.Load(confPath);
			m_mapCtrlDef = new Dictionary<string, CtrlDef_T>();
			m_mapPanelCtrlDef = new Dictionary<string, CtrlDef_T>();
			m_mapBasicCtrlDef = new Dictionary<string, CtrlDef_T>();
			m_mapHasBasicCtrlDef = new Dictionary<string, CtrlDef_T>();
			m_mapEnInsertCtrlDef = new Dictionary<string, CtrlDef_T>();
			m_mapEnInsertAllCtrlDef = new Dictionary<string, CtrlDef_T>();

			if(docDef.DocumentElement.Name == "CtrlAttrDef")
			{
				XmlElement xeRoot = docDef.DocumentElement;
				string nameDic;
				string tipDic;
				Dictionary<string, Dictionary<string, string>> mapNameDic;
				Dictionary<string, Dictionary<string, string>> mapTipDic;

				#region 词典
				if (xeRoot.GetAttribute("nameDic") != "")
				{
					nameDic = xeRoot.GetAttribute("nameDic");
				}
				else
				{
					nameDic = "DefDic";
				}
				if(m_strDic.m_mapStrDic.TryGetValue(nameDic, out mapNameDic))
				{

				}
				else
				{
					if(m_strDic.m_mapStrDic.TryGetValue("DefDic", out mapNameDic))
					{

					}
					else
					{
						return false;
					}
				}
				if (xeRoot.GetAttribute("tipDic") != "")
				{
					tipDic = xeRoot.GetAttribute("tipDic");
				}
				else
				{
					tipDic = "DefDic";
				}
				if (m_strDic.m_mapStrDic.TryGetValue(tipDic, out mapTipDic))
				{

				}
				else
				{
					if (m_strDic.m_mapStrDic.TryGetValue("DefDic", out mapTipDic))
					{

					}
					else
					{
						return false;
					}
				}
				#endregion

				#region conf
				foreach (XmlNode xnCtrl in xeRoot.ChildNodes)
				{
					if (xnCtrl.NodeType == XmlNodeType.Element)
					{
						XmlElement xeCtrl = (XmlElement)xnCtrl;

						if (xeCtrl.Name == "CtrlDef" && xeCtrl.GetAttribute("key") != "")
						{
							string keyCtrl = xeCtrl.GetAttribute("key");
							CtrlDef_T ctrlDef;

							if (!m_mapCtrlDef.TryGetValue(keyCtrl, out ctrlDef))
							{
								Dictionary<string, AttrDef_T> mapAttrDef = new Dictionary<string, AttrDef_T>();
								string isFrame = xeCtrl.GetAttribute("isFrame");
								string isBasic = xeCtrl.GetAttribute("isBasic");
								string hasBasic = xeCtrl.GetAttribute("hasBasic");
								string enInsert = xeCtrl.GetAttribute("enInsert");

								ctrlDef = new CtrlDef_T(mapAttrDef, null);
								if(isFrame == "true")
								{
									ctrlDef.m_isFrame = true;
									m_mapPanelCtrlDef.Add(keyCtrl, ctrlDef);
								}
								else
								{
									ctrlDef.m_isFrame = false;
								}
								if (isBasic == "true")
								{
									ctrlDef.m_isBasic = true;
									m_mapBasicCtrlDef.Add(keyCtrl, ctrlDef);
								}
								else
								{
									ctrlDef.m_isBasic = false;
								}
								if (hasBasic == "false")
								{
									ctrlDef.m_hasBasic = false;
								}
								else
								{
									ctrlDef.m_hasBasic = true;
									m_mapHasBasicCtrlDef.Add(keyCtrl, ctrlDef);
								}
								if (enInsert == "false")
								{
									ctrlDef.m_enInsert = false;
									ctrlDef.m_enInsertAll = false;
								}
								else if(enInsert == "all")
								{
									ctrlDef.m_enInsert = false;
									ctrlDef.m_enInsertAll = true;
									m_mapEnInsertAllCtrlDef.Add(keyCtrl, ctrlDef);
								}
								else
								{
									ctrlDef.m_enInsert = true;
									ctrlDef.m_enInsertAll = false;
									m_mapEnInsertCtrlDef.Add(keyCtrl, ctrlDef);
								}
								m_mapCtrlDef.Add(keyCtrl, ctrlDef);
								addAttrConf(xeCtrl, mapAttrDef);

								AttrList attrListUI = new AttrList(keyCtrl);
								ctrlDef.m_attrListUI = attrListUI;
							}
						}
					}
				}
				refreshSkinApprSuf();
				#endregion

				return true;
			}

			return false;
		}
		public void addSkinNodeConf(XmlElement xe, Dictionary<string, SkinDef_T> mapSkinTreeDef)
		{
			foreach (XmlNode xnNode in xe.ChildNodes)
			{
				if (xnNode.NodeType == XmlNodeType.Element)
				{
					XmlElement xeNode = (XmlElement)xnNode;

					if (xeNode.Name == "node")
					{
						string keySkin = xeNode.GetAttribute("key");
						SkinDef_T skinDef;

						if (keySkin != "" && !mapSkinTreeDef.TryGetValue(keySkin, out skinDef))
						{
							Dictionary<string, AttrDef_T> mapAttrDef;
							if (m_mapSkinAttrDef.TryGetValue(keySkin, out mapAttrDef))
							{
								Dictionary<string, SkinDef_T> mapTree = new Dictionary<string, SkinDef_T>();

								addSkinNodeConf(xeNode, mapTree);
								skinDef = new SkinDef_T(mapTree, mapAttrDef);
								mapSkinTreeDef.Add(keySkin, skinDef);
							}
						}
					}
				}
			}
		}
		public bool initSkinDef()
		{

			#region 属性设置
			string attrPath = conf_pathPlugInBoloUI + @"SkinAttrDef.xml";
			XmlDocument docAttr = new XmlDocument();
			docAttr.Load(attrPath);

			if(docAttr.DocumentElement.Name != "SkinAttrDef")
			{
				return false;
			}

			m_mapSkinAttrDef = new Dictionary<string, Dictionary<string, AttrDef_T>>();
			XmlElement xe = docAttr.DocumentElement;

			foreach(XmlNode xnSkinDef in xe.ChildNodes)
			{
				if(xnSkinDef.NodeType == XmlNodeType.Element)
				{
					XmlElement xeSkinDef = (XmlElement)xnSkinDef;
					string keySkin = xeSkinDef.GetAttribute("key");

					if (xeSkinDef.Name == "SkinDef" && keySkin != "")
					{
						Dictionary<string, AttrDef_T> mapAttrDef = new Dictionary<string,AttrDef_T>();

						addAttrConf(xeSkinDef, mapAttrDef);
						m_mapSkinAttrDef.Add(keySkin, mapAttrDef);
					}
				}
			}
			#endregion

			#region 节点设置
			string nodePath = conf_pathPlugInBoloUI + @"SkinNodes.xml";
			XmlDocument docNode = new XmlDocument();

			docNode.Load(nodePath);

			if (docNode.DocumentElement.Name != "SkinNodes")
			{
				return false;
			}

			m_mapSkinTreeDef = new Dictionary<string, SkinDef_T>();
			XmlElement xeRoot = docNode.DocumentElement;

			addSkinNodeConf(xeRoot, m_mapSkinTreeDef);
			#endregion

			return true;
		}
		public void initXmlValueDef()
		{
			initCtrlDef();
			initSkinDef();

			initResMap(m_mapSkinTreeDef);

			foreach (KeyValuePair<string, CtrlDef_T> pairCtrlDef in m_mapCtrlDef.ToList())
			{
				mx_toolArea.Children.Add(m_mapCtrlDef[pairCtrlDef.Key].m_attrListUI);
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
			foreach (AttrList attrList in mx_toolArea.Children)
			{
				attrList.Visibility = Visibility.Collapsed;
			}
		}
		#endregion

		public void refreshAllCtrlUIHeader()
		{
			foreach (KeyValuePair<string, OpenedFile> pairOpenedFile in m_mapOpenedFiles.ToList())
			{
				if (pairOpenedFile.Value != null && pairOpenedFile.Value.m_frame != null && pairOpenedFile.Value.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					foreach (KeyValuePair<string, BoloUI.Basic> pairCtrlUI in ((XmlControl)pairOpenedFile.Value.m_frame).m_mapCtrlUI.ToList())
					{
						if (pairCtrlUI.Value != null)
						{
							pairCtrlUI.Value.initHeader();
						}
					}
				}
			}
		}
		public void refreshAllSkinHeader()
		{
			foreach (KeyValuePair<string, OpenedFile> pairOpenedFile in m_mapOpenedFiles.ToList())
			{
				if (pairOpenedFile.Value.m_frame.GetType() == Type.GetType("UIEditor.XmlControl"))
				{
					foreach (KeyValuePair<string, BoloRes.ResBasic> pairSkin in ((XmlControl)pairOpenedFile.Value.m_frame).m_mapSkin.ToList())
					{
						if (pairSkin.Value != null)
						{
							pairSkin.Value.initHeader();
						}
					}
				}
			}
		}
		private void ScrollViewer_SizeChanged(object sender, SizeChangedEventArgs e)
		{
			mx_toolScroll.ScrollToRightEnd();
		}
		private void selCtrlBybutton(object sender, RoutedEventArgs e)
		{
		}

		private void mx_bClearDebug_Click(object sender, RoutedEventArgs e)
		{
			mx_debug.Text = "";
		}
		private void mx_debug_TextChanged(object sender, TextChangedEventArgs e)
		{
			mx_debug.ScrollToEnd();
		}
		private void mx_checkVName_Checked(object sender, RoutedEventArgs e)
		{
			m_vCtrlName = true;
			refreshAllCtrlUIHeader();
		}
		private void mx_checkVName_Unchecked(object sender, RoutedEventArgs e)
		{
			m_vCtrlName = false;
			refreshAllCtrlUIHeader();
		}
		private void mx_checkVId_Checked(object sender, RoutedEventArgs e)
		{
			m_vCtrlId = true;
			refreshAllCtrlUIHeader();
		}
		private void mx_checkVId_Unchecked(object sender, RoutedEventArgs e)
		{
			m_vCtrlId = false;
			refreshAllCtrlUIHeader();
		}
		private void mx_toolSave_Click(object sender, RoutedEventArgs e)
		{
			OpenedFile savedFile;

			if (m_mapOpenedFiles.Count > 0 && m_curFile != "" && m_mapOpenedFiles.TryGetValue(m_curFile, out savedFile))
			{
				if (savedFile.frameIsXmlCtrl())
				{
					((XmlControl)savedFile.m_frame).m_xmlDoc.Save(m_curFile);
					savedFile.m_lstOpt.m_saveNode = m_mapOpenedFiles[m_curFile].m_lstOpt.m_curNode;
					savedFile.updateSaveStatus();
				}
			}
		}
		private void mx_toolSaveAll_Click(object sender, RoutedEventArgs e)
		{
			foreach(KeyValuePair<string, OpenedFile> pairFile in m_mapOpenedFiles.ToList())
			{
				if(pairFile.Value.frameIsXmlCtrl())
				{
					((XmlControl)pairFile.Value.m_frame).m_xmlDoc.Save(pairFile.Key);
					pairFile.Value.m_lstOpt.m_saveNode = pairFile.Value.m_lstOpt.m_curNode;
					pairFile.Value.updateSaveStatus();
				}
			}
		}
		public bool curFileUndo()
		{
			OpenedFile openFileDef;

			if (m_curFile != "" &&
				m_mapOpenedFiles.TryGetValue(m_curFile, out openFileDef) &&
				openFileDef != null &&
				openFileDef.m_frame != null &&
				openFileDef.m_frame.GetType() == Type.GetType("UIEditor.XmlControl") &&
				openFileDef.m_lstOpt != null)
			{
				openFileDef.m_lstOpt.undo();

				return true;
			}
			else
			{
				return false;
			}
		}
		private void mx_toolUndo_Click(object sender, RoutedEventArgs e)
		{
			curFileUndo();
		}
		public bool curFileRedo()
		{
			OpenedFile openFileDef;

			if (m_curFile != "" &&
				m_mapOpenedFiles.TryGetValue(m_curFile, out openFileDef) &&
				openFileDef != null &&
				openFileDef.m_frame != null &&
				openFileDef.m_frame.GetType() == Type.GetType("UIEditor.XmlControl") &&
				openFileDef.m_lstOpt != null)
			{
				openFileDef.m_lstOpt.redo();

				return true;
			}
			else
			{
				return false;
			}
		}
		private void mx_toolRedo_Click(object sender, RoutedEventArgs e)
		{
			curFileRedo();
		}

		private void mx_toolCut_Click(object sender, RoutedEventArgs e)
		{
			if (m_curItem != null)
			{
				if (m_curItem.canCut())
				{
					m_curItem.cutItem();
				}
			}
		}
		private void mx_toolCopy_Click(object sender, RoutedEventArgs e)
		{
			if (m_curItem != null)
			{
				if (m_curItem.canCopy())
				{
					m_curItem.copyItem();
				}
			}
		}
		private void mx_toolPaste_Click(object sender, RoutedEventArgs e)
		{
			if (m_curItem != null && Keyboard.FocusedElement != null &&
				(Keyboard.FocusedElement.GetType().ToString() == "UIEditor.XmlItem" ||
				Keyboard.FocusedElement.GetType().BaseType.ToString() == "UIEditor.XmlItem"))
			{
				if (m_curItem.canPaste())
				{
					m_curItem.pasteItem();
				}
			}
		}
		private void mx_toolDelete_Click(object sender, RoutedEventArgs e)
		{
			if (m_curItem != null)
			{
				if (m_curItem.canDelete())
				{
					m_curItem.deleteItem();
				}
			}
		}
		private void mx_toolMoveUp_Click(object sender, RoutedEventArgs e)
		{
			if (m_curItem != null)
			{
				if (m_curItem.canMoveUp())
				{
					m_curItem.moveUpItem();
				}
			}
		}
		private void mx_toolMoveDown_Click(object sender, RoutedEventArgs e)
		{
			if (m_curItem != null)
			{
				if (m_curItem.canMoveDown())
				{
					m_curItem.moveDownItem();
				}
			}
		}

		static void viewPrevFile(MainWindow pW)
		{
			if (pW.mx_workTabs.Items.Count > 1)
			{
				if (pW.mx_workTabs.SelectedIndex > 0)
				{
					pW.mx_workTabs.SelectedItem = pW.mx_workTabs.Items.GetItemAt(pW.mx_workTabs.SelectedIndex - 1);
				}
				else
				{
					pW.mx_workTabs.SelectedItem = pW.mx_workTabs.Items.GetItemAt(pW.mx_workTabs.Items.Count - 1);
				}
			}
		}
		static void viewNextFile(MainWindow pW)
		{
			if (pW.mx_workTabs.Items.Count > 1)
			{
				if (pW.mx_workTabs.SelectedIndex < pW.mx_workTabs.Items.Count - 1)
				{
					pW.mx_workTabs.SelectedItem = pW.mx_workTabs.Items.GetItemAt(pW.mx_workTabs.SelectedIndex + 1);
				}
				else
				{
					pW.mx_workTabs.SelectedItem = pW.mx_workTabs.Items.GetItemAt(0);
				}
			}
		}
		private void mx_newFile_Click(object sender, RoutedEventArgs e)
		{
			NewFile.NewFileWin winNewFile = new NewFile.NewFileWin(".\\data\\Template\\");
			winNewFile.ShowDialog();
		}
		private void mx_newProj_Click(object sender, RoutedEventArgs e)
		{
			NewFile.NewFileWin winNewFile = new NewFile.NewFileWin(".\\data\\ProjTemplate\\", true);
			winNewFile.ShowDialog();
		}
		private void mx_viewPrevFile_Click(object sender, RoutedEventArgs e)
		{
			viewPrevFile(this);
		}
		private void mx_viewNextFile_Click(object sender, RoutedEventArgs e)
		{
			viewNextFile(this);
		}
		private void mx_viewCloseFile_Click(object sender, RoutedEventArgs e)
		{
			OpenedFile fileDef;

			if (m_mapOpenedFiles.TryGetValue(m_curFile, out fileDef) && fileDef != null && fileDef.m_tabItem != null)
			{
				fileDef.m_tabItem.closeFile();
			}
		}

		static public void refreshSearch(TreeViewItem viewItem, string key)
		{
			if(viewItem.Items.Count > 0)
			{
				foreach(TreeViewItem item in viewItem.Items)
				{
					if(key != "" && key != null)
					{
						if (item.Header.ToString().IndexOf(key, StringComparison.OrdinalIgnoreCase) < 0)
						{
							item.Visibility = System.Windows.Visibility.Collapsed;
						}
						else
						{
							for (object pItem = item.Parent;
								pItem.GetType().ToString() == "System.Windows.Controls.TreeViewItem" ||
									pItem.GetType().BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
									pItem.GetType().BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
									pItem.GetType().BaseType.BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem";
								pItem = ((TreeViewItem)pItem).Parent)
							{
								((TreeViewItem)pItem).Visibility = System.Windows.Visibility.Visible;
							}
						}
					}
					else
					{
						item.Visibility = System.Windows.Visibility.Visible;
					}
					refreshSearch(item, key);
				}
			}
		}
		private void mx_search_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (mx_search.Text != "")
			{
				refreshSearch(mx_treePro, null);
				mx_searchTip.Visibility = System.Windows.Visibility.Collapsed;
				refreshSearch(mx_treePro, mx_search.Text.ToString());
			}
			else
			{
				refreshSearch(mx_treePro, null);
				mx_searchTip.Visibility = System.Windows.Visibility.Visible;
			}
		}
		private void mx_uiSearch_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (mx_uiSearch.Text != "")
			{
				if (mx_treeCtrlFrame.Items.Count > 0 &&
						(mx_treeCtrlFrame.Items.GetItemAt(0).GetType().ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeCtrlFrame.Items.GetItemAt(0).GetType().BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeCtrlFrame.Items.GetItemAt(0).GetType().BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeCtrlFrame.Items.GetItemAt(0).GetType().BaseType.BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem"
						)
					)
				{
					refreshSearch((TreeViewItem)mx_treeCtrlFrame.Items.GetItemAt(0), null);
					refreshSearch((TreeViewItem)mx_treeCtrlFrame.Items.GetItemAt(0), mx_uiSearch.Text.ToString());
				}
				mx_uiSearchTip.Visibility = System.Windows.Visibility.Collapsed;
			}
			else
			{
				if (mx_treeCtrlFrame.Items.Count > 0 &&
						(mx_treeCtrlFrame.Items.GetItemAt(0).GetType().ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeCtrlFrame.Items.GetItemAt(0).GetType().BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeCtrlFrame.Items.GetItemAt(0).GetType().BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeCtrlFrame.Items.GetItemAt(0).GetType().BaseType.BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem"
						)
					)
				{
					refreshSearch((TreeViewItem)mx_treeCtrlFrame.Items.GetItemAt(0), null);
				}
				mx_uiSearchTip.Visibility = System.Windows.Visibility.Visible;
			}
		}
		private void mx_skinSearch_TextChanged(object sender, TextChangedEventArgs e)
		{
			if (mx_skinSearch.Text != "")
			{
				if (mx_treeSkinFrame.Items.Count > 0 &&
						(mx_treeSkinFrame.Items.GetItemAt(0).GetType().ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeSkinFrame.Items.GetItemAt(0).GetType().BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeSkinFrame.Items.GetItemAt(0).GetType().BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeSkinFrame.Items.GetItemAt(0).GetType().BaseType.BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem"
						)
					)
				{
					refreshSearch((TreeViewItem)mx_treeSkinFrame.Items.GetItemAt(0), null);
					refreshSearch((TreeViewItem)mx_treeSkinFrame.Items.GetItemAt(0), mx_skinSearch.Text.ToString());
				}
				mx_skinSearchTip.Visibility = System.Windows.Visibility.Collapsed;
			}
			else
			{
				if (mx_treeSkinFrame.Items.Count > 0 &&
						(mx_treeSkinFrame.Items.GetItemAt(0).GetType().ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeSkinFrame.Items.GetItemAt(0).GetType().BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeSkinFrame.Items.GetItemAt(0).GetType().BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem" ||
							mx_treeSkinFrame.Items.GetItemAt(0).GetType().BaseType.BaseType.BaseType.ToString() == "System.Windows.Controls.TreeViewItem"
						)
					)
				{
					refreshSearch((TreeViewItem)mx_treeSkinFrame.Items.GetItemAt(0), null);
				}
				mx_skinSearchTip.Visibility = System.Windows.Visibility.Visible;
			}
		}

		private void mx_help_Click(object sender, RoutedEventArgs e)
		{
			string path = System.IO.Path.GetDirectoryName(this.GetType().Assembly.Location) + "/doc/help.html";

			if (System.IO.File.Exists(path))
			{
				System.Diagnostics.Process.Start("file:///" + path);
			}
			else
			{
				mx_debug.Text += "<错误>没有找到文件：" + path + "。\r\n";
			}
		}
		private void mx_version_Click(object sender, RoutedEventArgs e)
		{
			string path = System.IO.Path.GetDirectoryName(this.GetType().Assembly.Location) + "/doc/version.html";

			if (System.IO.File.Exists(path))
			{
				System.Diagnostics.Process.Start("file:///" + path);
			}
			else
			{
				mx_debug.Text += "<错误>没有找到文件：" + path + "。\r\n";
			}
		}
		private void mx_debug_SizeChanged(object sender, SizeChangedEventArgs e)
		{
			mx_debug.ScrollToEnd();
		}

		private void mx_GLCtrl_SizeChanged(object sender, SizeChangedEventArgs e)
		{
			if (mx_GLCtrl != null && mx_GLHost != null)
			{
				mx_debug.Text += "bw:" + mx_GLCtrl.ActualWidth + "\t" + "bh:" + mx_GLCtrl.ActualHeight + "\t" +
					"gw:" + mx_GLHost.ActualWidth + "\t" + "gh:" + mx_GLHost.ActualHeight + "\r\n";
			}
		}

		private void mx_isViewMode_Checked(object sender, RoutedEventArgs e)
		{
			updateGL("true", W2GTag.W2G_VIEWMODE);
		}
		private void mx_isViewMode_Unchecked(object sender, RoutedEventArgs e)
		{
			updateGL("false", W2GTag.W2G_VIEWMODE);
		}
		private void mx_btnNesting_Click(object sender, RoutedEventArgs e)
		{
			if(m_projPath != null && m_projPath != "")
			{
				if (!System.IO.Directory.Exists(m_projPath + "\\images\\"))
				{
					Directory.CreateDirectory(m_projPath + "\\images\\");
				}
				ImageTools.ImageNesting winNesting = new ImageTools.ImageNesting(m_projPath + "\\images\\", "*.png", 1);
				winNesting.ShowDialog();
			}
		}

		[DllImport("user32.dll", CharSet = CharSet.Auto)]
		public static extern int MoveWindow(IntPtr hWnd, int x, int y, int nWidth, int nHeight, bool BRePaint);

		static double s_x = 0;
		static double s_y = 0;
		private void mx_scrollFrame_ScrollChanged(object sender, ScrollChangedEventArgs e)
		{
			mx_debug.Text += "sw:" + mx_scrollFrame.ActualWidth + "\t" + "sh:" + mx_scrollFrame.ActualHeight + "\t" +
				"sx:" + mx_scrollFrame.HorizontalOffset + "\t" + "sy:" + mx_scrollFrame.VerticalOffset + "\r\n";

			double dx = s_x - mx_scrollFrame.HorizontalOffset;
			double dy = s_y - mx_scrollFrame.VerticalOffset;

			s_x = mx_scrollFrame.HorizontalOffset;
			s_y = mx_scrollFrame.VerticalOffset;
			MoveWindow(m_hwndGL, (int)-s_x, (int)-s_y, 960, 640, true);
			
			//mx_drawFrame.BringIntoView(new Rect(mx_GLScroll.HorizontalOffset, mx_GLScroll.VerticalOffset, mx_GLScroll.HorizontalOffset, mx_GLScroll.VerticalOffset));
			//mx_GLHost.BringIntoView(new Rect(mx_GLScroll.HorizontalOffset, mx_GLScroll.VerticalOffset, mx_GLScroll.HorizontalOffset, mx_GLScroll.VerticalOffset));
			//mx_glX.Width = new GridLength(mx_GLScroll.HorizontalOffset);
			//mx_glX.Width = new GridLength(mx_GLScroll.HorizontalOffset);
		}
	}
}

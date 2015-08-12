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
	public enum ApprSuffix
	{
		APPRSUF_NORMAL = 0,					//正常状态
		APPRSUF_PRESSED = 1,				//按下状态
		APPRSUF_DISABLED = 2,				//禁用状态
		APPRSUF_CHECKED_NORMAL = 3,			//选中 - 正常状态
		APPRSUF_CHECKED_PRESSED = 4,		//选中 - 按下状态
		APPRSUF_CHECKED_DISABLED = 5,		//选中 - 禁用状态
		APPRSUF_NORMAL_BORDER = 6,			//正常边框
		APPRSUF_NORMAL_FILLED = 7,			//正常填充
		APPRSUF_NORMAL_BACKGROUND = 8,		//正常背景
		APPRSUF_NORMAL_FILLEDHEAD = 9,		//正常填充头
		APPRSUF_NORMAL_FILLEDTAIL = 10,		//正常填充尾
		APPRSUF_SELECT = 11,				//选中
		APPRSUF_NORMAL_FILLEDSLIDER = 12,	//正常填充滑块
		APPRSUF_TIPS = 13,					//tips
		APPRSUF_MESSAGE_TIPS_NORMAL = 14,	//消息提示正常
		APPRSUF_MESSAGE_TIPS_LIGHT = 15,	//消息提示亮
		APPRSUF_NORMAL_PRE_GROWTH = 16,		//预增长
		APPRSUF_KEYSELECT_NOMAL = 17,		//按键选中
		APPRSUF_KEYSELECT_CHECK = 18,		//按键选中 - 选中
		APPRSUF_MAX
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
		public Dictionary<string, SkinDef_T> m_mapEventDef;
		public Dictionary<string, SkinDef_T> m_mapShapeChildDef;
		public Dictionary<string, SkinDef_T> m_mapSkinChildDef;
		public Dictionary<string, SkinDef_T> m_mapSkinResDef;
		public Dictionary<string, SkinDef_T> m_mapAllResDef;
		public Dictionary<XmlElement, BoloUI.SelButton> m_mapXeSel;
		public float m_dpiSysX;
		public float m_dpiSysY;
		public IntPtr m_hwndGLFrame;
		public IntPtr m_hwndGLParent;
		public IntPtr m_hwndGL;
		public AttrList m_otherAttrList;
		public bool m_attrBinding;		//xml属性绑定用，上锁和解锁必须成对出现
		public bool m_vCtrlName;
		public bool m_vCtrlId;

		public XmlDocument m_xdTest;
		public XmlElement m_xeTest;
		public string m_strTestXml;

		public string m_curFile;	//todo
		public XmlItem m_curItem;
		private int m_dep;

		public XmlElement m_xePaste;

		public bool m_isMouseDown;
		public bool m_isCtrlMoved;
		public int m_downX;
		public int m_downY;
		public string m_pasteFilePath;

		ControlHost mx_GLHost;

		public string conf_pathGlApp = @".\dsuieditor.exe";
		public string conf_pathConf = @".\conf.xml";
		public XmlDocument m_docConf;
		public bool m_isDebug;

		public MainWindow()
		{
			StringDic.initDic();
			s_pW = this;
			m_skinPath = "";
			m_projPath = "";
			m_hwndGL = IntPtr.Zero;
			m_hwndGLParent = IntPtr.Zero;
			m_mapOpenedFiles = new Dictionary<string, OpenedFile>();
			m_attrBinding = true;
			InitializeComponent();
			m_mapStrSkinGroup = new Dictionary<string, XmlDocument>();
			m_mapStrSkin = new Dictionary<string, XmlElement>();
			m_mapAllResDef = new Dictionary<string, SkinDef_T>();
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
			if(m_isDebug)
			{
				mx_debugTools.Visibility = System.Windows.Visibility.Visible;
			}
			else
			{
				mx_debugTools.Visibility = System.Windows.Visibility.Collapsed;
			}
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
			if (((TabItem)mx_workTabs.SelectedItem) != null)
			{
				if (((ToolTip)((TabItem)mx_workTabs.SelectedItem).ToolTip) != null)
				{
					string tabPath = ((ToolTip)((TabItem)mx_workTabs.SelectedItem).ToolTip).Content.ToString();
					string fileType = StringDic.getFileType(tabPath);

					m_curFile = tabPath;
					mx_treeCtrlFrame.Items.Clear();
					mx_treeSkinFrame.Items.Clear();
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
			WM_DESTROY			= 0x0002,
			WM_CLOSE			= 0x0010,
			WM_QUIT				= 0x0012,
			WM_COPYDATA			= 0x004A,
			WM_COMMAND			= 0x0111,
			
			WM_KEYDOWN			= 0x0100,

			WM_MOUSEFIRST		= 0x0200,
			WM_MOUSEMOVE		= 0x0200,
			WM_LBUTTONDOWN		= 0x0201,
			WM_LBUTTONUP		= 0x0202,
			WM_LBUTTONDBLCLK	= 0x0203,
			WM_RBUTTONDOWN		= 0x0204,
			WM_RBUTTONUP		= 0x0205,
			WM_RBUTTONDBLCLK	= 0x0206,
			WM_MBUTTONDOWN		= 0x0207,
			WM_MBUTTONUP		= 0x0208,
			WM_MBUTTONDBLCLK	= 0x0209,
			
			LBN_SELCHANGE		= 0x0001,
			LB_GETCURSEL		= 0x0188,
			LB_GETTEXTLEN		= 0x018A,
			LB_ADDSTRING		= 0x0180,
			LB_GETTEXT			= 0x0189,
			LB_DELETESTRING		= 0x0182,
			LB_GETCOUNT			= 0x018B,

			VK_PRIOR	= 0x21,
			VK_NEXT		= 0x22,
			VK_LEFT		= 0x25,
			VK_UP		= 0x26,
			VK_RIGHT	= 0x27,
			VK_DOWN		= 0x28,
			VK_DELETE	= 0x2E,

			VK_OEM_PLUS		= 0xBB,
			VK_OEM_MINUS	= 0xBD,

			VK_A	= 0x41,
			VK_B	= 0x42,
			VK_C	= 0x43,
			VK_D	= 0x44,
			VK_E	= 0x45,
			VK_F	= 0x46,
			VK_G	= 0x47,
			VK_H	= 0x48,
			VK_I	= 0x49,
			VK_J	= 0x4A,
			VK_K	= 0x4B,
			VK_L	= 0x4C,
			VK_M	= 0x4D,
			VK_N	= 0x4E,
			VK_O	= 0x4F,
			VK_P	= 0x50,
			VK_Q	= 0x51,
			VK_R	= 0x52,
			VK_S	= 0x53,
			VK_T	= 0x54,
			VK_U	= 0x55,
			VK_V	= 0x56,
			VK_W	= 0x57,
			VK_X	= 0x58,
			VK_Y	= 0x59,
			VK_Z	= 0x5A;
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
					break;
				case WM_LBUTTONDOWN:
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
					break;
				case WM_LBUTTONUP:
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
								foreach (KeyValuePair<string, BoloUI.Basic> pairCtrlDef in ((XmlControl)m_mapOpenedFiles[m_curFile].m_frame).m_mapCtrlUI.ToList())
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
								if ((System.Windows.Forms.Control.ModifierKeys & System.Windows.Forms.Keys.Control) == System.Windows.Forms.Keys.Control)
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
					mx_GLHost.m_process.Kill();
					break;
				case WM_DESTROY:
					mx_GLHost.m_process.Kill();
					break;
				case WM_KEYDOWN:
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
			((XmlControl)m_mapOpenedFiles[m_curFile].m_frame).refreshVRect();
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

	#region xml控件名、属性名、默认值、取值范围等。
		public class AttrDef_T
		{
			public AttrRow m_attrRowUI;
			public string m_type;
			public string m_defValue;
			public bool m_isEnum;
			public List<string> m_lstEnumValue;

			public AttrDef_T(string type = "int", string defValue = null, AttrRow rowUI = null, bool isEnum = false, List<string> lstEnumValue = null)
			{
				m_attrRowUI = rowUI;
				m_type = type;
				m_defValue = defValue;
				m_isEnum = isEnum;
				m_lstEnumValue = lstEnumValue;
			}
		}
		public class CtrlDef_T
		{
			public Dictionary<string, AttrDef_T> m_mapAttrDef;
			public AttrList m_attrListUI;
			public Dictionary<ApprSuffix, bool> m_mapApprSuffix;

			public CtrlDef_T(Dictionary<string, AttrDef_T> mapAttrDef, AttrList attrListUI, Dictionary<ApprSuffix, bool> mapApprSuffix = null)
			{
				m_mapAttrDef = mapAttrDef;
				m_attrListUI = attrListUI;
				if (mapApprSuffix == null)
				{
					m_mapApprSuffix = MainWindow.s_pW.conf_mapApprSufEnable;
				}
				else
				{
					m_mapApprSuffix = mapApprSuffix;
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

		#region m_mapApprSuf
		Dictionary<ApprSuffix, string> conf_mapApprSuf = new Dictionary<ApprSuffix, string>
		{
			{ ApprSuffix.APPRSUF_NORMAL, "正常状态"},
			{ ApprSuffix.APPRSUF_PRESSED, "按下状态"},
			{ ApprSuffix.APPRSUF_DISABLED, "禁用状态"},
			{ ApprSuffix.APPRSUF_CHECKED_NORMAL, "选中 - 正常状态"},
			{ ApprSuffix.APPRSUF_CHECKED_PRESSED, "选中 - 按下状态"},
			{ ApprSuffix.APPRSUF_CHECKED_DISABLED, "选中 - 禁用状态"},
			{ ApprSuffix.APPRSUF_NORMAL_BORDER, "正常边框"},
			{ ApprSuffix.APPRSUF_NORMAL_FILLED, "正常填充"},
			{ ApprSuffix.APPRSUF_NORMAL_BACKGROUND, "正常背景"},
			{ ApprSuffix.APPRSUF_NORMAL_FILLEDHEAD, "正常填充头"},
			{ ApprSuffix.APPRSUF_NORMAL_FILLEDTAIL, "正常填充尾"},
			{ ApprSuffix.APPRSUF_SELECT, "选中"},
			{ ApprSuffix.APPRSUF_NORMAL_FILLEDSLIDER, "正常填充滑块"},
			{ ApprSuffix.APPRSUF_TIPS, "tips"},
			{ ApprSuffix.APPRSUF_MESSAGE_TIPS_NORMAL, "消息提示正常"},
			{ ApprSuffix.APPRSUF_MESSAGE_TIPS_LIGHT, "消息提示亮"},
			{ ApprSuffix.APPRSUF_NORMAL_PRE_GROWTH, "预增长"},
			{ ApprSuffix.APPRSUF_KEYSELECT_NOMAL, "按键选中"},
			{ ApprSuffix.APPRSUF_KEYSELECT_CHECK, "按键选中 - 选中"}
		};

		Dictionary<ApprSuffix, bool> conf_mapApprSufEnable = new Dictionary<ApprSuffix, bool>
		{
			{ ApprSuffix.APPRSUF_NORMAL, true},
			{ ApprSuffix.APPRSUF_PRESSED, true},
			{ ApprSuffix.APPRSUF_DISABLED, true},
			{ ApprSuffix.APPRSUF_CHECKED_NORMAL, true},
			{ ApprSuffix.APPRSUF_CHECKED_PRESSED, true},
			{ ApprSuffix.APPRSUF_CHECKED_DISABLED, true},
			{ ApprSuffix.APPRSUF_NORMAL_BORDER, true},
			{ ApprSuffix.APPRSUF_NORMAL_FILLED, true},
			{ ApprSuffix.APPRSUF_NORMAL_BACKGROUND, true},
			{ ApprSuffix.APPRSUF_NORMAL_FILLEDHEAD, true},
			{ ApprSuffix.APPRSUF_NORMAL_FILLEDTAIL, true},
			{ ApprSuffix.APPRSUF_SELECT, true},
			{ ApprSuffix.APPRSUF_NORMAL_FILLEDSLIDER, true},
			{ ApprSuffix.APPRSUF_TIPS, true},
			{ ApprSuffix.APPRSUF_MESSAGE_TIPS_NORMAL, true},
			{ ApprSuffix.APPRSUF_MESSAGE_TIPS_LIGHT, true},
			{ ApprSuffix.APPRSUF_NORMAL_PRE_GROWTH, true},
			{ ApprSuffix.APPRSUF_KEYSELECT_NOMAL, true},
			{ ApprSuffix.APPRSUF_KEYSELECT_CHECK, true}
		};
		#endregion

		#region conf
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
				{"bgColor", new AttrDef_T("color")},
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
				{"cdRGB", new AttrDef_T("color")},
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
		Dictionary<string, AttrDef_T> conf_mapRootEventAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region RootEvent
				{"type", new AttrDef_T("string")},
				{"function", new AttrDef_T("string")},
				{"sound", new AttrDef_T("string")}
				#endregion
			};
		Dictionary<string, AttrDef_T> conf_mapToolTipAttrDef = new Dictionary<string, AttrDef_T>
			{
			};

		Dictionary<string, AttrDef_T> conf_mapResAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region 资源
				{"name", new AttrDef_T("string")}
				#endregion
			};
		Dictionary<string, AttrDef_T> conf_mapSkinGroupAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region 皮肤组
				{"Name", new AttrDef_T("string")}
				#endregion
			};
		Dictionary<string, AttrDef_T> conf_mapSkinAttrDef = new Dictionary<string, AttrDef_T>
			{
				#region 皮肤
				{"Name", new AttrDef_T("string")},
				{"Width", new AttrDef_T("int")},
				{"Height", new AttrDef_T("int")},
				#endregion
			};
		#endregion

		public void initResMap(Dictionary<string, SkinDef_T> mapResDef)
		{
			foreach(KeyValuePair<string, SkinDef_T> pairSkinDef in mapResDef.ToList())
			{
				SkinDef_T skinDef;
				if (!m_mapAllResDef.TryGetValue(pairSkinDef.Key, out skinDef))
				{
					m_mapAllResDef.Add(pairSkinDef.Key, pairSkinDef.Value);
					if (pairSkinDef.Value.m_mapEnChild != null && pairSkinDef.Value.m_mapEnChild.Count > 0)
					{
						initResMap(pairSkinDef.Value.m_mapEnChild);
					}
				}
			}
		}
		public void initXmlValueDef()
		{
			m_mapCtrlDef = new Dictionary<string, CtrlDef_T>
			{
				#region boloUI控件的定义
				{ "basic", new CtrlDef_T(conf_mapBaseAttrDef, null,
						new Dictionary<ApprSuffix, bool>
						{
							{ ApprSuffix.APPRSUF_NORMAL, true},
							{ ApprSuffix.APPRSUF_PRESSED, true},
							{ ApprSuffix.APPRSUF_DISABLED, true},
							{ ApprSuffix.APPRSUF_CHECKED_NORMAL, false},
							{ ApprSuffix.APPRSUF_CHECKED_PRESSED, false},
							{ ApprSuffix.APPRSUF_CHECKED_DISABLED, false},
							{ ApprSuffix.APPRSUF_NORMAL_BORDER, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLED, false},
							{ ApprSuffix.APPRSUF_NORMAL_BACKGROUND, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDHEAD, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDTAIL, false},
							{ ApprSuffix.APPRSUF_SELECT, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDSLIDER, false},
							{ ApprSuffix.APPRSUF_TIPS, true},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_NORMAL, false},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_LIGHT, false},
							{ ApprSuffix.APPRSUF_NORMAL_PRE_GROWTH, false},
							{ ApprSuffix.APPRSUF_KEYSELECT_NOMAL, true},
							{ ApprSuffix.APPRSUF_KEYSELECT_CHECK, true}
						}
					)},
				{ "panel", new CtrlDef_T(conf_mapPanelAttrDef, null)},
				{ "label", new CtrlDef_T(conf_mapLabelAttrDef, null)},
				{ "button", new CtrlDef_T(conf_mapButtonAttrDef, null,
						new Dictionary<ApprSuffix, bool>
						{
							{ ApprSuffix.APPRSUF_NORMAL, true},
							{ ApprSuffix.APPRSUF_PRESSED, true},
							{ ApprSuffix.APPRSUF_DISABLED, true},
							{ ApprSuffix.APPRSUF_CHECKED_NORMAL, false},
							{ ApprSuffix.APPRSUF_CHECKED_PRESSED, false},
							{ ApprSuffix.APPRSUF_CHECKED_DISABLED, false},
							{ ApprSuffix.APPRSUF_NORMAL_BORDER, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLED, false},
							{ ApprSuffix.APPRSUF_NORMAL_BACKGROUND, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDHEAD, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDTAIL, false},
							{ ApprSuffix.APPRSUF_SELECT, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDSLIDER, false},
							{ ApprSuffix.APPRSUF_TIPS, true},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_NORMAL, true},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_LIGHT, true},
							{ ApprSuffix.APPRSUF_NORMAL_PRE_GROWTH, false},
							{ ApprSuffix.APPRSUF_KEYSELECT_NOMAL, true},
							{ ApprSuffix.APPRSUF_KEYSELECT_CHECK, true}
						}
					)},
				{ "skillbutton", new CtrlDef_T(conf_mapSkillButtonAttrDef, null)},
				{ "progress", new CtrlDef_T(conf_mapProgressAttrDef, null,
						new Dictionary<ApprSuffix, bool>
						{
							{ ApprSuffix.APPRSUF_NORMAL, true},
							{ ApprSuffix.APPRSUF_PRESSED, true},
							{ ApprSuffix.APPRSUF_DISABLED, true},
							{ ApprSuffix.APPRSUF_CHECKED_NORMAL, false},
							{ ApprSuffix.APPRSUF_CHECKED_PRESSED, false},
							{ ApprSuffix.APPRSUF_CHECKED_DISABLED, false},
							{ ApprSuffix.APPRSUF_NORMAL_BORDER, true},
							{ ApprSuffix.APPRSUF_NORMAL_FILLED, true},
							{ ApprSuffix.APPRSUF_NORMAL_BACKGROUND, true},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDHEAD, true},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDTAIL, true},
							{ ApprSuffix.APPRSUF_SELECT, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDSLIDER, true},
							{ ApprSuffix.APPRSUF_TIPS, true},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_NORMAL, false},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_LIGHT, false},
							{ ApprSuffix.APPRSUF_NORMAL_PRE_GROWTH, true},
							{ ApprSuffix.APPRSUF_KEYSELECT_NOMAL, true},
							{ ApprSuffix.APPRSUF_KEYSELECT_CHECK, true}
						}
					)},
				{ "radio", new CtrlDef_T(conf_mapRadioAttrDef, null)},
				{ "check", new CtrlDef_T(conf_mapCheckAttrDef, null,
						new Dictionary<ApprSuffix, bool>
						{
							{ ApprSuffix.APPRSUF_NORMAL, true},
							{ ApprSuffix.APPRSUF_PRESSED, true},
							{ ApprSuffix.APPRSUF_DISABLED, true},
							{ ApprSuffix.APPRSUF_CHECKED_NORMAL, true},
							{ ApprSuffix.APPRSUF_CHECKED_PRESSED, true},
							{ ApprSuffix.APPRSUF_CHECKED_DISABLED, true},
							{ ApprSuffix.APPRSUF_NORMAL_BORDER, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLED, false},
							{ ApprSuffix.APPRSUF_NORMAL_BACKGROUND, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDHEAD, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDTAIL, false},
							{ ApprSuffix.APPRSUF_SELECT, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDSLIDER, false},
							{ ApprSuffix.APPRSUF_TIPS, true},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_NORMAL, false},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_LIGHT, false},
							{ ApprSuffix.APPRSUF_NORMAL_PRE_GROWTH, false},
							{ ApprSuffix.APPRSUF_KEYSELECT_NOMAL, true},
							{ ApprSuffix.APPRSUF_KEYSELECT_CHECK, true}
						}
					)},
				{ "listPanel", new CtrlDef_T(conf_mapListPanelAttrDef, null)},
				{ "tabPanel", new CtrlDef_T(conf_mapTabPanelAttrDef, null)},
				{ "pagePanel", new CtrlDef_T(conf_mapPagePanelAttrDef, null)},
				{ "virtualpad", new CtrlDef_T(conf_mapVirtualPadAttrDef, null)},
				{ "richText", new CtrlDef_T(conf_mapRichTextAttrDef, null)},
				{ "pageText", new CtrlDef_T(conf_mapPageTextAttrDef, null)},
				{ "scriptPanel", new CtrlDef_T(conf_mapScriptPanelAttrDef, null)},
				{ "countDown", new CtrlDef_T(conf_mapCountDownAttrDef, null)},
				{ "apartPanel", new CtrlDef_T(conf_mapApartPanelAttrDef, null)},
				{ "draggedPanel", new CtrlDef_T(conf_mapDraggedPanelAttrDef, null,
						new Dictionary<ApprSuffix, bool>
						{
							{ ApprSuffix.APPRSUF_NORMAL, true},
							{ ApprSuffix.APPRSUF_PRESSED, true},
							{ ApprSuffix.APPRSUF_DISABLED, true},
							{ ApprSuffix.APPRSUF_CHECKED_NORMAL, false},
							{ ApprSuffix.APPRSUF_CHECKED_PRESSED, false},
							{ ApprSuffix.APPRSUF_CHECKED_DISABLED, false},
							{ ApprSuffix.APPRSUF_NORMAL_BORDER, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLED, false},
							{ ApprSuffix.APPRSUF_NORMAL_BACKGROUND, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDHEAD, false},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDTAIL, false},
							{ ApprSuffix.APPRSUF_SELECT, true},
							{ ApprSuffix.APPRSUF_NORMAL_FILLEDSLIDER, false},
							{ ApprSuffix.APPRSUF_TIPS, true},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_NORMAL, false},
							{ ApprSuffix.APPRSUF_MESSAGE_TIPS_LIGHT, false},
							{ ApprSuffix.APPRSUF_NORMAL_PRE_GROWTH, false},
							{ ApprSuffix.APPRSUF_KEYSELECT_NOMAL, true},
							{ ApprSuffix.APPRSUF_KEYSELECT_CHECK, true}
						}
					)},
				{ "turnTable", new CtrlDef_T(conf_mapTurnTableAttrDef, null)},
				{ "drawModel", new CtrlDef_T(conf_mapDrawModelAttrDef, null)},
				{ "dropList", new CtrlDef_T(conf_mapDropListAttrDef, null)},
				{ "event", new CtrlDef_T(conf_mapEventAttrDef, null)},
				{ "tooltip", new CtrlDef_T(conf_mapToolTipAttrDef, null)}
				#endregion
			};

			m_mapPanelCtrlDef = new Dictionary<string, CtrlDef_T>
			{
				#region boloUI父控件的定义
				{ "panel",		m_mapCtrlDef["panel"]},
				{ "listPanel",	m_mapCtrlDef["listPanel"]},
				{ "tabPanel",	m_mapCtrlDef["tabPanel"]},
				{ "pagePanel",	m_mapCtrlDef["pagePanel"]},
				{ "apartPanel", m_mapCtrlDef["apartPanel"]}
				#endregion
			};

			m_mapEventDef = new Dictionary<string, SkinDef_T>
			{
				#region BoloUIEvent（事件组）
				{
					"event",
					new SkinDef_T(null, conf_mapRootEventAttrDef)
				}
				#endregion
			};

			m_mapShapeChildDef = new Dictionary<string, SkinDef_T>
			{
				#region shape的子节点
				{"animation",
					new SkinDef_T(
						new Dictionary<string, SkinDef_T>
						{
							{"frame",
								new SkinDef_T(
									new Dictionary<string, SkinDef_T>(),
									new Dictionary<string, AttrDef_T>
									{
										{"image", new AttrDef_T("string")},
										{"time", new AttrDef_T("int")},
										{"x", new AttrDef_T("int")},
										{"y", new AttrDef_T("int")},
										{"w", new AttrDef_T("int")},
										{"h", new AttrDef_T("int")},
										{"X", new AttrDef_T("int")},
										{"Y", new AttrDef_T("int")},
										{"Width", new AttrDef_T("int")},
										{"Height", new AttrDef_T("int")},
										{"topBorder", new AttrDef_T("int")},
										{"bottomBorder", new AttrDef_T("int")},
										{"leftBorder", new AttrDef_T("int")},
										{"rightBorder", new AttrDef_T("int")},
										{"Anchor", new AttrDef_T("int")},
										{"angle", new AttrDef_T("int")},
										{"rotateType", new AttrDef_T("int")},
										{"mirrorType", new AttrDef_T("int")},
										
										{"ImageName", new AttrDef_T("string")},
										{"Dock", new AttrDef_T("int")},
										{"NineGrid", new AttrDef_T("bool")},
										{"NGX", new AttrDef_T("int")},
										{"NGY", new AttrDef_T("int")},
										{"NGWidth", new AttrDef_T("int")},
										{"NGHeight", new AttrDef_T("int")},
										{"LIGHT", new AttrDef_T("bool")},
										{"Color", new AttrDef_T("color")},

										{"Font", new AttrDef_T("int")},
										{"Color0", new AttrDef_T("color")},
										{"Color1", new AttrDef_T("color")},
										{"Color2", new AttrDef_T("color")},
										{"Style", new AttrDef_T("int")},
										{"fontSize", new AttrDef_T("int")}
									}
								)
							}
						},
						new Dictionary<string, AttrDef_T>
						{
							{"loop", new AttrDef_T("bool")}
						}
					)
				}
				#endregion
			};

			m_mapSkinChildDef = new Dictionary<string, SkinDef_T>
			{
				#region skin的子节点
				{"apperance",
					new SkinDef_T(
						new Dictionary<string, SkinDef_T>
						{
							{"imageShape",
								new SkinDef_T(
									m_mapShapeChildDef,
									new Dictionary<string, AttrDef_T>
									{
										{"ImageName", new AttrDef_T("string")},
										{"Dock", new AttrDef_T("int")},
										{"NineGrid", new AttrDef_T("bool")},
										{"NGX", new AttrDef_T("int")},
										{"NGY", new AttrDef_T("int")},
										{"NGWidth", new AttrDef_T("int")},
										{"NGHeight", new AttrDef_T("int")},
										{"LIGHT", new AttrDef_T("bool")},
										{"Color", new AttrDef_T("color")},
										
										{"X", new AttrDef_T("int")},
										{"Y", new AttrDef_T("int")},
										{"Width", new AttrDef_T("int")},
										{"Height", new AttrDef_T("int")},
										{"topBorder", new AttrDef_T("int")},
										{"bottomBorder", new AttrDef_T("int")},
										{"leftBorder", new AttrDef_T("int")},
										{"rightBorder", new AttrDef_T("int")},
										{"Anchor", new AttrDef_T("int")},
										{"angle", new AttrDef_T("int")},
										{"rotateType", new AttrDef_T("int")},
										{"mirrorType", new AttrDef_T("int")}
									}
								)
							},
							{"textShape",
								new SkinDef_T(
									m_mapShapeChildDef,
									new Dictionary<string, AttrDef_T>
									{
										{"Font", new AttrDef_T("int")},
										{"Color", new AttrDef_T("color")},
										{"Color0", new AttrDef_T("color")},
										{"Color1", new AttrDef_T("color")},
										{"Color2", new AttrDef_T("color")},
										{"Style", new AttrDef_T("int")},
										{"fontSize", new AttrDef_T("int")},
										
										{"X", new AttrDef_T("int")},
										{"Y", new AttrDef_T("int")},
										{"Width", new AttrDef_T("int")},
										{"Height", new AttrDef_T("int")},
										{"topBorder", new AttrDef_T("int")},
										{"bottomBorder", new AttrDef_T("int")},
										{"leftBorder", new AttrDef_T("int")},
										{"rightBorder", new AttrDef_T("int")},
										{"Anchor", new AttrDef_T("int")},
										{"angle", new AttrDef_T("int")},
										{"rotateType", new AttrDef_T("int")},
										{"mirrorType", new AttrDef_T("int")}
									}
								)
							}
						},
						new Dictionary<string, AttrDef_T>
						{
							{"id", new AttrDef_T("string")}
						}
					)
				}
				#endregion
			};

			m_mapSkinResDef = new Dictionary<string, SkinDef_T>
			{
				#region 皮肤与资源等的定义
				{"BoloUIEvent",
					new SkinDef_T(
						m_mapEventDef,
						null
					)
				},
				{"skingroup",
					new SkinDef_T(
						null,
						conf_mapSkinGroupAttrDef
					)
				},
				{"resource",
					new SkinDef_T(
						null,
						conf_mapResAttrDef
					)
				},
				{"publicresource",
					new SkinDef_T(
						null,
						conf_mapResAttrDef
					)
				},
				{"skin",
					new SkinDef_T(
						m_mapSkinChildDef,
						conf_mapSkinAttrDef
					)
				},
				{"publicskin",
					new SkinDef_T(
						m_mapSkinChildDef,
						conf_mapSkinAttrDef
					)
				}
				#endregion
			};

			initResMap(m_mapSkinResDef);

			foreach(KeyValuePair<string, CtrlDef_T> pairCtrlDef in m_mapCtrlDef.ToList())
			{
				mx_toolArea.Children.Add(m_mapCtrlDef[pairCtrlDef.Key].m_attrListUI = new AttrList(pairCtrlDef.Key, this));
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
	}
}

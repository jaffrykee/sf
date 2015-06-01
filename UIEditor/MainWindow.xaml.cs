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
		public Dictionary<string, Dictionary<string, MapAttrDef_T>> m_mapCtrlDef;
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
			initXmlValueDef();
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

			refreshSkin(path + "\\skin");
			refreshProjTree(path, this.mx_treePro, true);
		}

		private void refreshSkin(string path)
		{
			DirectoryInfo di = new DirectoryInfo(path);


			foreach (var dri in di.GetFiles("*.xml"))
			{
				XmlDocument xmlDoc = new XmlDocument();
				xmlDoc = new XmlDocument();
				xmlDoc.Load(path + "\\" + dri.Name);
				XmlNode xn = xmlDoc.SelectSingleNode("BoloUI");

				if (xn != null)
				{
					string buffer = xmlDoc.InnerXml;
					updateGL(buffer, true);
				}
			}
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

		public void updateGL(string buffer, bool isSkin = false)
		{
			ControlHostElement.Visibility = System.Windows.Visibility.Visible;
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
					if (isSkin != true)
					{
						msgData.dwData = (IntPtr)SEND_NORMAL;
					}
					else
					{
						msgData.dwData = (IntPtr)SEND_SKIN;
					}
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

		  SEND_NORMAL = 0x0001,
		  SEND_SKIN = 0x0002,

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
						XmlDocument xmlDoc = new XmlDocument();
						xmlDoc.Load(tabPath);
						string buffer = xmlDoc.InnerXml;
						this.updateGL(buffer);
						ControlHostElement.Visibility = System.Windows.Visibility.Visible;
					}
					else
					{
						ControlHostElement.Visibility = System.Windows.Visibility.Collapsed;
					}
				}
			}
		}

		#region xml控件名、属性名、默认值、取值范围等。
		public class MapAttrDef_T
		{
			public string m_type;
			public string m_defValue;
			public bool m_isEnum;
			public List<string> m_enumValue;

			public MapAttrDef_T(string type, string defValue)
			{
				m_type = type;
				m_defValue = defValue;
				m_isEnum = false;
				m_enumValue = null;
			}

			public MapAttrDef_T(string type)
				: this(type, null)
			{
			}

			public MapAttrDef_T()
				: this("int", null)
			{
			}
		}

		public struct MapCtrlDef_T
		{
			public Dictionary<string, MapAttrDef_T> m_mapAttrDef;
		}


		Dictionary<string, MapAttrDef_T> conf_mapBaseAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region Base
				{"name", new MapAttrDef_T("string")},
				{"baseID", new MapAttrDef_T("string")},
				{"text", new MapAttrDef_T("string")},
				{"alpha", new MapAttrDef_T("int")},
				{"x", new MapAttrDef_T("int")},
				{"y", new MapAttrDef_T("int")},
				{"w", new MapAttrDef_T("int")},
				{"h", new MapAttrDef_T("int")},
				{"maxWidth", new MapAttrDef_T("int")},
				{"maxHeight", new MapAttrDef_T("int")},
				{"minWidth", new MapAttrDef_T("int")},
				{"minHeight", new MapAttrDef_T("int")},
				{"leftBorder", new MapAttrDef_T("int")},
				{"rightBorder", new MapAttrDef_T("int")},
				{"topBorder", new MapAttrDef_T("int")},
				{"bottomBorder", new MapAttrDef_T("int")},
				{"visible", new MapAttrDef_T("bool")},
				{"enable", new MapAttrDef_T("bool")},
				{"dock", new MapAttrDef_T("int")},
				{"docklayer", new MapAttrDef_T("int")},
				{"anchor", new MapAttrDef_T("int")},
				{"anchorSelf", new MapAttrDef_T("int")},
				{"canFocus", new MapAttrDef_T("bool")},
				{"skin", new MapAttrDef_T("string")},
				{"tips", new MapAttrDef_T("bool")},
				{"tipCx", new MapAttrDef_T("int")},
				{"tipCy", new MapAttrDef_T("int")},
				{"tipMaxWidth", new MapAttrDef_T("int")},
				{"tipText", new MapAttrDef_T("string")},
				{"showStyle", new MapAttrDef_T("int")},
				{"movieSpe", new MapAttrDef_T("int")},
				{"angle", new MapAttrDef_T("int")},
				{"rotateType", new MapAttrDef_T("int")},
				{"movieLayer", new MapAttrDef_T("int")},
				{"scalePerX", new MapAttrDef_T("int")},
				{"scalePerY", new MapAttrDef_T("int")},
				{"onSelectByKey", new MapAttrDef_T("bool")},
				{"canSelectByKey", new MapAttrDef_T("bool")},
				{"canAutoBuildTopKey", new MapAttrDef_T("bool")},
				{"canAutoBuildLeftKey", new MapAttrDef_T("bool")},
				{"assignTopKeyBaseID", new MapAttrDef_T("string")},
				{"assignBottomKeyBaseID", new MapAttrDef_T("string")},
				{"assignLeftKeyBaseID", new MapAttrDef_T("string")},
				{"assignRightKeyBaseID", new MapAttrDef_T("string")},
				{"scrollBorder", new MapAttrDef_T("int")},
				{"hScrollHeight", new MapAttrDef_T("int")},
				{"vScrollWidth", new MapAttrDef_T("int")},
				{"vScrollSliderHeight", new MapAttrDef_T("int")},
				{"hScrollSliderWidth", new MapAttrDef_T("int")},
				{"scrollSliderBorder", new MapAttrDef_T("int")},
				{"scrollSliderAutosize", new MapAttrDef_T("bool")},
				{"scrollDecay", new MapAttrDef_T("int")},
				{"scrollPickupInterval", new MapAttrDef_T("int")},
				{"scrollSpeed", new MapAttrDef_T("int")},
				{"scrollInitPos", new MapAttrDef_T("int")},
				{"rememberScrollPos", new MapAttrDef_T("bool")},
				{"scrollParentLayerWhenGetFocus", new MapAttrDef_T("int")},
				{"isMaskAreaByKey", new MapAttrDef_T("bool")},
				{"ownEvt", new MapAttrDef_T("bool")},
				{"isEffectParentAutosize", new MapAttrDef_T("bool")},
				{"canUsedEvent", new MapAttrDef_T("bool")},
				{"canHandleEvent", new MapAttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapPanelAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region Panel
				{"isEnableScroll", new MapAttrDef_T("bool")},
				{"own", new MapAttrDef_T("bool")},
				{"autoSize", new MapAttrDef_T("bool")},
				{"backSpeed", new MapAttrDef_T("int")},
				{"bkH_T", new MapAttrDef_T("int")},
				{"bkH_B", new MapAttrDef_T("int")},
				{"bkW_L", new MapAttrDef_T("int")},
				{"bkW_R", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapLabelAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region Label
				{"bgColor", new MapAttrDef_T("intx16")},
				{"speed", new MapAttrDef_T("int")},
				{"autoSize", new MapAttrDef_T("bool")},
				{"autoFontSize", new MapAttrDef_T("bool")},
				{"scrollcountType", new MapAttrDef_T("int")},
				{"scrollTime", new MapAttrDef_T("int")},
				{"scrollRate", new MapAttrDef_T("int")},
				{"scrollRateHalf", new MapAttrDef_T("int")},
				{"scrollTimeMax", new MapAttrDef_T("int")},
				{"startXPer", new MapAttrDef_T("int")},
				{"defaultMsgTime", new MapAttrDef_T("int")},
				{"nextUIevent", new MapAttrDef_T("bool")},
				{"nextUIeventType", new MapAttrDef_T("int")},
				{"drawType", new MapAttrDef_T("int")},
				{"ellipsisWhenTooLong", new MapAttrDef_T("bool")},
				{"reelScrollDerection", new MapAttrDef_T("int")},
				{"reelScrollSpeed", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapButtonAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region Button
				{"wordWhole", new MapAttrDef_T("bool")},
				{"interval", new MapAttrDef_T("int")},
				{"blinktimes", new MapAttrDef_T("int")},
				{"blinkTextAreaX", new MapAttrDef_T("int")},
				{"blinkTextAreaY", new MapAttrDef_T("int")},
				{"blinkTextAreaW", new MapAttrDef_T("int")},
				{"blinkTextAreaH", new MapAttrDef_T("int")},
				{"slideOri", new MapAttrDef_T("int")},
				{"pressedEndBlink", new MapAttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapSkillButtonAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region SkillButton
				{"cdStyle", new MapAttrDef_T("int")},
				{"cdTime", new MapAttrDef_T("int")},
				{"cdRange", new MapAttrDef_T("int")},
				{"cdRGB", new MapAttrDef_T("intx16")},
				{"cdEx", new MapAttrDef_T("int")},
				{"cdEy", new MapAttrDef_T("int")},
				{"cdExN", new MapAttrDef_T("int")},
				{"cdEyN", new MapAttrDef_T("int")},
				{"showCdTime", new MapAttrDef_T("bool")},
				{"clockwiseRad", new MapAttrDef_T("int")},
				{"clockwiseOffsetx", new MapAttrDef_T("int")},
				{"clockwiseOffsety", new MapAttrDef_T("int")},
				{"clockwiseAngle", new MapAttrDef_T("int")},
				{"clockwiseOriginAngle", new MapAttrDef_T("int")},
				{"progressIncrease", new MapAttrDef_T("bool")},
				{"disableWhenBeginCold", new MapAttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapProgressAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region Progress
				{"min", new MapAttrDef_T("int")},
				{"max", new MapAttrDef_T("int")},
				{"value", new MapAttrDef_T("int")},
				{"ori", new MapAttrDef_T("int")},
				{"track", new MapAttrDef_T("bool")},
				{"sliderWidth", new MapAttrDef_T("int")},
				{"sliderHeight", new MapAttrDef_T("int")},
				{"changeSpeed", new MapAttrDef_T("int")},
				{"changeRate", new MapAttrDef_T("int")},
				{"clockwiseRad", new MapAttrDef_T("int")},
				{"clockwiseOffsetx", new MapAttrDef_T("int")},
				{"clockwiseOffsety", new MapAttrDef_T("int")},
				{"clockwiseAngle", new MapAttrDef_T("int")},
				{"clockwiseOriginAngle", new MapAttrDef_T("int")},
				{"sliderShowType", new MapAttrDef_T("int")},
				{"fillHeadTailShowType", new MapAttrDef_T("int")},
				{"preGrowthValue", new MapAttrDef_T("int")},
				{"decaySpeed", new MapAttrDef_T("int")},
				{"beginDecay", new MapAttrDef_T("bool")},
				{"sliderLeftFill", new MapAttrDef_T("bool")},
				{"delayValueRate", new MapAttrDef_T("int")},
				{"gridValue", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapRadioAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region Radio
				{"select", new MapAttrDef_T("bool")},
				{"ntw", new MapAttrDef_T("int")},
				{"wordWhole", new MapAttrDef_T("bool")},
				{"checkLayer", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapCheckAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region Check
				{"select", new MapAttrDef_T("bool")},
				{"ntw", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapListPanelAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region ListPanel
				{"lineHeight", new MapAttrDef_T("int")},
				{"own", new MapAttrDef_T("bool")},
				{"cel", new MapAttrDef_T("int")},
				{"celCountMax", new MapAttrDef_T("int")},
				{"select", new MapAttrDef_T("int")},
				{"autoSize", new MapAttrDef_T("bool")},
				{"maxSize", new MapAttrDef_T("int")},
				{"bkH_T", new MapAttrDef_T("int")},
				{"bkH_B", new MapAttrDef_T("int")},
				{"backSpeed", new MapAttrDef_T("int")},
				{"appendOri", new MapAttrDef_T("int")},
				{"lineSpace", new MapAttrDef_T("int")},
				{"removeExceedFromHead", new MapAttrDef_T("bool")},
				{"onBottomEventPercent", new MapAttrDef_T("int")},
				{"middleSelect", new MapAttrDef_T("int")},
				{"isMiddleCardList", new MapAttrDef_T("bool")},
				{"middleCardBorder", new MapAttrDef_T("int")},
				{"middleCardZoomValue", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapTabPanelAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region TabPanel
				{"cascadeOrder", new MapAttrDef_T("int")},
				{"alignment", new MapAttrDef_T("int")},
				{"tabIndent", new MapAttrDef_T("int")},
				{"tabInterval", new MapAttrDef_T("int")},
				{"tabPageSpacing", new MapAttrDef_T("int")},
				{"tabWidth", new MapAttrDef_T("int")},
				{"tabHeight", new MapAttrDef_T("int")},
				{"own", new MapAttrDef_T("bool")},
				{"duiqi", new MapAttrDef_T("int")},
				{"wordWhole", new MapAttrDef_T("bool")},
				{"tabChangeTime", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapPagePanelAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region PagePanel
				{"speed", new MapAttrDef_T("int")},
				{"own", new MapAttrDef_T("bool")},
				{"switchType", new MapAttrDef_T("int")},
				{"controlRotateType", new MapAttrDef_T("int")},
				{"turnEnable", new MapAttrDef_T("bool")},
				{"switchPageNeedlen", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapVirtualPadAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region VirtualPad
				{"vStyle", new MapAttrDef_T("int")},
				{"fingerpadr", new MapAttrDef_T("int")},
				{"pf", new MapAttrDef_T("int")},
				{"areaMaxWidthPer", new MapAttrDef_T("int")},
				{"areaMaxHeightPer", new MapAttrDef_T("int")},
				{"setAx", new MapAttrDef_T("int")},
				{"setAy", new MapAttrDef_T("int")},
				{"backTime", new MapAttrDef_T("int")},
				{"clickTime", new MapAttrDef_T("int")},
				{"interval", new MapAttrDef_T("int")},
				{"blinktimes", new MapAttrDef_T("int")},
				{"padToFingerDistanceMax", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapRichTextAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region RichText
				{"maxLength", new MapAttrDef_T("int")},
				{"maxLine", new MapAttrDef_T("int")},
				{"readOnly", new MapAttrDef_T("bool")},
				{"passwordChar", new MapAttrDef_T("bool")},
				{"wrodWrap", new MapAttrDef_T("bool")},
				{"vScrollBoarder", new MapAttrDef_T("int")},
				{"lineSpacing", new MapAttrDef_T("int")},
				{"speed", new MapAttrDef_T("int")},
				{"wordWhole", new MapAttrDef_T("bool")},
				{"autoSize", new MapAttrDef_T("bool")},
				{"richTips", new MapAttrDef_T("string")},
				{"convertIndex", new MapAttrDef_T("int")},
				{"inputType", new MapAttrDef_T("int")},
				{"bkH_T", new MapAttrDef_T("int")},
				{"bkH_B", new MapAttrDef_T("int")},
				{"beforeSkins", new MapAttrDef_T("string")},
				{"scrollTime", new MapAttrDef_T("int")},
				{"scrollTextSpeed", new MapAttrDef_T("int")},
				{"scrollText", new MapAttrDef_T("bool")},
				{"scrollcountType", new MapAttrDef_T("int")},
				{"backSpeed", new MapAttrDef_T("int")},
				{"textAnchorType", new MapAttrDef_T("int")},
				{"independentDrawSub", new MapAttrDef_T("bool")},
				{"alignBottomText", new MapAttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapPageTextAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region PageText
				{"pressedWidth", new MapAttrDef_T("int")},
				{"pressedHeight", new MapAttrDef_T("int")},
				{"PageNumHeight", new MapAttrDef_T("int")},
				{"PageNumWidth", new MapAttrDef_T("int")},
				{"PageNumIndent", new MapAttrDef_T("int")},
				{"lineSpacing", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapScriptPanelAttrDef = new Dictionary<string, MapAttrDef_T>
		{
		};

		Dictionary<string, MapAttrDef_T> conf_mapCountDownAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region CountDown
				{"start", new MapAttrDef_T("bool")},
				{"unit", new MapAttrDef_T("int")},
				{"days", new MapAttrDef_T("int")},
				{"hours", new MapAttrDef_T("int")},
				{"minutes", new MapAttrDef_T("int")},
				{"seconds", new MapAttrDef_T("int")},
				{"milliseconds", new MapAttrDef_T("int")},
				{"countType", new MapAttrDef_T("int")},
				{"timeout", new MapAttrDef_T("int")},
				{"countChangeRate", new MapAttrDef_T("float")},
				{"autoShowLength", new MapAttrDef_T("int")},
				{"timePreset", new MapAttrDef_T("time")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapApartPanelAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region ApartPanel
				{"own", new MapAttrDef_T("bool")},
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapDraggedPanelAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region DraggedPanel
				{"canDraggedCopy", new MapAttrDef_T("bool")},
				{"getInfoIndex", new MapAttrDef_T("int")},
				{"copyTime", new MapAttrDef_T("int")},
				{"own", new MapAttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapTurnTableAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region TurnTable
				{"tableCount", new MapAttrDef_T("int")},
				{"resultIndexString", new MapAttrDef_T("string")},
				{"interval", new MapAttrDef_T("int")},
				{"turnTime", new MapAttrDef_T("int")},
				{"maxTurntime", new MapAttrDef_T("int")},
				{"turnType", new MapAttrDef_T("int")},
				{"defaultRun", new MapAttrDef_T("bool")},
				{"maxSpeed", new MapAttrDef_T("int")},
				{"runAcceleration", new MapAttrDef_T("int")},
				{"backAcceleration", new MapAttrDef_T("int")},
				{"tableInterval", new MapAttrDef_T("int")},
				{"lineSpace", new MapAttrDef_T("int")},
				{"backTime", new MapAttrDef_T("int")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapDrawModelAttrDef = new Dictionary<string, MapAttrDef_T>
		{
		};

		Dictionary<string, MapAttrDef_T> conf_mapDropListAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region DropList
				{"appendOri", new MapAttrDef_T("int")},
				{"packWidth", new MapAttrDef_T("int")},
				{"packHeight", new MapAttrDef_T("int")},
				{"expansionWidth", new MapAttrDef_T("int")},
				{"expansionHeight", new MapAttrDef_T("int")},
				{"lineSpace", new MapAttrDef_T("int")},
				{"ignoreParentClip", new MapAttrDef_T("bool")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapEventAttrDef = new Dictionary<string, MapAttrDef_T>
			{
				#region Event
				{"type", new MapAttrDef_T("string")},
				{"function", new MapAttrDef_T("string")},
				{"sound", new MapAttrDef_T("string")}
				#endregion
			};

		Dictionary<string, MapAttrDef_T> conf_mapToolTipAttrDef = new Dictionary<string, MapAttrDef_T>
		{
		};

		public void initXmlValueDef()
		{
			m_mapCtrlDef = new Dictionary<string, Dictionary<string, MapAttrDef_T>>
			{
				#region boloUIControls
				{ "basic", conf_mapBaseAttrDef },
				{ "panel", conf_mapPanelAttrDef },
				{ "label", conf_mapLabelAttrDef },
				{ "button", conf_mapButtonAttrDef },
				{ "skillbutton", conf_mapSkillButtonAttrDef },
				{ "progress", conf_mapProgressAttrDef },
				{ "radio", conf_mapRadioAttrDef },
				{ "check", conf_mapCheckAttrDef },
				{ "listPanel", conf_mapListPanelAttrDef },
				{ "tabPanel", conf_mapTabPanelAttrDef },
				{ "pagePanel", conf_mapPagePanelAttrDef},
				{ "virtualpad", conf_mapVirtualPadAttrDef},
				{ "richText", conf_mapRichTextAttrDef},
				{ "pageText", conf_mapPageTextAttrDef},
				{ "scriptPanel", conf_mapScriptPanelAttrDef },
				{ "countDown", conf_mapCountDownAttrDef},
				{ "apartPanel", conf_mapApartPanelAttrDef},
				{ "draggedPanel", conf_mapDraggedPanelAttrDef},
				{ "turnTable", conf_mapTurnTableAttrDef},
				{ "drawModel", conf_mapDrawModelAttrDef },
				{ "dropList", conf_mapDropListAttrDef},
				{ "event", conf_mapEventAttrDef},
				{ "tooltip", conf_mapToolTipAttrDef}
				#endregion
			};
		}
		#endregion

	}
}

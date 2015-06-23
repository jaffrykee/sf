using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Interop;
using System.Runtime.InteropServices;
using System.Windows;

namespace UIEditor
{
	public class ControlHost : HwndHost
	{
		IntPtr m_hwndControl;
		IntPtr m_hwndHost;
		int m_hostHeight, m_hostWidth;

		public ControlHost(double width = 960, double height = 640)
		{
			m_hostWidth = (int)width;
			m_hostHeight = (int)height;
			//(PresentationSource.FromVisual(this) as System.Windows.Interop.HwndSource).AddHook(new System.Windows.Interop.HwndSourceHook(WndProc));
		}

		internal const int
			WS_CHILD = 0x40000000,
			WS_VISIBLE = 0x10000000,
			LBS_NOTIFY = 0x00000001,
			HOST_ID = 0x00000002,
			LISTBOX_ID = 0x00000001,
			WS_HSCROLL = 0x00100000,
			WS_VSCROLL = 0x00200000,
			WS_CLIPCHILDREN = 0x02000000,
			WS_BORDER = 0x00800000;

		public IntPtr hwndListBox
		{
			get { return m_hwndControl; }
		}

		//PInvoke declarations
		[DllImport("user32.dll", EntryPoint = "CreateWindowEx", CharSet = CharSet.Unicode)]
		internal static extern IntPtr CreateWindowEx(
			int dwExStyle,
			string lpszClassName,
			string lpszWindowName,
			int style,
			int x, int y,
			int width, int height,
			IntPtr hwndParent,
			IntPtr hMenu,
			IntPtr hInst,
			[MarshalAs(UnmanagedType.AsAny)] object pvParam);

		protected override HandleRef BuildWindowCore(HandleRef hwndParent)
		{
			m_hwndControl = IntPtr.Zero;
			m_hwndHost = IntPtr.Zero;

			m_hwndHost = CreateWindowEx(
				0, "static", "",
				WS_CHILD | WS_VISIBLE,
				0, 0,
				m_hostWidth, m_hostHeight,
				hwndParent.Handle,
				(IntPtr)HOST_ID,
				IntPtr.Zero,
				0);

			MainWindow pW = Window.GetWindow(this) as MainWindow;
			pW.m_hwndGLParent = (IntPtr)m_hwndHost;
			m_hwndControl = pW.m_hwndGLParent;
			String path;
            path = @"E:\mmo2013001\clienttools\DsUiEditor\dist\Debug\MinGW-Windows\dsuieditor.exe";
            //path = @".\dsuieditor.exe";
			System.Diagnostics.Process.Start(path, pW.m_hwndGLParent.ToString() + " " + m_hostWidth.ToString() + " " + m_hostHeight.ToString());

			return new HandleRef(this, m_hwndHost);
		}

		protected override IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
		{
			handled = false;

			return IntPtr.Zero;
		}

		protected override void DestroyWindowCore(HandleRef hwnd)
		{
			DestroyWindow(hwnd.Handle);
		}

		[DllImport("user32.dll", EntryPoint = "DestroyWindow", CharSet = CharSet.Unicode)]
		internal static extern bool DestroyWindow(IntPtr hwnd);
	}
}

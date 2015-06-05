using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UIEditor
{
	class StringDic
	{
		public static Dictionary<string, string> m_control = new Dictionary<string, string>
		{
			{ "basic", "基本"},
			{ "panel", "面板"},
			{ "label", "标签"},
			{ "button", "按钮"},
			{ "skillbutton", "技能按钮"},
			{ "progress", "进度条"},
			{ "radio", "单选按钮"},
			{ "check", "复选按钮"},
			{ "listPanel", "列表面板"},
			{ "tabPanel", "选项卡面板"},
			{ "pagePanel", ""},
			{ "virtualpad", "虚拟按盘"},
			{ "richText", "富文本框"},
			{ "pageText", ""},
			{ "scriptPanel", "脚本面板"},
			{ "countDown", "计时控件"},
			{ "apartPanel", "拆分面板"},
			{ "draggedPanel", ""},
			{ "turnTable", ""},
			{ "drawModel", ""},
			{ "dropList", ""},
			{ "event", "事件"},
			{ "tooltip", "说明"}
		};

		public static string getRandString(int pwdlen = 16, string pwdchars = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ")
		{
			string tmpstr = "";
			int iRandNum;
			Random rnd = new Random();

			for (int i = 0; i < pwdlen; i++)
			{
				iRandNum = rnd.Next(pwdchars.Length);
				tmpstr += pwdchars[iRandNum];
			}
			return tmpstr;
		}
	}
}

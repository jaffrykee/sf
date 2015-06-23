using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UIEditor
{
	class StringDic
	{
		public static Dictionary<string, string> m_mapStrControl = new Dictionary<string, string>
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

		public static Dictionary<string, string> m_mapStrNode = new Dictionary<string, string>
		{
			{"BoloUIEvent", "事件组"},
			{"skingroup", "皮肤组"},
			{"resource", "资源"},
			{"publicresource", "公共资源"},
			{"skin", "皮肤"},
			{"publicskin", "公共皮肤"},

			{"apperance", "外观节点"},
			{"imageShape", "图形"},
			{"textShape", "文本"}
		};

		public static Dictionary<string, string> m_mapStrAttr = new Dictionary<string, string>
		{
			{"ImageName", "图片名"},
			{"Dock", "停靠"},
			{"NineGrid", "是否NineGrid(九宫格)"},
			{"NGX", ""},
			{"NGY", ""},
			{"NGWidth", "NG宽"},
			{"NGHeight", "NG长"},
			{"LIGHT", ""},
			{"Color", "颜色"},

			{"X", ""},
			{"Y", ""},
			{"Width", "宽"},
			{"Height", "长"},
			{"topBorder", "顶边距"},
			{"bottomBorder", "底边距"},
			{"leftBorder", "左边距"},
			{"rightBorder", "右边距"},
			{"Anchor", "锚点"},
			{"angle", "旋转角度"},
			{"rotateType", "旋转类型"},
			{"mirrorType", "镜像"},

			{"Font", "字体"},
			{"fontSize", "字体大小"},
			{"Color0", "字体颜色0"},
			{"Color1", "字体颜色1"},
			{"Color2", "字体颜色2"},
			{"Style", "字体类型"}
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

		public static string getFileType(string filePath)
		{
			return filePath.Substring(filePath.LastIndexOf(".") + 1, (filePath.Length - filePath.LastIndexOf(".") - 1));
		}

		public static string getFileNameWithoutPath(string filePath)
		{
			return filePath.Substring(filePath.LastIndexOf("\\") + 1, (filePath.Length - filePath.LastIndexOf("\\") - 1));
		}

		public static string getFileNameWithoutType(string filePath)
		{
			string fileName = getFileNameWithoutPath(filePath);

			return fileName.Substring(0, fileName.LastIndexOf("."));
		}
	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Controls;
using System.Threading.Tasks;

namespace UIEditor
{
	static class StringDic
	{
		public static Dictionary<string, string> m_mapStrControl;
		public static Dictionary<string, string> m_mapStrNode;
		public static Dictionary<string, string> m_mapStrAttr;

		public static void initDic()
		{
			m_mapStrControl = new Dictionary<string, string>
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

			m_mapStrNode = new Dictionary<string, string>
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

			m_mapStrAttr = new Dictionary<string, string>
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
				{"mirrorType", "镜像"},

				{"Font", "字体"},
				{"fontSize", "字体大小"},
				{"Color0", "字体颜色0"},
				{"Color1", "字体颜色1"},
				{"Color2", "字体颜色2"},
				{"Style", "字体类型"},

				{"name", ""},
				{"baseID", ""},
				{"text", "文本"},
				{"alpha", "透明度"},
				{"x", "横坐标"},
				{"y", "纵坐标"},
				{"w", "宽度"},
				{"h", "高度"},
				{"maxWidth", "最大宽度"},
				{"maxHeight", "最大高度"},
				{"minWidth", "最小宽度"},
				{"minHeight", "最小高度"},
				{"visible", "可见性"},
				{"enable", "可用性"},
				{"dock", "停靠方式"},
				{"docklayer", "停靠层"},
				{"anchor", "边界锚"},
				{"anchorSelf", "自身锚点"},
				{"canFocus", "可以激活"},
				{"skin", "皮肤"},
				{"tips", ""},
				{"tipCx", ""},
				{"tipCy", ""},
				{"tipMaxWidth", ""},
				{"tipText", ""},
				{"showStyle", ""},
				{"movieSpe", ""},
				{"rotateType", "旋转中心"},
				{"movieLayer", ""},
				{"scalePerX", "缩放百分比X"},
				{"scalePerY", "缩放百分比Y"},
				{"onSelectByKey", ""},
				{"canSelectByKey", ""},
				{"canAutoBuildTopKey", ""},
				{"canAutoBuildLeftKey", ""},
				{"assignTopKeyBaseID", ""},
				{"assignBottomKeyBaseID", ""},
				{"assignLeftKeyBaseID", ""},
				{"assignRightKeyBaseID", ""},
				{"scrollBorder", "滚动条边距"},
				{"hScrollHeight", "水平滚动条高度"},
				{"vScrollWidth", "垂直滚动条宽度"},
				{"vScrollSliderHeight", "垂直滚动滑块高度"},
				{"hScrollSliderWidth", "水平滚动滑块宽度"},
				{"scrollSliderBorder", "滚动滑块边距"},
				{"scrollSliderAutosize", "滚动滑块大小自适应"},
				{"scrollDecay", "滚动条滑动衰减"},
				{"scrollPickupInterval", "滚动条初速度采样间隔"},
				{"scrollSpeed", "滚动条滚动速度"},
				{"scrollInitPos", "滚动条初始位置"},
				{"rememberScrollPos", "滚动条位置保留"},
				{"scrollParentLayerWhenGetFocus", "焦点滚动父容器层数"},
				{"isMaskAreaByKey", ""},
				{"ownEvt", "独占事件"},
				{"isEffectParentAutosize", "扩充父容器"},
				{"canUsedEvent", "可使用事件"},
				{"canHandleEvent", "可独占事件"},

				{"own", "独占屏幕"},
				{"autoSize", "自适应大小"},
				{"backSpeed", "复位速度"},
				{"bkH_B", "下边框高度"},
				{"bkH_T", "上边框高度"},
				{"bkW_L", "左边框宽度"},
				{"bkW_R", "右边框宽度"}
			};
		}

		public static void getNameAndTip(MenuItem menuItem, string key, Dictionary<string, string> mapStr)
		{
			string strName;

			menuItem.ToolTip = key;
			if (mapStr.TryGetValue(key, out strName) && strName != "")
			{
				menuItem.Header = strName;
			}
			else
			{
				menuItem.Header = key;
			}
		}

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

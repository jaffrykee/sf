﻿#pragma once
#pragma execution_character_set("utf-8")

using namespace std;

class __declspec(dllexport) SFPlayerBuffer
{
public:
	int m_id;
	PCWSTR m_name;
	PCWSTR m_headImgPath;
	D2D_RECT_U m_headImgRect;
};

class __declspec(dllexport) SFSkillFrame
{
public:
	int m_id;
	D2D_VECTOR_2F m_move;
	ID2D1Bitmap* m_imgFrame;
	bool m_enBody;
	D2D_RECT_F m_boxBody;
	bool m_enAttack;
	D2D_RECT_F m_boxAttack;
	bool m_enChain;
};

class __declspec(dllexport) SFSkill
{
public:
	int m_id;
	string m_name;
	SF_EKA m_eka;
	int m_maxFrame;
	list<SFSkillFrame> m_skillFrames;
};

class __declspec(dllexport) SFPlayer
{
public:
	//人物id，初始化调用资源用
	string m_id;
	//属于哪个场景
	SFActScene* m_pScene;
	SFSpriteGroup* m_pGroup;
	//皮肤id，初始化调用资源用
	int m_skinId;
	string m_name;
	//代表P1还是P2，即在左边还是右边
	int m_pid;
	D2D_POINT_2U m_headImgWH;
	//全局配置的引用
	SFConfig* m_pSfconfig;
	//玩家资源
	SFResPlayer* m_resPlayer;

	//按键状态
	SFPEventStatus m_eStatus;
	//心跳超时计时
	UINT m_iTimeOut;
	//被击状态
	SF_ASH m_hitStatus;
	//站立跳跃状态等
	SF_AS m_standStatus;

	//当前等待打印的技能
	SF_EKA m_nowSkill;
	SF_AS m_nowAs;
	SF_SSSE m_nowSsse;
	//当前等待打印的技能的帧计数器
	UINT m_countSkillFrame;

#pragma region 物理
	//当前位置
	D2D1_POINT_2F m_position;

	//朝向，true为朝右
	bool m_isTwdRight;
	//旋转角度
	double m_angle;
	bool m_enAngle;

	double m_phyax;
	double m_phyay;
	double m_phyvx;
	double m_phyvy;

#pragma endregion

	SFPlayer(UINT id, SF_SKN skinId, int pid, SFActScene* pScene = NULL);
	SFPlayer(string id, SF_SKN skinId, int pid, SFActScene* pScene = NULL);
	~SFPlayer();
	void setEventListTimeout();
	void setDownStatusEnable(SF_EK val);
	void setDownStatusDisable(SF_EK val);
	void setHitStatus(SF_ASH ash);
	bool getEnableSavedInSkill(SF_EKA skill, SF_AS sta);
	bool getEnableUpEventInSkill(SF_EKA skill, SF_AS sta);
	SF_EKA getActionSkill(string ekaStr);
	SF_EK getLastKeyFromSkill(SF_EKA skill);
	bool upEvent(SF_EK key);
	bool downEvent(SF_EK key);
	int getMaxSkillFrame();
	void moveToNextFrame();
	void doTimer(SF_TEV);
};

//将来会改为继承关系，也有可能不改了
typedef SFPlayer SFSprite;
#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>

using namespace std;

class SFPlayerBuffer
{
public:
	int m_id;
	PCWSTR m_name;
	PCWSTR m_headImgPath;
	D2D_RECT_U m_headImgRect;
};

class SFSkillFrame
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

class SFSkill
{
public:
	int m_id;
	string m_name;
	SF_EKA m_eka;
	int m_maxFrame;
	list<SFSkillFrame> m_skillFrames;
};

class SFPlayer
{
public:
	//人物id，初始化调用资源用
	int m_id;
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

	//技能资源
	SFSkill* m_aSkill[SF_EKA::EKA_MAX];

	//按键状态
	SFPEventStatus m_eStatus;
	SF_ASH m_hitStatus;
	SF_AS m_standStatus;

	//当前等待打印的技能
	SF_EKA m_nowSkill;
	//当前等待打印的技能的帧计数器
	int m_countSkillFrame;

	SFPlayer(unsigned int id, SF_SKN skinId, int pid);
	~SFPlayer();
	void setUpEventListTimeout();
	void enableDownStatus(SF_EKD val);
	void disableDownStatus(SF_EKD val);
	void addEvent(SF_EKU val);
	string getEkaString(string tail);
	SF_EKA getActionSkill(string ekaStr);
	bool selectSkill(SF_EKD key);
	bool doSkill();
	int getMaxSkillFrame();
	void moveToNextFrame();
};
#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>
#include <list>

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
	bool m_enAtted;
	D2D_RECT_F m_rAtted;
	bool m_enAtt;
	D2D_RECT_F m_rAtt;
	bool m_enBreak;
	bool m_enChain;

};

#pragma region 虚拟按键事件编号define
#define EK_8U 0x01
#define EK_8D 0x02
#define EK_4U 0x03
#define EK_4D 0x04
#define EK_2U 0x05
#define EK_2D 0x06
#define EK_6U 0x07
#define EK_6D 0x08
#define EK_S1U 0x21
#define EK_S1D 0x22
#define EK_S2U 0x23
#define EK_S2D 0x24
#define EK_AU 0x41
#define EK_AD 0x42
#define EK_BU 0x43
#define EK_BD 0x44
#define EK_CU 0x45
#define EK_CD 0x46
#define EK_DU 0x47
#define EK_DD 0x48
#define EK_EU 0x49
#define EK_ED 0x4a
#define EK_FU 0x4b
#define EK_FD 0x4c
#pragma endregion

#pragma region 虚拟按键事件连击define
enum SF_EKF
{
	EKF_236A = 1, EKF_236Ad, EKF_236B, EKF_236Bd, EKF_236C, EKF_236Cd, EKF_236D, EKF_236Dd,
	EKF_214A, EKF_214Ad, EKF_214B, EKF_214Bd, EKF_214C, EKF_214Cd, EKF_214D, EKF_214Dd,
	EKF_6326A, EKF_6326Ad, EKF_6326B, EKF_6326Bd, EKF_6326C, EKF_6326Cd, EKF_6326D, EKF_6326Dd,
	EKF_4124A, EKF_4124Ad, EKF_4124B, EKF_4124Bd, EKF_4124C, EKF_4124Cd, EKF_4124D, EKF_4124Dd,
	EKF_41236A, EKF_41236Ad, EKF_41236B, EKF_41236Bd, EKF_41236C, EKF_41236Cd, EKF_41236D, EKF_41236Dd,
	EKF_63214A, EKF_63214Ad, EKF_63214B, EKF_63214Bd, EKF_63214C, EKF_63214Cd, EKF_63214D, EKF_63214Dd,
};
#pragma endregion

#define SF_SKILL_EK_MAX 16

struct SFSkillKeys
{
	int m_body[SF_SKILL_EK_MAX];
};

class SFSkill
{
public:
	int m_id;
	int m_name;
	PCWSTR m_key;
};

class SFPlayer
{
public:
	int m_id;
	PCWSTR m_name;
	D2D_POINT_2U m_headImgWH;
};
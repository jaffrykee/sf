#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>
#include <map>

#pragma region ��������define
#define KD_P1UP VK_W
#define KD_P1LF VK_A
#define KD_P1DW VK_S
#define KD_P1RG VK_D
#define KD_P1AA VK_U
#define KD_P1BB VK_I
#define KD_P1CC VK_O
#define KD_P1DD VK_J
#define KD_P1EE VK_K
#define KD_P1FF VK_L
#define KD_P1ST VK_1
#define KD_P1MN VK_2

#define KD_P2UP VK_UP
#define KD_P2LF VK_LEFT
#define KD_P2DW VK_DOWN
#define KD_P2RG VK_RIGHT
#define KD_P2AA VK_NUMPAD1
#define KD_P2BB VK_NUMPAD2
#define KD_P2CC VK_NUMPAD3
#define KD_P2DD VK_NUMPAD0
#define KD_P2EE VK_NUMPAD5
#define KD_P2FF VK_NUMPAD6
#define KD_P2ST VK_3
#define KD_P2MN VK_4
#pragma endregion

#pragma region ���ⰴ���¼�define(SF_EK)
enum SF_EKD
{
	EK_8D, EK_4D, EK_2D, EK_6D, EK_S1D, EK_S2D,
	EK_AD, EK_BD, EK_CD, EK_DD, EK_ED, EK_FD,
	EKD_MAX
};

enum SF_EKU
{
	EK_8U, EK_4U, EK_2U, EK_6U, EK_S1U, EK_S2U,
	EK_AU, EK_BU, EK_CU, EK_DU, EK_EU, EK_FU,
	EKU_MAX
};
#pragma endregion

#pragma region ��ʱ��define(TMR)
enum TMR_ID
{
	TMR_NULL, TMR_PAINT, TMR_ACTION, TMR_SKILL,
	TMR_MAX
};

const unsigned int gc_arrTmr[TMR_MAX] = { 0, 15, 10, 100 };
#pragma endregion

#pragma region ��ɫ��ǰ����״̬
enum SF_AS
{
	AS_STAND, AS_J, AS_B, AS_S, AS_F, AS_DF, AS_SDF, AS_JEX, AS_R, AS_DDG,
	AS_MAX
};
#pragma endregion

#pragma region ���ⰴ���¼�����define(SF_EKF)
/*
j:jump
b:back
s:squat
f:front
def:defend
defs:squat defend
jex:big jump
r:run
ddg:dodge(����)
���Ͼ�Ϊ��������̬����Ҫ�����������򣬼����ڵ��棬�Ҳ��ܵ����¡�
��Ϊskill������±�ʹ�ã����Դ�0��ʼ��
*/
enum SF_EKF
{
	EKF_j, EKF_jex, EKF_rj, EKF_rjex,
	EKF_fj, EKF_fjex, EKF_bj, EKF_bjex,
#if 0
	EKF_jA, EKF_jB, EKF_jC, EKF_jD,
	//���ܻ����Ժ�汾�õ��������ܵ��˶��켣��ͼ�������߼��ֿ���
#else
	EKF_jA, EKF_jexA, EKF_rjA, EKF_rjexA,
	EKF_fjA, EKF_fjexA, EKF_bjA, EKF_bjexA,
	EKF_jB, EKF_jexB, EKF_rjB, EKF_rjexB,
	EKF_fjB, EKF_fjexB, EKF_bjB, EKF_bjexB,
	EKF_jC, EKF_jexC, EKF_rjC, EKF_rjexC,
	EKF_fjC, EKF_fjexC, EKF_bjC, EKF_bjexC,
	EKF_jD, EKF_jexD, EKF_rjD, EKF_rjexD,
	EKF_fjD, EKF_fjexD, EKF_bjD, EKF_bjexD,
#endif
	EKF_b, EKF_def, EKF_defs,
	EKF_s, EKF_sA, EKF_sB, EKF_sC, EKF_sD,
	EKF_f, EKF_fA, EKF_fB, EKF_fC, EKF_fD,
	EKF_r, EKF_ddg,

	EKF_SKILL_MIN,
	EKF_8, EKF_4, EKF_2, EKF_6, EKF_44, EKF_66,
	EKF_A, EKF_B, EKF_C, EKF_D,
	EKF_26A, EKF_26B, EKF_26C, EKF_26D,
	EKF_24A, EKF_24B, EKF_24C, EKF_24D,
	EKF_626A, EKF_626B, EKF_626C, EKF_626D,
	EKF_424A, EKF_424B, EKF_424C, EKF_424D,
	EKF_426A, EKF_426B, EKF_426C, EKF_426D,
	EKF_624A, EKF_624B, EKF_624C, EKF_624D,
	EKF_2624A, EKF_2624B, EKF_2624C, EKF_2624D,
	EKF_2426A, EKF_2426B, EKF_2426C, EKF_2426D,
	EKF_2626A, EKF_2626B, EKF_2626C, EKF_2626D,
	EKF_2424A, EKF_2424B, EKF_2424C, EKF_2424D,
	EKF_624624A, EKF_624624B, EKF_624624C, EKF_624624D,
	EKF_426426A, EKF_426426B, EKF_426426C, EKF_426426D,
	EKF_MAX
};

/*
	���������жϡ�
*/
enum SF_EKA
{
	EKA_8, EKA_4, EKA_2, EKA_6, EKA_44, EKA_66,
	EKA_A, EKA_B, EKA_C, EKA_D,
	EKA_26A, EKA_26B, EKA_26C, EKA_26D,
	EKA_24A, EKA_24B, EKA_24C, EKA_24D,
	EKA_626A, EKA_626B, EKA_626C, EKA_626D,
	EKA_424A, EKA_424B, EKA_424C, EKA_424D,
	EKA_426A, EKA_426B, EKA_426C, EKA_426D,
	EKA_624A, EKA_624B, EKA_624C, EKA_624D,
	EKA_2624A, EKA_2624B, EKA_2624C, EKA_2624D,
	EKA_2426A, EKA_2426B, EKA_2426C, EKA_2426D,
	EKA_2626A, EKA_2626B, EKA_2626C, EKA_2626D,
	EKA_2424A, EKA_2424B, EKA_2424C, EKA_2424D,
	EKA_624624A, EKA_624624B, EKA_624624C, EKA_624624D,
	EKA_426426A, EKA_426426B, EKA_426426C, EKA_426426D,
	EKA_MAX
};
#pragma endregion

/* ȫ�����õ����� */
class SFConfig
{
public:
	static map<string, int> s_mEkf;
	static map<string, int> s_mEka;

private:
	SFConfig()
	{
		int i = 0;

		s_mEkf.insert(pair<string, int>("j", EKF_j));
		s_mEkf.insert(pair<string, int>("jex", EKF_jex));
		s_mEkf.insert(pair<string, int>("rj", EKF_rj));
		s_mEkf.insert(pair<string, int>("rjex", EKF_rjex));
		s_mEkf.insert(pair<string, int>("fj", EKF_fj));
		s_mEkf.insert(pair<string, int>("fjex", EKF_fjex));
		s_mEkf.insert(pair<string, int>("bj", EKF_bj));
		s_mEkf.insert(pair<string, int>("bjex", EKF_bjex));
		s_mEkf.insert(pair<string, int>("jA", EKF_jA));
		s_mEkf.insert(pair<string, int>("jexA", EKF_jexA));
		s_mEkf.insert(pair<string, int>("rjA", EKF_rjA));
		s_mEkf.insert(pair<string, int>("rjexA", EKF_rjexA));
		s_mEkf.insert(pair<string, int>("fjA", EKF_fjA));
		s_mEkf.insert(pair<string, int>("fjexA", EKF_fjexA));
		s_mEkf.insert(pair<string, int>("bjA", EKF_bjA));
		s_mEkf.insert(pair<string, int>("bjexA", EKF_bjexA));
		s_mEkf.insert(pair<string, int>("jB", EKF_jB));
		s_mEkf.insert(pair<string, int>("jexB", EKF_jexB));
		s_mEkf.insert(pair<string, int>("rjB", EKF_rjB));
		s_mEkf.insert(pair<string, int>("rjexB", EKF_rjexB));
		s_mEkf.insert(pair<string, int>("fjB", EKF_fjB));
		s_mEkf.insert(pair<string, int>("fjexB", EKF_fjexB));
		s_mEkf.insert(pair<string, int>("bjB", EKF_bjB));
		s_mEkf.insert(pair<string, int>("bjexB", EKF_bjexB));
		s_mEkf.insert(pair<string, int>("jC", EKF_jC));
		s_mEkf.insert(pair<string, int>("jexC", EKF_jexC));
		s_mEkf.insert(pair<string, int>("rjC", EKF_rjC));
		s_mEkf.insert(pair<string, int>("rjexC", EKF_rjexC));
		s_mEkf.insert(pair<string, int>("fjC", EKF_fjC));
		s_mEkf.insert(pair<string, int>("fjexC", EKF_fjexC));
		s_mEkf.insert(pair<string, int>("bjC", EKF_bjC));
		s_mEkf.insert(pair<string, int>("bjexC", EKF_bjexC));
		s_mEkf.insert(pair<string, int>("jD", EKF_jD));
		s_mEkf.insert(pair<string, int>("jexD", EKF_jexD));
		s_mEkf.insert(pair<string, int>("rjD", EKF_rjD));
		s_mEkf.insert(pair<string, int>("rjexD", EKF_rjexD));
		s_mEkf.insert(pair<string, int>("fjD", EKF_fjD));
		s_mEkf.insert(pair<string, int>("fjexD", EKF_fjexD));
		s_mEkf.insert(pair<string, int>("bjD", EKF_bjD));
		s_mEkf.insert(pair<string, int>("bjexD", EKF_bjexD));
		s_mEkf.insert(pair<string, int>("b", EKF_b));
		s_mEkf.insert(pair<string, int>("def", EKF_def));
		s_mEkf.insert(pair<string, int>("defs", EKF_defs));
		s_mEkf.insert(pair<string, int>("s", EKF_s));
		s_mEkf.insert(pair<string, int>("sA", EKF_sA));
		s_mEkf.insert(pair<string, int>("sB", EKF_sB));
		s_mEkf.insert(pair<string, int>("sC", EKF_sC));
		s_mEkf.insert(pair<string, int>("sD", EKF_sD));
		s_mEkf.insert(pair<string, int>("f", EKF_f));
		s_mEkf.insert(pair<string, int>("fA", EKF_fA));
		s_mEkf.insert(pair<string, int>("fB", EKF_fB));
		s_mEkf.insert(pair<string, int>("fC", EKF_fC));
		s_mEkf.insert(pair<string, int>("fD", EKF_fD));
		s_mEkf.insert(pair<string, int>("r", EKF_r));
		s_mEkf.insert(pair<string, int>("ddg", EKF_ddg));
		s_mEkf.insert(pair<string, int>("A", EKF_A));
		s_mEkf.insert(pair<string, int>("B", EKF_B));
		s_mEkf.insert(pair<string, int>("C", EKF_C));
		s_mEkf.insert(pair<string, int>("D", EKF_D));
		s_mEkf.insert(pair<string, int>("8", EKF_8));
		s_mEkf.insert(pair<string, int>("4", EKF_4));
		s_mEkf.insert(pair<string, int>("2", EKF_2));
		s_mEkf.insert(pair<string, int>("6", EKF_6));
		s_mEkf.insert(pair<string, int>("44", EKF_44));
		s_mEkf.insert(pair<string, int>("66", EKF_66));
		s_mEkf.insert(pair<string, int>("26A", EKF_26A));
		s_mEkf.insert(pair<string, int>("26B", EKF_26B));
		s_mEkf.insert(pair<string, int>("26C", EKF_26C));
		s_mEkf.insert(pair<string, int>("26D", EKF_26D));
		s_mEkf.insert(pair<string, int>("24A", EKF_24A));
		s_mEkf.insert(pair<string, int>("24B", EKF_24B));
		s_mEkf.insert(pair<string, int>("24C", EKF_24C));
		s_mEkf.insert(pair<string, int>("24D", EKF_24D));
		s_mEkf.insert(pair<string, int>("626A", EKF_626A));
		s_mEkf.insert(pair<string, int>("626B", EKF_626B));
		s_mEkf.insert(pair<string, int>("626C", EKF_626C));
		s_mEkf.insert(pair<string, int>("626D", EKF_626D));
		s_mEkf.insert(pair<string, int>("424A", EKF_424A));
		s_mEkf.insert(pair<string, int>("424B", EKF_424B));
		s_mEkf.insert(pair<string, int>("424C", EKF_424C));
		s_mEkf.insert(pair<string, int>("424D", EKF_424D));
		s_mEkf.insert(pair<string, int>("426A", EKF_426A));
		s_mEkf.insert(pair<string, int>("426B", EKF_426B));
		s_mEkf.insert(pair<string, int>("426C", EKF_426C));
		s_mEkf.insert(pair<string, int>("426D", EKF_426D));
		s_mEkf.insert(pair<string, int>("624A", EKF_624A));
		s_mEkf.insert(pair<string, int>("624B", EKF_624B));
		s_mEkf.insert(pair<string, int>("624C", EKF_624C));
		s_mEkf.insert(pair<string, int>("624D", EKF_624D));
		s_mEkf.insert(pair<string, int>("2624A", EKF_2624A));
		s_mEkf.insert(pair<string, int>("2624B", EKF_2624B));
		s_mEkf.insert(pair<string, int>("2624C", EKF_2624C));
		s_mEkf.insert(pair<string, int>("2624D", EKF_2624D));
		s_mEkf.insert(pair<string, int>("2426A", EKF_2426A));
		s_mEkf.insert(pair<string, int>("2426B", EKF_2426B));
		s_mEkf.insert(pair<string, int>("2426C", EKF_2426C));
		s_mEkf.insert(pair<string, int>("2426D", EKF_2426D));
		s_mEkf.insert(pair<string, int>("2626A", EKF_2626A));
		s_mEkf.insert(pair<string, int>("2626B", EKF_2626B));
		s_mEkf.insert(pair<string, int>("2626C", EKF_2626C));
		s_mEkf.insert(pair<string, int>("2626D", EKF_2626D));
		s_mEkf.insert(pair<string, int>("2424A", EKF_2424A));
		s_mEkf.insert(pair<string, int>("2424B", EKF_2424B));
		s_mEkf.insert(pair<string, int>("2424C", EKF_2424C));
		s_mEkf.insert(pair<string, int>("2424D", EKF_2424D));
		s_mEkf.insert(pair<string, int>("624624A", EKF_624624A));
		s_mEkf.insert(pair<string, int>("624624B", EKF_624624B));
		s_mEkf.insert(pair<string, int>("624624C", EKF_624624C));
		s_mEkf.insert(pair<string, int>("624624D", EKF_624624D));
		s_mEkf.insert(pair<string, int>("426426A", EKF_426426A));
		s_mEkf.insert(pair<string, int>("426426B", EKF_426426B));
		s_mEkf.insert(pair<string, int>("426426C", EKF_426426C));
		s_mEkf.insert(pair<string, int>("426426D", EKF_426426D));
		s_mEkf.insert(pair<string, int>("MAX", EKF_MAX));

		s_mEka.insert(pair<string, int>("A", EKA_A));
		s_mEka.insert(pair<string, int>("B", EKA_B));
		s_mEka.insert(pair<string, int>("C", EKA_C));
		s_mEka.insert(pair<string, int>("D", EKA_D));
		s_mEka.insert(pair<string, int>("8", EKA_8));
		s_mEka.insert(pair<string, int>("4", EKA_4));
		s_mEka.insert(pair<string, int>("2", EKA_2));
		s_mEka.insert(pair<string, int>("6", EKA_6));
		s_mEka.insert(pair<string, int>("44", EKA_44));
		s_mEka.insert(pair<string, int>("66", EKA_66));
		s_mEka.insert(pair<string, int>("26A", EKA_26A));
		s_mEka.insert(pair<string, int>("26B", EKA_26B));
		s_mEka.insert(pair<string, int>("26C", EKA_26C));
		s_mEka.insert(pair<string, int>("26D", EKA_26D));
		s_mEka.insert(pair<string, int>("24A", EKA_24A));
		s_mEka.insert(pair<string, int>("24B", EKA_24B));
		s_mEka.insert(pair<string, int>("24C", EKA_24C));
		s_mEka.insert(pair<string, int>("24D", EKA_24D));
		s_mEka.insert(pair<string, int>("626A", EKA_626A));
		s_mEka.insert(pair<string, int>("626B", EKA_626B));
		s_mEka.insert(pair<string, int>("626C", EKA_626C));
		s_mEka.insert(pair<string, int>("626D", EKA_626D));
		s_mEka.insert(pair<string, int>("424A", EKA_424A));
		s_mEka.insert(pair<string, int>("424B", EKA_424B));
		s_mEka.insert(pair<string, int>("424C", EKA_424C));
		s_mEka.insert(pair<string, int>("424D", EKA_424D));
		s_mEka.insert(pair<string, int>("426A", EKA_426A));
		s_mEka.insert(pair<string, int>("426B", EKA_426B));
		s_mEka.insert(pair<string, int>("426C", EKA_426C));
		s_mEka.insert(pair<string, int>("426D", EKA_426D));
		s_mEka.insert(pair<string, int>("624A", EKA_624A));
		s_mEka.insert(pair<string, int>("624B", EKA_624B));
		s_mEka.insert(pair<string, int>("624C", EKA_624C));
		s_mEka.insert(pair<string, int>("624D", EKA_624D));
		s_mEka.insert(pair<string, int>("2624A", EKA_2624A));
		s_mEka.insert(pair<string, int>("2624B", EKA_2624B));
		s_mEka.insert(pair<string, int>("2624C", EKA_2624C));
		s_mEka.insert(pair<string, int>("2624D", EKA_2624D));
		s_mEka.insert(pair<string, int>("2426A", EKA_2426A));
		s_mEka.insert(pair<string, int>("2426B", EKA_2426B));
		s_mEka.insert(pair<string, int>("2426C", EKA_2426C));
		s_mEka.insert(pair<string, int>("2426D", EKA_2426D));
		s_mEka.insert(pair<string, int>("2626A", EKA_2626A));
		s_mEka.insert(pair<string, int>("2626B", EKA_2626B));
		s_mEka.insert(pair<string, int>("2626C", EKA_2626C));
		s_mEka.insert(pair<string, int>("2626D", EKA_2626D));
		s_mEka.insert(pair<string, int>("2424A", EKA_2424A));
		s_mEka.insert(pair<string, int>("2424B", EKA_2424B));
		s_mEka.insert(pair<string, int>("2424C", EKA_2424C));
		s_mEka.insert(pair<string, int>("2424D", EKA_2424D));
		s_mEka.insert(pair<string, int>("624624A", EKA_624624A));
		s_mEka.insert(pair<string, int>("624624B", EKA_624624B));
		s_mEka.insert(pair<string, int>("624624C", EKA_624624C));
		s_mEka.insert(pair<string, int>("624624D", EKA_624624D));
		s_mEka.insert(pair<string, int>("426426A", EKA_426426A));
		s_mEka.insert(pair<string, int>("426426B", EKA_426426B));
		s_mEka.insert(pair<string, int>("426426C", EKA_426426C));
		s_mEka.insert(pair<string, int>("426426D", EKA_426426D));
		s_mEka.insert(pair<string, int>("MAX", EKA_MAX));
	}
	static SFConfig *m_pInstance;
	class SFCGarbo   //����Ψһ��������������������ɾ��CSingleton��ʵ��  
	{
	public:
		~SFCGarbo()
		{
			if (SFConfig::m_pInstance)
				delete SFConfig::m_pInstance;
		}
	};
	static SFCGarbo s_garbo;  //����һ����̬��Ա�������������ʱ��ϵͳ���Զ�����������������  
public:
	static SFConfig * GetInstance()
	{
		if (m_pInstance == NULL)  //�ж��Ƿ��һ�ε���  
			m_pInstance = new SFConfig();
		return m_pInstance;
	}
};
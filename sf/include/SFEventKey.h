#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>
#include <list>

using namespace std;

#pragma region ���ⰴ���¼�define(SF_EK)
//��Ϊ�����±꣬������0��ʼ
enum SF_EKD
{
	EK_8D, EK_4D, EK_2D, EK_6D, EK_S1D, EK_S2D,
	EK_AD, EK_BD, EK_CD, EK_DD, EK_ED, EK_FD,
	EKD_MAX
};

//��Ϊֵ�������Ǵ�1��ʼ
enum SF_EKU
{
	EK_8U = 1, EK_4U, EK_2U, EK_6U, EK_S1U, EK_S2U,
	EK_AU, EK_BU, EK_CU, EK_DU, EK_EU, EK_FU,
	EKU_MAX
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
	ddg:dodge
	���Ͼ�Ϊ��������̬����Ҫ�����������򣬼����ڵ��棬�Ҳ��ܵ����¡�
	��Ϊskill������±�ʹ�ã����Դ�0��ʼ��
*/
enum SF_EKF
{
	EKF_A, EKF_B, EKF_C, EKF_D,

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

#pragma endregion

//�����ж��б��������Ŀ
#define EKL_MAX 6

//�����ж���ʱʱ��(ms)
#define EKL_TIMEOUT TMR_CHAIN_MS

/*
	���а���up�¼��б����У��͵�ǰ����down״̬���顣
*/
class SFPEventStatus
{
public:
	list<SF_EKU> m_lUp;
	unsigned char m_aStatus[EKD_MAX];

	SFPEventStatus()
	{
		for (int i = 0; i<EKD_MAX; i++)
		{
			m_aStatus[i] = 0;
		}
	}

	void setTimeout()
	{
		m_lUp.empty();
	}

	void addEvent(SF_EKU val)
	{
		if (m_lUp.size() >= EKL_MAX)
		{
			m_lUp.pop_front();
		}
		m_lUp.push_back(val);
	}
};
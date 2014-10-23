#include <init.h>
#include <list>

using namespace std;

#pragma region 虚拟按键事件define(SF_EK)
//作为数组下标，所以是0开始
enum SF_EKD
{
	EK_8D, EK_4D, EK_2D, EK_6D, EK_S1D, EK_S2D,
	EK_AD, EK_BD, EK_CD, EK_DD, EK_ED, EK_FD,
	EKD_MAX
};

//作为值，所以是从1开始
enum SF_EKU
{
	EK_8U = 1, EK_4U, EK_2U, EK_6U, EK_S1U, EK_S2U,
	EK_AU, EK_BU, EK_CU, EK_DU, EK_EU, EK_FU,
	EKU_MAX
};
#pragma endregion

#pragma region 虚拟按键事件连锁define(SF_EKF)
enum SF_EKF
{
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
#pragma endregion

#define EKL_MAX 6

class SFPlayerStatus
{
public:
	static const int s_lMax = EKL_MAX;
	list<SF_EKU> m_lChain;
	unsigned char m_aStatus[EKD_MAX];

	SFPlayerStatus()
	{
		for (int i = 0; i<EKD_MAX; i++)
		{
			m_aStatus[i] = 0;
		}
	}

	void setTimeout()
	{
		m_lChain.empty();
	}

	void addEvent(SF_EKU val)
	{
		if (m_lChain.size() >= s_lMax)
		{
			m_lChain.pop_front();
		}
		m_lChain.push_back(val);
	}
};
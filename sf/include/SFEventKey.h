#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>
#include <list>

using namespace std;

//技能判定列表缓存最大数目
#define EKL_MAX 6

//技能判定超时时间(ms)
#define EKL_TIMEOUT TMR_CHAIN_MS

/*
	内有按键up事件列表（序列）和当前按键down状态数组。
*/
class SFPEventStatus
{
public:
	string m_sUp;
	unsigned char m_aStatus[EKD_MAX];

	SFPEventStatus()
	{
		for (int i = 0; i<EKD_MAX; i++)
		{
			m_aStatus[i] = 0;
		}
	}

	char getEkuChar(SF_EKU val)
	{
		switch (val)
		{
			case EK_8U:
				return '8';
			case EK_4U:
				return '4';
			case EK_2U:
				return '2';
			case EK_6U:
				return '6';
#if 0
			case EK_S1U:
				return 'S';
			case EK_S2U:
				return 'T';
#endif
			case EK_AU:
				return 'A';
			case EK_BU:
				return 'B';
			case EK_CU:
				return 'C';
			case EK_DU:
				return 'D';
#if 0
			case EK_EU:
				return 'E';
			case EK_FU:
				return 'F';
#endif
			default:
				return 0;
		}
	}

	char getEkdChar(SF_EKD val)
	{
		switch (val)
		{
		case EK_8D:
			return '8';
		case EK_4D:
			return '4';
		case EK_2D:
			return '2';
		case EK_6D:
			return '6';
#if 0
		case EK_S1D:
			return 'S';
		case EK_S2D:
			return 'T';
#endif
		case EK_AD:
			return 'A';
		case EK_BD:
			return 'B';
		case EK_CD:
			return 'C';
		case EK_DD:
			return 'D';
#if 0
		case EK_ED:
			return 'E';
		case EK_FD:
			return 'F';
#endif
		default:
			return 0;
		}
	}

	void setTimeout()
	{
		m_sUp = "";
	}

	int addEvent(SF_EKU val)
	{
		char cVal = '\0';

		cVal = getEkuChar(val);
		if (cVal)
		{
			if (m_sUp.size() >= EKL_MAX)
			{
				m_sUp = m_sUp.substr(1, EKL_MAX);
			}
			m_sUp.push_back(cVal);
			return m_sUp.size();
		}
		else
		{
			return 0;
		}
	}
};
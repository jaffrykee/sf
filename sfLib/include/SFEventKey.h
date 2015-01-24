#pragma once
#pragma execution_character_set("utf-8")

using namespace std;

//技能判定列表缓存最大数目
#define EKL_MAX 7

//技能判定超时时间(ms)
#define EKL_TIMEOUT TMR_CHAIN_MS

/*
	内有按键事件列表（序列）和当前按键down状态数组。
*/
class SFPEventStatus
{
public:
	string m_sDownEvent;
	unsigned char m_aStatus[EK_MAX];

	SFPEventStatus()
	{
		for (int i = 0; i < EK_MAX; i++)
		{
			m_aStatus[i] = 0;
		}
	}

	char getEkuChar(SF_EK val)
	{
		switch (val)
		{
		case EK_8:
			return '8';
		case EK_4:
			return '4';
		case EK_2:
			return '2';
		case EK_6:
			return '6';
#if 0
		case EK_S1:
			return 'S';
		case EK_S2:
			return 'T';
#endif
		case EK_A:
			return 'A';
		case EK_B:
			return 'B';
		case EK_C:
			return 'C';
		case EK_D:
			return 'D';
#if 0
		case EK_E:
			return 'E';
		case EK_F:
			return 'F';
#endif
		default:
			return 0;
		}
	}

	char getEkdChar(SF_EK val)
	{
		switch (val)
		{
		case EK_8:
			return '8';
		case EK_4:
			return '4';
		case EK_2:
			return '2';
		case EK_6:
			return '6';
#if 0
		case EK_S1:
			return 'S';
		case EK_S2:
			return 'T';
#endif
		case EK_A:
			return 'A';
		case EK_B:
			return 'B';
		case EK_C:
			return 'C';
		case EK_D:
			return 'D';
#if 0
		case EK_E:
			return 'E';
		case EK_F:
			return 'F';
#endif
		default:
			return 0;
		}
	}

	void setTimeout()
	{
		m_sDownEvent = "";
	}

	int addEvent(SF_EK val)
	{
		char cVal = '\0';

		cVal = getEkdChar(val);
		if (cVal)
		{
			if (m_sDownEvent.size() >= EKL_MAX)
			{
				m_sDownEvent = m_sDownEvent.substr(1, EKL_MAX);
			}
			m_sDownEvent.push_back(cVal);
			return m_sDownEvent.size();
		}
		else
		{
			return 0;
		}
	}
};

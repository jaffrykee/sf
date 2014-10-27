#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>
#include <list>

using namespace std;

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
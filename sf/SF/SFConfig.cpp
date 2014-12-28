﻿#pragma execution_character_set("utf-8")
#include <SFConfig.h>

SFConfig::SFConfig()
{
	int i = 0;
#pragma region s_mEkf赋值
	s_mEkf.insert(pair<string, SF_EKF>("j", EKF_j));
	s_mEkf.insert(pair<string, SF_EKF>("jex", EKF_jex));
	s_mEkf.insert(pair<string, SF_EKF>("rj", EKF_rj));
	s_mEkf.insert(pair<string, SF_EKF>("rjex", EKF_rjex));
	s_mEkf.insert(pair<string, SF_EKF>("fj", EKF_fj));
	s_mEkf.insert(pair<string, SF_EKF>("fjex", EKF_fjex));
	s_mEkf.insert(pair<string, SF_EKF>("bj", EKF_bj));
	s_mEkf.insert(pair<string, SF_EKF>("bjex", EKF_bjex));
	s_mEkf.insert(pair<string, SF_EKF>("jA", EKF_jA));
	s_mEkf.insert(pair<string, SF_EKF>("jexA", EKF_jexA));
	s_mEkf.insert(pair<string, SF_EKF>("rjA", EKF_rjA));
	s_mEkf.insert(pair<string, SF_EKF>("rjexA", EKF_rjexA));
	s_mEkf.insert(pair<string, SF_EKF>("fjA", EKF_fjA));
	s_mEkf.insert(pair<string, SF_EKF>("fjexA", EKF_fjexA));
	s_mEkf.insert(pair<string, SF_EKF>("bjA", EKF_bjA));
	s_mEkf.insert(pair<string, SF_EKF>("bjexA", EKF_bjexA));
	s_mEkf.insert(pair<string, SF_EKF>("jB", EKF_jB));
	s_mEkf.insert(pair<string, SF_EKF>("jexB", EKF_jexB));
	s_mEkf.insert(pair<string, SF_EKF>("rjB", EKF_rjB));
	s_mEkf.insert(pair<string, SF_EKF>("rjexB", EKF_rjexB));
	s_mEkf.insert(pair<string, SF_EKF>("fjB", EKF_fjB));
	s_mEkf.insert(pair<string, SF_EKF>("fjexB", EKF_fjexB));
	s_mEkf.insert(pair<string, SF_EKF>("bjB", EKF_bjB));
	s_mEkf.insert(pair<string, SF_EKF>("bjexB", EKF_bjexB));
	s_mEkf.insert(pair<string, SF_EKF>("jC", EKF_jC));
	s_mEkf.insert(pair<string, SF_EKF>("jexC", EKF_jexC));
	s_mEkf.insert(pair<string, SF_EKF>("rjC", EKF_rjC));
	s_mEkf.insert(pair<string, SF_EKF>("rjexC", EKF_rjexC));
	s_mEkf.insert(pair<string, SF_EKF>("fjC", EKF_fjC));
	s_mEkf.insert(pair<string, SF_EKF>("fjexC", EKF_fjexC));
	s_mEkf.insert(pair<string, SF_EKF>("bjC", EKF_bjC));
	s_mEkf.insert(pair<string, SF_EKF>("bjexC", EKF_bjexC));
	s_mEkf.insert(pair<string, SF_EKF>("jD", EKF_jD));
	s_mEkf.insert(pair<string, SF_EKF>("jexD", EKF_jexD));
	s_mEkf.insert(pair<string, SF_EKF>("rjD", EKF_rjD));
	s_mEkf.insert(pair<string, SF_EKF>("rjexD", EKF_rjexD));
	s_mEkf.insert(pair<string, SF_EKF>("fjD", EKF_fjD));
	s_mEkf.insert(pair<string, SF_EKF>("fjexD", EKF_fjexD));
	s_mEkf.insert(pair<string, SF_EKF>("bjD", EKF_bjD));
	s_mEkf.insert(pair<string, SF_EKF>("bjexD", EKF_bjexD));
	s_mEkf.insert(pair<string, SF_EKF>("b", EKF_b));
	s_mEkf.insert(pair<string, SF_EKF>("def", EKF_def));
	s_mEkf.insert(pair<string, SF_EKF>("defs", EKF_defs));
	s_mEkf.insert(pair<string, SF_EKF>("s", EKF_s));
	s_mEkf.insert(pair<string, SF_EKF>("sA", EKF_sA));
	s_mEkf.insert(pair<string, SF_EKF>("sB", EKF_sB));
	s_mEkf.insert(pair<string, SF_EKF>("sC", EKF_sC));
	s_mEkf.insert(pair<string, SF_EKF>("sD", EKF_sD));
	s_mEkf.insert(pair<string, SF_EKF>("f", EKF_f));
	s_mEkf.insert(pair<string, SF_EKF>("fA", EKF_fA));
	s_mEkf.insert(pair<string, SF_EKF>("fB", EKF_fB));
	s_mEkf.insert(pair<string, SF_EKF>("fC", EKF_fC));
	s_mEkf.insert(pair<string, SF_EKF>("fD", EKF_fD));
	s_mEkf.insert(pair<string, SF_EKF>("r", EKF_r));
	s_mEkf.insert(pair<string, SF_EKF>("ddg", EKF_ddg));
	s_mEkf.insert(pair<string, SF_EKF>("A", EKF_A));
	s_mEkf.insert(pair<string, SF_EKF>("B", EKF_B));
	s_mEkf.insert(pair<string, SF_EKF>("C", EKF_C));
	s_mEkf.insert(pair<string, SF_EKF>("D", EKF_D));
	s_mEkf.insert(pair<string, SF_EKF>("8", EKF_8));
	s_mEkf.insert(pair<string, SF_EKF>("4", EKF_4));
	s_mEkf.insert(pair<string, SF_EKF>("2", EKF_2));
	s_mEkf.insert(pair<string, SF_EKF>("6", EKF_6));
	s_mEkf.insert(pair<string, SF_EKF>("44", EKF_44));
	s_mEkf.insert(pair<string, SF_EKF>("66", EKF_66));
	s_mEkf.insert(pair<string, SF_EKF>("26A", EKF_26A));
	s_mEkf.insert(pair<string, SF_EKF>("26B", EKF_26B));
	s_mEkf.insert(pair<string, SF_EKF>("26C", EKF_26C));
	s_mEkf.insert(pair<string, SF_EKF>("26D", EKF_26D));
	s_mEkf.insert(pair<string, SF_EKF>("24A", EKF_24A));
	s_mEkf.insert(pair<string, SF_EKF>("24B", EKF_24B));
	s_mEkf.insert(pair<string, SF_EKF>("24C", EKF_24C));
	s_mEkf.insert(pair<string, SF_EKF>("24D", EKF_24D));
	s_mEkf.insert(pair<string, SF_EKF>("626A", EKF_626A));
	s_mEkf.insert(pair<string, SF_EKF>("626B", EKF_626B));
	s_mEkf.insert(pair<string, SF_EKF>("626C", EKF_626C));
	s_mEkf.insert(pair<string, SF_EKF>("626D", EKF_626D));
	s_mEkf.insert(pair<string, SF_EKF>("424A", EKF_424A));
	s_mEkf.insert(pair<string, SF_EKF>("424B", EKF_424B));
	s_mEkf.insert(pair<string, SF_EKF>("424C", EKF_424C));
	s_mEkf.insert(pair<string, SF_EKF>("424D", EKF_424D));
	s_mEkf.insert(pair<string, SF_EKF>("426A", EKF_426A));
	s_mEkf.insert(pair<string, SF_EKF>("426B", EKF_426B));
	s_mEkf.insert(pair<string, SF_EKF>("426C", EKF_426C));
	s_mEkf.insert(pair<string, SF_EKF>("426D", EKF_426D));
	s_mEkf.insert(pair<string, SF_EKF>("624A", EKF_624A));
	s_mEkf.insert(pair<string, SF_EKF>("624B", EKF_624B));
	s_mEkf.insert(pair<string, SF_EKF>("624C", EKF_624C));
	s_mEkf.insert(pair<string, SF_EKF>("624D", EKF_624D));
	s_mEkf.insert(pair<string, SF_EKF>("2624A", EKF_2624A));
	s_mEkf.insert(pair<string, SF_EKF>("2624B", EKF_2624B));
	s_mEkf.insert(pair<string, SF_EKF>("2624C", EKF_2624C));
	s_mEkf.insert(pair<string, SF_EKF>("2624D", EKF_2624D));
	s_mEkf.insert(pair<string, SF_EKF>("2426A", EKF_2426A));
	s_mEkf.insert(pair<string, SF_EKF>("2426B", EKF_2426B));
	s_mEkf.insert(pair<string, SF_EKF>("2426C", EKF_2426C));
	s_mEkf.insert(pair<string, SF_EKF>("2426D", EKF_2426D));
	s_mEkf.insert(pair<string, SF_EKF>("2626A", EKF_2626A));
	s_mEkf.insert(pair<string, SF_EKF>("2626B", EKF_2626B));
	s_mEkf.insert(pair<string, SF_EKF>("2626C", EKF_2626C));
	s_mEkf.insert(pair<string, SF_EKF>("2626D", EKF_2626D));
	s_mEkf.insert(pair<string, SF_EKF>("2424A", EKF_2424A));
	s_mEkf.insert(pair<string, SF_EKF>("2424B", EKF_2424B));
	s_mEkf.insert(pair<string, SF_EKF>("2424C", EKF_2424C));
	s_mEkf.insert(pair<string, SF_EKF>("2424D", EKF_2424D));
	s_mEkf.insert(pair<string, SF_EKF>("624624A", EKF_624624A));
	s_mEkf.insert(pair<string, SF_EKF>("624624B", EKF_624624B));
	s_mEkf.insert(pair<string, SF_EKF>("624624C", EKF_624624C));
	s_mEkf.insert(pair<string, SF_EKF>("624624D", EKF_624624D));
	s_mEkf.insert(pair<string, SF_EKF>("426426A", EKF_426426A));
	s_mEkf.insert(pair<string, SF_EKF>("426426B", EKF_426426B));
	s_mEkf.insert(pair<string, SF_EKF>("426426C", EKF_426426C));
	s_mEkf.insert(pair<string, SF_EKF>("426426D", EKF_426426D));
	s_mEkf.insert(pair<string, SF_EKF>("MAX", EKF_MAX));
#pragma endregion

#pragma region s_mEka赋值
	s_mEka.insert(pair<string, SF_EKA>("A", EKA_A));
	s_mEka.insert(pair<string, SF_EKA>("B", EKA_B));
	s_mEka.insert(pair<string, SF_EKA>("C", EKA_C));
	s_mEka.insert(pair<string, SF_EKA>("D", EKA_D));
	s_mEka.insert(pair<string, SF_EKA>("8", EKA_8));
	s_mEka.insert(pair<string, SF_EKA>("4", EKA_4));
	s_mEka.insert(pair<string, SF_EKA>("2", EKA_2));
	s_mEka.insert(pair<string, SF_EKA>("6", EKA_6));
	s_mEka.insert(pair<string, SF_EKA>("44", EKA_44));
	s_mEka.insert(pair<string, SF_EKA>("66", EKA_66));
	s_mEka.insert(pair<string, SF_EKA>("26A", EKA_26A));
	s_mEka.insert(pair<string, SF_EKA>("26B", EKA_26B));
	s_mEka.insert(pair<string, SF_EKA>("26C", EKA_26C));
	s_mEka.insert(pair<string, SF_EKA>("26D", EKA_26D));
	s_mEka.insert(pair<string, SF_EKA>("24A", EKA_24A));
	s_mEka.insert(pair<string, SF_EKA>("24B", EKA_24B));
	s_mEka.insert(pair<string, SF_EKA>("24C", EKA_24C));
	s_mEka.insert(pair<string, SF_EKA>("24D", EKA_24D));
	s_mEka.insert(pair<string, SF_EKA>("626A", EKA_626A));
	s_mEka.insert(pair<string, SF_EKA>("626B", EKA_626B));
	s_mEka.insert(pair<string, SF_EKA>("626C", EKA_626C));
	s_mEka.insert(pair<string, SF_EKA>("626D", EKA_626D));
	s_mEka.insert(pair<string, SF_EKA>("424A", EKA_424A));
	s_mEka.insert(pair<string, SF_EKA>("424B", EKA_424B));
	s_mEka.insert(pair<string, SF_EKA>("424C", EKA_424C));
	s_mEka.insert(pair<string, SF_EKA>("424D", EKA_424D));
	s_mEka.insert(pair<string, SF_EKA>("426A", EKA_426A));
	s_mEka.insert(pair<string, SF_EKA>("426B", EKA_426B));
	s_mEka.insert(pair<string, SF_EKA>("426C", EKA_426C));
	s_mEka.insert(pair<string, SF_EKA>("426D", EKA_426D));
	s_mEka.insert(pair<string, SF_EKA>("624A", EKA_624A));
	s_mEka.insert(pair<string, SF_EKA>("624B", EKA_624B));
	s_mEka.insert(pair<string, SF_EKA>("624C", EKA_624C));
	s_mEka.insert(pair<string, SF_EKA>("624D", EKA_624D));
	s_mEka.insert(pair<string, SF_EKA>("2624A", EKA_2624A));
	s_mEka.insert(pair<string, SF_EKA>("2624B", EKA_2624B));
	s_mEka.insert(pair<string, SF_EKA>("2624C", EKA_2624C));
	s_mEka.insert(pair<string, SF_EKA>("2624D", EKA_2624D));
	s_mEka.insert(pair<string, SF_EKA>("2426A", EKA_2426A));
	s_mEka.insert(pair<string, SF_EKA>("2426B", EKA_2426B));
	s_mEka.insert(pair<string, SF_EKA>("2426C", EKA_2426C));
	s_mEka.insert(pair<string, SF_EKA>("2426D", EKA_2426D));
	s_mEka.insert(pair<string, SF_EKA>("2626A", EKA_2626A));
	s_mEka.insert(pair<string, SF_EKA>("2626B", EKA_2626B));
	s_mEka.insert(pair<string, SF_EKA>("2626C", EKA_2626C));
	s_mEka.insert(pair<string, SF_EKA>("2626D", EKA_2626D));
	s_mEka.insert(pair<string, SF_EKA>("2424A", EKA_2424A));
	s_mEka.insert(pair<string, SF_EKA>("2424B", EKA_2424B));
	s_mEka.insert(pair<string, SF_EKA>("2424C", EKA_2424C));
	s_mEka.insert(pair<string, SF_EKA>("2424D", EKA_2424D));
	s_mEka.insert(pair<string, SF_EKA>("624624A", EKA_624624A));
	s_mEka.insert(pair<string, SF_EKA>("624624B", EKA_624624B));
	s_mEka.insert(pair<string, SF_EKA>("624624C", EKA_624624C));
	s_mEka.insert(pair<string, SF_EKA>("624624D", EKA_624624D));
	s_mEka.insert(pair<string, SF_EKA>("426426A", EKA_426426A));
	s_mEka.insert(pair<string, SF_EKA>("426426B", EKA_426426B));
	s_mEka.insert(pair<string, SF_EKA>("426426C", EKA_426426C));
	s_mEka.insert(pair<string, SF_EKA>("426426D", EKA_426426D));
	s_mEka.insert(pair<string, SF_EKA>("MAX", EKA_MAX));
#pragma endregion
}

SFConfig* SFConfig::GetInstance()
{
	if (m_pInstance == NULL)  //判断是否第一次调用  
		m_pInstance = new SFConfig();
	return m_pInstance;
}

SFConfig::SFCGarbo::~SFCGarbo()
{
	if (SFConfig::m_pInstance)
		delete SFConfig::m_pInstance;
}
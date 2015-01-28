#pragma once
#pragma execution_character_set("utf-8")

enum SF_DEBUG
{
	DEBUG_COM, DEBUG_RES_LOAD, DEBUG_SKILL_KEY,
	DEBUG_PLAYER_ACT,
	DEBUG_MAX
};

#define sf_comma ,
#define SF_OUT_BEGIN(enable)	\
do	\
{	\
	if (g_pConf->m_enDebug[enable])	\
	{	\

#define SF_OUT_END	\
	}	\
}	\
while (0)

//对于printf中的“,”，使用sf_comma来表示
#define sf_printf(sf_dbug,parameters)	\
SF_OUT_BEGIN(sf_dbug)	\
		printf(parameters);		\
SF_OUT_END

//对于wprintf中的“,”，使用sf_comma来表示
#define sf_wprintf(sf_dbug,parameters)	\
SF_OUT_BEGIN(sf_dbug)	\
		wprintf(parameters);	\
SF_OUT_END

#define sf_cout(sf_dbug,parameters)	\
SF_OUT_BEGIN(sf_dbug)	\
		cout<< parameters;	\
SF_OUT_END

#define sf_wcout(sf_dbug,parameters)	\
SF_OUT_BEGIN(sf_dbug)	\
		wcout<< parameters;	\
SF_OUT_END


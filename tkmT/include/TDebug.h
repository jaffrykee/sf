#pragma once
#pragma execution_character_set("utf-8")

enum T_DEBUG
{
	TDEBUG_COM, TDEBUG_ERR, TDEBUG_RES_LOAD,
	TDEBUG_MAX
};

#define t_comma ,
#define T_OUT_BEGIN(enable)	\
do	\
{	\
	if (g_pTConf->m_enDebug[enable])	\
	{	\

#define T_OUT_END	\
	}	\
}	\
while (0)

//对于printf中的“,”，使用t_comma来表示
#define t_printf(t_dbug,parameters)	\
T_OUT_BEGIN(t_dbug)	\
		printf(parameters);		\
T_OUT_END

//对于wprintf中的“,”，使用t_comma来表示
#define t_wprintf(t_dbug,parameters)	\
T_OUT_BEGIN(t_dbug)	\
		wprintf(parameters);	\
T_OUT_END

#define t_cout(t_dbug,parameters)	\
T_OUT_BEGIN(t_dbug)	\
		cout<< parameters;	\
T_OUT_END

#define t_wcout(t_dbug,parameters)	\
T_OUT_BEGIN(t_dbug)	\
		wcout<< parameters;	\
T_OUT_END


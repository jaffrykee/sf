#pragma once
#pragma execution_character_set("utf-8")

enum SF_DEBUG
{
	DEBUG_COM, DEBUG_RES_LOAD, DEBUG_SKILL_KEY,
	DEBUG_PLAYER_ACT,
	DEBUG_MAX
};

#define sf_comma ,

//对于printf中的“,”，使用sf_comma来表示
#define sf_printf(sf_dbug,parameters)	\
do	\
{	\
	if (SFConfig::m_enDebug[sf_dbug])	\
	{	\
		printf(parameters);		\
	}	\
}	\
while (0)

//对于wprintf中的“,”，使用sf_comma来表示
#define sf_wprintf(sf_dbug,parameters)	\
do	\
{	\
	if (SFConfig::m_enDebug[sf_dbug])	\
	{	\
		wprintf(parameters);	\
	}	\
}	\
while (0)

#define sf_cout(sf_dbug,parameters)	\
do	\
{	\
	if (SFConfig::m_enDebug[sf_dbug])	\
	{	\
		cout<< parameters;	\
	}	\
}	\
while (0)

#define sf_wcout(sf_dbug,parameters)	\
do	\
{	\
	if (SFConfig::m_enDebug[sf_dbug])	\
	{	\
		wcout<< parameters;	\
	}	\
}	\
while (0)


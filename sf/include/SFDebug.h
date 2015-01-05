#pragma once
#pragma execution_character_set("utf-8")

enum SF_DEBUG
{
	DEBUG_COM, DEBUG_RES_LOAD, DEBUG_SKILL_KEY,
	DEBUG_MAX
};

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
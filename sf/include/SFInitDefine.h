#pragma once
#pragma execution_character_set("utf-8")

#include <init.h>

#pragma region 按键设置define
#define KD_P1UP VK_W
#define KD_P1LF VK_A
#define KD_P1DW VK_S
#define KD_P1RG VK_D
#define KD_P1AA VK_U
#define KD_P1BB VK_I
#define KD_P1CC VK_O
#define KD_P1DD VK_J
#define KD_P1EE VK_K
#define KD_P1FF VK_L
#define KD_P1ST VK_1
#define KD_P1MN VK_2

#define KD_P2UP VK_UP
#define KD_P2LF VK_LEFT
#define KD_P2DW VK_DOWN
#define KD_P2RG VK_RIGHT
#define KD_P2AA VK_NUMPAD1
#define KD_P2BB VK_NUMPAD2
#define KD_P2CC VK_NUMPAD3
#define KD_P2DD VK_NUMPAD0
#define KD_P2EE VK_NUMPAD5
#define KD_P2FF VK_NUMPAD6
#define KD_P2ST VK_3
#define KD_P2MN VK_4
#pragma endregion

#pragma region 计时器define(TMR)
enum TMR_ID
{
	TMR_PAINT = 1, TMR_ACTION, TMR_CHAIN,
	TMR_MAX
};

//显示刷新计时器
#define TMR_PAINT_MS 15
//动作变化计时器
#define TMR_ACTION_MS 5
//按键连锁检测计时器
#define TMR_CHAIN_MS 100
#pragma endregion

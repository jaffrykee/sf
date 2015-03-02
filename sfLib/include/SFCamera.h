#pragma once
#pragma execution_character_set("utf-8")
//摄像机类

class __declspec(dllexport) SFCamera
{
public:
	SFActScene* m_pCurScene;

private:
	FLOAT m_width;
	FLOAT m_height;
	D2D1_POINT_2F m_poiCenter;


public:
	SFCamera();
	~SFCamera();

	bool setCurrentScene(SFActScene* pCurScene);
};
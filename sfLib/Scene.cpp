#pragma execution_character_set("utf-8")
#include <sfLibInit.h>
#include <sfLib.h>

Scene::Scene()
{

}

Scene::~Scene()
{

}

bool Scene::doEvent(SF_TEV event)
{
	return true;
}

bool Scene::doMouseEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
	return true;
}

void Scene::onDraw()
{

}
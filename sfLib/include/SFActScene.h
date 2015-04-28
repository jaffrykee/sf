#pragma once
#pragma execution_character_set("utf-8")

typedef enum SF_SCN_MAP
{
	SCN_MAP_DEF, SCN_SKY, SCN_WATER,
	SCN_MAX
};

typedef enum SF_SCN_STAGE
{
	SCN_STG_FREE, SCN_STG_LOADING, SCN_STG_PAINTING, SCN_STG_KILLING,
	SCN_STG_MAX
}SF_SCN_STG;

//暂时没用,PLR是玩家的意思，MST是怪物的意思
typedef enum SF_PLR_GROUPTYPE
{
	PGT_PLR, PGT_MST,
	PGT_MAX
};

typedef enum SF_FIGHT_PlayerGroupName
{
	FIGHT_PGN_P1, FIGHT_PGN_P2,
	FIGHT_PGN_MAX
}SF_FIGHT_PGN;
const vector <string> conf_aStrFightPGN = {
	"p1", "p2"
};

class __declspec(dllexport) SFSpriteGroup
{
public:
	string m_name;
	vector<SFSprite*> m_aSprite;

	SFSpriteGroup(string name);
	~SFSpriteGroup();
	bool addSprite(SFSprite* pSprite);
};

//场景类，目前只能是单线程，将来可能会向多线程发展。
class __declspec(dllexport) SFActScene
{
public:
	map<string, SFSpriteGroup*> m_mapSpriteGroup;
	SFResScene* m_pResScene;
	SF_SCN_MAP m_mapType;
	SF_SCN_STAGE m_stage;

	map<SF_TEV, SF_EK> m_mapTevEk;
	//静摩擦系数
	FLOAT m_fMoveFs;
	//动摩擦系数
	FLOAT m_fMoveFk;
	FLOAT m_width;
	FLOAT m_height;
	FLOAT m_ground;
	D2D1_POINT_2F m_poiInitP1;
	D2D1_POINT_2F m_poiInitP2;

	//测试用
	UINT m_tc;

	SFActScene(SF_SCN_MAP mapType = SCN_MAP_DEF);
	SFActScene(UINT resId1, SF_SKN skin1, UINT resId2, SF_SKN skin2, SF_SCN_MAP mapType = SCN_MAP_DEF);
	~SFActScene();
	bool addSpriteGroup(string groupName);
	bool addSprite(string groupName, SFSprite* pSprite);
	SFPlayer* getPlayerInSceneByPGN(string groupName);
	bool doEvent(SF_TEV event);
	bool addFrameToCollosion(SFPlayer* pPlayer, __out vector<SFResFrame*>& arrpFrame);
	bool doCollision();

	//将来可能会将Fight类型的Scene以继承类的方式提出来。
	bool addFightP1(SFSprite* pSprite);
	bool addFightP2(SFSprite* pSprite);
	SFPlayer* getFightP1();
	SFPlayer* getFightP2();
	bool setPositionFightP1(D2D1_POINT_2F point);
	bool initPositionFightP1();
	bool setPositionFightP2(D2D1_POINT_2F point);
	bool initPositionFightP2();
	void setDirection(bool isP1Left);
	void refreshDirection();
	D2D1_POINT_2F getScenePoiFromView(ID2D1HwndRenderTarget* pRenderTarget, D2D1_POINT_2F vPoi);
	D2D1_RECT_F getSceneRectFromView(ID2D1HwndRenderTarget* pRenderTarget, D2D1_RECT_F vRect);
	D2D1_POINT_2F getViewPoiFromScene(ID2D1HwndRenderTarget* pRenderTarget, D2D1_POINT_2F sPoi);
	D2D1_RECT_F getViewRectFromScene(ID2D1HwndRenderTarget* pRenderTarget, D2D1_RECT_F sRect);
	void onDrawForFightBox(ID2D1HwndRenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush, SFPlayer* pPlayer, list<D2D1_RECT_F>* pList);
	void onDrawForFightSprite(ID2D1HwndRenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBodyBrush, ID2D1SolidColorBrush* pActBrush, SFPlayer* pPlayer);
	void onDraw(ID2D1HwndRenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBodyBrush, ID2D1SolidColorBrush* pActBrush, ID2D1BitmapBrush* pBackBrush);
};
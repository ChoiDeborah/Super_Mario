#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"
#include "Tile.h"
#include "Item.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "CollisionMgr.h"
#include "BackGroundMgr.h"
#include "Coin.h"
#include "ItemFlower.h"
#include "Life_Mushroom.h"
#include "SizeUp_Mushroom.h"

CMainGame::CMainGame()
{
	//11
	//하하하 되는건가?
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_dwTime = GetTickCount();
	m_hDC = GetDC(g_hWnd);

	CObjMgr::Get_Instance()->AddObject(OBJID::PLAYER, CAbstractFactory<CPlayer>::Create());

	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM, CAbstractFactory<CItem>::Create(50, 500));
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM, CAbstractFactory<CItem>::Create(100, 500));
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM, CAbstractFactory<CItem>::Create(150, 500));

	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::TILE, CAbstractFactory<CTile>::Create(50, 200));
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::TILE, CAbstractFactory<CTile>::Create(100, 200));
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::TILE, CAbstractFactory<CTile>::Create(150, 200));


	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM_COIN, CAbstractFactory<CCoin>::Create());
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM_SIZE_UP, CAbstractFactory<CSizeUp_Mushroom>::Create());
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM_LIFE, CAbstractFactory<CLife_Mushroom>::Create());
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM_FLOWER, CAbstractFactory<CItemFlower>::Create());

}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
	CBackGroundMgr::Get_Instance()->Update();

	// 충돌체크 
	// 
	//
	
}

void CMainGame::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	CBackGroundMgr::Get_Instance()->LateUpdate();
}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, 0, 50, WINCX, WINCY-50);
	CObjMgr::Get_Instance()->Render(m_hDC);
	CBackGroundMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	CObjMgr::Destory_Instance();
	CBackGroundMgr::Get_Instance()->Destroy_Instance();
}

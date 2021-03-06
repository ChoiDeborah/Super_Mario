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
#include "LineMgr.h"
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

	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::TILE, CAbstractFactory<CTile>::Create(500, 500));
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::TILE, CAbstractFactory<CTile>::Create(600, 500));
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::TILE, CAbstractFactory<CTile>::Create(700, 500));


	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM_COIN, CAbstractFactory<CCoin>::Create(800,200));
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM_SIZE_UP, CAbstractFactory<CSizeUp_Mushroom>::Create(900,550));
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM_LIFE, CAbstractFactory<CLife_Mushroom>::Create(1000, 500));
	CBackGroundMgr::Get_Instance()->AddObject(BACKGROUNDID::ITEM_FLOWER, CAbstractFactory<CItemFlower>::Create(1100, 500));
	
	CLineMgr::Get_Instance()->Initialize();
}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
	CBackGroundMgr::Get_Instance()->Update();


	// 충돌체크 
	//CCollisionMgr::CollisionRect_Coin(CBackGroundMgr::Get_Instance()->m_Backgroundlist[BACKGROUNDID::ITEM_COIN], CObjMgr::Get_Instance()->m_Objlist[OBJID::PLAYER], BACKGROUNDID::ITEM_COIN, OBJID::PLAYER);
	CCollisionMgr::CollisionRectEX(CBackGroundMgr::Get_Instance()->m_Backgroundlist[BACKGROUNDID::ITEM_COIN], CObjMgr::Get_Instance()->m_Objlist[OBJID::PLAYER], BACKGROUNDID::ITEM_COIN, OBJID::PLAYER);
	CCollisionMgr::CollisionRect_SizeUp(CBackGroundMgr::Get_Instance()->m_Backgroundlist[BACKGROUNDID::ITEM_SIZE_UP], CObjMgr::Get_Instance()->m_Objlist[OBJID::PLAYER], BACKGROUNDID::ITEM_SIZE_UP, OBJID::PLAYER);
	CCollisionMgr::CollisionRect_SizeUp_And_Bullet(CBackGroundMgr::Get_Instance()->m_Backgroundlist[BACKGROUNDID::ITEM_FLOWER], CObjMgr::Get_Instance()->m_Objlist[OBJID::PLAYER], BACKGROUNDID::ITEM_FLOWER, OBJID::PLAYER);
	CCollisionMgr::CollisionRect_Tile(CBackGroundMgr::Get_Instance()->m_Backgroundlist[BACKGROUNDID::ITEM_COIN], CObjMgr::Get_Instance()->m_Objlist[OBJID::PLAYER], BACKGROUNDID::ITEM_COIN, OBJID::PLAYER);


	
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

	TCHAR szName[32] = {};
	swprintf_s(szName, L"점수 : %d", CObjMgr::Get_Instance()->Get_Player()->Get_Coin());
	TextOut(m_hDC, 100.f, 100.f, szName, lstrlen(szName));

	CObjMgr::Get_Instance()->Render(m_hDC);
	CBackGroundMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	CObjMgr::Destory_Instance();
	CBackGroundMgr::Get_Instance()->Destroy_Instance();
	CLineMgr::Destroy_Instance();
}

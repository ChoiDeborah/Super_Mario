#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "CollisionMgr.h"


CMainGame::CMainGame()
{
	//11
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

}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CMainGame::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	CObjMgr::Destory_Instance();
}

#include "stdafx.h"
#include "BackGroundMgr.h"


CBackGroundMgr::CBackGroundMgr()
{
}


CBackGroundMgr::~CBackGroundMgr()
{
}

void CBackGroundMgr::AddObject(BACKGROUNDID::ID eID, CObj * pObj)
{
	m_Backgroundlist[eID].emplace_back(pObj);
}

void CBackGroundMgr::Update()
{
}

void CBackGroundMgr::LateUpdate()
{
}

void CBackGroundMgr::Render(HDC hDC)
{
}

void CBackGroundMgr::Release()
{
	Release();
}

void CBackGroundMgr::Scroll_BackGround(float _fSpeed)
{
}

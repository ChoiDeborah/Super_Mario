#include "stdafx.h"
#include "ItemFlower.h"


CItemFlower::CItemFlower()
{
}


CItemFlower::~CItemFlower()
{
}

void CItemFlower::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.fX = 100.f;
	m_tInfo.fY = 300.f;
	m_fSpeed = 5.f;
}

int CItemFlower::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;
}

void CItemFlower::LateUpdate()
{
}

void CItemFlower::Render(HDC hDC)
{
	CObj::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TCHAR szName[32] = {};
	swprintf_s(szName, L"╡июс");
	TextOut(hDC, m_tInfo.fX, m_tInfo.fY, szName, lstrlen(szName));
}

void CItemFlower::Release()
{
}

#include "stdafx.h"
#include "CoinTile.h"


CCoinTile::CCoinTile()
{
}


CCoinTile::~CCoinTile()
{
}

void CCoinTile::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.fX = 200.f;
	m_tInfo.fY = 500.f;
}

int CCoinTile::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;
}

void CCoinTile::LateUpdate()
{
}

void CCoinTile::Render(HDC hDC)
{
	CObj::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CCoinTile::Release()
{
}

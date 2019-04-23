#include "stdafx.h"
#include "Tile.h"


CTile::CTile()
{
}


CTile::~CTile()
{
}

void CTile::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_fSpeed = 5.f;
}

int CTile::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;
}

void CTile::LateUpdate()
{
	CObj::UpdateRect();
	/*if (0 >= m_tRect.left ||
		0 >= m_tRect.top ||
		WINCX <= m_tRect.right ||
		WINCY <= m_tRect.bottom)
	{
		m_bIsDead = true;
	}*/
}

void CTile::Render(HDC hDC)
{
	CObj::UpdateRect();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CTile::Release()
{
}

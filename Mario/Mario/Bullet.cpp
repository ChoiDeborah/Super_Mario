#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
	m_fSpeed = 10.f;
}

int CBullet::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	m_tInfo.fX += cosf(m_fAngle * 3.14f / 180.f) * m_fSpeed;
	m_tInfo.fY -= sinf(m_fAngle * 3.14f / 180.f) * m_fSpeed;
	
	return OBJ_NOEVENT;
}

void CBullet::LateUpdate()
{
	CObj::UpdateRect();
	if (0 >= m_tRect.left ||
		0 >= m_tRect.top ||
		WINCX <= m_tRect.right ||
		WINCY <= m_tRect.bottom)
	{
		m_bIsDead = true;
	}
}

void CBullet::Render(HDC hDC)
{
	CObj::UpdateRect();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}

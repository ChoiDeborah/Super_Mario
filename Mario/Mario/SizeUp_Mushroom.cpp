#include "stdafx.h"
#include "SizeUp_Mushroom.h"


CSizeUp_Mushroom::CSizeUp_Mushroom()
{
}


CSizeUp_Mushroom::~CSizeUp_Mushroom()
{
}

void CSizeUp_Mushroom::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_fSpeed = 5.f;
}

int CSizeUp_Mushroom::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;
}

void CSizeUp_Mushroom::LateUpdate()
{
}

void CSizeUp_Mushroom::Render(HDC hDC)
{
	CObj::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CSizeUp_Mushroom::Release()
{
}

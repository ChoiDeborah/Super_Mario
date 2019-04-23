#include "stdafx.h"
#include "Life_Mushroom.h"


CLife_Mushroom::CLife_Mushroom()
{
}


CLife_Mushroom::~CLife_Mushroom()
{
}

void CLife_Mushroom::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.fX = 300.f;
	m_tInfo.fY = 300.f;
	m_fSpeed = 5.f;
}

int CLife_Mushroom::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;
}

void CLife_Mushroom::LateUpdate()
{
}

void CLife_Mushroom::Render(HDC hDC)
{
	CObj::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CLife_Mushroom::Release()
{
}

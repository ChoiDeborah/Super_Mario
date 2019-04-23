#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	m_tInfo.fY = 600.f;
	m_tInfo.fX = 400.f;
	m_fSpeed = 2.f;
}

int CMonster::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;


	return OBJ_NOEVENT;

}

void CMonster::LateUpdate()
{
	//CObj::UpdateRect();
	//if (0 >= m_tRect.left ||
	//	0 >= m_tRect.top ||
	//	WINCX <= m_tRect.right ||
	//	WINCY <= m_tRect.bottom)
	//{
	//	m_bIsDead = true;
	//}
}

void CMonster::Render(HDC hDC)
{
	CObj::UpdateRect();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}

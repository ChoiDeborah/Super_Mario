#include "stdafx.h"
#include "Coin.h"


CCoin::CCoin()
{
}


CCoin::~CCoin()
{
}

void CCoin::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.fX = 200.f;
	m_tInfo.fY = 500.f;
	m_fSpeed = 5.f;
}

int CCoin::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;
}

void CCoin::LateUpdate()
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

void CCoin::Render(HDC hDC)
{
	CObj::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TCHAR szName[32] = {};
	swprintf_s(szName, L"ÄÚÀÎ");
	TextOut(hDC, m_tInfo.fX, m_tInfo.fY, szName, lstrlen(szName));
}

void CCoin::Release()
{
}

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

	m_tInfo.fX = 500.f;
	m_tInfo.fY = 500.f;
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
	CObj::UpdateRect();
	if (0 >= m_tRect.left ||
		0 >= m_tRect.top ||
		WINCX <= m_tRect.right ||
		WINCY <= m_tRect.bottom)
	{
		m_bIsDead = true;
	}
}

void CSizeUp_Mushroom::Render(HDC hDC)
{
	CObj::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TCHAR szName[32] = {};
	swprintf_s(szName, L"Ä¿Áö´Â ¹ö¼¸");
	TextOut(hDC, m_tInfo.fX, m_tInfo.fY, szName, lstrlen(szName));
}

void CSizeUp_Mushroom::Release()
{
}

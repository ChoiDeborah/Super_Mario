#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	ZeroMemory(&P1, sizeof(POINT));
	ZeroMemory(&P2, sizeof(POINT));
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;
	m_fSpeed = 5.f;
	m_fAngle = 45.f;

	m_fSpeed = 10.f;
	m_fForce = 20.f;
	m_fTime = 0.f;

	m_bIsJump = false;
}

int CPlayer::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	POINT P1 = { 0, WINCY };
	POINT P2 = { WINCX, WINCY };

	if (m_tInfo.fX >= P1.x && m_tInfo.fX <= P2.x)
	{
		m_fGuideHeight = (P2.y - P1.y) / (P2.x - P1.x) * (m_tInfo.fX - P1.x) + P1.y - m_tInfo.fCY / 2;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
	}

	if (m_bIsJump)
	{
		if (m_tInfo.fX >= P1.x && m_tInfo.fX <= P2.x && IsLine(P1, P2))
			m_bIsJump = false;
	}
	else
	{
		m_tInfo.fY = m_fGuideHeight;
	}

	if (m_tInfo.fY >= m_fGuideHeight)
		m_tInfo.fY = m_fGuideHeight;

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (!m_bIsJump)
		{
			m_bIsJump = true;
		}
	}


	return OBJ_NOEVENT;
}

void CPlayer::LateUpdate()
{
	if (m_bIsJump)
	{
		Jump();
	}
}

void CPlayer::Render(HDC hDC)
{
	CObj::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Jump()
{
	m_fTime += 0.1;

	float a = (m_fForce *m_fTime);

	float b = (10.f * (m_fTime * m_fTime));

	float y = m_fGuideHeight;

	if (m_tInfo.fY <= y)
	{
		m_tInfo.fY -= a - b;

		if (m_tInfo.fY > y)
		{
			m_tInfo.fY = y;
			m_bIsJump = false;
			m_fTime = 0;
		}
	}
}

bool CPlayer::IsLine(POINT _P1, POINT _P2)
{
	int iResult = (_P1.y - _P1.y) / (_P2.x - _P1.x) * (m_tInfo.fX - _P1.x) + _P1.y - m_tInfo.fY;

	if (iResult <= 0)
		return true;

	return false;

}

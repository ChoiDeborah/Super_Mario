#include "stdafx.h"
#include "Player.h"
#include "BackGroundMgr.h"
#include "ObjMgr.h"
#include "LineMgr.h"


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

	m_fSpeed = 3.f;
	m_fForce = 20.f;
	m_fTime = 0.f;
	m_fForce2 = 0.f;


	m_bIsJump = false;
	m_bIsRuning = false;

	m_fJumpAccel = 0.f;
	m_fJumpPower = 15.f;
}

int CPlayer::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	POINT P1 = { 0, WINCY-50 };
	POINT P2 = { WINCX, WINCY-50 };

	if (m_tInfo.fX >= P1.x && m_tInfo.fX <= P2.x)
	{
		m_fGuideHeight = (P2.y - P1.y) / (P2.x - P1.x) * (m_tInfo.fX - P1.x) + P1.y - m_tInfo.fCY / 2;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		if (m_bIsRuning)
		{
			m_tInfo.fX -= (m_fSpeed + m_fForce2);
		}
		else
		{
			CBackGroundMgr::Get_Instance()->Scroll_BackGround(m_fSpeed);
			m_tInfo.fX -= m_fSpeed;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if(m_bIsRuning)
		{
			m_tInfo.fX += (m_fSpeed + m_fForce2);
		}
		else
		{
			CBackGroundMgr::Get_Instance()->Scroll_BackGround(-m_fSpeed);
			m_tInfo.fX += m_fSpeed;
		}
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		
	 	m_bIsJump = true;
		
	}

	/*if (m_bIsJump)
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
*/


	if (GetAsyncKeyState('Z'))
	{
		m_bIsRuning = true;
	}
	else
	{
		if (m_bIsRuning) {
			m_bIsRuning = false;
		
			m_fForce2 = 0.f;
		}
	}


	return OBJ_NOEVENT;
}

void CPlayer::LateUpdate()
{
	IsJumping();
	if (m_bIsRuning)
	{
		Run();
	}
}


void CPlayer::Run()
{

	// z누르면 뛰는 상태가 되고
	// 뛰는 상태이면 시간 만큼 가속도에 시간을 더해준다.
	// 일정 속도에 다다르면 속도 증가를 멈추고
	// 뛰는 상태가 아니면 원래 속도로 되돌려 준다.
	m_fTime += 0.005;

	if (m_fForce2 <= 3.0f)
	{
		m_fForce2 += m_fTime;
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

//bool CPlayer::IsLine(POINT _P1, POINT _P2)
//{
//	int iResult = (_P1.y - _P1.y) / (_P2.x - _P1.x) * (m_tInfo.fX - _P1.x) + _P1.y - m_tInfo.fY;
//
//	if (iResult <= 0)
//		return true;
//
//	return false;
//
//}

void CPlayer::IsJumping()
{
	float fy = 0.f;
	bool bIsColl = CLineMgr::Get_Instance()->LineCollision(m_tInfo.fX, &fy, m_tInfo.fCY);

	// 사용자가 점프를 눌렀을때!
	if (m_bIsJump)
	{
		// 자유낙하 공식 사용 
		// y= 힘 * sin@(1이라 생략) * 시간 - 1/2 * 중력 * 시간 * 시간;
		m_tInfo.fY -= m_fJumpPower * m_fJumpAccel - GRAVITY * m_fJumpAccel * m_fJumpAccel * 0.5f;

		m_fJumpAccel += 0.21f;

		if (bIsColl && m_tInfo.fY > fy)
		{
			m_bIsJump = false;
			m_fJumpAccel = 0.f;
			m_tInfo.fY = fy;
		}
	}
	else if (bIsColl)
		m_tInfo.fY = fy;
}

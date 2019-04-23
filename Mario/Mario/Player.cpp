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

	m_bIsJump = false;
	m_bIsRuning = false;

	m_fJumpAccel = 0.f;
	m_fJumpPower = 20.f;
}

int CPlayer::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;


	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		CBackGroundMgr::Get_Instance()->Scroll_BackGround(m_fSpeed);
		CLineMgr::Get_Instance()->UpdateLine(m_fSpeed);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
		CBackGroundMgr::Get_Instance()->Scroll_BackGround(-m_fSpeed);
		CLineMgr::Get_Instance()->UpdateLine(-m_fSpeed);
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
	 	m_bIsJump = true;	
	}

	return OBJ_NOEVENT;
}

void CPlayer::LateUpdate()
{
	/*
	float fy = 0.f;
	bool isCol = CLineMgr::Get_Instance()->LineCollision(m_tInfo.fX, m_tInfo.fY, &fy, m_tInfo.fCY);*/
	
	//if(isCol)
	//	m_tInfo.fY = fy;

 	IsJumping();
	/*if (m_bIsRuning)
	{
		Run();
	}*/
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

void CPlayer::IsJumping()
{
	float fy = 0.f;
	bool bIsColl = CLineMgr::Get_Instance()->LineCollision(m_tInfo.fX, m_tInfo.fY, &fy, m_tInfo.fCY);
	
	// 사용자가 점프를 눌렀을때!
	if (m_bIsJump)
	{
		// 자유낙하 공식 사용 
		// y= 힘 * sin@(1이라 생략) * 시간 - 1/2 * 중력 * 시간 * 시간;
		m_tInfo.fY -= m_fJumpPower * m_fJumpAccel - GRAVITY * m_fJumpAccel * m_fJumpAccel * 0.5f;
		m_fJumpAccel += 0.21f;

		if (bIsColl)
		{
			m_bIsJump = false;
			m_fJumpAccel = 0.f;
			m_tInfo.fY = fy;
		}
	}
	else if (bIsColl)
	{
		//m_tInfo.fY = fy;
	}

	//m_tInfo.fY = fy;
}

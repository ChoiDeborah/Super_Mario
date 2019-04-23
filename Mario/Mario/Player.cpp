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
		if (m_bIsRuning)
		{
			m_tInfo.fX -= (m_fSpeed + m_fForce2);
		}
		else
		{
			
			m_tInfo.fX -= m_fSpeed;
			CBackGroundMgr::Get_Instance()->Scroll_BackGround(m_fSpeed);
			CLineMgr::Get_Instance()->UpdateLine(m_fSpeed);

			
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
			m_tInfo.fX += m_fSpeed;

			CBackGroundMgr::Get_Instance()->Scroll_BackGround(-m_fSpeed);
			CLineMgr::Get_Instance()->UpdateLine(-m_fSpeed);
			
		}
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
	 	m_bIsJump = true;	
	}


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

	// z������ �ٴ� ���°� �ǰ�
	// �ٴ� �����̸� �ð� ��ŭ ���ӵ��� �ð��� �����ش�.
	// ���� �ӵ��� �ٴٸ��� �ӵ� ������ ���߰�
	// �ٴ� ���°� �ƴϸ� ���� �ӵ��� �ǵ��� �ش�.
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
	bool bIsColl = CLineMgr::Get_Instance()->LineCollision(m_tInfo.fX, &fy, m_tInfo.fCY);

	// ����ڰ� ������ ��������!
	if (m_bIsJump)
	{
		// �������� ���� ��� 
		// y= �� * sin@(1�̶� ����) * �ð� - 1/2 * �߷� * �ð� * �ð�;
		m_tInfo.fY -= m_fJumpPower * m_fJumpAccel - GRAVITY * m_fJumpAccel * m_fJumpAccel * 0.5f;

		m_fJumpAccel += 0.21f;

		if (bIsColl && m_tInfo.fY > fy)
		{
			m_bIsJump = false;
			m_fJumpAccel = 0.f;

			//m_tInfo.fY = fy;
		}
	}
	else if (bIsColl)
	{
		m_tInfo.fY = fy;
	}
}

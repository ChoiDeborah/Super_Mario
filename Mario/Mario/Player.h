#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	template<class T>
	CObj* CreateBullet()
	{
		CObj* pObj = CAbstractFactory<T>::Create(float(m_tPosin.x), static_cast<float>(m_tPosin.y));
		pObj->Set_Angle(m_fAngle);
		pObj->Set_Target(this);
		return pObj;
	}

public:
	//void Jump();
	void Run();
public:
	void Set_BulletList(list<CObj*>* plistBullet) { m_plistBullet = plistBullet; }
	//bool IsLine(POINT _P1, POINT _P2);

public:
	void IsJumping();
	//void KeyCheck();
	void Set_Player_SizeUP()
	{
		m_tInfo.fCY += 30.f;
	}

private:
	list<CObj*>* m_plistBullet;

	bool m_bIsJump;
	float m_fForce;
	float m_fTime;
	float m_fGuideHeight;
	bool m_bIsRuning;
	float m_fForce2;

	float m_fJumpPower; // �������� v�� �ǰڴ�. 
	float m_fJumpAccel; // �̰� ���� t�� �ǰڴ�. ���ӵ�. 



	POINT P1;
	POINT P2;
};


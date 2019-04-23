#pragma once
class CObj
{
public:
	CObj();
	virtual ~CObj();
public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hDC) = 0;
	virtual void Release() = 0;


public:
	const INFO& Get_Info()const { return m_tInfo; }
	const RECT& Get_Rect()const { return m_tRect; }
	const LINEINFO& Get_LineInfo()const	{return m_tLineInfo;}



public:
	void Set_Pos(float fx, float fy)
	{
		m_tInfo.fX = fx;
		m_tInfo.fY = fy;
	}

	void Set_LineInfo(float x1, float y1, float x2, float y2)
	{
		m_tLineInfo.tLeftPoint = LINEPOS(x1, y1);
		m_tLineInfo.tRightPoint = LINEPOS(x2, y2);
	}
	void Set_Angle(float fAngle) { m_fAngle = fAngle; }
	void Set_Dead() { m_bIsDead = true; }
	void Set_Target(CObj* pTarget) { m_pTarget = pTarget; }
public:
	void UpdateRect();
	virtual void LateInit();
	
protected:
	INFO m_tInfo;
	RECT m_tRect;
	float m_fSpeed;
	float m_fAngle;
	bool m_bIsDead;
	CObj* m_pTarget;
	bool m_bIsInit;
	LINEINFO m_tLineInfo;

};


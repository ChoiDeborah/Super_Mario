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

public:
	void Set_Coin() { m_iCoin += 100; }						// 점수
	void Set_Life() { m_iLife += 1; }						// 라이프버섯 먹으면 라이프가 1 올라감
	void Set_Life_Damege() { m_iLife -= 1; }				// 몬스터에게 맞으면 라이프가 1 줄음.
	void Set_Player_Damege()
	{
		m_tInfo.fX -= 30.f;
		m_tInfo.fY -= 50.f;
	}

public:
	int Get_Coin() { return m_iCoin; }
	int Get_Life() { return m_iLife; }

public :

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

	float m_fPlayer_SizeUP;		// 버섯을 먹으면 플레이어의 크기를 키우는 변수
	int m_iCoin;				// 코인 변수 추가
	int m_iLife;				// 라이프 변수 추가

};


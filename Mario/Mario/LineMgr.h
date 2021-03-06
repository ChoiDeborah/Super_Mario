#pragma once
class CLine;
class CLineMgr
{
private:
	CLineMgr();
	~CLineMgr();
public:
	static CLineMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CLineMgr;

		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void Initialize();
	void Render(HDC hDC);
	void Release();
	void UpdateLine(float _fSpeed);
public:
	bool LineCollision(float fInX, float fInY, float* pOutY, float sizeY);

	bool UnderLine(LINEPOS _P1, LINEPOS _P2, float fX, float fY);
private:
	static CLineMgr* m_pInstance;
	list<CLine*> m_listLine;
	LINEPOS tPosGround[2];

};


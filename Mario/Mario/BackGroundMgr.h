#pragma once
class CObj;
class CBackGroundMgr
{
private:
	CBackGroundMgr();
	~CBackGroundMgr();

public:
	static CBackGroundMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
		{
			m_pInstance = new CBackGroundMgr;
		}

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
	void AddObject(BACKGROUNDID::ID eID, CObj* pObj);
	void Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();

	void Scroll_BackGround(float _fSpeed);

private:
	static CBackGroundMgr* m_pInstance;
	// ��濡 �� �� �����ϴ� �迭��
	OBJLIST m_Backgroundlist[BACKGROUNDID::END];
};


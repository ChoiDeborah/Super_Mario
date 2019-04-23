#pragma once
class CMainGame
{
public:
	CMainGame();
	~CMainGame();
public:
	// �ʱ�ȭ�� ���� �Լ�. 
	void Initialize();
	// ��ü���� ������ �� �Լ�. 
	void Update();
	// ���� �����̳� ������ �� �ʰ� ���ư����ϴ� �͵��� �� �Լ�. 
	void LateUpdate();
	// �׸� �׸� �Լ�. 
	void Render();
	// ���� �� �Լ�. 
	void Release();

private:
	HDC m_hDC;
	DWORD m_dwTime;
};


#pragma once
#include "Obj.h"
class CMonster :
	public CObj
{
public:
	CMonster();
	virtual ~CMonster();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};


#pragma once
#include "Obj.h"
class CCoin :
	public CObj
{
public:
	CCoin();
	virtual ~CCoin();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};


#pragma once
#include "Obj.h"
class CItemFlower :
	public CObj
{
public:
	CItemFlower();
	virtual ~CItemFlower();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};


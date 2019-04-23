#pragma once
#include "Obj.h"
class CItemFlower :
	public CObj
{
public:
	CItemFlower();
	virtual ~CItemFlower();

	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};


#pragma once
#include "Obj.h"
class CLife_Mushroom :
	public CObj
{
public:
	CLife_Mushroom();
	virtual ~CLife_Mushroom();

	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};


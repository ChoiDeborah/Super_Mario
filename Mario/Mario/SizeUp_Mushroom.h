#pragma once
#include "Obj.h"
class CSizeUp_Mushroom :
	public CObj
{
public:
	CSizeUp_Mushroom();
	virtual ~CSizeUp_Mushroom();

	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};


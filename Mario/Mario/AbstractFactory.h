#pragma once

template<class T>
class CAbstractFactory
{
public:
	static CObj* Create()
	{
		CObj* pObj = new T;
		pObj->Initialize();
		return pObj;
	}
	static CObj* Create(float fx, float fy)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fx, fy);
		pObj->Set_LineInfo(pObj->Get_Info().fX - pObj->Get_Info().fCX / 2, pObj->Get_Info().fY - pObj->Get_Info().fCY / 2, pObj->Get_Info().fX + pObj->Get_Info().fCX / 2, pObj->Get_Info().fY - pObj->Get_Info().fCY / 2);

		return pObj;
	}
};

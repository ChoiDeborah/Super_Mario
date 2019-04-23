#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"
#include "ObjMgr.h"
#include "Player.h"
CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::CollisionRect(OBJLIST & DestList, OBJLIST & SourList, OBJID::ID eDestID, OBJID::ID eSourID)
{
	RECT rc = {};
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				pDst->Set_Dead();
				pSrc->Set_Dead();
			}
		}
	}
}

void CCollisionMgr::CollisionRect_Coin(OBJLIST & DestList, OBJLIST & SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID)
{
	RECT rc = {};
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				pDst->Set_Dead();
				pSrc->Set_Coin();
			}
		}
	}
}

void CCollisionMgr::CollisionRect_SizeUp(OBJLIST & DestList, OBJLIST & SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID)
{
	RECT rc = {};
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				pDst->Set_Dead();
				dynamic_cast<CPlayer*>(pSrc)->Set_Player_SizeUP();
			}
		}
	}
}

void CCollisionMgr::CollisionRectEX(OBJLIST & DestList, OBJLIST & SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID)
{
	float fMoveX = 0.f, fMoveY = 0.f;
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (CheckRect(pDst, pSrc, &fMoveX, &fMoveY))
			{
				float x = pSrc->Get_Info().fX;
				float y = pSrc->Get_Info().fY;

				if (fMoveX > fMoveY)
				{
					if (y < pDst->Get_Info().fY)
						fMoveY *= -1.f;

					if (pSrc->Get_Rect().bottom <= pDst->Get_Rect().top)
						pSrc->Set_Pos(x, pDst->Get_Rect().top - fMoveY);
					else
						pSrc->Set_Pos(x, y + fMoveY);

				}
				else
				{
					if (x < pDst->Get_Info().fX)
						fMoveX *= -1.f;

					pSrc->Set_Pos(x + fMoveX, y);
				}
			}
		}
	}
}

void CCollisionMgr::CollisionRect_SizeUp_And_Bullet(OBJLIST & DestList, OBJLIST & SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID)
{
	RECT rc = {};
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				pDst->Set_Dead();
				dynamic_cast<CPlayer*>(pSrc)->Set_Player_SizeUP();
			}
		}
	}
}

void CCollisionMgr::CollisionRect_LifeUp(OBJLIST & DestList, OBJLIST & SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID)
{
	RECT rc = {};
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				pDst->Set_Dead();
				pSrc->Set_Life();
			}
		}
	}
}

void CCollisionMgr::CollisionRect_LifeDamege(OBJLIST & DestList, OBJLIST & SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID)
{
	RECT rc = {};
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				pSrc->Set_Life_Damege();
				pSrc->Set_Player_Damege();
			}
		}
	}
}

void CCollisionMgr::CollisionRect_Tile(OBJLIST & DestList, OBJLIST & SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID)
{
	RECT rc = {};
	float x = DestList.front()->Get_Info().fX;
	float y = DestList.front()->Get_Info().fY - 10.f;

	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				pDst->Set_Pos(x, y);
				pDst->Set_Coin();
			}
		}
	}
}

void CCollisionMgr::CollisionRectEX(OBJLIST & DestList, OBJLIST & SourList, OBJID::ID eDestID, OBJID::ID eSourID)
{
	float fMoveX = 0.f, fMoveY = 0.f;
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (CheckRect(pDst, pSrc, &fMoveX, &fMoveY))
			{
				float x = pSrc->Get_Info().fX;
				float y = pSrc->Get_Info().fY;

				if (fMoveX > fMoveY)
				{
					if (y < pDst->Get_Info().fY)
						fMoveY *= -1.f;

					pSrc->Set_Pos(x, y + fMoveY);
				}
				else
				{
					if (x < pDst->Get_Info().fX)
						fMoveX *= -1.f;

					pSrc->Set_Pos(x + fMoveX, y);
				}
			}
		}
	}

}

void CCollisionMgr::CollisionSphere(OBJLIST & DestList, OBJLIST & SourList, OBJID::ID eDestID, OBJID::ID eSourID)
{
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (CheckSphere(pDst, pSrc))
			{
				pDst->Set_Dead();
				pSrc->Set_Dead();
			}
		}
	}
}

void CCollisionMgr::CollisionRectExWithPlayer_OBJ(OBJLIST & ObjtList, OBJID::ID eOBJID)
{
	float fMoveX = 0.f, fMoveY = 0.f;

	CObj * pPlayer = CObjMgr::Get_Instance()->Get_Player();

	if (pPlayer != nullptr) 
	{
		for (auto& pObj : ObjtList)
		{

			if (CheckRect(pObj, CObjMgr::Get_Instance()->Get_Player(), &fMoveX, &fMoveY))
			{
				float x = pPlayer->Get_Info().fX;
				float y = pPlayer->Get_Info().fY;

				if (fMoveX > fMoveY)
				{
					if (y < pObj->Get_Info().fY)
						fMoveY *= -1.f;

					pPlayer->Set_Pos(x, y + fMoveY);
				}
				else
				{
					if (x < pObj->Get_Info().fX)
						fMoveX *= -1.f;

					pPlayer->Set_Pos(x + fMoveX, y);
				}
			}

		}
	}

}

void CCollisionMgr::CollisionRectExWithPlayer_BACKGROUND(OBJLIST & ObjtList, BACKGROUNDID::ID eOBJID)
{
	float fMoveX = 0.f, fMoveY = 0.f;
	CObj * pPlayer = CObjMgr::Get_Instance()->Get_Player();

	if (pPlayer != nullptr)
	{
		for (auto& pObj : ObjtList)
		{
			if (CheckRect(pObj, CObjMgr::Get_Instance()->Get_Player(), &fMoveX, &fMoveY))
			{
				float x = pPlayer->Get_Info().fX;
				float y = pPlayer->Get_Info().fY;

				if (fMoveX > fMoveY)
				{
					if (y < pObj->Get_Info().fY)
						fMoveY *= -1.f;

					pPlayer->Set_Pos(x, y + fMoveY);
				}
				else
				{
					if (x < pObj->Get_Info().fX)
						fMoveX *= -1.f;

					pPlayer->Set_Pos(x + fMoveX, y);
				}
			}
		}
	}

}

bool CCollisionMgr::CheckSphere(CObj * pDest, CObj * pSour)
{

	// 반지름의 합 구하기. 
	float fRadiusSum = (pDest->Get_Info().fCX * 0.5f) + (pSour->Get_Info().fCX * 0.5f);
	// 밑변과 높이 구하기. 
	float fx = pDest->Get_Info().fX - pSour->Get_Info().fX;
	float fy = pDest->Get_Info().fY - pSour->Get_Info().fY;

	// 피타고라스의 정리를 사용하여 거리를 구하기. 
	float fDist = sqrtf(fx * fx + fy * fy); // a^2 + b^2 = fDist;
											//거리와 반지름의 합으로 충돌판정. 
	return fDist <= fRadiusSum;
}

bool CCollisionMgr::CheckRect(CObj * pDest, CObj * pSour, float* pMoveX, float* pMoveY)
{
	// 반지름의 합. 
	float fRadiusSumX = (pDest->Get_Info().fCX * 0.5f) + (pSour->Get_Info().fCX * 0.5f);
	float fRadiusSumY = (pDest->Get_Info().fCY * 0.5f) + (pSour->Get_Info().fCY * 0.5f);

	float fDistX = fabs(pDest->Get_Info().fX - pSour->Get_Info().fX);
	float fDistY = fabs(pDest->Get_Info().fY - pSour->Get_Info().fY);

	if (fRadiusSumX >= fDistX && fRadiusSumY >= fDistY)
	{
		*pMoveX = fRadiusSumX - fDistX;
		*pMoveY = fRadiusSumY - fDistY;
		return true;
	}

	return false;
}
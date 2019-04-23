#include "stdafx.h"
#include "BackGroundMgr.h"
#include "Obj.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"

CBackGroundMgr* CBackGroundMgr::m_pInstance = nullptr;
CBackGroundMgr::CBackGroundMgr()
{
}


CBackGroundMgr::~CBackGroundMgr()
{
}

void CBackGroundMgr::AddObject(BACKGROUNDID::ID eID, CObj * pObj)
{
	m_Backgroundlist[eID].emplace_back(pObj);
}

int CBackGroundMgr::Update()
{
	for (int i = 0; i < BACKGROUNDID::END; ++i)
	{
		for (OBJITER iter = m_Backgroundlist[i].begin(); iter != m_Backgroundlist[i].end();)
		{
			int iEvent = (*iter)->Update();
			if (OBJ_DEAD == iEvent)
			{
				if ((*iter) != nullptr)
				{
					delete *iter;
					*iter = nullptr;
					iter = m_Backgroundlist[i].erase(iter);
				}
			}
			else
				++iter;
		}
	}
	return 0;
}

void CBackGroundMgr::LateUpdate()
{

	for (int i = 0; i < BACKGROUNDID::END; ++i)
	{
		for (auto& pObj : m_Backgroundlist[i])
		{
			pObj->LateUpdate();
		}
	}
	
	/*CCollisionMgr::CollisionRectExWithPlayer_BACKGROUND(m_Backgroundlist[BACKGROUNDID::ITEM], BACKGROUNDID::ITEM);
	CCollisionMgr::CollisionRectExWithPlayer_BACKGROUND(m_Backgroundlist[BACKGROUNDID::TILE], BACKGROUNDID::TILE);*/


}

void CBackGroundMgr::Render(HDC hDC)
{
	for (int i = 0; i < BACKGROUNDID::END; ++i)
	{
		for (auto& pObj : m_Backgroundlist[i])
		{
			pObj->Render(hDC);
		}
	}
}

void CBackGroundMgr::Release()
{
	for (int i = 0; i < BACKGROUNDID::END; ++i)
	{
		for (auto& pObj : m_Backgroundlist[i])
		{
			if (nullptr != pObj)
			{
				delete pObj;
				pObj = nullptr;
			}
		}
		m_Backgroundlist[i].clear();
	}
}

void CBackGroundMgr::Scroll_BackGround(float _fSpeed)
{
	for (int i = 0; i < BACKGROUNDID::END; ++i)
	{
		for (auto& pObj : m_Backgroundlist[i])
		{
			pObj->Set_Pos(pObj->Get_Info().fX + _fSpeed, pObj->Get_Info().fY);
		}
	}
}

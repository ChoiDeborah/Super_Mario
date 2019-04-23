#include "stdafx.h"
#include "LineMgr.h"
#include "Line.h"
#include "BackGroundMgr.h"
#include "Obj.h"
CLineMgr* CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
{
}


CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize()
{
	//LINEPOS tPosArr[4] = { { 100.f, 500.f },{ 300.f, 500.f },{ 500.f, 300.f },{ 700.f, 300.f } };
	LINEPOS tPosArr[2] = { { 0, WINCY - 50 } ,{ WINCX, WINCY - 50 }};
	m_listLine.emplace_back(new CLine(LINEINFO(tPosArr[0], tPosArr[1])));

	for (int i = 0; i < BACKGROUNDID::END; ++i)
	{
		for (auto& pObj : CBackGroundMgr::Get_Instance()->m_Backgroundlist[i])
		{
			m_listLine.emplace_back(new CLine(
				LINEINFO(
					LINEPOS(pObj->Get_LineInfo().tLeftPoint.fx, pObj->Get_LineInfo().tLeftPoint.fy),
					LINEPOS(pObj->Get_LineInfo().tRightPoint.fx, pObj->Get_LineInfo().tRightPoint.fy)))
			);
		}
	}

	
	//m_listLine.emplace_back(new CLine(LINEINFO(tPosArr[1], tPosArr[2])));
	//m_listLine.emplace_back(new CLine(LINEINFO(tPosArr[2], tPosArr[3])));
}

void CLineMgr::Render(HDC hDC)
{
	for (auto& pLine : m_listLine)
		pLine->Render(hDC);
}

void CLineMgr::Release()
{
	for (auto& pLine : m_listLine)
	{
		if (pLine)
		{
			delete pLine;
			pLine = nullptr;
		}
	}
	m_listLine.clear();
}

bool CLineMgr::LineCollision(float fInX, float * pOutY , float sizeY)
{
	if (m_listLine.empty())
		return false;

	CLine* pTarget = nullptr;
	for (auto& pLine : m_listLine)
	{
		if (fInX >= pLine->Get_LineInfo().tLeftPoint.fx &&
			fInX <= pLine->Get_LineInfo().tRightPoint.fx)
		{
			pTarget = pLine;
		}
	}
	if (nullptr == pTarget)
		return false;

	// Outy = ((y2 - y1) / (x2 - x1)) * (InX - x1) + y1;

	float x1 = pTarget->Get_LineInfo().tLeftPoint.fx;
	float x2 = pTarget->Get_LineInfo().tRightPoint.fx;
	float y1 = pTarget->Get_LineInfo().tLeftPoint.fy;
	float y2 = pTarget->Get_LineInfo().tRightPoint.fy;

	*pOutY = ((y2 - y1) / (x2 - x1)) * (fInX - x1) + y1 - sizeY/2;
	return true;


}

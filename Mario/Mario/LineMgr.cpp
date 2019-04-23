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
		for (OBJITER iter = CBackGroundMgr::Get_Instance()->m_Backgroundlist[i].begin(); iter != CBackGroundMgr::Get_Instance()->m_Backgroundlist[i].end(); ++iter)
		{
			m_listLine.emplace_back(new CLine(LINEINFO(
					LINEPOS((*iter)->Get_LineInfo().tLeftPoint.fx, (*iter)->Get_LineInfo().tLeftPoint.fy),
					LINEPOS((*iter)->Get_LineInfo().tRightPoint.fx, (*iter)->Get_LineInfo().tRightPoint.fy)))
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
			
			if(UnderLine(pLine->Get_LineInfo().tLeftPoint, pLine->Get_LineInfo().tRightPoint, fInX, *pOutY)) 
			{
				pTarget = pLine;
			}
		}
	}
	if (nullptr == pTarget)
		return false;

	float x1 = pTarget->Get_LineInfo().tLeftPoint.fx;
	float x2 = pTarget->Get_LineInfo().tRightPoint.fx;
	float y1 = pTarget->Get_LineInfo().tLeftPoint.fy;
	float y2 = pTarget->Get_LineInfo().tRightPoint.fy;

	*pOutY = ((y2 - y1) / (x2 - x1)) * (fInX - x1) + y1 - sizeY/2;
	return true;

}

bool CLineMgr::UnderLine(LINEPOS _P1, LINEPOS _P2 , float fX, float fY)
{
	
	int iResult = (_P1.fx - _P1.fy) / (_P2.fx - _P1.fx) * (fX - _P1.fx) + _P1.fy - fY;

	if (iResult >= 0)
		return true;

	return false;

	
}

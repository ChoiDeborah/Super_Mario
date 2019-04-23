#include "stdafx.h"
#include "Line.h"


CLine::CLine()
{
}

CLine::CLine(LINEINFO & rLineInfo)
	:m_tInfo(rLineInfo)
{
}

CLine::~CLine()
{
}

void CLine::Render(HDC hDC)
{
	MoveToEx(hDC, static_cast<int>(m_tInfo.tLeftPoint.fx), static_cast<int>(m_tInfo.tLeftPoint.fy), nullptr);
	LineTo(hDC, static_cast<int>(m_tInfo.tRightPoint.fx), static_cast<int>(m_tInfo.tRightPoint.fy));
}

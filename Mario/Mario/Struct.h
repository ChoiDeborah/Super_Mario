#pragma once
typedef struct tagInfo
{
	float fX;
	float fY;

	float fCX;
	float fCY;
}INFO;

typedef struct tagLinePos
{
	tagLinePos()
	{
		ZeroMemory(this, sizeof(tagLinePos));
	}
	tagLinePos(float x, float y)
		:fx(x)
		, fy(y)
	{}
	float fx;
	float fy;
}LINEPOS;

typedef struct tagLine
{
	tagLine()
	{
		ZeroMemory(this, sizeof(tagLine));
	}
	tagLine(LINEPOS& rLP, LINEPOS& rRP)
		:tLeftPoint(rLP)
		, tRightPoint(rRP)
	{}
	LINEPOS tLeftPoint;
	LINEPOS tRightPoint;
}LINEINFO;
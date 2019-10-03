#pragma once
#include "publichinh.h"
class hcn :
	public publichinh
{
private:
	int x1, y1, x2, y2;
public:
	hcn(CPoint p1,CPoint p2);
	hcn(int x1, int y1, int x2, int y2);
	void thietlap(int x1, int y1, int x2, int y2);
	CPoint getA();
	CPoint getC();
	void ve(CClientDC *pDC);
	int tronghinh(CPoint p);
	hcn();
	~hcn();
};


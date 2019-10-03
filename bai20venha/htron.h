#pragma once
#include "publichinh.h"
class htron :
	public publichinh
{
private:
	int x, y;
	int r;
public:
	htron(CPoint p1, CPoint p2);

	void ve(CClientDC *pDC);
	int tronghinh(CPoint p);
	void tang(CClientDC *pDC);
	void giam(CClientDC *pDC);
	void de(CClientDC *pDC);
	void velai(CClientDC *pDC);
	htron();
	~htron();
};


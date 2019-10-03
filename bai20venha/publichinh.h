#pragma once
class publichinh
{
public:
	CPoint point1, point2;
	virtual void ve(CClientDC *pDC);
	virtual int tronghinh(CPoint p);
	virtual void tang(CClientDC *pDC);
	virtual void giam(CClientDC *pDC);
	virtual void de(CClientDC *pDC);
	virtual void velai(CClientDC *pDC);
	publichinh();
	~publichinh();
};


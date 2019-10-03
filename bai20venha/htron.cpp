#include "stdafx.h"
#include "htron.h"

htron::htron(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	//x = (p1.x + p2.x) / 2;
	//y = (p1.y + p2.y) / 2;
//	r = (sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y))) / 2;
}
void htron::ve(CClientDC *pDC)
{
	pDC->Ellipse(point1.x, point1.y, point2.x, point2.y);
}
int htron::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= point1.x && p.x <= point2.x && p.y >= point1.y && p.y <= point2.y)
	{
		kq = 1;
	}
	return kq;
}
void htron::de(CClientDC *pDC)
{
	CBrush *mau;
	CPen *pen;
	CBrush *mau1;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 0, RGB(255, 255, 255));
	pen = pDC->SelectObject(pen1);
	mau1 = new CBrush(RGB(255, 255, 255));
	mau = pDC->SelectObject(mau1);
	pDC->Ellipse(point1.x, point1.y, point2.x, point2.y);

}
void htron::velai(CClientDC *pDC)
{
	CBrush *mau;
	CPen *pen;
	CBrush *mau1;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 0, RGB(0, 0, 0));
	pen = pDC->SelectObject(pen1);
	mau1 = new CBrush(RGB(255, 255, 255));
	mau = pDC->SelectObject(mau1);
	
}
void htron::tang(CClientDC *pDC)
{
	int a = 20;
	
	point1.x = point1.x - a;
	point1.y = point1.y - a;
	point2.x = point2.x + a;
	point2.y = point2.y + a;
	//a += 20;
	
}
void htron::giam(CClientDC *pDC)
{
	int a = 20;
	if (point1.y > 70 && point2.y > 70)
	{
		point1.x = point1.x + a;
		point1.y = point1.y + a;
		point2.x = point2.x - a;
		point2.y = point2.y - a;
		//a += 20;
	}
}
htron::htron()
{
}


htron::~htron()
{
}

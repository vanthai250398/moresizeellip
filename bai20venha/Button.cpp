#include "stdafx.h"
#include "Button.h"


Button::Button()
{
}
void Button::ve(CClientDC *pDC)
{
	pDC->Rectangle(getA().x, getA().y, getC().x, getC().y);
	pDC->TextOutW(getA().x + 15, getA().y + 20, c);
}

Button::~Button()
{
}

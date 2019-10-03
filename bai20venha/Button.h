#pragma once
#include "hcn.h"
class Button :
	public hcn
{
public:
	CString c;
	void ve(CClientDC *pDC);
	Button();
	~Button();
};


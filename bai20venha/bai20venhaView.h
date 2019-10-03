
// bai20venhaView.h : interface of the Cbai20venhaView class
//

#pragma once
#include"hcn.h"
#include"Button.h"
#include"htron.h"

class Cbai20venhaView : public CView
{
protected: // create from serialization only
	Cbai20venhaView() noexcept;
	DECLARE_DYNCREATE(Cbai20venhaView)

// Attributes
public:
	Cbai20venhaDoc* GetDocument() const;

// Operations
public:
	Button vehinh,tang,giam;
	publichinh *ph[10];
	CString c;
	CPoint p1, p2, p3, p4;
	int n, control;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cbai20venhaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in bai20venhaView.cpp
inline Cbai20venhaDoc* Cbai20venhaView::GetDocument() const
   { return reinterpret_cast<Cbai20venhaDoc*>(m_pDocument); }
#endif


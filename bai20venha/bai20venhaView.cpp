
// bai20venhaView.cpp : implementation of the Cbai20venhaView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "bai20venha.h"
#endif

#include "bai20venhaDoc.h"
#include "bai20venhaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbai20venhaView

IMPLEMENT_DYNCREATE(Cbai20venhaView, CView)

BEGIN_MESSAGE_MAP(Cbai20venhaView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_NCLBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cbai20venhaView construction/destruction

Cbai20venhaView::Cbai20venhaView() noexcept
{
	// TODO: add construction code here
	vehinh.thietlap(0, 0, 70, 50);
	vehinh.c = CString ("Htron");
	tang.thietlap(70, 0, 145, 50);
	tang.c = CString("TangKT");
	giam.thietlap(145, 0, 220, 50);
	giam.c = CString("GiamKT");
	n = 0;
	control = 0;
}

Cbai20venhaView::~Cbai20venhaView()
{
}

BOOL Cbai20venhaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cbai20venhaView drawing

void Cbai20venhaView::OnDraw(CDC* /*pDC*/)
{
	Cbai20venhaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pDC(this);
	
	CPen *pen;
	CBrush *mau;
	//
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 0, RGB(0, 225, 225));
	pen = pDC.SelectObject(pen1);
	vehinh.ve(&pDC);
	tang.ve(&pDC);
	giam.ve(&pDC);
	// TODO: add draw code for native data here
}


// Cbai20venhaView printing

BOOL Cbai20venhaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cbai20venhaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cbai20venhaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cbai20venhaView diagnostics

#ifdef _DEBUG
void Cbai20venhaView::AssertValid() const
{
	CView::AssertValid();
}

void Cbai20venhaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cbai20venhaDoc* Cbai20venhaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cbai20venhaDoc)));
	return (Cbai20venhaDoc*)m_pDocument;
}
#endif //_DEBUG


// Cbai20venhaView message handlers


//void Cbai20venhaView::OnNcLButtonDown(UINT nHitTest, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CView::OnNcLButtonDown(nHitTest, point);
//}


void Cbai20venhaView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x = point.x;
	p1.y = point.y;
	p2.x = point.x;
	p2.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void Cbai20venhaView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pDC(this);
	p2.x = point.x;
	p2.y = point.y;
	if (vehinh.tronghinh(point) == 1)
		control = 1;
	else
		if (tang.tronghinh(point) == 1)
			control = 2;
		else
			if (giam.tronghinh(point) == 1)
				control = 3;
			else
				if (control == 1 && p1.y > 50 && p2.y > 50)
				{
					ph[n] = new htron(p1,p2);
					ph[n]->ve(&pDC);
					n++;
				}
				else
				{
					if (control == 2 && p1.y > 50 && p2.y > 50)
					{
						for (int i = 0; i < n; i++)
						{
							if (ph[i]->tronghinh(point) == 1)
							{
								
								ph[i]->de(&pDC);
								ph[i]->ve(&pDC);
								ph[i]->tang(&pDC);
								ph[i]->velai(&pDC);
								ph[i]->ve(&pDC);
							}
						}
					}
					else
					{
						if (control == 3 && p1.y > 50 && p2.y > 50)
						{
							for (int i = 0; i < n; i++)
							{
								if (ph[i]->tronghinh(point) == 1)
								{
									ph[i]->de(&pDC);
									ph[i]->ve(&pDC);
									ph[i]->giam(&pDC);
									ph[i]->velai(&pDC);
									ph[i]->ve(&pDC);
								}
							}
						}
					}
				}
	CView::OnLButtonUp(nFlags, point);
}

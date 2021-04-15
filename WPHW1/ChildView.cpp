
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "WPHW1.h"
#include "ChildView.h"
#include "Cshape.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_LButtonDown = false;
	m_RButtonDown = false;
	m_rectnum = 0;
	m_cirnum = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	CRect rect;
	GetClientRect(&rect);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memDC.SelectObject(&bitmap);
	BITMAP bmpInfo;
	bitmap.GetBitmap(&bmpInfo);
		
	for (int i = 0; i < m_rectnum + 1; i++)
	{
		if (m_LButtonDown)
		{
			m_rectLisdt[i].Draw(&dc);

			CBitmap bg;

			bg.LoadBitmap(IDB_BITMAP1);

			CBrush bitbrush(&bg);

			memDC.SelectObject(&bitbrush);

			memDC.Rectangle(0, 0, 40, 40);


			dc.StretchBlt(m_rectLisdt[i].m_StartPoint.x, m_rectLisdt[i].m_StartPoint.y, m_rectLisdt[i].m_EndPoint.x - m_rectLisdt[i].m_StartPoint.x,
				m_rectLisdt[i].m_EndPoint.y - m_rectLisdt[i].m_StartPoint.y, &memDC, 0, 0, 40, 40, SRCCOPY);
			//dc.Rectangle(m_rectLisdt[i].m_StartPoint.x, m_rectLisdt[i].m_StartPoint.y, m_rectLisdt[i].m_EndPoint.x, m_rectLisdt[i].m_EndPoint.y);

			//dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

		}
	}

		for (int a = 0; a < m_cirnum + 1; a++)
		{

			if (m_RButtonDown)

			{

				m_circleList[a].Draw(&dc);
				CBrush brush1(RGB(255, 250, 0));
				dc.SelectObject(&brush1);
				dc.SetROP2(R2_COPYPEN);
				memDC.Ellipse(m_StartPoint.x, m_StartPoint.y, m_EndPoint.x- m_StartPoint.x, m_EndPoint.y- m_StartPoint.y);
				dc.Ellipse(m_circleList[a].m_StartPoint.x, m_circleList[a].m_StartPoint.y, m_circleList[a].m_EndPoint.x, m_circleList[a].m_EndPoint.y);
			}


		}
	

		


	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_LButtonDown = true;
	m_rectLisdt[m_rectnum].m_StartPoint = point;
	//m_StartPoint = point;
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{


	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//m_EndPoint = point;

	m_LButtonDown = false;
	m_rectLisdt[m_rectnum].m_EndPoint = point;
	m_rectnum++;
	::ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_RButtonDown = true;
	m_circleList[m_cirnum].m_StartPoint = point;
	//m_StartPoint = point;
	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//m_EndPoint = point;
	m_RButtonDown = false;
	m_circleList[m_cirnum].m_EndPoint = point;
	m_cirnum++;
	::ReleaseCapture();
	CWnd::OnRButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_LButtonDown || m_RButtonDown)
	{


		m_rectLisdt[m_rectnum].m_EndPoint = point;
		m_circleList[m_cirnum].m_EndPoint = point;
		Invalidate(false);

	}


	CWnd::OnMouseMove(nFlags, point);
}

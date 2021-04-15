#include "pch.h"
#include"Ccircle.h"

Ccircle::Ccircle()
{

}
Ccircle::~Ccircle()
{

}

void Ccircle::Draw(CDC* pDC)
{
	pDC->Ellipse(m_StartPoint.x, m_StartPoint.y, m_EndPoint.x, m_EndPoint.y);
}
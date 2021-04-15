#include "pch.h"
#include "Crectangle.h"

Crectangle::Crectangle(void)
{

}
Crectangle::~Crectangle(void)
{

}

void Crectangle ::Draw(CDC* pDC)
{
	pDC->StretchBlt(this->m_StartPoint.x, this->m_StartPoint.y, this->m_EndPoint.x - this->m_StartPoint.x,
		this->m_EndPoint.y - this->m_StartPoint.y, pDC, 0, 0, 40, 40, SRCCOPY);
}
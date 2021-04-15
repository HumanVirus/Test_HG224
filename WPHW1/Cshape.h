#pragma once
#include"Ccircle.h"
#include"Crectangle.h"
class Cshape
{
public:
	Cshape(void);
	~Cshape(void);

	CPoint m_EndPoint;
	CPoint m_StartPoint;
	Crectangle Draw2();
	Ccircle Draw1();
	void Draw(CDC* pDC);

};
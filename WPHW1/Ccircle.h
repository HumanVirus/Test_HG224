#pragma once

class Ccircle
{
public:
	Ccircle(void);
	~Ccircle(void);

	CPoint m_EndPoint;
	CPoint m_StartPoint;


	void Draw(CDC* pDC);
};
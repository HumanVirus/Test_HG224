#pragma once

class Crectangle
{
public:
	Crectangle(void);
	~Crectangle(void);

	CPoint m_EndPoint;
	CPoint m_StartPoint;

	void Draw(CDC* pDC);
};
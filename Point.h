#pragma once
#include <string>
#include <iostream>

class Point
{
public:
	Point(float x, float y){}
	Point() : m_x(0), m_y(0){}
	~Point();
	const int getX() const { return m_x; }
	const int getY() const { return m_y; }
	void operator=(const Point& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Point& rhs);

private:
	int m_x;
	int m_y;
};

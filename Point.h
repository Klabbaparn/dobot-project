#ifndef POINT_H
#define POINT_H
#include <string>
#include <iostream>

class Point
{
public:
	Point(float x, float y) : m_x(x), m_y(y){}
	Point() : m_x(0), m_y(0){}
	~Point();
	const float getX() const { return m_x; }
	const float getY() const { return m_y; }
	Point(const Point&);
	void operator=(const Point& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Point& rhs);

private:
	float m_x;
	float m_y;
};

#endif // POINT_H
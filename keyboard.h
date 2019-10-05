#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <Point.h>
#include <map>
#include <string>
class keyboard
{
public:
	keyboard();
	Point getKeyCoord(const char charToPrint);
	~keyboard() {}

private:
	std::map<const char, Point> m_KeyboardCoords;
};

#endif // KEYBOARD_H

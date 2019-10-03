#include "keyboard.h"
#include <map>
#include <utility>
#include <iostream> 
#include <string.h> 
using namespace std;


keyboard::keyboard()
{
	std::map<char, Point> m_KeyboardCoords;
	m_KeyboardCoords['q'] = Point(225, -186); //
	m_KeyboardCoords['w'] = Point(225, -186);
	m_KeyboardCoords['e'] = Point(225, -186);
	m_KeyboardCoords['r'] = Point(225, -186);
	m_KeyboardCoords['t'] = Point(225, -186);
	m_KeyboardCoords['y'] = Point(225, -186);
	m_KeyboardCoords['u'] = Point(225, -186);
	m_KeyboardCoords['i'] = Point(225, -186);
	m_KeyboardCoords['o'] = Point(225, -186);
	m_KeyboardCoords['p'] = Point(225, -186);
	m_KeyboardCoords['a'] = Point(225, -186);
	m_KeyboardCoords['s'] = Point(225, -186);
	m_KeyboardCoords['d'] = Point(225, -186);
	m_KeyboardCoords['f'] = Point(225, -186);
	m_KeyboardCoords['g'] = Point(225, -186);
	m_KeyboardCoords['h'] = Point(225, -186);
	m_KeyboardCoords['j'] = Point(225, -186);
	m_KeyboardCoords['k'] = Point(225, -186);
	m_KeyboardCoords['l'] = Point(225, -186);
	m_KeyboardCoords['z'] = Point(225, -186);
	m_KeyboardCoords['x'] = Point(225, -186);
	m_KeyboardCoords['c'] = Point(225, -186);
	m_KeyboardCoords['v'] = Point(225, -186);
	m_KeyboardCoords['b'] = Point(225, -186);
	m_KeyboardCoords['n'] = Point(225, -186);
	m_KeyboardCoords['m'] = Point(225, -186);
}


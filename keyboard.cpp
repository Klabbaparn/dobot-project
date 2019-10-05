#include "keyboard.h"
#include <map>
#include <utility>
#include <iostream> 
#include <string.h> 
using namespace std;


keyboard::keyboard()
{
	m_KeyboardCoords['q'] = Point(281.86F, 68.36F); 
	m_KeyboardCoords['w'] = Point(284, 50.37F); 
	m_KeyboardCoords['e'] = Point(285.3F, 32.43F); 
	m_KeyboardCoords['r'] = Point(283.5F, 15.2F);
	m_KeyboardCoords['t'] = Point(285.48F, -0.13F);
	m_KeyboardCoords['y'] = Point(285.43F, -17.4F);
	m_KeyboardCoords['u'] = Point(284.57F, -35.8F);
	m_KeyboardCoords['i'] = Point(282.83F, -52.87F);
	m_KeyboardCoords['o'] = Point(284.3F, -69.1F);
	m_KeyboardCoords['p'] = Point(282.54F, -87.63F); 
	m_KeyboardCoords['a'] = Point(260.58F, 59.76F); 
	m_KeyboardCoords['s'] = Point(261.8F, 40.23F); 
	m_KeyboardCoords['d'] = Point(263.45F, 23);
	m_KeyboardCoords['f'] = Point(262.1F, 6.54F);
	m_KeyboardCoords['g'] = Point(261.9F, -9.92F);
	m_KeyboardCoords['h'] = Point(260.86F, -26.24F); 
	m_KeyboardCoords['j'] = Point(261.1F, -46); 
	m_KeyboardCoords['k'] = Point(260.65F, -63.5F);
	m_KeyboardCoords['l'] = Point(261.8F, -78.16F);
	m_KeyboardCoords['z'] = Point(240.5F, 39.57F);
	m_KeyboardCoords['x'] = Point(240.84F, 24.23F);
	m_KeyboardCoords['c'] = Point(239.14F, 5.97F);
	m_KeyboardCoords['v'] = Point(239.57F, -9.19F);
	m_KeyboardCoords['b'] = Point(239.36F, -27.1F);
	m_KeyboardCoords['n'] = Point(239.46F, -45.56F);
	m_KeyboardCoords['m'] = Point(238.98F, -61.24F); 
	m_KeyboardCoords[' '] = Point(212.1F, -8); 
}

Point keyboard::getKeyCoord(const char charToPrint)
{
	return m_KeyboardCoords[charToPrint];
}


#include "Blank.h"

Blank::Blank(int _x, int _y, QPixmap& _icon, QWidget* parent)
	: Corner::Corner(_x, _y, _icon, parent)
{
	setConnectDirection();
}

void Blank::setConnectDirection()
{
	connectDirection[0] = 0;
	connectDirection[1] = 0;
	connectDirection[2] = 0;
	connectDirection[3] = 0;
	connectDirection[4] = 0;
}

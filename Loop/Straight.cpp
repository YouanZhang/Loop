#include "Straight.h"

Straight::Straight(int _x, int _y, QPixmap& _icon, QWidget* parent)
	: Corner::Corner(_x, _y, _icon, parent)
{
	setConnectDirection();
	for (int r = rand() % 4; r; r--) rotateCorner();
}

void Straight::setConnectDirection()
{
	connectDirection[0] = 1;
	connectDirection[1] = 0;
	connectDirection[2] = 1;
	connectDirection[3] = 0;
	connectDirection[4] = 1;
}

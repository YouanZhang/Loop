#include "ThreeCorner.h"

ThreeCorner::ThreeCorner(int _x, int _y, QPixmap& _icon, QWidget* parent)
	: Corner::Corner(_x, _y, _icon, parent)
{
	setConnectDirection();
	for (int r = rand() % 4; r; r--) rotateCorner();
}

void ThreeCorner::setConnectDirection()
{
	connectDirection[0] = 1;
	connectDirection[1] = 1;
	connectDirection[2] = 1;
	connectDirection[3] = 0;
	connectDirection[4] = 1;
}

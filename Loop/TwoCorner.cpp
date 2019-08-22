#include "TwoCorner.h"

void TwoCorner::setConnectDirection()
{
	connectDirection[0] = 1;
	connectDirection[1] = 1;
	connectDirection[2] = 0;
	connectDirection[3] = 0;
	connectDirection[4] = 1;
}

TwoCorner::TwoCorner(int _x, int _y, QPixmap& _icon, QWidget* parent)
	: Corner::Corner(_x, _y, _icon, parent)
{
	setConnectDirection();
	for (int r = rand() % 4; r; r--) rotateCorner();
}

//bool TwoCorner::checkCorner(Corner* L, Corner* U, Corner* R, Corner* D)
//{
//	if (connectDirection[0])
//		if (U->connectDirection[2] == 0)
//			return false;
//	if (connectDirection[1])
//		if (R->connectDirection[3] == 0)
//			return false;
//	if (connectDirection[2])
//		if (D->connectDirection[0] == 0)
//			return false;
//	if (connectDirection[3])
//		if (L->connectDirection[1] == 0)
//			return false;
//	return true;
//}

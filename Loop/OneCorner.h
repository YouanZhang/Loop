#pragma once

#include "Corner.h"

class OneCorner : public Corner
{
private:
	//bool connectDirection[5];
	//0 -> U
	//1 -> R
	//2 -> D
	//3 -> L
protected:
	virtual void setConnectDirection();
	//bool checkCorner(Corner* ,Corner* ,Corner* ,Corner*);
public:
	OneCorner(int, int, QPixmap&, QWidget* parent = NULL);
};

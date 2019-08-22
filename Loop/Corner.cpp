#include "Corner.h"
#include <QDebug>

Corner::Corner(/*int _type, */int _x, int _y, QPixmap& _icon, QWidget* parent)
	: QPushButton(parent)
	, icon(_icon)
	, rot(/*rand() % 4 * 90*/0)
	//, type(_type)
	, x(_x)
	, y(_y)
{
	/*qDebug() << "Corner" << endl;
	for (int i=0;i<5;i++)
		connectDirection[i] = 0;
	for (int i=0;i<type;i++)
		connectDirection[i] = 1;
	if (type == 5)
	{
		connectDirection[0] = 1;
		connectDirection[1] = 0;
		connectDirection[2] = 1;
		connectDirection[3] = 0;
	}
	connectDirection[4] = connectDirection[0];
	for (int r = rot; r; r -= 90)
	{
		connectDirection[4] = connectDirection[3];
		connectDirection[3] = connectDirection[2];
		connectDirection[2] = connectDirection[1];
		connectDirection[1] = connectDirection[0];
		connectDirection[0] = connectDirection[4];
	}*/
	connect(this, &Corner::clicked, this, &Corner::OnClicked);
	//icon.scaled(QSize(100, 100));
	setIconSize(icon.size());
	setIcon(icon);
	//setStyleSheet("margin:0; border:1; padding:0;");
	//setFixedSize(icon.size());
	setGeometry(x, y, 50, 50);
}

void Corner::setX(int _x)
{
	x = _x;
}

int& Corner::getX()
{
	return x;
}

void Corner::setY(int _y)
{
	y = _y;
}

int& Corner::getY()
{
	return y;
}

void Corner::setRot(int _rot)
{
	rot = _rot;
}

int& Corner::getRot()
{
	return rot;
}

//void Corner::setType(int _type)
//{
//	type = _type;
//}

//int& Corner::getType()
//{
//	return type;
//}

void Corner::setConnectDirection(int direction, bool statue)
{
	connectDirection[direction] = statue;
}

bool& Corner::getConnectDirection(int direction)
{
	return connectDirection[direction];
}

void Corner::setIcon(QPixmap _icon)
{
	icon = _icon;
}

QPixmap& Corner::getIcon()
{
	//qDebug() << icon << endl;
	return icon;
}

void Corner::rotateCorner()
{
	qDebug() << "Corner::rotateCorner" << endl;
	qDebug() << x << ' ' << y << endl;
	for (int i = 0; i < 5; i++) qDebug() << (int)connectDirection[i] << ' ';
	qDebug() << endl;

	connectDirection[4] = connectDirection[3];
	connectDirection[3] = connectDirection[2];
	connectDirection[2] = connectDirection[1];
	connectDirection[1] = connectDirection[0];
	connectDirection[0] = connectDirection[4];

	for (int i = 0; i < 5; i++) qDebug() << (int)connectDirection[i] << ' ';
	qDebug() << endl;

	rot += 90;
	if (rot == 360) rot = 0;
	update();
}

bool Corner::checkCorner(Corner* L, Corner* U, Corner* R, Corner* D)
{
	qDebug() << x << ' ' << y << endl;
	qDebug() << U->x << U->y << (int)U->connectDirection[0] << (int)U->connectDirection[1] << (int)U->connectDirection[2] << (int)U->connectDirection[3] << ' ';
	qDebug() << L->x << L->y << (int)L->connectDirection[0] << (int)L->connectDirection[1] << (int)L->connectDirection[2] << (int)L->connectDirection[3] << ' ';
	qDebug() << D->x << D->y << (int)D->connectDirection[0] << (int)D->connectDirection[1] << (int)D->connectDirection[2] << (int)D->connectDirection[3] << ' ';
	qDebug() << R->x << R->y << (int)R->connectDirection[0] << (int)R->connectDirection[1] << (int)R->connectDirection[2] << (int)R->connectDirection[3] << ' ';
	if (connectDirection[0])
		if (U->connectDirection[2] == 0)
			return false;
	if (connectDirection[1])
		if (R->connectDirection[3] == 0)
			return false;
	if (connectDirection[2])
		if (D->connectDirection[0] == 0)
			return false;
	if (connectDirection[3])
		if (L->connectDirection[1] == 0)
			return false;
	return true;
	/*if (getConnectDirection(0))
		if (U->getConnectDirection(2) == 0)
			return false;
	qDebug() << "?0";
	if (getConnectDirection(1))
		if (R->getConnectDirection(3) == 0)
			return false;
	qDebug() << "?1";
	if (getConnectDirection(2))
		if (D->getConnectDirection(0) == 0)
			return false;
	qDebug() << "?2";
	if (getConnectDirection(3))
		if (L->getConnectDirection(1) == 0)
			return false;
	qDebug() << "?3";
	return true;*/
}

void Corner::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	qDebug() << "Corner::paintEvent" << endl;
	//qDebug() << x << ' ' << y << endl;
	QMatrix matrix;
	//qDebug() << qreal(rot);
	matrix.rotate(rot);
	painter.drawPixmap(0, 0, icon.transformed(matrix));
	//QPixmap icon;
	//for (int i = 0; i <= 2 + 1; i++)
		//for (int j = 0; j <= 2 + 1; j++)
		//{
			//icon = graph[i][j]->geticon();
			//painter.drawPixmap(0, 0, icon);
		//}
}

void Corner::OnClicked()
{
	rotateCorner();
	qDebug() << "OnClicked";
	repaint();
	emit beenClicked();
}
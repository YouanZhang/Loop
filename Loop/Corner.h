#pragma once

#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QMatrix>

class Corner : public QPushButton
{
	Q_OBJECT
private:
	bool connectDirection[5];
	int x, y;
	int type;
	int rot;
	//0 -> U
	//1 -> R
	//2 -> D
	//3 -> L
	QPixmap icon;

public:
	Corner(int,int,int,QPixmap&, QWidget* parent = NULL);
	int& getX();
	void setX(int);
	int& getY();
	void setY(int);
	int& getRot();
	bool& getConnectDirection(int);
	int& getType();
	QPixmap& getIcon();
	void rotateCorner();
	bool checkCorner(Corner*, Corner*, Corner*, Corner*);
	//void painter(QPainter*);

protected:
	void paintEvent(QPaintEvent* );

signals:
	void beenClicked();

public slots:
	void OnClicked();
};
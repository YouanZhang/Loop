#pragma once

#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QMatrix>

class Corner : public QPushButton
{
	Q_OBJECT
protected:
	int x;
	int y;
	int rot;
	//int type;
	QPixmap icon;

public:
	Corner(/*int,*/int,int,QPixmap&, QWidget* parent = NULL);
	void setX(int);
	int& getX();
	void setY(int);
	int& getY();
	void setRot(int);
	int& getRot();
	//void setType(int);
	//int& getType();
	virtual void setConnectDirection() {};
	bool& getConnectDirection(int);
	void setIcon(QPixmap);
	QPixmap& getIcon();
	void rotateCorner();
	bool checkCorner(Corner*, Corner*, Corner*, Corner*);
	//void painter(QPainter*);

protected:
	bool connectDirection[5];
	void paintEvent(QPaintEvent* );

public slots:
	void OnClicked();

signals:
	void beenClicked();
};

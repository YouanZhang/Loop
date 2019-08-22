#pragma once

#include <QWidget>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QEvent>
#include <QMatrix>
#include "Corner.h"
#include "Blank.h"
#include "OneCorner.h"
#include "TwoCorner.h"
#include "ThreeCorner.h"
#include "FourCorner.h"
#include "Straight.h"

class Graph : public QWidget
{
	Q_OBJECT

private:
	static const int MAX_SIZE = 20;
	int n, m;
	Corner* graph[MAX_SIZE][MAX_SIZE];
	int posx[MAX_SIZE];
	int posy[MAX_SIZE];

public:
	Graph(int, int, QString, QWidget* parent = nullptr);

protected:
	void paintEvent(QPaintEvent*);

public slots:
	void checkGraph();
signals:
	void isComplete();
};
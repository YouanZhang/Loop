#pragma once

#include <QWidget>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QEvent>
#include <QMatrix>
#include <QFileInfo>
#include <queue>
#include <utility>
#include "Corner.h"
#include "Blank.h"
#include "OneCorner.h"
#include "TwoCorner.h"
#include "ThreeCorner.h"
#include "FourCorner.h"
#include "Straight.h"
using namespace std;

static const int MAX_SIZE = 20;
static const double extendedProbability = 0.13971934550852228839889753863791;
static const int movex[4] = { -1,0,1,0 };
static const int movey[4] = { 0,1,0,-1 };
static const int type[1 << 4] = { 0,1,1,2,1,5,2,3,1,2,5,3,2,3,3,4 };

typedef pair <int, int> P;

class Graph : public QWidget
{
	Q_OBJECT

private:
	int n, m;
	Corner* graph[MAX_SIZE][MAX_SIZE];
	int posx[MAX_SIZE];
	int posy[MAX_SIZE];

public:
	Graph(int, int, QString, QWidget* parent = nullptr);
	void createGraph(QString);
protected:
	void paintEvent(QPaintEvent*);

public slots:
	void checkGraph();
signals:
	void isComplete();
};
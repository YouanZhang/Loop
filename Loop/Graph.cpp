#include "Graph.h"
#include <QDebug>
#include <QStyleOption>

Graph::Graph(int w,int h,QString level, QWidget* parent)
	: QWidget(parent)
{
	setStyleSheet("background-color: rgb("+QString::number(rand()%56+200)+"," + QString::number(rand() % 56+200) + "," + QString::number(rand() % 56+200) + ");");
	qDebug() << "Graph" << endl;
	QFile file(":/level/level/"+level);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream in(&file);
	QString s;
	in >> s;
	n = s.toInt();
	in >> s;
	m = s.toInt();
	for (int i = 0; i <= n + 1; i++)
	{
		posx[i] = i * 50;
		qDebug() << posx[i];
	}
	for (int i = 0; i <= m + 1; i++)
	{
		posy[i] = i * 50;
		qDebug() << posy[i];
	}
	int g;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
		{
			int w = (width() - (n + 2) * 50) / 2;
			int h = (height() - (m + 2) * 50) / 2;
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
				graph[i][j] = new Corner(0, posx[i] + w, posy[j] + h, QPixmap(QString(":/image/image/transparent.png")), this);
			else
			{
				in >> s;
				g = s.toInt();
				graph[i][j] = new Corner(g, posx[i] + w, posy[j] + h, QPixmap(QString(":/image/image/" + QString::number(g) + ".png")), this);
				//int rot = graph[i][j]->getRot();
				//qDebug() << '!' << rot << endl;																		
			}
			connect(graph[i][j], &Corner::beenClicked, this, &Graph::checkGraph);
		}
	for (int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++)
		{
			qDebug() << (int)graph[i][j]->getConnectDirection(0) 
					 << (int)graph[i][j]->getConnectDirection(1) 
					 << (int)graph[i][j]->getConnectDirection(2) 
					 << (int)graph[i][j]->getConnectDirection(3) 
					 << graph[i][j]->getRot()
					 << graph[i][j]->getType()
					 << ' ';
		}
}

void Graph::paintEvent(QPaintEvent*)
{
	qDebug() << "Graph::paintEvent" << endl;
	int w = (width() - (n + 2) * 50) / 2;
	int h = (height() - (m + 2) * 50) / 2;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
		{
			graph[i][j]->setX(posx[i] + w);
			graph[i][j]->setY(posy[j] + h);
			graph[i][j]->setGeometry(graph[i][j]->getX(), graph[i][j]->getY(), 50, 50);
		}
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
//	QPainter painter(this);
//	painter.drawPixmap(0, 0, QPixmap(":/Loop/image/timg.jfif"));
//	//painter.background(":/Loop/image/timg.jfif");
}

void Graph::checkGraph()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (graph[i][j]->checkCorner(graph[i - 1][j], graph[i][j - 1], graph[i + 1][j], graph[i][j + 1]) == false)
			{
				qDebug() << "!" << i << ' ' << j << endl;
				return;
			}
		}
	emit isComplete();
}


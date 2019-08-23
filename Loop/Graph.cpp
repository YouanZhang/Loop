#include "Graph.h"
#include <QDebug>
#include <QStyleOption>

// Constructor
Graph::Graph(int w, int h, QString level, QWidget* parent)
	: QWidget(parent)
	, graph()
	, posx()
	, posy()
{
	// Set the background-color
	// The reason why the parameters are written in order to make the background color lighter
	setStyleSheet("background-color: rgb(" + QString::number(rand() % 56 + 200) + "," + QString::number(rand() % 56 + 200) + "," + QString::number(rand() % 56 + 200) + ");");
	/*qDebug() << "Graph" << endl;*/

	// Check that the current level file does exist or not, if it does not, create it
	QFileInfo f("level/" + level);
	if (!f.exists()) createGraph(level);

	// Open the current level file and read graph infomation
	QFile file("level/" + level);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream in(&file);

	// Read the size of graph
	QString s;
	in >> s;
	n = s.toInt();
	in >> s;
	m = s.toInt();

	// Set the relative position of each row and columu 
	for (int i = 0; i <= n + 1; i++)
	{
		posx[i] = i * 50;
		/*qDebug() << posx[i];*/
	}
	for (int i = 0; i <= m + 1; i++)
	{
		posy[i] = i * 50;
		/*qDebug() << posy[i];*/
	}

	// Read the infomation of each grid(which I called "Corner"), and set it, and paint it
	int g;
	// w and h is the absolute transformation coordinates
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			int w = (width() - (n + 2) * 50) / 2;
			int h = (height() - (m + 2) * 50) / 2;
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
			{
				graph[i][j] = new Blank(posx[i] + w, posy[j] + h, QPixmap(QString(":/image/image/transparent.png")), this);
			}
			else
			{
				in >> s;
				g = s.toInt();
				/*qDebug() << g;*/
				switch (g)
				{
				case 0:
					graph[i][j] = new Blank(posx[i] + w, posy[j] + h, QPixmap(QString(":/image/image/transparent.png")), this);
					break;
				case 1:
					graph[i][j] = new OneCorner(posx[i] + w, posy[j] + h, QPixmap(QString(":/image/image/" + QString::number(g) + ".png")), this);
					break;
				case 2:
					graph[i][j] = new TwoCorner(posx[i] + w, posy[j] + h, QPixmap(QString(":/image/image/" + QString::number(g) + ".png")), this);
					break;
				case 3:
					graph[i][j] = new ThreeCorner(posx[i] + w, posy[j] + h, QPixmap(QString(":/image/image/" + QString::number(g) + ".png")), this);
					break;
				case 4:
					graph[i][j] = new FourCorner(posx[i] + w, posy[j] + h, QPixmap(QString(":/image/image/" + QString::number(g) + ".png")), this);
					break;
				case 5:
					graph[i][j] = new Straight(posx[i] + w, posy[j] + h, QPixmap(QString(":/image/image/" + QString::number(g) + ".png")), this);
					break;
				default:
					break;
				}

				//int rot = graph[i][j]->getRot();
				//qDebug() << '!' << rot << endl;
			}

			// Connect signal(beenClicked) and slot function(checkGraph)
			// Whenever the grid been clicked, check the graph is complete or not
			connect(graph[i][j], &Corner::beenClicked, this, &Graph::checkGraph);
		}
	}

	// Check if the map is already completed when it is first generated
	if (checkGraph())
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				// Make sure that the same rotation level is no longer generated
				for (int k = rand() % 3 + 1; k; k--)
				{
					graph[i][j]->rotateCorner();
				}
			}
		}
	}
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//	{
	//		qDebug() << (int)graph[i][j]->getConnectDirection(0)
	//			<< (int)graph[i][j]->getConnectDirection(1)
	//			<< (int)graph[i][j]->getConnectDirection(2)
	//			<< (int)graph[i][j]->getConnectDirection(3)
	//			<< graph[i][j]->getRot()
	//			//<< graph[i][j]->getType()
	//			<< ' ';
	//	}
	//}
}

// Create a new graph
void Graph::createGraph(QString level)
{
	/*qDebug() << "createGraph";*/

	// Create/Open the file
	QFile file("level/" + level);
	file.open(QIODevice::ReadWrite | QIODevice::Text);
	QTextStream out(&file);

	// Randomly generate map size
	int n = min(level.toInt(), 15);
	int m = min(level.toInt(), 10);

	// Randomly make each grid extend around
	bool g[MAX_SIZE][MAX_SIZE][4] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (i + movex[k]<0 || i + movex[k]>n - 1 || j + movey[k]<0 || j + movey[k]>m - 1 || g[i][j][k]) continue;
				if (rand() < 32767 * extendedProbability)
				{
					/*qDebug() << i << j << k;*/
					g[i][j][k] = 1;
					g[i + movex[k]][j + movey[k]][(k + 2) % 4] = 1;
				}
			}
		}
	}

	// Data input
	out << n << ' ' << m << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t = 0;
			for (int k = 0; k < 4; k++) t += ((g[i][j][k] ? 1 : 0) << k);
			/*qDebug()
				<< '!'<<  (g[i][j][0] ? 1 : 0)
				<< ' ' << (g[i][j][1] ? 1 : 0)
				<< ' ' << (g[i][j][2] ? 1 : 0)
				<< ' ' << (g[i][j][3] ? 1 : 0) << '!';
			qDebug() << t << ' ';*/
			out << type[t] << ' ';
		}
		out << endl;
	}

	// Close file
	file.close();
}

// paintEvent
void Graph::paintEvent(QPaintEvent*)
{
	/*qDebug() << "Graph::paintEvent" << endl;*/
	int w = (width() - (n + 2) * 50) / 2;
	int h = (height() - (m + 2) * 50) / 2;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
		{
			/*if (graph[i][j] == nullptr)
				qDebug() << "!" << i << ' ' << j;*/
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

// check graph is completed or not
bool Graph::checkGraph()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			// If each grid has been completed, the graph is also been completed
			if (graph[i][j]->checkCorner(graph[i - 1][j], graph[i][j - 1], graph[i + 1][j], graph[i][j + 1]) == false)
			{
				/*qDebug() << "!" << i << ' ' << j << endl;*/
				return false;
			}
		}

	// Send signal
	emit isCompleted();
	return true;
}


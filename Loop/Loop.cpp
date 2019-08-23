#include "Loop.h"
#include <QDebug>
#include <QMessageBox>

static int level = 1;

Loop::Loop(QWidget* parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	/*qDebug() << "Loop" << endl;*/

	// Read progress
	QFile progress("progress/progress");
	progress.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream in(&progress);
	QString s;
	in >> s;
	level = s.toInt();
	progress.close();

	// Create graph
	G = new Graph(600, 900, QString::number(level));
	//G = new Graph(ui.widget->width(), ui.widget->height(), QString::number(++level), ui.widget);

	//G->setGeometry(0, 0, ui.widget->width(), ui.widget->height());
	//QPalette pal(G->palette());
	//pal.setColor(QPalette::Background, Qt::black);
	//G->setAutoFillBackground(true);
	//G->setPalette(pal);
	G->show();

	// Connect signal(isCompleted) and slot function(levelUp)
	// Whenever the graph is completed, enter the next level
	connect(G, &Graph::isCompleted, this, &Loop::levelUp);
}

void Loop::levelUp()
{
	_sleep(1000);

	/*qDebug() << "levelUp" << endl;*/
	//QMessageBox::warning(this, "a", "b");

	// Get the current widget position
	int x = G->frameGeometry().x();
	int y = G->frameGeometry().y();
	int w = G->frameGeometry().width();
	int h = G->frameGeometry().height();

	delete G;

	G = new Graph(600, 900, QString::number(++level));

	// Set the new widget in the original position
	G->setGeometry(x, y, w, h);

	/*qDebug() << level;*/
	// Write current progress
	QFile progress("progress/progress");
	progress.open(QIODevice::ReadWrite | QIODevice::Text);
	QTextStream out(&progress);
	out << QString::number(level);
	progress.close();

	G->show();

	// Connect signal(isCompleted) and slot function(levelUp)
	// Whenever the graph is completed, enter the next level
	connect(G, &Graph::isCompleted, this, &Loop::levelUp);
	//update();
}

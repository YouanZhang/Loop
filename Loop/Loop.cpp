#include "Loop.h"
#include <QDebug>
#include <QMessageBox>

static int level = 0;

Loop::Loop(QWidget* parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	qDebug() << "Loop" << endl;
	G = new Graph(300, 900, QString::number(++level));
	//G = new Graph(ui.widget->width(), ui.widget->height(), QString::number(++level), ui.widget);

	//G->setGeometry(0, 0, ui.widget->width(), ui.widget->height());
	//QPalette pal(G->palette());
	//pal.setColor(QPalette::Background, Qt::black);
	//G->setAutoFillBackground(true);
	//G->setPalette(pal);
	G->show();
	connect(G, &Graph::isComplete, this, &Loop::levelUp);

}

void Loop::levelUp()
{
	qDebug() << "levelUp" << endl;
	//QMessageBox::warning(this, "a", "b");
	delete G;
	G = new Graph(ui.widget->width(), ui.widget->height(), QString::number(++level), ui.widget);
	G->setGeometry(0, 0, 600, 880);
	G->show();
	connect(G, &Graph::isComplete, this, &Loop::levelUp);
	//update();
}
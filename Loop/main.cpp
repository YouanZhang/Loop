#include "Loop.h"
#include "Graph.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	srand(time(0));
	QApplication a(argc, argv);
	Loop w;
	//w.show();
	//Graph w("1");
	//w.show();
	return a.exec();
}

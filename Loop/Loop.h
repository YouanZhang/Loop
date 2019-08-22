#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>
#include <QFile>
#include "ui_Loop.h"
#include "Graph.h"

class Loop : public QMainWindow
{
	Q_OBJECT

public:
	Loop(QWidget* parent = Q_NULLPTR);

private:
	Ui::LoopClass ui;
	Graph* G;

public slots:
	void levelUp();

};

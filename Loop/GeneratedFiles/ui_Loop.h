/********************************************************************************
** Form generated from reading UI file 'Loop.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOP_H
#define UI_LOOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoopClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *LoopClass)
    {
        if (LoopClass->objectName().isEmpty())
            LoopClass->setObjectName(QString::fromUtf8("LoopClass"));
        LoopClass->resize(600, 900);
        centralWidget = new QWidget(LoopClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 600, 880));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LoopClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoopClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        LoopClass->setMenuBar(menuBar);

        retranslateUi(LoopClass);

        QMetaObject::connectSlotsByName(LoopClass);
    } // setupUi

    void retranslateUi(QMainWindow *LoopClass)
    {
        LoopClass->setWindowTitle(QCoreApplication::translate("LoopClass", "Loop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoopClass: public Ui_LoopClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOP_H

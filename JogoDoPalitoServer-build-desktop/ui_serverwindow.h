/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created: Thu 5. Jul 17:34:44 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QSpinBox *playersSpinBox;
    QPushButton *startButton;
    QTableView *gameTableView;
    QLabel *ipLabel;
    QLabel *portLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName(QString::fromUtf8("ServerWindow"));
        ServerWindow->resize(282, 356);
        centralWidget = new QWidget(ServerWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 101, 21));
        playersSpinBox = new QSpinBox(centralWidget);
        playersSpinBox->setObjectName(QString::fromUtf8("playersSpinBox"));
        playersSpinBox->setGeometry(QRect(120, 10, 42, 22));
        playersSpinBox->setMinimum(1);
        playersSpinBox->setMaximum(4);
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(200, 10, 75, 23));
        gameTableView = new QTableView(centralWidget);
        gameTableView->setObjectName(QString::fromUtf8("gameTableView"));
        gameTableView->setGeometry(QRect(10, 110, 261, 192));
        ipLabel = new QLabel(centralWidget);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));
        ipLabel->setGeometry(QRect(10, 50, 271, 20));
        portLabel = new QLabel(centralWidget);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));
        portLabel->setGeometry(QRect(10, 80, 271, 21));
        ServerWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ServerWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 282, 21));
        ServerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ServerWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ServerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ServerWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ServerWindow->setStatusBar(statusBar);

        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerWindow)
    {
        ServerWindow->setWindowTitle(QApplication::translate("ServerWindow", "Servidor Jogo do Palito", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ServerWindow", "Number of players:", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("ServerWindow", "Start!", 0, QApplication::UnicodeUTF8));
        ipLabel->setText(QApplication::translate("ServerWindow", "Ip:", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("ServerWindow", "Port:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H

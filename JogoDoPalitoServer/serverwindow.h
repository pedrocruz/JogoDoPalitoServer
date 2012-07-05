#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include "basketserver.h"


namespace Ui {
class ServerWindow;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ServerWindow(QWidget *parent = 0);    
    ~ServerWindow();

private:
    Ui::ServerWindow *ui;
    BasketServer basketServer;

private slots:
    void on_startButton_clicked();
};

#endif // SERVERWINDOW_H

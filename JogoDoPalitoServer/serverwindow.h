#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <QTcpServer>

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ServerWindow(QWidget *parent = 0);
    int playersNumber;
    QTcpServer server;

    void setUpServer();
    void startGame();

    ~ServerWindow();

signals:
    allPlayersReady();

private slots:
    sendPlayersResult();
    getPlayerMove();
    
private:
    Ui::ServerWindow *ui;
};

#endif // SERVERWINDOW_H

#ifndef BASKETSERVER_H
#define BASKETSERVER_H

#include <QTcpServer>
#include <QList>
#include <QNetworkInterface>
#include <player.h>

class BasketServer : QObject
{
    Q_OBJECT
public:
    BasketServer();
    ~BasketServer();

    int playersNumber;
    int playersConnected;
    QTcpServer server;
    QList<Player*> playersList;
    QString  ipAddress;
    int port;

    void setUpServer(); //start listening to ports
    void startGame(); //invoked when all players are connected
signals:
    void allPlayersReady();

private slots:
    void sendPlayersResult();
    void getPlayersMoves();
    void acceptConnection();

};

#endif // BASKETSERVER_H

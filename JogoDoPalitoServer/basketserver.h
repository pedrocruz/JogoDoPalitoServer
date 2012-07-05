#ifndef BASKETSERVER_H
#define BASKETSERVER_H

#include <QTcpServer>
#include <QList>
#include <player.h>

class BasketServer
{
public:
    BasketServer();

    int playersNumber;
    QTcpServer server;
    QList<Player> playersList;

    void setUpServer(); //start listening to ports
    void startGame(); //invoked when all players are connected
signals:
    void allPlayersReady();

private slots:
    void sendPlayersResult();
    void getPlayerMove();

};

#endif // BASKETSERVER_H

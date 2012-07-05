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

    void setUpServer();
    void startGame();
signals:
    allPlayersReady();

private slots:
    sendPlayersResult();
    getPlayerMove();

};

#endif // BASKETSERVER_H

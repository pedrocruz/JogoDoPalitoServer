#ifndef BASKETSERVER_H
#define BASKETSERVER_H
#define separator ","
#define moveConst "<move>"
#define indexConst "<index>"
#define playersConst "<players>"

#include <QTcpServer>
#include <QList>
#include <QNetworkInterface>
#include <player.h>
#include<QString>
#include <iostream>


class BasketServer :public QObject
{
    Q_OBJECT
public:
    BasketServer();
    ~BasketServer();

    int playersNumber;
    int nPlayersWithName;
    int playersConnected;
    int numberOfGuesses;
    QTcpServer server;
    QList<Player*> playersList;
    QString  ipAddress;
    int port;
    void sendMessage(QString message, QTcpSocket* tcpSocket);
    void setUpServer(int nPlayers); //start listening to ports
    void startGame(); //invoked when all players are connected
signals:
    void allPlayersReady();
    void sendLog(QString log);

private slots:
    void getNameChosen(int index, QString name);
    void sendPlayersResult();
    void getGuess(int index);
    void acceptConnection();

};

#endif // BASKETSERVER_H

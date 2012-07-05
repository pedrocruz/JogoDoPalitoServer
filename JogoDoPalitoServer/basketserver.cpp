#include "basketserver.h"





BasketServer::BasketServer()
{
}
BasketServer::~BasketServer()
{
}
void BasketServer::setUpServer()
{
    playersConnected=0;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    connect(&server, SIGNAL(newConnection()),
        this, SLOT(acceptConnection()));
    server.listen();
    port=server.serverPort();
}

void BasketServer::acceptConnection()
{
    if (playersConnected < playersNumber)
    {

        Player* player=new Player();
        player->socket=server.nextPendingConnection();
        playersList.append(player);
        connect(playersList.at(playersConnected)->socket, SIGNAL(readyRead()),
        this , SLOT(getPlayersMoves()));
        playersConnected++;


    }
}

void BasketServer::startGame()
{
}
void BasketServer::sendPlayersResult()
{}
void BasketServer::getPlayersMoves()
{

}

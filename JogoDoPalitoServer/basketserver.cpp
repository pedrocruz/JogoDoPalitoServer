#include "basketserver.h"





BasketServer::BasketServer()
{
}
BasketServer::~BasketServer()
{
}
void BasketServer::setUpServer(int nPlayers)
{
    playersConnected=0;
    playersNumber=nPlayers;
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
    emit sendLog("Servidor Iniciado");
}

void BasketServer::acceptConnection()
{
    Player* player=new Player();
    player->socket=server.nextPendingConnection();
    if (playersConnected < playersNumber)
    {
        playersList.append(player);
        connect(player->socket, SIGNAL(readyRead()),
         player, SLOT(updateMoves()));
        sendMessage(QString(indexConst)+QString(",")+QString::number(playersConnected),player->socket);
        playersConnected++;
        emit sendLog("Jogador Conectado");


    }else{
        sendMessage("server full",player->socket);
        delete player;
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
void BasketServer::sendMessage(QString message,QTcpSocket* tcpSocket)
{

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out<< message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    tcpSocket->write(block);
    tcpSocket->flush();

}

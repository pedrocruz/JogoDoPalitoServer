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
    nPlayersWithName=0;
    numberOfGuesses=0;
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
    emit sendLog("Servidor iniciado.");
}

void BasketServer::acceptConnection()
{
    Player* player=new Player();
    player->socket=server.nextPendingConnection();
    if (playersConnected < playersNumber)
    {
        player->index=playersConnected;
        playersList.append(player);
        connect(player->socket, SIGNAL(readyRead()),
                player, SLOT(messageReceived()));
        connect (player,SIGNAL(nameChosen(int, QString)), this,SLOT(getNameChosen(int, QString)) );
        connect (player,SIGNAL(guessMade(int)),this,SLOT(getGuess(int)));
        sendMessage(QString(indexConst)+QString(",")+QString::number(playersConnected),player->socket);
        playersConnected++;
        emit sendLog("Jogador "+QString::number(playersConnected)+ " conectado.");


    }else{
        sendMessage("server full",player->socket);
        emit sendLog("Conexão não permitida. Servidor lotado.");
        delete player;
    }
}

void BasketServer::startGame()
{
}
void BasketServer::sendPlayersResult()
{}

void BasketServer::getGuess(int index)
{
    emit sendLog("Jogador "+QString::number(index+1)+" deu seu palpite");
    numberOfGuesses++;
    if(numberOfGuesses==playersNumber)
    {
        QString message=moveConst;
        for (int i=0;i<playersNumber;i++){
            message= message + ","+QString::number(playersList.at(i)->hand);
            message= message + ","+QString::number(playersList.at(i)->guess);
        }
        for (int i=0;i<playersNumber;i++)
        {
          sendMessage(message,playersList.at(i)->socket);
        }
        numberOfGuesses=0;
    }
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
 void BasketServer::getNameChosen(int index, QString name){
     emit sendLog("Jogador "+QString::number(index+1)+" escolheu o nome "+name);
     nPlayersWithName++;
     if(nPlayersWithName==playersNumber)
     {
         QString message=playersConst;
         for (int i=0;i<playersNumber;i++){
             message= message + ","+playersList.at(i)->name;
         }
         for (int i=0;i<playersNumber;i++)
         {
           sendMessage(message,playersList.at(i)->socket);
         }
     }
 }

#include "player.h"

Player::Player()
{
    blockSize = 0;
}
void Player::updateMoves()
{

}
void Player::messageReceived(){

    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);
    if (blockSize == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;

    }

    if (socket->bytesAvailable() < blockSize){
        return;
   }
    QString inMessage;
    in >> inMessage;
    blockSize = 0;
    parseMessage(inMessage);
}
void Player::parseMessage(QString message)
{
    QStringList list;
    list = message.split(separator);
    if(message.contains(moveConst))
    {
        hand=list.at(1).toInt();
        guess=list.at(2).toInt();
        emit guessMade(index);

     }else if (message.contains(nameConst))
     {
        name=list.at(1);
        emit nameChosen(index,name);
     }

}


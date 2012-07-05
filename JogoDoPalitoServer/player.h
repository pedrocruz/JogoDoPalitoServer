#ifndef PLAYER_H
#define PLAYER_H

#include <QTcpSocket>
#include <QString>

class Player
{
public:
    Player();
    QTcpSocket socket;
    QString name;
    int turn;
    int hand;
    int guess;
};

#endif // PLAYER_H

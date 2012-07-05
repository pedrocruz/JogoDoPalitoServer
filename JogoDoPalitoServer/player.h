#ifndef PLAYER_H
#define PLAYER_H

#include <QTcpSocket>
#include <QString>
#include <QObject>

class Player : QObject
{
Q_OBJECT
public:
    Player();
    QTcpSocket *socket;
    QString name;
    int turn;
    int hand;
    int guess;
private slots:
    void updateMoves();
};

#endif // PLAYER_H

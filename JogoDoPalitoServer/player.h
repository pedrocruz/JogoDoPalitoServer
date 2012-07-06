#ifndef PLAYER_H
#define PLAYER_H
#define separator ","
#define moveConst "<move>"
#define nameConst "<name>"
#define indexConst "<index>"
#define playersConst "<players>"

#include <QTcpSocket>
#include <QString>
#include <QObject>
#include<QStringList>
#include<iostream>
class Player : public QObject
{
Q_OBJECT
public:
    Player();
    QTcpSocket *socket;
    QString name;
    int index;
    int turn;
    int hand;
    int guess;
    int alreadyPlayed;
    qint16 blockSize;
    void parseMessage(QString message);
signals:
    void nameChosen(int index,QString name);
    void guessMade(int index);
public slots:
    void messageReceived();
private slots:
    void updateMoves();
};

#endif // PLAYER_H

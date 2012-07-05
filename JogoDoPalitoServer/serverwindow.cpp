#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}


void ServerWindow::on_startButton_clicked()
{
    basketServer.setUpServer();

    ui->ipLabel->setText("Ip:"+basketServer.ipAddress);
    ui->portLabel->setText("Port:"+ QString::number(basketServer.port));
}


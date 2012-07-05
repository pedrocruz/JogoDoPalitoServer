#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    connect(&basketServer, SIGNAL(sendLog(QString)),
     this, SLOT(displayLog(QString)));
}

ServerWindow::~ServerWindow()
{
    delete ui;
}


void ServerWindow::on_startButton_clicked()
{
    basketServer.setUpServer(ui->playersSpinBox->value());

    ui->ipLabel->setText("Ip:"+basketServer.ipAddress);
    ui->portLabel->setText("Port:"+ QString::number(basketServer.port));
}
void ServerWindow::displayLog(QString log)
{
    ui->LogEdit->append(log);
}


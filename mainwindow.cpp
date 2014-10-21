#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include ""
#include "QtSerialPort/QSerialPort"

int c=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    port=new QSerialPort(this);
    port->setPortName("COM3");
    port->setBaudRate(BAUD_9600);

    ui->btnSaludar->connect(ui->btnSaludar,SIGNAL(clicked()),this,SLOT(Saludar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Saludar()
{
    c++;
    qDebug("Hola mundo ");
    ui->texto->setText("Hola Mundo\n");
    ui->btnCombo->addItem("%c",c);
    port->write("1");
}

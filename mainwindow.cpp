#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnSaludar->connect(ui->btnSaludar,SIGNAL(clicked()),this,SLOT(Saludar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Saludar()
{
    qDebug("Hola mundo ");
    ui->lista->addItem("Hola Mundo");
}

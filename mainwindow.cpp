#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "particula.h"
#include <QTimer>
   //Declarando un objeto grafico de la clase Particula

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->resize(1100,700);
    this->setFixedSize(1100,700);
    timer = new QTimer(this);

    escena = new QGraphicsScene;
    ui->fondo->setScene(escena);

    escena->setSceneRect(-5,-5,995,495);
    particle = new Particula(10,70,20,70,5,0.01);
    escena->addItem(particle);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizarEscena()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::actualizarEscena(void)
{

    particle->moverParticula(1, 495);
    particle->colisionParticula(995,495);


}

void MainWindow::on_pushButton_clicked()
{
//    particle = new Particula(7,7,30,50,5);
//    escena->addItem(particle);
//    t=0;
    timer->start(50);
    //actualizarEscena();
    /*escena->addLine(0,250,0,-250,QPen(Qt::red));
    escena->addLine(-250,0,250,0,QPen(Qt::red));
    QGraphicsRectItem *rectangulo;
    rectangulo = escena->addRect(-150,-150,90,90,QPen(Qt::black),QBrush(Qt::green));*/
}

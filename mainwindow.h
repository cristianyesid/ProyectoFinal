#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "particula.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void actualizarEscena(void);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    Particula *particle;
    QTimer *timer;
};

#endif // MAINWINDOW_H

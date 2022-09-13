#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    oglwidget olgw;
//    olgw.show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

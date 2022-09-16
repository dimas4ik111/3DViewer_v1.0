#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{  
    ui->setupUi(this);
    ui->xSlider->setRange(0, 360 * 16);
    ui->xSlider->setSingleStep(16);
    ui->xSlider->setPageStep(15 * 16);
    ui->xSlider->setTickInterval(15 * 16);
//    ui->xSlider->setTickPosition(QSlider::TicksRight);

    ui->ySlider->setRange(0, 360 * 16);
    ui->ySlider->setSingleStep(16);
    ui->ySlider->setPageStep(15 * 16);
    ui->ySlider->setTickInterval(15 * 16);
//    ui->ySlider->setTickPosition(QSlider::TicksRight);

    ui->zSlider->setRange(0, 360 * 16);
    ui->zSlider->setSingleStep(16);
    ui->zSlider->setPageStep(15 * 16);
    ui->zSlider->setTickInterval(15 * 16);
//    ui->zSlider->setTickPosition(QSlider::TicksRight);
    connect(ui->xSlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setXRotation);
    connect(ui->OGLwidget, &GLWidget::xRotationChanged, ui->xSlider, &QSlider::setValue);
    connect(ui->ySlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setYRotation);
    connect(ui->OGLwidget, &GLWidget::yRotationChanged, ui->ySlider, &QSlider::setValue);
    connect(ui->zSlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setZRotation);
    connect(ui->OGLwidget, &GLWidget::zRotationChanged, ui->zSlider, &QSlider::setValue);
    ui->xSlider->setValue(360 * 8);
    ui->ySlider->setValue(360 * 8);
    ui->zSlider->setValue(360 * 8);
}

//void createSlider(QSlider)
//{
//    QSlider *slider = new QSlider(Qt::Vertical);
//    slider->setRange(0, 360 * 16);
//    slider->setSingleStep(16);
//    slider->setPageStep(15 * 16);
//    slider->setTickInterval(15 * 16);
//    slider->setTickPosition(QSlider::TicksRight);
//    return slider;
//}

MainWindow::~MainWindow()
{
    delete ui;
}

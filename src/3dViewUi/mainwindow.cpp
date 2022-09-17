#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{  
    ui->setupUi(this);

    connect(ui->openObjButton, SIGNAL(clicked()), this, SLOT(handleOpenFile()));

    ui->xSlider->setRange(0, 360 * 16);
    ui->xSlider->setSingleStep(16);
    ui->xSlider->setPageStep(15 * 16);
    ui->xSlider->setTickInterval(15 * 16);

    ui->ySlider->setRange(0, 360 * 16);
    ui->ySlider->setSingleStep(16);
    ui->ySlider->setPageStep(15 * 16);
    ui->ySlider->setTickInterval(15 * 16);

    ui->zSlider->setRange(0, 360 * 16);
    ui->zSlider->setSingleStep(16);
    ui->zSlider->setPageStep(15 * 16);
    ui->zSlider->setTickInterval(15 * 16);

    connect(ui->xSlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setXRotation);
    connect(ui->OGLwidget, &GLWidget::xRotationChanged, ui->xSlider, &QSlider::setValue);
    connect(ui->xText, SIGNAL(editingFinished()), (this), SLOT(xTextEdit()));

    connect(ui->ySlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setYRotation);
    connect(ui->OGLwidget, &GLWidget::yRotationChanged, ui->ySlider, &QSlider::setValue);
    connect(ui->yText, SIGNAL(editingFinished()), (this), SLOT(yTextEdit()));

    connect(ui->zSlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setZRotation);
    connect(ui->OGLwidget, &GLWidget::zRotationChanged, ui->zSlider, &QSlider::setValue);
    connect(ui->zText, SIGNAL(editingFinished()), (this), SLOT(zTextEdit()));

    ui->xSlider->setValue(360 * 8);
    ui->ySlider->setValue(360 * 8);
    ui->zSlider->setValue(360 * 8);
    ui->xText->setText(QString::number(0));
    ui->yText->setText(QString::number(0));
    ui->zText->setText(QString::number(0));
}

void MainWindow::handleOpenFile() {
    // Определяем класс диалогового окна выбора файла
    QFileDialog *fileDialog = new QFileDialog(this);
    // Определяем заголовок окна
    fileDialog-> setWindowTitle (tr ("Выберите .obj-файл"));
    // Устанавливаем путь к файлу по умолчанию
    // fileDialog->setDirectory(QDir::homePath());
    // Устанавливаем фильтр файлов
    fileDialog->setNameFilter(tr("(*.obj)"));
    // Устанавливаем режим просмотра
    fileDialog->setViewMode(QFileDialog::Detail);
    // Вызываем диалог
    QStringList fileNames;
    if (fileDialog->exec()) {
       fileNames = fileDialog->selectedFiles();
       // В случае успеха и если что-то выбрано
       if (fileNames.size() > 0) {
           QString fileName = fileNames.at(0);
           qDebug() << "Выбран файл: " << fileName;
           ui->statusbar->showMessage("Выбран файл: " + fileName);
           QByteArray ba = fileName.toLocal8Bit();
           char *input = ba.data();
           // Парсим файл
           s21_parse_file(input, &ui->OGLwidget->rawObjData);
           // Инициализируем буфферы OpenGL распарсенными данными
           ui->OGLwidget->initBuffers();
       }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

int valNormalize(int val) {
    while (val > 180) {
        val -= 360;
    }
    while (val < -180) {
        val += 360;
    }
    return val;
}

void MainWindow::xTextEdit()
{
    int val = ui->xText->text().toInt();
    val += 180;
    val = valNormalize(val);
    ui->OGLwidget->setXRotation(val * 16);
}

void MainWindow::yTextEdit()
{
    int val = ui->yText->text().toInt();
    val += 180;
    val = valNormalize(val);
    ui->OGLwidget->setYRotation(val * 16);
}

void MainWindow::zTextEdit()
{
    int val = ui->zText->text().toInt();
    val += 180;
    val = valNormalize(val);
    ui->OGLwidget->setZRotation(val * 16);
}

void MainWindow::on_pushButton_clicked()
{
    ui->xSlider->setValue(360 * 8);
    ui->ySlider->setValue(360 * 8);
    ui->zSlider->setValue(360 * 8);
}

void MainWindow::on_xSlider_valueChanged(int value)
{
    ui->xText->setText(QString::number(-180 + value / 16));
}


void MainWindow::on_ySlider_valueChanged(int value)
{
    ui->yText->setText(QString::number(-180 + value / 16));
}


void MainWindow::on_zSlider_valueChanged(int value)
{
    ui->zText->setText(QString::number(-180 + value / 16));
}

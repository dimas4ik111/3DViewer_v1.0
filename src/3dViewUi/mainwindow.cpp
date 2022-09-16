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

    connect(ui->ySlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setYRotation);
    connect(ui->OGLwidget, &GLWidget::yRotationChanged, ui->ySlider, &QSlider::setValue);

    connect(ui->zSlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setZRotation);
    connect(ui->OGLwidget, &GLWidget::zRotationChanged, ui->zSlider, &QSlider::setValue);

    ui->xSlider->setValue(360 * 8);
    ui->ySlider->setValue(360 * 8);
    ui->zSlider->setValue(360 * 8);
    ui->xText->setText(QString::number(0));
    ui->yText->setText(QString::number(0));
    ui->zText->setText(QString::number(0));
}

void MainWindow::handleOpenFile() {
    // Определить класс диалогового окна файла
    QFileDialog *fileDialog = new QFileDialog(this);
    // определить заголовок файла
    fileDialog-> setWindowTitle (tr ("Открыть изображение"));
    // Установить путь к файлу по умолчанию
    //    fileDialog->setDirectory("");
    // Установить фильтр файлов
    fileDialog->setNameFilter(tr("(*.obj)"));
    // Настройка позволяет выбрать несколько файлов, по умолчанию используется только один файл QFileDialog :: ExistingFiles
    //fileDialog->setFileMode(QFileDialog::ExistingFiles);
    // Установить режим просмотра
    fileDialog->setViewMode(QFileDialog::Detail);
    // выводим путь ко всем выбранным файлам
    QStringList fileNames;
    if(fileDialog->exec())
    {
       fileNames = fileDialog->selectedFiles();
    }

    if (fileNames.size() > 0) {
        QString fileName = fileNames.at(0);
        qDebug() << fileName;
        QByteArray ba = fileName.toLocal8Bit();
        char *input = ba.data();
        s21_parse_file(input, &ui->OGLwidget->rawObjData);
        ui->OGLwidget->initBuffers();
    }

//    for(auto tmp:fileNames)
//    qDebug()<<tmp;

}

MainWindow::~MainWindow()
{
    delete ui;
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

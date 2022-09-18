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

    ui->xMove->setRange(0, 100);
    ui->xMove->setSingleStep(1);

    ui->yMove->setRange(0, 100);
    ui->yMove->setSingleStep(1);

    ui->zMove->setRange(0, 100);
    ui->zMove->setSingleStep(1);

    ui->zoomSlider->setRange(1, 300);
    ui->zMove->setSingleStep(1);

    // slider rotate val
    // x
    connect(ui->xSlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setXRotation);
    connect(ui->OGLwidget, &GLWidget::xRotationChanged, ui->xSlider, &QSlider::setValue);
    connect(ui->xText, SIGNAL(editingFinished()), (this), SLOT(xTextEdit()));
    // y
    connect(ui->ySlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setYRotation);
    connect(ui->OGLwidget, &GLWidget::yRotationChanged, ui->ySlider, &QSlider::setValue);
    connect(ui->yText, SIGNAL(editingFinished()), (this), SLOT(yTextEdit()));
    // z
    connect(ui->zSlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setZRotation);
    connect(ui->OGLwidget, &GLWidget::zRotationChanged, ui->zSlider, &QSlider::setValue);
    connect(ui->zText, SIGNAL(editingFinished()), (this), SLOT(zTextEdit()));



    // slider move val
    // x
    connect(ui->xMove, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setXMove);
    connect(ui->xMText, SIGNAL(editingFinished()), (this), SLOT(xMoveTextEdit()));

    connect(ui->yMove, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setYMove);
    connect(ui->yMText, SIGNAL(editingFinished()), (this), SLOT(yMoveTextEdit()));

    connect(ui->zMove, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setZMove);
    connect(ui->zMText, SIGNAL(editingFinished()), (this), SLOT(zMoveTextEdit()));


    // zoom slider
    connect(ui->zoomSlider, &QSlider::valueChanged, ui->OGLwidget, &GLWidget::setZoom);
    connect(ui->zoomText, SIGNAL(editingFinished()), (this), SLOT(zoomTextEdit()));


    // slider value in to text line
    connect(ui->xSlider, &QSlider::valueChanged, (this), &MainWindow::xSliderValueChanged);
    connect(ui->ySlider, &QSlider::valueChanged, (this), &MainWindow::ySliderValueChanged);
    connect(ui->zSlider, &QSlider::valueChanged, (this), &MainWindow::zSliderValueChanged);

    connect(ui->xMove, &QSlider::valueChanged, (this), &MainWindow::xMoveSliderValueChanged);
    connect(ui->yMove, &QSlider::valueChanged, (this), &MainWindow::yMoveSliderValueChanged);
    connect(ui->zMove, &QSlider::valueChanged, (this), &MainWindow::zMoveSliderValueChanged);

    connect(ui->zoomSlider, &QSlider::valueChanged, (this), &MainWindow::zoomSliderValueChanged);

    // reset all val
    connect(ui->resetButton, SIGNAL(released()), (this), SLOT(resetValue()));

    // screenshot
    connect(ui->btn_screen, SIGNAL(released()), (this), SLOT(createScreenshot()));


    // dots view
    connect(ui->disableView, &QRadioButton::pressed, (this), &MainWindow::DisableView);
    connect(ui->circleView, &QRadioButton::pressed, (this), &MainWindow::CircleView);
    connect(ui->squareView, &QRadioButton::pressed, (this), &MainWindow::SquareView);

    ui->xSlider->setValue(360 * 8);
    ui->ySlider->setValue(360 * 8);
    ui->zSlider->setValue(360 * 8);
    ui->zoomSlider->setValue(30);
    ui->xMove->setValue(50);
    ui->yMove->setValue(50);
    ui->zMove->setValue(50);
    ui->xText->setText(QString::number(0));
    ui->yText->setText(QString::number(0));
    ui->zText->setText(QString::number(0));
    ui->disableView->setChecked(true);
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
           if (strstr(input, ".obj") != NULL) { // Типо проверка на файл .obj
               s21_parse_file(input, &ui->OGLwidget->rawObjData);
           }
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

void MainWindow::DisableView()
{
    ui->OGLwidget->pointMode = 0;
    ui->OGLwidget->update();
}

void MainWindow::CircleView()
{
    ui->OGLwidget->pointMode = 1;
    ui->OGLwidget->update();
}

void MainWindow::SquareView()
{
    ui->OGLwidget->pointMode = 2;
    ui->OGLwidget->update();
}

void MainWindow::resetValue()
{
    ui->xSlider->setValue(360 * 8);
    ui->ySlider->setValue(360 * 8);
    ui->zSlider->setValue(360 * 8);
    ui->disableView->setChecked(true);
    ui->OGLwidget->initSettings();
    ui->xMove->setValue(50);
    ui->yMove->setValue(50);
    ui->zMove->setValue(50);
    ui->zoomSlider->setValue(30);
    ui->OGLwidget->update();
}

void MainWindow::xMoveSliderValueChanged(int value) {
    ui->xMText->setText(QString::number(value - 50));
}

void MainWindow::yMoveSliderValueChanged(int value) {
    ui->yMText->setText(QString::number(value - 50));
}

void MainWindow::zMoveSliderValueChanged(int value) {
    ui->zMText->setText(QString::number(value - 50));
}

void MainWindow::xSliderValueChanged(int value)
{
    ui->xText->setText(QString::number(-180 + value / 16));
}

void MainWindow::ySliderValueChanged(int value)
{
    ui->yText->setText(QString::number(-180 + value / 16));
}

void MainWindow::zSliderValueChanged(int value)
{
    ui->zText->setText(QString::number(-180 + value / 16));
}

void MainWindow::zoomSliderValueChanged(int value) {
    ui->zoomText->setText(QString::number(value));
}

void MainWindow::xMoveTextEdit() {
    int val = ui->xMText->text().toInt();
    val += 50;
//    val = valNormalize(val);
//    ui->OGLwidget->setXMove(val);
    ui->xMove->setValue(val);
}

void MainWindow::yMoveTextEdit() {
    int val = ui->yMText->text().toInt();
    val += 50;
//    val = valNormalize(val);
//    ui->OGLwidget->setYMove(val);
    ui->yMove->setValue(val);
}

void MainWindow::zMoveTextEdit() {
    int val = ui->zMText->text().toInt();
    val += 50;
//    val = valNormalize(val);
//    ui->OGLwidget->setZMove(val);
    ui->zMove->setValue(val);
}

void MainWindow::zoomTextEdit() {
    int val = ui->zoomText->text().toInt();
    ui->zoomSlider->setValue(val);
}

void MainWindow::createScreenshot() {
    ui->OGLwidget->grab().save("../../../../SCREEEEEN1.bmp");
    QMovie
}

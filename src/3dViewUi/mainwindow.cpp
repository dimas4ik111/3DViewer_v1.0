#include "mainwindow.h"

#include <unistd.h>

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

#include "../gif/gif.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  sliderSetUp();
  connectSetUp();
  defaultSettings();
  ui->OGLwidget->update();
}

MainWindow::~MainWindow() {
  saveSettings();
  delete ui;
}

void MainWindow::sliderSetUp() {
  ui->xRotate->setRange(0, 360 * 16);
  ui->xRotate->setSingleStep(16);
  ui->xRotate->setPageStep(15 * 16);
  ui->xRotate->setTickInterval(15 * 16);

  ui->yRotate->setRange(0, 360 * 16);
  ui->yRotate->setSingleStep(16);
  ui->yRotate->setPageStep(15 * 16);
  ui->yRotate->setTickInterval(15 * 16);

  ui->zRotate->setRange(0, 360 * 16);
  ui->zRotate->setSingleStep(16);
  ui->zRotate->setPageStep(15 * 16);
  ui->zRotate->setTickInterval(15 * 16);

  ui->xMove->setRange(0, 100);
  ui->xMove->setSingleStep(1);

  ui->yMove->setRange(0, 100);
  ui->yMove->setSingleStep(1);

  ui->zMove->setRange(0, 100);
  ui->zMove->setSingleStep(1);

  ui->zoomSlider->setRange(1, 300);
  ui->zMove->setSingleStep(1);

  ui->vertexSizeSlider->setRange(1, 25);
  ui->vertexSizeSlider->setSingleStep(1);

  ui->linesSizeSlider->setRange(1, 20);
  ui->linesSizeSlider->setSingleStep(1);
}

void MainWindow::connectSetUp() {
  // Соединяем сигналы и слоты
  // для слайдеров движения
  // по X
  connect(ui->xMove, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setXMove);
  connect(ui->xMText, SIGNAL(editingFinished()), (this), SLOT(xMoveTextEdit()));
  // По Y
  connect(ui->yMove, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setYMove);
  connect(ui->yMText, SIGNAL(editingFinished()), (this), SLOT(yMoveTextEdit()));
  // По Z
  connect(ui->zMove, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setZMove);
  connect(ui->zMText, SIGNAL(editingFinished()), (this), SLOT(zMoveTextEdit()));
  // для слайдеров вращения
  // по X
  connect(ui->xRotate, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setXRotation);
  connect(ui->OGLwidget, &GLWidget::xRotationChanged, ui->xRotate,
          &QSlider::setValue);
  connect(ui->xRotateText, SIGNAL(editingFinished()), (this),
          SLOT(xRotateTextEdit()));
  // По Y
  connect(ui->yRotate, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setYRotation);
  connect(ui->OGLwidget, &GLWidget::yRotationChanged, ui->yRotate,
          &QSlider::setValue);
  connect(ui->yRotateText, SIGNAL(editingFinished()), (this), SLOT(yRotateTextEdit()));
  // По Z
  connect(ui->zRotate, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setZRotation);
  connect(ui->OGLwidget, &GLWidget::zRotationChanged, ui->zRotate,
          &QSlider::setValue);
  connect(ui->zRotateText, SIGNAL(editingFinished()), (this), SLOT(zRotateTextEdit()));
  // Режим вращения
  connect(ui->RotateAxesRadio, &QRadioButton::pressed, (this),
          &MainWindow::EnableRotateAxesMode);
  connect(ui->RotateModelRadio, &QRadioButton::pressed, (this),
          &MainWindow::EnableRotateModelMode);
  // Для слайдера масштабированя
  connect(ui->zoomSlider, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setZoom);
  connect(ui->zoomText, SIGNAL(editingFinished()), (this),
          SLOT(zoomTextEdit()));
  // Для выбора типа проекции
  connect(ui->projectionParallel, &QRadioButton::pressed, (this),
          &MainWindow::projectionParallel);
  connect(ui->projectionCentral, &QRadioButton::pressed, (this),
          &MainWindow::projectionCentral);
  // Для настройки ребер
  // Внешний вид
  connect(ui->solidEdges, &QRadioButton::pressed, (this),
          &MainWindow::linesTypeSolid);
  connect(ui->dashedEdges, &QRadioButton::pressed, (this),
          &MainWindow::linesTypeDashed);
  // Толщина
  connect(ui->linesSizeSlider, &QSlider::valueChanged, (this),
          &MainWindow::linesSizeSliderChanged);
  // Цвет
  connect(ui->colorEdges, SIGNAL(released()), (this),
          SLOT(edgesColorChanged()));
  // Для настройки вершин
  // Размер
  connect(ui->vertexSizeSlider, &QSlider::valueChanged, (this),
          &MainWindow::vertexSize);
  // Внешний вид
  connect(ui->disableView, &QRadioButton::pressed, (this),
          &MainWindow::DisableView);
  connect(ui->circleView, &QRadioButton::pressed, (this),
          &MainWindow::CircleView);
  connect(ui->squareView, &QRadioButton::pressed, (this),
          &MainWindow::SquareView);
  // Цвет
  connect(ui->colorVertex, SIGNAL(released()), (this),
          SLOT(vertexColorChanged()));
  // Цвет Фона
  connect(ui->widgetBackGroundColor, SIGNAL(released()), (this),
          SLOT(backgroundColorChanged()));
  // CPU/GPU
  connect(ui->CalcModeGPURadio, &QRadioButton::pressed, (this),
          &MainWindow::EnableGPUMode);
  connect(ui->CalcModeCPURadio, &QRadioButton::pressed, (this),
          &MainWindow::EnableCPUMode);
  // Сбросить настройки
  connect(ui->resetButton, SIGNAL(released()), (this), SLOT(resetValue()));
  // Кнопка открытия obj-файла для парсинга
  connect(ui->openObjButton, SIGNAL(clicked()), this, SLOT(handleOpenFile()));
  // Обновление текстовых полей вращения
  connect(ui->xRotate, &QSlider::valueChanged, (this),
          &MainWindow::xRotateValueChanged);
  connect(ui->yRotate, &QSlider::valueChanged, (this),
          &MainWindow::yRotateValueChanged);
  connect(ui->zRotate, &QSlider::valueChanged, (this),
          &MainWindow::zRotateValueChanged);
  // Обновление текстовых полей движения
  connect(ui->xMove, &QSlider::valueChanged, (this),
          &MainWindow::xMoveSliderValueChanged);
  connect(ui->yMove, &QSlider::valueChanged, (this),
          &MainWindow::yMoveSliderValueChanged);
  connect(ui->zMove, &QSlider::valueChanged, (this),
          &MainWindow::zMoveSliderValueChanged);
  // Обновление текстовых полей масштабирования
  connect(ui->zoomSlider, &QSlider::valueChanged, (this),
          &MainWindow::zoomSliderValueChanged);
  // Создать BMP
  connect(ui->btn_screen_bmp, SIGNAL(released()), (this),
          SLOT(createScreenshot()));
  // Создать JPG
  connect(ui->btn_screen_jpg, SIGNAL(released()), (this),
          SLOT(createScreenshot()));
  // Создать GIF
  connect(ui->btn_screen_gif, SIGNAL(released()), (this),
          SLOT(createScreenshot()));
}

void MainWindow::defSliders() {
  ui->xRotate->setValue(360 * 8);
  ui->yRotate->setValue(360 * 8);
  ui->zRotate->setValue(360 * 8);
  ui->zoomSlider->setValue(30);
  ui->xMove->setValue(50);
  ui->yMove->setValue(50);
  ui->zMove->setValue(50);
  ui->xRotateText->setText(QString::number(0));
  ui->yRotateText->setText(QString::number(0));
  ui->zRotateText->setText(QString::number(0));
}

void MainWindow::defaultSettings() {
  defSliders();
  ui->disableView->setChecked(true);
  ui->CalcModeGPURadio->setChecked(true);
  ui->RotateAxesRadio->setChecked(true);
  ui->solidEdges->setChecked(true);
  ui->projectionCentral->setChecked(true);
  ui->linesSizeSlider->setValue(15);

  ui->linesSizeSlider->setValue(1);
  ui->OGLwidget->initSettings();
  ui->vertexSizeSlider->setValue(1);

  if (QFile::exists(pathProject + "settings.conf")) {
    QSettings settings(pathProject + "settings.conf", QSettings::IniFormat);
    settings.beginGroup("LineSet");

    ui->linesSizeSlider->setValue(settings.value("value").toInt());

    if (settings.value("solid").toBool()) {
      ui->solidEdges->setChecked(true);
      ui->OGLwidget->lineMode = 0;
    } else if (settings.value("dashed").toBool()) {
      ui->dashedEdges->setChecked(true);
      ui->OGLwidget->lineMode = 1;
    }

    if (settings.value("color").toString().length() > 0) {
      ui->OGLwidget->lineColor = settings.value("color").toString();
      settings.endGroup();
    }

    settings.beginGroup("VertexSet");
    if (settings.value("disable").toBool()) {
      ui->disableView->setChecked(true);
      ui->OGLwidget->pointMode = 0;
    } else if (settings.value("circle").toBool()) {
      ui->circleView->setChecked(true);
      ui->OGLwidget->pointMode = 1;
    } else if (settings.value("square").toBool()) {
      ui->squareView->setChecked(true);
      ui->OGLwidget->pointMode = 2;
    }

    ui->OGLwidget->pointColor = settings.value("color").toString();

    ui->vertexSizeSlider->setValue(settings.value("size").toInt());

    settings.endGroup();

    settings.beginGroup("background");

    if (settings.value("color").toString().length() > 0) {
      ui->OGLwidget->backgroundColor = settings.value("color").toString();
      settings.endGroup();
    }

    settings.beginGroup("proection");
    if (settings.value("mode").toInt() == 0 &&
        settings.value("mode").toInt() != 1) {
      ui->OGLwidget->projectionMode = 0;
    } else if (settings.value("mode").toInt() == 1 &&
               settings.value("mode").toString().length() > 0) {
      ui->OGLwidget->projectionMode = 1;
      ui->projectionParallel->setChecked(true);
    }
    settings.endGroup();
  }

  updateUiColors();
}

void MainWindow::saveSettings() {
  QSettings settings(pathProject + "settings.conf", QSettings::IniFormat);
  settings.beginGroup("LineSet");
  settings.setValue("value", ui->linesSizeSlider->value());
  settings.setValue("solid", ui->solidEdges->isChecked());
  settings.setValue("dashed", ui->dashedEdges->isChecked());
  settings.setValue("color", ui->OGLwidget->lineColor);
  settings.endGroup();
  settings.beginGroup("VertexSet");
  settings.setValue("disable", ui->disableView->isChecked());
  settings.setValue("circle", ui->circleView->isChecked());
  settings.setValue("square", ui->squareView->isChecked());
  settings.setValue("color", ui->OGLwidget->pointColor);
  settings.setValue("size", ui->vertexSizeSlider->value());
  settings.endGroup();
  settings.beginGroup("background");
  settings.setValue("color", ui->OGLwidget->backgroundColor);
  settings.endGroup();
  settings.beginGroup("proection");
  settings.setValue("mode", ui->OGLwidget->projectionMode);
  settings.endGroup();
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

void MainWindow::xRotateTextEdit() {
  int val = ui->xRotateText->text().toInt();
  val += 180;
  val = valNormalize(val);
  ui->OGLwidget->setXRotation(val * 16);
}

void MainWindow::yRotateTextEdit() {
  int val = ui->yRotateText->text().toInt();
  val += 180;
  val = valNormalize(val);
  ui->OGLwidget->setYRotation(val * 16);
}

void MainWindow::zRotateTextEdit() {
  int val = ui->zRotateText->text().toInt();
  val += 180;
  val = valNormalize(val);
  ui->OGLwidget->setZRotation(val * 16);
}

void MainWindow::DisableView() {
  ui->OGLwidget->pointMode = 0;
  ui->OGLwidget->update();
}

void MainWindow::CircleView() {
  ui->OGLwidget->pointMode = 1;
  ui->OGLwidget->update();
}

void MainWindow::SquareView() {
  ui->OGLwidget->pointMode = 2;
  ui->OGLwidget->update();
}

void MainWindow::EnableGPUMode() {
  ui->OGLwidget->calcMode = 0;
  ui->OGLwidget->update();
}

void MainWindow::EnableCPUMode() {
  ui->OGLwidget->calcMode = 1;
  ui->OGLwidget->update();
}

void MainWindow::EnableRotateAxesMode() {
  ui->OGLwidget->rotateMode = 0;
  ui->OGLwidget->update();
}

void MainWindow::EnableRotateModelMode() {
  ui->OGLwidget->rotateMode = 1;
  ui->OGLwidget->update();
}

void MainWindow::resetValue() {
  defaultSettings();
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

void MainWindow::linesSizeSliderChanged(int value) {
  ui->OGLwidget->lineSize = value;
  ui->OGLwidget->update();
}

void MainWindow::vertexSize(int value) {
  ui->OGLwidget->pointSize = value;
  ui->OGLwidget->update();
}

void MainWindow::linesTypeSolid() {
  ui->OGLwidget->lineMode = 0;
  ui->OGLwidget->update();
}

void MainWindow::linesTypeDashed() {
  ui->OGLwidget->lineMode = 1;
  ui->OGLwidget->update();
}

void MainWindow::projectionParallel() {
  ui->OGLwidget->projectionMode = 1;
  ui->OGLwidget->update();
}

void MainWindow::projectionCentral() {
  ui->OGLwidget->projectionMode = 0;
  ui->OGLwidget->update();
}

void MainWindow::xRotateValueChanged(int value) {
  ui->xRotateText->setText(QString::number(-180 + value / 16));
}

void MainWindow::yRotateValueChanged(int value) {
  ui->yRotateText->setText(QString::number(-180 + value / 16));
}

void MainWindow::zRotateValueChanged(int value) {
  ui->zRotateText->setText(QString::number(-180 + value / 16));
}

void MainWindow::zoomSliderValueChanged(int value) {
  ui->zoomText->setText(QString::number(value));
}

void MainWindow::xMoveTextEdit() {
  int val = ui->xMText->text().toInt();
  val += 50;
  ui->xMove->setValue(val);
}

void MainWindow::yMoveTextEdit() {
  int val = ui->yMText->text().toInt();
  val += 50;
  ui->yMove->setValue(val);
}

void MainWindow::zMoveTextEdit() {
  int val = ui->zMText->text().toInt();
  val += 50;
  ui->zMove->setValue(val);
}

void MainWindow::zoomTextEdit() {
  int val = ui->zoomText->text().toInt();
  ui->zoomSlider->setValue(val);
}

void MainWindow::edgesColorChanged() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
  if (color.isValid()) {
    ui->OGLwidget->lineColor = color;
    updateUiColors();
  }
}

void MainWindow::vertexColorChanged() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
  if (color.isValid()) {
    ui->OGLwidget->pointColor = color;
    updateUiColors();
  }
}

void MainWindow::backgroundColorChanged() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
  if (color.isValid()) {
    ui->OGLwidget->backgroundColor = color;
    updateUiColors();
  }
}

void MainWindow::updateUiColors() {
  ui->boxBackGroundColor->setAutoFillBackground(true);
  ui->boxBackGroundColor->setStyleSheet(
      QString("border-style: solid; border-width: 1px; border-color: black; "
              "padding-top: 3px; background-color: rgb(%1, %2, %3);")
          .arg(ui->OGLwidget->backgroundColor.red())
          .arg(ui->OGLwidget->backgroundColor.green())
          .arg(ui->OGLwidget->backgroundColor.blue()));
  ui->boxEdgesColor->setAutoFillBackground(true);
  ui->boxEdgesColor->setStyleSheet(
      QString("border-style: solid; border-width: 1px; border-color: black; "
              "padding-top: 3px; background-color: rgb(%1, %2, %3);")
          .arg(ui->OGLwidget->lineColor.red())
          .arg(ui->OGLwidget->lineColor.green())
          .arg(ui->OGLwidget->lineColor.blue()));
  ui->boxVertexColor->setAutoFillBackground(true);
  ui->boxVertexColor->setStyleSheet(
      QString("border-style: solid; border-width: 1px; border-color: black; "
              "padding-top: 3px; background-color: rgb(%1, %2, %3);")
          .arg(ui->OGLwidget->pointColor.red())
          .arg(ui->OGLwidget->pointColor.green())
          .arg(ui->OGLwidget->pointColor.blue()));
  ui->OGLwidget->update();
}

void MainWindow::handleOpenFile() {
  // Определяем класс диалогового окна выбора файла
  QFileDialog *fileDialog = new QFileDialog(this);
  // Определяем заголовок окна
  fileDialog->setWindowTitle(tr("Выберите .obj-файл"));
  // Устанавливаем путь к файлу по умолчанию
  // fileDialog->setDirectory(QDir::homePath());
  // Устанавливаем фильтр файлов
  fileDialog->setNameFilter(tr("(*.obj)"));
  // Устанавливаем режим просмотра
  fileDialog->setViewMode(QFileDialog::Detail);
  // Режим: выбор только существующего файла
  fileDialog->setFileMode(QFileDialog::ExistingFile);
  // Вызываем диалог
  QStringList fileNames;
  if (fileDialog->exec()) {
    fileNames = fileDialog->selectedFiles();
    // В случае успеха и если что-то выбрано
    if (fileNames.size() > 0) {
      QString fileName = fileNames.at(0);
      QByteArray ba = fileName.toLocal8Bit();
      char *input = ba.data();
      // Парсим файл
      s21_destroy_obj_data(&ui->OGLwidget->rawObjData);
      s21_destroy_obj_data(&ui->OGLwidget->rawObjDataCPU);
      s21_parser_result code =
          s21_parse_file(input, &ui->OGLwidget->rawObjData, S21_TRUE);
      if (code == S21_PARSER_OK) {
        // Пишем путь до файла в статусбар приложения
        ui->statusbar->showMessage("Выбран файл: " + fileName);
        // Инициализируем буфферы OpenGL распарсенными данным
        defSliders();
        ui->OGLwidget->initBuffers();
        ui->numberOfEdges->setText(
            QString::number(ui->OGLwidget->numberOfEdges));
        ui->numberOfVerticies->setText(
            QString::number(ui->OGLwidget->numberOfVerticies));
      } else {
        GLWidget::handleErrorByCode(code);
      }
    }
  }
}

void MainWindow::createScreenshot() {
  QPushButton *btn = (QPushButton *)sender();
  QString butVal = btn->text();

  QDir *pathDir = new QDir();
  pathDir->mkdir(pathProject);
  pathDir->mkdir(pathProject + "/screenshots");

  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");

  if (QString::compare(butVal, "bmp", Qt::CaseInsensitive) == 0) {
    ui->btn_screen_bmp->setEnabled(false);
    ui->OGLwidget->grab().save(pathProject + "screenshots/" + currentDateTime +
                               ".bmp");
    ui->btn_screen_bmp->setEnabled(true);
  } else if (QString::compare(butVal, "jpg", Qt::CaseInsensitive) == 0) {
    ui->btn_screen_jpg->setEnabled(false);
    ui->OGLwidget->grab().save(pathProject + "screenshots/" + currentDateTime +
                               ".jpg");
    ui->btn_screen_jpg->setEnabled(true);
  } else if (QString::compare(butVal, "gif", Qt::CaseInsensitive) == 0) {
    ui->btn_screen_gif->setEnabled(false);
    pathDir->mkdir(pathProject + "/screenshots/gif_obj/");
    startTime = 0, tmpTime = 1000 / GifFps;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(oneGif()));
    timer->start(1000 / GifFps);
  }
}

void MainWindow::oneGif() {
  if (startTime == tmpTime) {
    ui->OGLwidget->grab()
        .scaled(640, 480, Qt::IgnoreAspectRatio)
        .save(pathProject + "/screenshots/gif_obj/" + QString::number(counter) +
              ".bmp");
    counter++;
    tmpTime += 1000 / GifFps;
  }
  if (startTime == 1000 * GifLength) {
    createGif();
    timer->stop();
    counter = 1;
  }
  startTime += 1000 / GifFps;
}

void MainWindow::createGif() {
  QDir pathFile;
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  QString gif_name = pathProject + "/screenshots/" + currentDateTime + ".gif";
  QByteArray ga = gif_name.toLocal8Bit();
  GifWriter writer = {};
  int err = 0;

  if (GifBegin(&writer, ga.data(), 640, 480, 10, 8, false)) {
    for (int i = 1; i <= 50; i++) {
      if (err == 1) {
        break;
      }
      QImage img(pathProject + "/screenshots/gif_obj/" + QString::number(i) +
                 ".bmp");
      if (!img.isNull()) {
        if (GifWriteFrame(&writer,
                          img.convertToFormat(QImage::Format_Indexed8)
                              .convertToFormat(QImage::Format_RGBA8888)
                              .constBits(),
                          640, 480, 10, 8, false)) {
        } else {
          QMessageBox::critical(0, "Error", "Gif file can not be create!d");
          err = 1;
        }
      } else {
        QMessageBox::critical(0, "Error", "Gif file can not be created!");
        err = 1;
      }
    }
    if (err == 0) {
      GifEnd(&writer);
    }
  } else {
    err = 1;
    QMessageBox::critical(0, "Error", "Gif file can not be created!");
  }

  if (err == 1) {
    if (QFile::exists(gif_name)) {
      QFile::remove(gif_name);
    }
  }

  pathFile.setPath(pathProject + "/screenshots/gif_obj/");
  pathFile.removeRecursively();
  ui->btn_screen_gif->setEnabled(true);
}

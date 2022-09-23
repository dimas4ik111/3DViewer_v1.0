#include "mainwindow.h"

#include "../gif/gif.h"
#include <unistd.h>

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  sliderSetUp();

  connect(ui->openObjButton, SIGNAL(clicked()), this, SLOT(handleOpenFile()));

  // slider rotate val
  // x
  connect(ui->xSlider, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setXRotation);
  connect(ui->OGLwidget, &GLWidget::xRotationChanged, ui->xSlider,
          &QSlider::setValue);
  connect(ui->xText, SIGNAL(editingFinished()), (this), SLOT(xTextEdit()));
  // y
  connect(ui->ySlider, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setYRotation);
  connect(ui->OGLwidget, &GLWidget::yRotationChanged, ui->ySlider,
          &QSlider::setValue);
  connect(ui->yText, SIGNAL(editingFinished()), (this), SLOT(yTextEdit()));
  // z
  connect(ui->zSlider, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setZRotation);
  connect(ui->OGLwidget, &GLWidget::zRotationChanged, ui->zSlider,
          &QSlider::setValue);
  connect(ui->zText, SIGNAL(editingFinished()), (this), SLOT(zTextEdit()));

  // slider line size
  connect(ui->linesSizeSlider, &QSlider::valueChanged, (this),
          &MainWindow::linesSizeSliderChanged);

  // slider move val
  // x
  connect(ui->xMove, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setXMove);
  connect(ui->xMText, SIGNAL(editingFinished()), (this), SLOT(xMoveTextEdit()));

  connect(ui->yMove, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setYMove);
  connect(ui->yMText, SIGNAL(editingFinished()), (this), SLOT(yMoveTextEdit()));

  connect(ui->zMove, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setZMove);
  connect(ui->zMText, SIGNAL(editingFinished()), (this), SLOT(zMoveTextEdit()));

  // zoom slider
  connect(ui->zoomSlider, &QSlider::valueChanged, ui->OGLwidget,
          &GLWidget::setZoom);
  connect(ui->zoomText, SIGNAL(editingFinished()), (this),
          SLOT(zoomTextEdit()));

  // slider value in to text line
  connect(ui->xSlider, &QSlider::valueChanged, (this),
          &MainWindow::xSliderValueChanged);
  connect(ui->ySlider, &QSlider::valueChanged, (this),
          &MainWindow::ySliderValueChanged);
  connect(ui->zSlider, &QSlider::valueChanged, (this),
          &MainWindow::zSliderValueChanged);

  connect(ui->xMove, &QSlider::valueChanged, (this),
          &MainWindow::xMoveSliderValueChanged);
  connect(ui->yMove, &QSlider::valueChanged, (this),
          &MainWindow::yMoveSliderValueChanged);
  connect(ui->zMove, &QSlider::valueChanged, (this),
          &MainWindow::zMoveSliderValueChanged);

  connect(ui->zoomSlider, &QSlider::valueChanged, (this),
          &MainWindow::zoomSliderValueChanged);

  // reset all val
  connect(ui->resetButton, SIGNAL(released()), (this), SLOT(resetValue()));

  // screenshot
  connect(ui->btn_screen_bmp, SIGNAL(released()), (this),
          SLOT(createScreenshot()));
  connect(ui->btn_screen_jpg, SIGNAL(released()), (this),
          SLOT(createScreenshot()));
  connect(ui->btn_screen_gif, SIGNAL(released()), (this),
          SLOT(createScreenshot()));

  // vertex size
  connect(ui->vertexSizeSlider, &QSlider::valueChanged, (this),
          &MainWindow::vertexSize);

  // vertex view
  connect(ui->disableView, &QRadioButton::pressed, (this),
          &MainWindow::DisableView);
  connect(ui->circleView, &QRadioButton::pressed, (this),
          &MainWindow::CircleView);
  connect(ui->squareView, &QRadioButton::pressed, (this),
          &MainWindow::SquareView);

  // lines view
  connect(ui->solidEdges, &QRadioButton::pressed, (this),
          &MainWindow::linesTypeSolid);
  connect(ui->dashedEdges, &QRadioButton::pressed, (this),
          &MainWindow::linesTypeDashed);

  // CPU / GPU
  connect(ui->CalcModeGPURadio, &QRadioButton::pressed, (this),
          &MainWindow::EnableGPUMode);
  connect(ui->CalcModeCPURadio, &QRadioButton::pressed, (this),
          &MainWindow::EnableCPUMode);

  // Rotate
  connect(ui->RotateAxesRadio, &QRadioButton::pressed, (this),
          &MainWindow::EnableRotateAxesMode);
  connect(ui->RotateModelRadio, &QRadioButton::pressed, (this),
          &MainWindow::EnableRotateModelMode);

  // projection select
  connect(ui->projectionParallel, &QRadioButton::pressed, (this),
          &MainWindow::projectionParallel);
  connect(ui->projectionCentral, &QRadioButton::pressed, (this),
          &MainWindow::projectionCentral);

  // colors
  connect(ui->colorEdges, SIGNAL(released()), (this),
          SLOT(edgesColorChanged()));
  connect(ui->colorVertex, SIGNAL(released()), (this),
          SLOT(vertexColorChanged()));
  connect(ui->widgetBackGroundColor, SIGNAL(released()), (this),
          SLOT(backgroundColorChanged()));

  defaultSettings();
  ui->OGLwidget->update();
}

void MainWindow::defSliders() {
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

MainWindow::~MainWindow() {
  saveSettings();
  delete ui;
  //    settings.setValue( "y", ui->OGLwidget->y());
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
      qDebug() << "Выбран файл: " << fileName;
      QByteArray ba = fileName.toLocal8Bit();
      char *input = ba.data();
      // Парсим файл
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

int valNormalize(int val) {
  while (val > 180) {
    val -= 360;
  }
  while (val < -180) {
    val += 360;
  }
  return val;
}

void MainWindow::xTextEdit() {
  int val = ui->xText->text().toInt();
  val += 180;
  val = valNormalize(val);
  ui->OGLwidget->setXRotation(val * 16);
}

void MainWindow::yTextEdit() {
  int val = ui->yText->text().toInt();
  val += 180;
  val = valNormalize(val);
  ui->OGLwidget->setYRotation(val * 16);
}

void MainWindow::zTextEdit() {
  int val = ui->zText->text().toInt();
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

void MainWindow::xSliderValueChanged(int value) {
  ui->xText->setText(QString::number(-180 + value / 16));
}

void MainWindow::ySliderValueChanged(int value) {
  ui->yText->setText(QString::number(-180 + value / 16));
}

void MainWindow::zSliderValueChanged(int value) {
  ui->zText->setText(QString::number(-180 + value / 16));
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
    ui->OGLwidget->grab().save(pathProject + "screenshots/" + currentDateTime + ".bmp");
    ui->btn_screen_bmp->setEnabled(true);
  } else if (QString::compare(butVal, "jpg", Qt::CaseInsensitive) == 0) {
    ui->btn_screen_jpg->setEnabled(false);
    ui->OGLwidget->grab().save(pathProject + "screenshots/" + currentDateTime + ".jpg");
    ui->btn_screen_jpg->setEnabled(true);
  } else if (QString::compare(butVal, "gif", Qt::CaseInsensitive) == 0) {
    ui->btn_screen_gif->setEnabled(false);
    pathDir->mkdir(pathProject + "/screenshots/gif_obj/");
    QSize pic_size(640, 480);
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
          QMessageBox::critical(0, "Ошибка", "Что то пошло не так!");
          err = 1;
        }
      } else {
        QMessageBox::critical(0, "Ошибка",  "Что то пошло не так!");
        err = 1;
      }
    }
    if (err == 0) {
      GifEnd(&writer);
    }
  } else {
    err = 1;
    QMessageBox::critical(0, "Ошибка",  "Что то пошло не так!");
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

void MainWindow::sliderSetUp() {
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

  ui->vertexSizeSlider->setRange(1, 25);
  ui->vertexSizeSlider->setSingleStep(1);

  ui->linesSizeSlider->setRange(1, 20);
  ui->linesSizeSlider->setSingleStep(1);
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

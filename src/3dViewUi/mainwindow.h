#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>
#include <QDir>
#include <QImage>
#include <QMainWindow>
#include <QPainter>
#include <QSettings>
#include <QTimer>
#include <QVector>

#include "glwidget.h"

extern "C" {
#include "../backend/backend.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void xTextEdit();
  void yTextEdit();
  void zTextEdit();

  void xMoveTextEdit();
  void yMoveTextEdit();
  void zMoveTextEdit();

  void zoomTextEdit();

  void DisableView();
  void CircleView();
  void SquareView();

  void EnableGPUMode();
  void EnableCPUMode();

  void EnableRotateAxesMode();
  void EnableRotateModelMode();

  void xSliderValueChanged(int value);
  void ySliderValueChanged(int value);
  void zSliderValueChanged(int value);

  void xMoveSliderValueChanged(int value);
  void yMoveSliderValueChanged(int value);
  void zMoveSliderValueChanged(int value);

  void linesSizeSliderChanged(int value);

  void edgesColorChanged();
  void vertexColorChanged();
  void backgroundColorChanged();

  void vertexSize(int value);

  void linesTypeSolid();
  void linesTypeDashed();

  void projectionParallel();
  void projectionCentral();

  void zoomSliderValueChanged(int value);

  void handleOpenFile();

  void resetValue();

  void createScreenshot();

  void oneGif();

 private:
  const int GifFps = 10, GifLength = 5;
  Ui::MainWindow *ui;
  QTimer *timer;
  QString pathProject = QDir::homePath() + "/3dViewer1/";
  int startTime, tmpTime;
  int counter = 1;
  void sliderSetUp();
  void createGif();
  void defaultSettings();
  void defSliders();
  void saveSettings();
  void updateUiColors();
};
#endif  // MAINWINDOW_H

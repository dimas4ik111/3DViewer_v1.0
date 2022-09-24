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
  void xMoveTextEdit();
  void yMoveTextEdit();
  void zMoveTextEdit();
  void xRotateTextEdit();
  void yRotateTextEdit();
  void zRotateTextEdit();
  void zoomTextEdit();
  void linesTypeSolid();
  void linesTypeDashed();
  void linesSizeSliderChanged(int value);
  void DisableView();
  void CircleView();
  void SquareView();
  void EnableGPUMode();
  void EnableCPUMode();
  void EnableRotateAxesMode();
  void EnableRotateModelMode();
  void xRotateValueChanged(int value);
  void yRotateValueChanged(int value);
  void zRotateValueChanged(int value);
  void xMoveSliderValueChanged(int value);
  void yMoveSliderValueChanged(int value);
  void zMoveSliderValueChanged(int value);
  void edgesColorChanged();
  void vertexColorChanged();
  void backgroundColorChanged();
  void vertexSize(int value);
  void projectionParallel();
  void projectionCentral();
  void zoomSliderValueChanged(int value);
  void handleOpenFile();
  void resetValue();
  void createScreenshot();
  void oneGif();

 private:
  Ui::MainWindow *ui;
  const int GifFps = 10, GifLength = 5;
  QTimer *timer;
  QString pathProject = QDir::homePath() + "/3dViewer1/";
  int startTime, tmpTime;
  int counter = 1;
  void connectSetUp();
  void sliderSetUp();
  void createGif();
  void defaultSettings();
  void defSliders();
  void saveSettings();
  void updateUiColors();
};
#endif  // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"

extern "C" {
#include "../backend/backend.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void xTextEdit();
    void yTextEdit();
    void zTextEdit();

    void DisableView();
    void CircleView();
    void SquareView();

    void resetValue();
    void xSliderValueChanged(int value);
    void ySliderValueChanged(int value);
    void zSliderValueChanged(int value);
//    void on_xSlider_valueChanged(int value);
//    void on_ySlider_valueChanged(int value);
//    void on_zSlider_valueChanged(int value);
    void handleOpenFile();

private:
    Ui::MainWindow *ui;
    void sliderSetUp();
};
#endif // MAINWINDOW_H

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

    void xMoveTextEdit();
    void yMoveTextEdit();
    void zMoveTextEdit();

    void zoomTextEdit();

    void DisableView();
    void CircleView();
    void SquareView();

    void xSliderValueChanged(int value);
    void ySliderValueChanged(int value);
    void zSliderValueChanged(int value);

    void xMoveSliderValueChanged(int value);
    void yMoveSliderValueChanged(int value);
    void zMoveSliderValueChanged(int value);

    void zoomSliderValueChanged(int value);

    void handleOpenFile();

    void resetValue();

    void createScreenshot();

private:
    Ui::MainWindow *ui;
    void sliderSetUp();
};
#endif // MAINWINDOW_H

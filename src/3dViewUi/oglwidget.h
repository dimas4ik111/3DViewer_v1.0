#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QtOpenGLWidgets>
#include <QtWidgets>
#include <cmath>

class oglwidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    oglwidget(QWidget *parent = nullptr);
    ~oglwidget();
};

#endif // OGLWIDGET_H

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
    QOpenGLWidget *glwidget;
    QColor backGroundColor;

private:
    QOpenGLShaderProgram *model = nullptr;
    void draw();
    int faceAtPosition(const QPoint &pos);
    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QPoint lastPos;

protected:
    void initializeGL() override;
//    void resizeGL(int width, int height) override;
//    void paintGL() override;
//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseMoveEvent(QMouseEvent *event) override;
//    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // OGLWIDGET_H

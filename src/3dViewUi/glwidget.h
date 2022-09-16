#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QMouseEvent>

extern "C" {
    #include "../backend/backend.h"
}

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

    void testBuffers();
    void initBuffers();

    QColor backgroundColor;
    QColor lineColor;
    QColor pointColor;
    int orthoMode;

    int m_xRot = 0;
    int m_yRot = 0;
    int m_zRot = 0;

    int m_xMove = 0;

    s21_obj_data rawObjData;

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

public slots:
    void setXMove(int step);

    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void cleanup();

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

    void xMoveChanged(int step);

private:
    void initSettings();

    QPoint m_lastPos;

    int m_projectionMatrixLoc = 0;
    int m_cameraMatrixLoc = 0;
    int m_rotateMatrixLoc = 0;
    int m_moveMatrixLoc = 0;
    int m_scaleMatrixLoc = 0;
    int m_colorLoc = 0;

    QOpenGLShaderProgram *m_program = nullptr;
    QOpenGLBuffer vbo;
    QOpenGLBuffer ebo;
    QOpenGLVertexArrayObject vao;

    QMatrix4x4 projectionMatrix;
    QMatrix4x4 cameraMatrix;
    QMatrix4x4 rotateMatrix;
    QMatrix4x4 moveMatrix;
    QMatrix4x4 scaleMatrix;
};

#endif // GLWIDGET_H

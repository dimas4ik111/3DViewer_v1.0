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
    void initSettings();

    QColor backgroundColor;
    QColor lineColor;
    QColor pointColor;
    int orthoMode;
    int pointMode;
    int pointSize;
    int lineSize;
    int lineMode;

    int m_xRot = 2880;
    int m_yRot = 360 * 8;
    int m_zRot = 360 * 8;

    int m_xMove = 0;
    int m_yMove = 0;
    int m_zMove = 0;

    int zoomVal = 30;

    s21_obj_data rawObjData;

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

public slots:
    void setXMove(int step);
    void setYMove(int step);
    void setZMove(int step);

    void setZoom(int zoom);

    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

    void clearBuffers();
    void cleanup();

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:

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

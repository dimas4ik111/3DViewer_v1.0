#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

    void initBuffers();

    QColor backgroundColor;
    QColor lineColor;
    QColor pointColor;
    int orthoMode;
    QOpenGLShaderProgram *m_program = nullptr;

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    void initSettings();

    int m_projectionMatrixLoc = 0;
    int m_cameraMatrixLoc = 0;
    int m_rotateMatrixLoc = 0;
    int m_moveMatrixLoc = 0;
    int m_scaleMatrixLoc = 0;
    int m_colorLoc = 0;

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

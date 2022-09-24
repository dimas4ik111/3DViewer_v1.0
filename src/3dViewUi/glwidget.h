#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>

extern "C" {
#include "../backend/backend.h"
}

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  GLWidget(QWidget *parent = nullptr);
  ~GLWidget();
  void initBuffers();
  void initSettings();
  static void handleErrorByCode(s21_parser_result code);

  QColor backgroundColor;
  QColor lineColor;
  QColor pointColor;
  int projectionMode;
  int pointMode;
  int pointSize;
  int lineSize;
  int lineMode;
  int calcMode;
  int rotateMode;
  s21_obj_data rawObjData;
  s21_obj_data rawObjDataCPU;

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
  void setXRotation(int angle);
  void setYRotation(int angle);
  void setZRotation(int angle);
  void setZoom(int zoom);

 signals:
  void xRotationChanged(int angle);
  void yRotationChanged(int angle);
  void zRotationChanged(int angle);

 private:
  QPoint m_lastPos;
  int m_coeffMatrixLoc = 0;
  int m_colorLoc = 0;
  QOpenGLShaderProgram *m_program = nullptr;
  QOpenGLBuffer vbo;
  QOpenGLBuffer vboCPU;
  QOpenGLBuffer ebo;
  QOpenGLBuffer eboCPU;
  QOpenGLVertexArrayObject vao;
  QOpenGLVertexArrayObject vaoCPU;
  QMatrix4x4 projectionMatrix;
  QMatrix4x4 cameraMatrix;
  QMatrix4x4 rotateMatrix;
  QMatrix4x4 moveMatrix;
  QMatrix4x4 scaleMatrix;

  int m_xRot = 2880;
  int m_yRot = 360 * 8;
  int m_zRot = 360 * 8;
  int m_xMove = 0;
  int m_yMove = 0;
  int m_zMove = 0;
  int zoomVal = 30;

  void initBuffersCPU();
  void setupProjection(int w = 0, int h = 0);
  void clearBuffers();
  void clearBuffersCPU();
  void cleanup();
};

#endif  // GLWIDGET_H

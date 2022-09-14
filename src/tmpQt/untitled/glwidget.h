#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

};

#endif // GLWIDGET_H

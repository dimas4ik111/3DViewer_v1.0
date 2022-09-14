#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

GLWidget::~GLWidget() {

}

// Функция initializeGL() вызывается один раз, перед вызовом paintGL(). Здесь выполняется настройка контекста отображения.
void GLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(255, 0, 0, 0);
}

// Функция paintGL() вызывается всякий раз, когда возникает необходимость перерисовать содержимое виджета.
void GLWidget::paintGL() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);

}

// Функция resizeGL() вызывается один раз, перед paintGL(), но после того, как будет вызвана функция initializeGL(). Здесь настраивается область просмотра (viewport), проекция и прочие настройки, которые зависят от размера виджета.
void GLWidget::resizeGL(int width, int height) {

}

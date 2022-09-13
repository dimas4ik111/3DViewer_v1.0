#include "oglwidget.h"

oglwidget::oglwidget(QWidget *parent) : QOpenGLWidget(parent)
{
    rotationX = 0;
    rotationY = 0;
    rotationZ = 0;
}

oglwidget::~oglwidget()
{

}

void oglwidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(255, 255, 255, 1);  // color back?
    //    initShaders();
    //    initTextures();
    glEnable(GL_DEPTH_TEST);
//    glwidget = new QOpenGLWidget;
    //    backGroundColor.setRgb(54, 23, 52);
}

void oglwidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

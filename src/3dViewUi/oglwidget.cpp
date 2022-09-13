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
    glEnable(GL_DEPTH_TEST);
    glwidget = new QOpenGLWidget;
//    glwidget->makeCurrent();
    backGroundColor.setRgb(54, 23, 52);
}

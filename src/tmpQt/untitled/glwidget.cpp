#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    initSettings();
}

GLWidget::~GLWidget() {

}

void GLWidget::initSettings() {
    backgroundColor.setRgb(0, 0, 0);
    lineColor.setRgb(255, 127, 51);
    pointColor.setRgb(0, 214, 120);
}

void GLWidget::initBuffers() {
    QList<GLfloat> m_data;

    m_data.push_back(1);m_data.push_back(-1);m_data.push_back(-1);
    m_data.push_back(1);m_data.push_back(-1);m_data.push_back(1);
    m_data.push_back(-1);m_data.push_back(-1);m_data.push_back(1);
    m_data.push_back(-1);m_data.push_back(-1);m_data.push_back(-1);
    m_data.push_back(1);m_data.push_back(1);m_data.push_back(-1);
    m_data.push_back(1);m_data.push_back(1);m_data.push_back(1);
    m_data.push_back(-1);m_data.push_back(1);m_data.push_back(1);
    m_data.push_back(-1);m_data.push_back(1);m_data.push_back(-1);

    //vao.create();
    //glBindBuffer()
    vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern(QOpenGLBuffer::DynamicDraw);
    vbo.allocate(m_data.constData(), m_data.count() * sizeof(GLfloat));

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);

    //setupVertexAttribs();

    GLuint inds[]={1,2,2,3,3,1,7,6,6,5,5,7,4,5,5,1,1,4,5,6,6,2,2,5,2,6,6,7,7,2,0,3,3,7,7,0,0,1,1,3,3,0,4,7,7,5,5,4,0,4,4,1,1,0,1,5,5,2,2,1,3,2,2,7,7,3,4,0,0,7,7,4};
    // GLuint inds[]={2,3,4,8,7,6,5,6,2,6,7,3,3,7,8,1,4,8,1,2,4,5,8,6,1,5,2,2,6,3,4,3,8,5,1,8};

    ebo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    ebo.create();
    ebo.bind();
    ebo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    ebo.allocate(inds, 72 * sizeof(GLuint));

}

// код веришнного шейдера на GLSL
static const char *vertexShaderSourceCore =
//    "#version 150\n"
//    "in vec4 vertex;\n"
    "attribute vec4 vertex;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "void main() {\n"
    "   gl_Position = projMatrix * mvMatrix * vertex;\n"
    "}\n";

static const char *fragmentShaderSourceCore =
//    "#version 330 core\n"
//    "out highp vec4 gl_FragColor;\n"
    "uniform vec4 color;\n"
    "void main() {\n"
    "   gl_FragColor = color;\n"
    "}\n";

// Функция initializeGL() вызывается один раз, перед вызовом paintGL(). Здесь выполняется настройка контекста отображения.
void GLWidget::initializeGL() {
    initializeOpenGLFunctions();

    m_program = new QOpenGLShaderProgram;
    // Настраиваем вершинный шейдер (программы, выполняемые видеочипами, которые производят математические операции с вершинами)
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSourceCore);
    // Настраиваем фрагментный шейдер (программы, выполняемые видеочипами, которые вычисляют выходной цвет пикселей)
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSourceCore);
    m_program->bindAttributeLocation("vertex", 0);
    m_program->link();
    m_program->bind();
    m_projMatrixLoc = m_program->uniformLocation("projMatrix");
    m_mvMatrixLoc = m_program->uniformLocation("mvMatrix");
    m_normalMatrixLoc = m_program->uniformLocation("normalMatrix");
    m_colorLoc = m_program->uniformLocation("color");

//    vao.create();
//    QOpenGLVertexArrayObject::Binder vaoBinder(&vao);

    initBuffers();



    // Our camera never changes in this example.
    m_camera.setToIdentity();
    m_camera.translate(0, 0, -5);

//    m_camera.frustum(-0.5, 0.5, -0.5, 0.5, 0.4, 4);
//    m_camera.translate(0, 0, -1.7);

    m_program->release();
}

// Функция paintGL() вызывается всякий раз, когда возникает необходимость перерисовать содержимое виджета.
void GLWidget::paintGL() {
    glClearColor(backgroundColor.redF(), backgroundColor.greenF(), backgroundColor.blueF(), backgroundColor.alphaF());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);

    m_world.setToIdentity();
        m_world.rotate(180.0f - (m_xRot / 16.0f), 1, 0, 0);
        m_world.rotate(m_yRot / 16.0f, 0, 1, 0);
        m_world.rotate(m_zRot / 16.0f, 0, 0, 1);

//    QOpenGLVertexArrayObject::Binder vaoBinder(&vao);
    m_program->bind();
    m_program->setUniformValue(m_projMatrixLoc, m_proj);
    m_program->setUniformValue(m_mvMatrixLoc, m_camera * m_world);
    QMatrix3x3 normalMatrix = m_world.normalMatrix();
    m_program->setUniformValue(m_normalMatrixLoc, normalMatrix);

//    vbo.bind();
//    glDrawElements(GL_POINTS, 8, GL_UNSIGNED_INT, nullptr);
    m_program->setUniformValue(m_colorLoc, pointColor);

    glPointSize(20);
    glEnable(GL_POINT_SMOOTH);
    glDrawArrays(GL_POINTS, 0, 8);
    glDisable(GL_POINT_SMOOTH);

    m_program->setUniformValue(m_colorLoc, lineColor);

    glDrawElements(GL_LINES, 72, GL_UNSIGNED_INT, 0);
    //glDrawElements(GL_LINE_STRIP, 72, GL_UNSIGNED_INT, inds);

//    vao.release();
    m_program->release();

}

// Функция resizeGL() вызывается один раз, перед paintGL(), но после того, как будет вызвана функция initializeGL(). Здесь настраивается область просмотра (viewport), проекция и прочие настройки, которые зависят от размера виджета.
void GLWidget::resizeGL(int width, int height) {
    m_proj.setToIdentity();
    m_proj.perspective(45.0f, GLfloat(width) / height, 0.01f, 100.0f);
}

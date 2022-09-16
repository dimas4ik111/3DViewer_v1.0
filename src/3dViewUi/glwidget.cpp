#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    initSettings();
}

void GLWidget::initSettings() {
    backgroundColor.setRgb(0, 0, 0);
    lineColor.setRgb(255, 127, 51);
    pointColor.setRgb(0, 214, 120);
    orthoMode = 0; // По умолчанию перспектива
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
    "uniform mat4 projectionMatrix;\n"
    "uniform mat4 cameraMatrix;\n"
    "uniform mat4 rotateMatrix;\n"
    "uniform mat4 moveMatrix;\n"
    "uniform mat4 scaleMatrix;\n"
    "void main() {\n"
    "   gl_Position = projectionMatrix * cameraMatrix * rotateMatrix * moveMatrix * scaleMatrix * vertex;\n"
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
    m_projectionMatrixLoc = m_program->uniformLocation("projectionMatrix");
    m_cameraMatrixLoc = m_program->uniformLocation("cameraMatrix");
    m_rotateMatrixLoc = m_program->uniformLocation("rotateMatrix");
    m_moveMatrixLoc = m_program->uniformLocation("moveMatrix");
    m_scaleMatrixLoc = m_program->uniformLocation("scaleMatrix");
    m_colorLoc = m_program->uniformLocation("color");

//    vao.create();
//    QOpenGLVertexArrayObject::Binder vaoBinder(&vao);

    initBuffers();



    // Our camera never changes in this example.
    cameraMatrix.setToIdentity();
//    cameraMatrix.translate(0, 0, -2);
    if (orthoMode == 0) {
        cameraMatrix.translate(0, 0, -4);
    } else {
        cameraMatrix.scale(0.5,0.5,0.5);
    }

//    cameraMatrix.ortho(-0.5, 0.5, -0.5, 0.5, 0.4, 4);
//    ortho(float left, float right, float bottom, float top, float nearPlane, float farPlane)
//    cameraMatrix.frustum(-0.5, 0.5, -0.5, 0.5, 0.4, 4);
//    cameraMatrix.viewport()
//    viewport(float left, float bottom, float width, float height, float nearPlane = 0.0f, float farPlane = 1.0f)
    rotateMatrix.setToIdentity();
//    rotateMatrix.rotate(180.0f - (m_xRot / 16.0f), 1, 0, 0);
//    rotateMatrix.rotate(m_yRot / 16.0f, 0, 1, 0);
//    rotateMatrix.rotate(m_zRot / 16.0f, 0, 0, 1);
    moveMatrix.setToIdentity();
    scaleMatrix.setToIdentity();

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

//    m_world.setToIdentity();
//        m_world.rotate(180.0f - (m_xRot / 16.0f), 1, 0, 0);
//        m_world.rotate(m_yRot / 16.0f, 0, 1, 0);
//        m_world.rotate(m_zRot / 16.0f, 0, 0, 1);

//    QOpenGLVertexArrayObject::Binder vaoBinder(&vao);

// Примеры трансформаций
//    rotateMatrix.rotate(5, 1, 0, 0);
//    rotateMatrix.rotate(5, 0, 1, 0);
//    rotateMatrix.rotate(5, 0, 0, 1);
//    scaleMatrix.scale(0.75,0.75,0.75);
//    moveMatrix.translate(0,0.1,0);


    m_program->bind();
    m_program->setUniformValue(m_projectionMatrixLoc, projectionMatrix);
    m_program->setUniformValue(m_cameraMatrixLoc, cameraMatrix);
    m_program->setUniformValue(m_rotateMatrixLoc, rotateMatrix);
    m_program->setUniformValue(m_moveMatrixLoc, moveMatrix);
    m_program->setUniformValue(m_scaleMatrixLoc, scaleMatrix);


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
    projectionMatrix.setToIdentity();
    if (orthoMode == 0) {
        projectionMatrix.perspective(45.0f, GLfloat(width) / height, 0.01f, 100.0f);
    }
//    projectionMatrix.viewport(0, 0, width*0.8, height*0.8, 0.1f, 4.0f);
}

// --------------------------------------------------------------------------

GLWidget::~GLWidget()
{
    cleanup();
}

//QSize GLWidget::sizeHint() const
//{
//    return QSize(400, 400);
//}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot) {
        m_xRot = angle;
//        rotateMatrix.setToIdentity();
        rotateMatrix.rotate(180.0f - (angle / 16.0f), 1, 0, 0);
        emit xRotationChanged(angle);
        update();
    }
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot) {
        m_yRot = angle;
//        rotateMatrix.setToIdentity();
        rotateMatrix.rotate(angle / 16.0f, 0, 1, 0);
        emit yRotationChanged(angle);
        update();
    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_zRot) {
        m_zRot = angle;
//        rotateMatrix.setToIdentity();
        rotateMatrix.rotate(angle / 16.0f, 0, 0, 1);
        emit zRotationChanged(angle);
        update();
    }
}

void GLWidget::cleanup()
{
    if (m_program == nullptr)
        return;
    makeCurrent();
    vbo.destroy();
    ebo.destroy();
    delete m_program;
    m_program = nullptr;
    doneCurrent();
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->position().toPoint();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->position().toPoint().x() - m_lastPos.x();
    int dy = event->position().toPoint().y() - m_lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(m_xRot + 8 * dy);
        setYRotation(m_yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(m_xRot + 8 * dy);
        setZRotation(m_zRot + 8 * dx);
    }
    m_lastPos = event->position().toPoint();
}


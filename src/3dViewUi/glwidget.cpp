#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    s21_init_obj_data(&rawObjData);
    s21_init_obj_data(&rawObjDataCPU);
    initSettings();
}

GLWidget::~GLWidget()
{
    cleanup();
}

void GLWidget::initSettings() {
    // Проекция: 0 - центральная, 1 - параллельная
    orthoMode = 0;
    // Цвет фона
    backgroundColor.setRgb(0, 0, 0);
    // Цвет линии
    lineColor.setRgb(255, 127, 51);
    // Толщина линии
    lineSize = 1;
    // Тип линии: 0 - сплошная, 1 - пунктирная
    lineMode = 0;
    // Цвет точки
    pointColor.setRgb(0, 214, 120);
    // Размер точки
    pointSize = 20;
    // Тип точки: 0 - нет точек, 1 - круг, 2 - квадрат
    pointMode = 0;
    // Режим вычислений: 0 - GPU, 1 - CPU
    calcMode = 0;
}

void GLWidget::testBuffers() {
    clearBuffers();
//x:  0.000000 y:  1.000000 z:  0.000000
//x: -1.000000 y:  0.000000 z: -1.000000
//x:  1.000000 y:  0.000000 z: -1.000000
//x:  1.000000 y:  0.000000 z:  1.000000
//x: -1.000000 y:  0.000000 z:  1.000000
//0,1,1,2,2,0,0,2,2,3,3,0,0,3,3,4,4,0,0,4,4,1,1,0,2,1,1,3,3,2,1,4,4,3,3,1,v: 5 (15)
//f: 18 (36)

    QList<GLfloat> m_data;
    // Куб
//    m_data.push_back(1);m_data.push_back(-1);m_data.push_back(-1);
//    m_data.push_back(1);m_data.push_back(-1);m_data.push_back(1);
//    m_data.push_back(-1);m_data.push_back(-1);m_data.push_back(1);
//    m_data.push_back(-1);m_data.push_back(-1);m_data.push_back(-1);
//    m_data.push_back(1);m_data.push_back(1);m_data.push_back(-1);
//    m_data.push_back(1);m_data.push_back(1);m_data.push_back(1);
//    m_data.push_back(-1);m_data.push_back(1);m_data.push_back(1);
//    m_data.push_back(-1);m_data.push_back(1);m_data.push_back(-1);
    // Пирамидка
    m_data.push_back(0);m_data.push_back(1);m_data.push_back(0);
    m_data.push_back(-1);m_data.push_back(0);m_data.push_back(-1);
    m_data.push_back(1);m_data.push_back(0);m_data.push_back(-1);
    m_data.push_back(1);m_data.push_back(0);m_data.push_back(1);
    m_data.push_back(-1);m_data.push_back(0);m_data.push_back(1);
    vao.create();
    vao.bind();

    vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern(QOpenGLBuffer::DynamicDraw);
    vbo.allocate(m_data.constData(), m_data.count() * sizeof(GLfloat));

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(0);

    //setupVertexAttribs();

    // Куб
//    GLuint inds[]={1,2,2,3,3,1,7,6,6,5,5,7,4,5,5,1,1,4,5,6,6,2,2,5,2,6,6,7,7,2,0,3,3,7,7,0,0,1,1,3,3,0,4,7,7,5,5,4,0,4,4,1,1,0,1,5,5,2,2,1,3,2,2,7,7,3,4,0,0,7,7,4};
    // Пирамидка
    GLuint inds[]={0,1,1,2,2,0,0,2,2,3,3,0,0,3,3,4,4,0,0,4,4,1,1,0,2,1,1,3,3,2,1,4,4,3,3,1};
    ebo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    ebo.create();
    ebo.bind();
    ebo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    // Куб
//    ebo.allocate(inds, 72 * sizeof(GLuint));
//    rawObjData.num_of_v = 8;
//    rawObjData.num_of_f = 72;
    // Пирамидка
    ebo.allocate(inds, 36 * sizeof(GLuint));
    rawObjData.num_of_v = 5;
    rawObjData.num_of_f = 36;

    vao.release();
}

void GLWidget::clearBuffers() {
    if (vao.isCreated()) {
        vao.destroy();
    }
    if (vbo.isCreated()) {
        vbo.destroy();
    }
    if (ebo.isCreated()) {
        ebo.destroy();
    }
}

void GLWidget::clearBuffersCPU() {
    if (vaoCPU.isCreated()) {
        vaoCPU.destroy();
    }
    if (vboCPU.isCreated()) {
        vboCPU.destroy();
    }
    if (eboCPU.isCreated()) {
        eboCPU.destroy();
    }
}

void GLWidget::initBuffers() {
    // Чистим все буферы, если они были ранее созданы
    clearBuffers();

    // Создаем Vertex Arrays Object (VAO) - хранилище индексов VBO (в элементах которого хранится информация о том, какую часть некого VBO использовать, и как эти данные нужно интерпретировать)
    vao.create();
    // Всё, что будет происходить далее, будет привязано к vao
    vao.bind();

    // Создаем Vertex Buffer Object (VBO) - средство OpenGL, позволяющее загружать определенные данные в память GPU. В данном случае будем хранить координаты вершин
    vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    // Заполняем VBO данными, которые были распарсены из .obj-файла
    vbo.allocate(rawObjData.array_of_v, rawObjData.num_of_v * sizeof(GLfloat));

    qDebug() << "Координат вершин:" << rawObjData.num_of_v;

    // Сообщаем OpenGL, как он должен интерпретировать данные вершин
    // 0 - Указываем location атрибута в шейдерах, который мы хотим настроить (у нас он один)
    // 3 - размер вершинного атрибута (состоит из 3х значений - x, y, z)
    // GL_FLOAT - указываем тип данных атрибута (т.е. float)
    // GL_FALSE - Указываем, хотим ли мы, чтобы наши данные были нормализованы (актуально только для целочисленных данных)
    // 3 * sizeof(GLfloat) - шаг, на который необходимо сдвигаться в пространстве атрибутов, чтобы получить значения следующе вершины
    // nullptr - Смещение от начала буфера, с которого начинается обработка. Тут задано смещение 0, поскольку данные находятся в начале массива
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
    // Устанавливаем индекс атрибута (включаем). Если это не сделать, то атрибут не будет использоваться
    glEnableVertexAttribArray(0);

    // Создаем Element Buffer Objects (EBO) - буффер, хранящий индексы вершин
    // Используем, чтобы соединить указанные вершины линиями
    ebo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    ebo.create();
    ebo.bind();
    ebo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    // Заполняем EBO данными, которые были распарсены из .obj-файла
    ebo.allocate(rawObjData.array_of_f, rawObjData.num_of_f * sizeof(GLuint));
    qDebug() << "Координат линий:" << rawObjData.num_of_f;
    qDebug() << "Максимальная координата:" << rawObjData.max_coord;

    // Сообщаем, что мы закончили привязывать к VAO
    vao.release();

    s21_copy_obj_data(&rawObjDataCPU, &rawObjData);
}

void GLWidget::initBuffersCPU() {
    // Чистим все буферы, если они были ранее созданы
    clearBuffersCPU();

    // Создаем Vertex Arrays Object (VAO) - хранилище индексов VBO (в элементах которого хранится информация о том, какую часть некого VBO использовать, и как эти данные нужно интерпретировать)
    vaoCPU.create();
    // Всё, что будет происходить далее, будет привязано к vao
    vaoCPU.bind();

    // Создаем Vertex Buffer Object (VBO) - средство OpenGL, позволяющее загружать определенные данные в память GPU. В данном случае будем хранить координаты вершин
    vboCPU = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vboCPU.create();
    vboCPU.bind();
    vboCPU.setUsagePattern(QOpenGLBuffer::StaticDraw);
    // Заполняем VBO данными, которые были распарсены из .obj-файла
    vboCPU.allocate(rawObjDataCPU.array_of_v, rawObjDataCPU.num_of_v * sizeof(GLfloat));

    qDebug() << "Координат вершин (CPU):" << rawObjDataCPU.num_of_v;

    // Сообщаем OpenGL, как он должен интерпретировать данные вершин
    // 0 - Указываем location атрибута в шейдерах, который мы хотим настроить (у нас он один)
    // 3 - размер вершинного атрибута (состоит из 3х значений - x, y, z)
    // GL_FLOAT - указываем тип данных атрибута (т.е. float)
    // GL_FALSE - Указываем, хотим ли мы, чтобы наши данные были нормализованы (актуально только для целочисленных данных)
    // 3 * sizeof(GLfloat) - шаг, на который необходимо сдвигаться в пространстве атрибутов, чтобы получить значения следующе вершины
    // nullptr - Смещение от начала буфера, с которого начинается обработка. Тут задано смещение 0, поскольку данные находятся в начале массива
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
    // Устанавливаем индекс атрибута (включаем). Если это не сделать, то атрибут не будет использоваться
    glEnableVertexAttribArray(0);

    // Создаем Element Buffer Objects (EBO) - буффер, хранящий индексы вершин
    // Используем, чтобы соединить указанные вершины линиями
    eboCPU = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    eboCPU.create();
    eboCPU.bind();
    eboCPU.setUsagePattern(QOpenGLBuffer::StaticDraw);
    // Заполняем EBO данными, которые были распарсены из .obj-файла
    eboCPU.allocate(rawObjDataCPU.array_of_f, rawObjDataCPU.num_of_f * sizeof(GLuint));
    qDebug() << "Координат линий (CPU):" << rawObjDataCPU.num_of_f;
    qDebug() << "Максимальная координата (CPU):" << rawObjDataCPU.max_coord;

    // Сообщаем, что мы закончили привязывать к VAO
    vaoCPU.release();
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

    // testBuffers();

    cameraMatrix.setToIdentity();
    if (orthoMode == 0) {
        cameraMatrix.translate(0, 0, -4);
    } else {
        cameraMatrix.scale(0.5, 0.5, 0.5);
    }

    rotateMatrix.setToIdentity();
    moveMatrix.setToIdentity();
    scaleMatrix.setToIdentity();

//    cameraMatrix.ortho(-0.5, 0.5, -0.5, 0.5, 0.4, 4);
//    ortho(float left, float right, float bottom, float top, float nearPlane, float farPlane)
//    cameraMatrix.frustum(-0.5, 0.5, -0.5, 0.5, 0.4, 4);
//    cameraMatrix.viewport()
//    viewport(float left, float bottom, float width, float height, float nearPlane = 0.0f, float farPlane = 1.0f)
//    rotateMatrix.rotate(180.0f - (m_xRot / 16.0f), 1, 0, 0);
//    rotateMatrix.rotate(m_yRot / 16.0f, 0, 1, 0);
//    rotateMatrix.rotate(m_zRot / 16.0f, 0, 0, 1);
//    m_camera.frustum(-0.5, 0.5, -0.5, 0.5, 0.4, 4);
//    m_camera.translate(0, 0, -1.7);
}

// Функция paintGL() вызывается всякий раз, когда возникает необходимость перерисовать содержимое виджета.
void GLWidget::paintGL() {
    glClearColor(backgroundColor.redF(), backgroundColor.greenF(), backgroundColor.blueF(), backgroundColor.alphaF());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
    qDebug() << m_xRot << m_yRot << m_zRot;
    qDebug() << 180 - m_xRot / 16.0f << 180 - m_yRot / 16.0f << 180 - m_zRot / 16.0f;

    // Пытаемся что-то рисовать только если создан VAO
    if (vao.isCreated()) {
        rotateMatrix.setToIdentity();
        moveMatrix.setToIdentity();
        scaleMatrix.setToIdentity();

        if (calcMode == 0) {
            rotateMatrix.rotate(180 - m_xRot / 16.0f, 1, 0, 0);
            rotateMatrix.rotate(180 - m_yRot / 16.0f, 0, 1, 0);
            rotateMatrix.rotate(180 - m_zRot / 16.0f, 0, 0, 1);

            moveMatrix.translate(0.05 * (50 - m_xMove), 0, 0);
            moveMatrix.translate(0, 0.05 * (50 - m_yMove), 0);
            moveMatrix.translate(0, 0, 0.05 * (50 - m_zMove));

            scaleMatrix.scale(fabs(zoomVal / 30.0f), fabs(zoomVal / 30.0f), fabs(zoomVal / 30.0f));
        } else {
            s21_scale(&rawObjDataCPU, fabs(zoomVal / 30.0f));

            s21_move_x(&rawObjDataCPU, 0.05 * (50 - m_xMove));
            s21_move_y(&rawObjDataCPU, 0.05 * (50 - m_yMove));
            s21_move_z(&rawObjDataCPU, 0.05 * (50 - m_zMove));

            s21_rotate_z(&rawObjDataCPU, 180 - m_zRot / 16.0f);
            s21_rotate_y(&rawObjDataCPU, 180 - m_yRot / 16.0f);
            s21_rotate_x(&rawObjDataCPU, 180 - m_xRot / 16.0f);

            initBuffersCPU();
        }

        m_program->bind();
        m_program->setUniformValue(m_projectionMatrixLoc, projectionMatrix);
        m_program->setUniformValue(m_cameraMatrixLoc, cameraMatrix);
        m_program->setUniformValue(m_rotateMatrixLoc, rotateMatrix);
        m_program->setUniformValue(m_moveMatrixLoc, moveMatrix);
        m_program->setUniformValue(m_scaleMatrixLoc, scaleMatrix);

        // Указываем, какой VAO будем использовать
        if (calcMode == 0) {
            vao.bind();
        } else {
            vaoCPU.bind();
        }

        // Рисуем точки
        if (pointMode != 0) {
            // Устанавливаем цвет точки для отрисовки
            m_program->setUniformValue(m_colorLoc, pointColor);
            glPointSize(pointSize);
            if (pointMode == 1) {
                glEnable(GL_POINT_SMOOTH);
            }
            glDrawArrays(GL_POINTS, 0, rawObjData.num_of_v);
            if (pointMode == 1) {
                glDisable(GL_POINT_SMOOTH);
            }
        }

        // Устанавливаем цвет линии для отрисовки
        m_program->setUniformValue(m_colorLoc, lineColor);

        glLineWidth (lineSize);
        if (lineMode == 1) {
            // Настраиваем тип линии
            glEnable(GL_LINE_STIPPLE);
            // TODO(maiamabl): glLineStipple deprecated in OpenGL 3.1 / Использовать геометрические шейдеры?
            glLineStipple(2, 0x00F0);
        }

        // Рисуем линии
        glDrawElements(GL_LINES, rawObjData.num_of_f, GL_UNSIGNED_INT, 0);

        if (lineMode == 1) {
            glDisable(GL_LINE_STIPPLE);
        }
        // Сообщаем, что мы закончили использовать этот VAO
        if (calcMode == 0) {
            vao.release();
        } else {
            vaoCPU.release();
        }

        m_program->release();
        if (calcMode == 1) {
            s21_destroy_obj_data(&rawObjDataCPU);
            s21_copy_obj_data(&rawObjDataCPU, &rawObjData);
        }
    }

}

// Функция resizeGL() вызывается один раз, перед paintGL(), но после того, как будет вызвана функция initializeGL(). Здесь настраивается область просмотра (viewport), проекция и прочие настройки, которые зависят от размера виджета.
void GLWidget::resizeGL(int width, int height) {
    projectionMatrix.setToIdentity();
    if (orthoMode == 0) {
        projectionMatrix.perspective(45.0f, GLfloat(width) / height, 0.01f, 100.0f);
    }
//    projectionMatrix.viewport(0, 0, width*0.8, height*0.8, 0.1f, 4.0f);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void GLWidget::setXMove(int step) {
    if (step != m_xMove) {
        m_xMove = step;
        update();
    }
}

void GLWidget::setYMove(int step) {
    if (step != m_yMove) {
        m_yMove = step;
        update();
    }
}

void GLWidget::setZMove(int step) {
    if (step != m_zMove) {
        m_zMove = step;
        update();
    }
}

void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot) {
        m_xRot = angle;
        emit xRotationChanged(angle);
        update();
    }
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot) {
        m_yRot = angle;
        emit yRotationChanged(angle);
        update();
    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_zRot) {
        m_zRot = angle;
        emit zRotationChanged(angle);
        update();
    }
}

void GLWidget::setZoom(int zoom) {
    if (zoom != zoomVal) {
        zoomVal = zoom;
        update();
    }
}

void GLWidget::cleanup()
{
    if (m_program == nullptr)
        return;
    makeCurrent();
    clearBuffers();
    clearBuffersCPU();
    s21_destroy_obj_data(&rawObjData);
    s21_destroy_obj_data(&rawObjDataCPU);
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


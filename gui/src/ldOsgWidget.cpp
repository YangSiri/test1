#include "ldOsgWidget.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>

#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include "moc_ldOsgWidget.cpp"

#include <thread>

ldOSGWidget::ldOSGWidget(osg::Node *root, QWidget *parent, Qt::WindowFlags f):
    QOpenGLWidget(parent, f),
    _graphicsWindow(new osgViewer::GraphicsWindowEmbedded(this->x(), this->y(), this->width(), this->height())),
    _viewer(new osgViewer::Viewer)
{
    float aspectRatio = static_cast<float>(this->width()) / static_cast<float>(this->height());
    osg::Camera *camera = _viewer->getCamera();
    camera->setViewport(0, 0, this->width(), this->height());
    camera->setClearColor(osg::Vec4(0.5, 0.5, 0.5, 1.0));
    camera->setProjectionMatrixAsPerspective(30.f, aspectRatio, 1.f, 10000.f);
    camera->setGraphicsContext(_graphicsWindow);
	camera->setName("main camera");

    _viewer->addEventHandler(new osgViewer::StatsHandler);
    osg::ref_ptr<osgGA::TrackballManipulator> trackball = new osgGA::TrackballManipulator;
    trackball->setAllowThrow(false);
    trackball->setAutoComputeHomePosition(true);
    _viewer->setCameraManipulator(trackball.get());
    _viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);
    _viewer->setSceneData(root);

	connect(this, SIGNAL(sendPaintMessage()), this, SLOT(revecivePaintMessage()));

//  	std::thread thrd([&](){
// 		while (true)
// 		{
// 			std::this_thread::sleep_for(std::chrono::milliseconds(10));
// 			emit sendPaintMessage();
// 			//revecivePaintMessage();
// 		}
//  	});
//  	thrd.detach();
	//emit sendPaintMessage();
}

void ldOSGWidget::revecivePaintMessage()
{
	//_viewer->frame();
	paintEvent(nullptr);
}

void ldOSGWidget::addEventHandler(osgGA::GUIEventHandler *handler)
{
    _viewer->addEventHandler(handler);
}

void ldOSGWidget::removeEventHandler(osgGA::GUIEventHandler *handler)
{
    _viewer->removeEventHandler(handler);
}
void ldOSGWidget::paintEvent(QPaintEvent * /* paintEvent */)
{
    this->makeCurrent();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    this->paintGL();

    painter.end();

    this->doneCurrent();
}

void ldOSGWidget::paintGL()
{
    _viewer->frame();
}

void ldOSGWidget::resizeGL(int width, int height)
{
    this->getEventQueue()->windowResize(this->x(), this->y(), width, height);
    _graphicsWindow->resized(this->x(), this->y(), width, height);

    this->onResize(width, height);
}

void ldOSGWidget::keyPressEvent(QKeyEvent *event)
{
    QString keyString   = event->text();
    const char *keyData = keyString.toLocal8Bit().data();

    this->getEventQueue()->keyPress(osgGA::GUIEventAdapter::KeySymbol(*keyData));
}

void ldOSGWidget::keyReleaseEvent(QKeyEvent *event)
{
    QString keyString   = event->text();
    const char *keyData = keyString.toLocal8Bit().data();

    this->getEventQueue()->keyRelease(osgGA::GUIEventAdapter::KeySymbol(*keyData));
}

void ldOSGWidget::mouseMoveEvent(QMouseEvent *event)
{

    this->getEventQueue()->mouseMotion(static_cast<float>(event->x()),
                                       static_cast<float>(event->y()));
}

void ldOSGWidget::mousePressEvent(QMouseEvent *event)
{

    // 1 = left mouse button
    // 2 = middle mouse button
    // 3 = right mouse button

    unsigned int button = 0;

    switch (event->button())
    {
    case Qt::LeftButton:
        button = 1;
        break;

    case Qt::MiddleButton:
        button = 2;
        break;

    case Qt::RightButton:
        button = 3;
        break;

    default:
        break;
    }

    this->getEventQueue()->mouseButtonPress(static_cast<float>(event->x()),
                                            static_cast<float>(event->y()),
                                            button);
}

void ldOSGWidget::mouseReleaseEvent(QMouseEvent *event)
{

    // 1 = left mouse button
    // 2 = middle mouse button
    // 3 = right mouse button

    unsigned int button = 0;

    switch (event->button())
    {
    case Qt::LeftButton:
        button = 1;
        break;

    case Qt::MiddleButton:
        button = 2;
        break;

    case Qt::RightButton:
        button = 3;
        break;

    default:
        break;
    }

    this->getEventQueue()->mouseButtonRelease(static_cast<float>(event->x()),
            static_cast<float>(event->y()),
            button);
}

void ldOSGWidget::wheelEvent(QWheelEvent *event)
{
    event->accept();
    int delta = event->delta();

    osgGA::GUIEventAdapter::ScrollingMotion motion = delta > 0 ?   osgGA::GUIEventAdapter::SCROLL_UP
            : osgGA::GUIEventAdapter::SCROLL_DOWN;

    this->getEventQueue()->mouseScroll(motion);
}

bool ldOSGWidget::event(QEvent *event)
{
    bool handled = QOpenGLWidget::event(event);

    // This ensures that the OSG widget is always going to be repainted after the
    // user performed some interaction. Doing this in the event handler ensures
    // that we don't forget about some event and prevents duplicate code.
    switch (event->type())
    {
    case QEvent::KeyPress:
    case QEvent::KeyRelease:
    case QEvent::MouseButtonDblClick:
    case QEvent::MouseButtonPress:
    case QEvent::MouseButtonRelease:
    case QEvent::MouseMove:
    case QEvent::Wheel:
        this->update();
        break;

    default:
        break;
    }

    return handled;
}

void ldOSGWidget::home()
{
    _viewer->home();
    this->update();
}

void ldOSGWidget::onResize(int width, int height)
{
    _viewer->getCamera()->setViewport(0, 0, this->width(), this->height());
}

osgGA::EventQueue *ldOSGWidget::getEventQueue() const
{
    osgGA::EventQueue *eventQueue = _graphicsWindow->getEventQueue();

    if (eventQueue) {
        return eventQueue;
    }
    else {
        throw std::runtime_error("Unable to obtain valid event queue");
    }
}

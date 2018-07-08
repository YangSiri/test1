#ifndef LDOSGWIDGET_H
#define LDOSGWIDGET_H

//Osg
#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
//Qt
#include <QOpenGLWidget>

/**
 * @brief The ldOSGWidget class is the bridge between OSG and Qt.
 * @author Shine Song
 */
class ldOSGWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    /**
     * @brief Default constructor
     * @param root root scene node
     * @param parent parent window pointer
     * @param f windows flags
     */
    ldOSGWidget(osg::Node *root, QWidget *parent = 0, Qt::WindowFlags f = 0);

    void addEventHandler(osgGA::GUIEventHandler *handler);

    void removeEventHandler(osgGA::GUIEventHandler *handler);

	osg::ref_ptr<osgViewer::Viewer> get_viewer()
	{
		return _viewer;
	}

private slots:
	void revecivePaintMessage();
signals :
	void sendPaintMessage();

protected:
    //inherit from QOpenGLWidget
    virtual void paintEvent(QPaintEvent *paintEvent);
    //inherit from QOpenGLWidget
    virtual void paintGL();
    //inherit from QOpenGLWidget
    virtual void resizeGL(int width, int height);

    //inherit from QOpenGLWidget
    virtual void keyPressEvent(QKeyEvent *event);
    //inherit from QOpenGLWidget
    virtual void keyReleaseEvent(QKeyEvent *event);

    //inherit from QOpenGLWidget
    virtual void mouseMoveEvent(QMouseEvent *event);
    //inherit from QOpenGLWidget
    virtual void mousePressEvent(QMouseEvent *event);
    //inherit from QOpenGLWidget
    virtual void mouseReleaseEvent(QMouseEvent *event);
    //inherit from QOpenGLWidget
    virtual void wheelEvent(QWheelEvent *event);

    //inherit from QOpenGLWidget
    virtual bool event(QEvent *event);
public slots:
    //! Zoom Viewer to whole display
    void home();

private:
    //inherit from QOpenGLWidget
    virtual void onResize(int width, int height);
    //! Getter of osg event queue
    osgGA::EventQueue *getEventQueue() const;
    //! Ref of OSG Graphics Window
    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> _graphicsWindow;
    //! Ref of OSG Viewer
    osg::ref_ptr<osgViewer::Viewer> _viewer;
};

#endif // LDOSGWIDGET_H

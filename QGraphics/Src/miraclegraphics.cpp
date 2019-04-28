#include "miraclegraphics.h"

MiracleGraphics::MiracleGraphics(QWidget* parent)
    :QGraphicsView(parent),
    m_scene(new QGraphicsScene())
    // m_rScaleFactor(1)
{    
    setScene(m_scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MiracleGraphics::~MiracleGraphics()
{
    //yüklemeden kapattığında zırlıyor
    if(m_imageItem != nullptr)
        delete m_imageItem;

    delete m_scene;
}

void MiracleGraphics::Load(QString& filePath)
{
    QImage image(filePath);
    ActualWidth = image.width();
    ActualHeight = image.height();
    m_imageItem = new QGraphicsPixmapItem(QPixmap::fromImage(image));    
    //m_imageItem->setScale(m_rScaleFactor);
    m_imageItem->setFlag(QGraphicsItem::ItemIsMovable);
    m_imageItem->setFlag(QGraphicsItem::ItemIsFocusable);
    m_scene->addItem(m_imageItem);
    
    show();
}
void MiracleGraphics::wheelEvent(QWheelEvent* event)
{
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        // Scale the view / do the zoom
        double scaleFactor = 1.15;
        if(event->delta() > 0) {
            // Zoom in
            scale(scaleFactor, scaleFactor);
 
        } else {
            // Zooming out
            scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
}
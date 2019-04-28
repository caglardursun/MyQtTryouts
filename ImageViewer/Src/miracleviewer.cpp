#include "miracleviewer.h"
#include <QFileDialog>
#include <QImageReader>
#include <QMessageBox>
#include <QSize>
#include <QDebug>

MiracleViewer::MiracleViewer(QWidget *parent)
    :QWidget(parent),
    scaleFactor(1),
    m_x(0),
    m_y(0)
{
    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    //white background for the image
    m_pImageReader = new QImageReader;
    m_pImageReader->setBackgroundColor(QColor::fromRgb(255,255,255));
    m_pImageReader->setAutoTransform(true);
}

MiracleViewer::~MiracleViewer()
{    
    delete m_pImageReader;
}

bool MiracleViewer::Load(QString& filePath)
{
    m_pImageReader->setFileName(filePath);
    m_RenderFocusZone.setX(0);
    m_RenderFocusZone.setY(0);
    m_RenderFocusZone.setWidth(width());
    m_RenderFocusZone.setHeight(height());

    if(m_pImageReader->canRead())
    {
        return true;
    }        
    else
    {
        return false;
    }
        
}


void MiracleViewer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    
    QPainter painter(this);
    const QRect viewPort(0,0,width(),height());
    
    qDebug() << "ViewPort : " << viewPort;    
    qDebug() << "Render Focus Zone : " << m_RenderFocusZone;

    m_pImageReader->setClipRect(m_RenderFocusZone);
    
    QImage img = m_pImageReader->read();
    painter.drawImage(viewPort,img);

}

void MiracleViewer::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMouseDown)
    {
        QPoint p = event->pos();
        int deltaX = p.x() - m_OldPos.x();
        int deltaY = p.y() - m_OldPos.y();
        qDebug() << "old position values" << m_OldPos;
        qDebug() << "P Point" << p;
        qDebug() << "Delta X, Y" << deltaX << deltaY;
        
        qDebug() << "Old Pos " << m_OldPos;
        m_x -= deltaX;
        m_y -= deltaY;

        qDebug() << "mx my" << m_x << m_y;

        m_RenderFocusZone.moveTo(m_x, m_y);
        qDebug() << "Render Focus " << m_RenderFocusZone;
        m_OldPos = p;
        

        update();
    }
}

void MiracleViewer::mousePressEvent(QMouseEvent *event)
{
    if(m_pImageReader->canRead())
    {
        m_bIsMouseDown = true;
        m_OldPos = event->pos();
    }
}

void MiracleViewer::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(m_pImageReader->canRead())
    {
        m_bIsMouseDown = false;
        m_NewPos =  event->pos();
    }

    
}
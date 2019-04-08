#include "View/mainviewer.h"


MainViewer::MainViewer(QWidget *parent) :
    QWidget(parent)    
{
    // ui->setupUi(this);        
    // Load();
}

MainViewer::~MainViewer()
{
    // delete ui;
}


void MainViewer::Load(QString& str)
{

    m_CachedImage.load(str);

    if(m_CachedImage.width() > m_CachedImage.height())
        m_aspectRatio = m_CachedImage.width() / m_CachedImage.height();
    if(m_CachedImage.height() > m_CachedImage.width())
        m_aspectRatio = m_CachedImage.height() / m_CachedImage.width();

}


void MainViewer::SetRenderFocus(QRect rect)
{
    m_RenderFocusZone = rect;
    m_AbsctractSize = rect.size() * m_Zoom;

    m_x = rect.x();
    m_y = rect.y();
}

void MainViewer::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    //on use of event pointer, remove this line
    //key events go here
}

void MainViewer::mousePressEvent(QMouseEvent *event)
{
    m_bIsMouseDown = true;
    m_OldPos = event->pos();
}

void MainViewer::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_bIsMouseDown = false;
}

void MainViewer::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bIsMouseDown)
    {
        QPoint p = event->pos();
        int deltaX = p.x() - m_OldPos.x();
        int deltaY = p.y() - m_OldPos.y();

        m_x -= deltaX;
        m_y -= deltaY;

        m_RenderFocusZone.moveTo(m_x, m_y);
        m_OldPos = p;

        update();
    }
}

void MainViewer::wheelEvent(QWheelEvent *event)
{
    const float divisionRatio = 0.05f;
    int delta = event->delta();

    if(delta < 0)
        m_Zoom -= divisionRatio;
    if(delta > 0)
        m_Zoom += divisionRatio;

    if(m_Zoom < divisionRatio)
        m_Zoom = divisionRatio;
    if(m_Zoom > 9)
        m_Zoom = 9;


    update();
}

void MainViewer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);


    QPainter painter(this);

    const QRect r(0, 0, width(), height());

    m_AbsctractSize = m_RenderFocusZone.size();

    m_AbsctractSize.scale(m_AbsctractSize * m_Zoom,
                          Qt::AspectRatioMode::KeepAspectRatio);

    QRect ar(m_RenderFocusZone.x() * m_Zoom,
             m_RenderFocusZone.y() * m_Zoom,
             m_AbsctractSize.width(),
             m_AbsctractSize.height());

    QImage p = m_CachedImage.copy(ar);

    painter.drawImage(r, p);
}

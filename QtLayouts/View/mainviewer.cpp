    #include "mainviewer.h"
    #include "utils.h"

    MainViewer::MainViewer(QWidget *parent, QString& filePath) :
        QWidget(parent),
        m_filePath(filePath),        
        m_Zoom(0),
        m_x(0),
        m_y(0),
        m_backgroundColor(255,255,255)    
    {
        // ui->setupUi(this);        
        //Load();
        m_CachedImage.load(m_filePath);

        m_RenderFocusZone = QRect(0,0,width(),height());

        if(m_CachedImage.width() > m_CachedImage.height())
            m_aspectRatio = m_CachedImage.width() / m_CachedImage.height();
        if(m_CachedImage.height() > m_CachedImage.width())
            m_aspectRatio = m_CachedImage.height() / m_CachedImage.width();

        // setAutoFillBackground(true);
        // setBackgroundRole(QPalette::Base);
        // QPalette pal = palette();
        // pal.setBrush(QPalette::Base, QPixmap(":/images/background.png"));
        // pal.setColor(QPalette::HighlightedText, Qt::red);
        // setPalette(pal);
    }

    

    MainViewer::~MainViewer()
    {
        // delete ui;
    }

    QSize MainViewer::minimumSizeHint() const
    {
            return QSize(100,100);
    }

    QSize MainViewer::sizeHint() const
    {
            return QSize(400,100);
    }

    void MainViewer::paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);
        

        QPainter painter(this);
        //Utils::Msg(QString("%1 %2").arg(width()).arg(height()));
        const QRect r(0, 0,width(), height());
        
        // painter.setBrush(m_backgroundColor);
        // painter.setRenderHint(QPainter::Antialiasing, true);        
        // painter.drawRect(this->rect());
        if(m_RenderFocusZone.width() == 0 || m_RenderFocusZone.height() == 0)
            m_RenderFocusZone = this->rect();

        m_AbsctractSize = m_RenderFocusZone.size();

        m_AbsctractSize.scale(m_AbsctractSize * m_Zoom, Qt::AspectRatioMode::KeepAspectRatio);

        QRect ar(m_RenderFocusZone.x() * m_Zoom,
                m_RenderFocusZone.y() * m_Zoom,
                m_AbsctractSize.width(),
                m_AbsctractSize.height());



        QImage p = m_CachedImage.copy(ar);

        painter.drawImage(r, p);
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

    

    

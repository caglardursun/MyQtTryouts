    #pragma once
    #include <QWidget>
    #include <QImage>
    #include <QPainter>
    #include <QDebug>
    #include <QKeyEvent>
    #include <QMouseEvent>
    #include <QWheelEvent>
    #include "basewindow.h"

    // namespace Ui {
    //     class MainViewer;
    // }

    class MainViewer : public QWidget, public BaseWindow
    {
        Q_OBJECT

    public:
        explicit MainViewer(QWidget *parent,QString& filePath);
        ~MainViewer();
        QSize minimumSizeHint() const Q_DECL_OVERRIDE;
        QSize sizeHint() const Q_DECL_OVERRIDE;

    private:
            
        void SetRenderFocus(QRect rect);
        QString& m_filePath;

    protected:
        void keyPressEvent(QKeyEvent* event);
        void mousePressEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void wheelEvent(QWheelEvent *event);

        void paintEvent(QPaintEvent * event);

    private:
        QImage m_CachedImage;

        QRect m_RenderFocusZone;
        QSize m_AbsctractSize;
        QPoint m_OldPos;
        QColor m_backgroundColor;
        int m_x, m_y;
        float m_aspectRatio;
        float m_Zoom;
        bool m_bIsMouseDown;
    };



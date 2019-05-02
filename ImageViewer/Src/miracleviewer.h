#pragma once
#include <QLabel>
#include <QWidget>
#include <QPaintEvent>

#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>


class MiracleViewer : public QWidget
{
    Q_OBJECT
    private:                
        QImageReader* m_pImageReader;
        //Zoom etc.
        double scaleFactor;
        QPoint m_OldPos;
        QPoint m_NewPos;
        QRect m_RenderFocusZone;
        bool m_bIsMouseDown;
        int m_x, m_y;

    protected:
        void mousePressEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);        
        void mouseMoveEvent(QMouseEvent *event);
    public:
        MiracleViewer(QWidget* parent = 0);
        ~MiracleViewer();
        bool Load(QString& filePath);
        void paintEvent(QPaintEvent *event);
        double GetScaleFactor(){ return scaleFactor; }
        void SetScaleFactor(double d) { scaleFactor =d; }
};


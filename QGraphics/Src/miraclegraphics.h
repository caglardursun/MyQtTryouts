#pragma once

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>

class MiracleGraphics : public QGraphicsView
{
    Q_OBJECT
    private:
        /* data */        
    private:
        QGraphicsScene* m_scene;
        QGraphicsPixmapItem* m_imageItem;
        //qreal m_rScaleFactor;
    public:
        MiracleGraphics(QWidget* parent);
        ~MiracleGraphics();
        void Load(QString& filePath);
        int ActualWidth;
        int ActualHeight;
    protected:
        void wheelEvent(QWheelEvent* event);     
};


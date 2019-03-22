#include "renderarea.h"
#include <QObject>
#include <QPaintEvent>
#include <QPainter>




    
RenderArea::RenderArea(QWidget *parent) 
        : QWidget(parent),
        m_backgroundColor(0,0,255),
        m_shapeColor(255,255,255)
{

}

void RenderArea::paintEvent(QPaintEvent* event)
{
        QPainter painter(this);
        painter.setBrush(m_backgroundColor);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(m_shapeColor);
        painter.drawRect(this->rect());
        painter.drawLine(this->rect().topLeft() , this->rect().bottomRight());
}

QSize RenderArea::minimumSizeHint() const
{
        return QSize(100,100);
}

QSize RenderArea::sizeHint() const
{
        return QSize(400,100);
}


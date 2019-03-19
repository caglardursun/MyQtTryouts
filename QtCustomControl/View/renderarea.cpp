#include "renderarea.h"
#include <QObject>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>



RenderArea::RenderArea(QWidget *parent) 
	: QWidget(parent)
{

}

void RenderArea::paintEvent(QPaintEvent* event)
{
    
	QPainter painter(this);
    painter.setBrush(QColor(0,0,0));
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRect(this->rect());
    
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100,100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400,100);
}

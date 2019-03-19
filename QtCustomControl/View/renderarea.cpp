#include "renderarea.h"
#include <QObject>
#include <QPaintEvent>



RenderArea::RenderArea(QWidget *parent) 
	: QWidget(parent)
{

}

void RenderArea::paintEvent(QPaintEvent* event)
{
    
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100,100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400,100);
}
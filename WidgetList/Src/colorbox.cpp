#include "colorbox.h"
#include <QObject>
#include <QPaintEvent>
#include <QPainter>

ColorBox::ColorBox(QWidget *parent)
    : QWidget(parent),
    m_backgroundColor(0,0,255),
    m_foregroundColor(255,255,255)
{

}
void ColorBox::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setBrush(m_backgroundColor);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(m_foregroundColor);

    QPainterPath path;
    path.addRoundedRect(rect(), 10, 10);
    
    painter.fillPath(path, Qt::red);
    painter.drawPath(path);

    //painter.drawRect(this->rect());
    // painter.drawLine(this->rect().topLeft() , this->rect().bottomRight());
    // QString msg("%1/%2/%3");
    // msg = msg.arg(m_backgroundColor.red()).arg(m_backgroundColor.green()).arg(m_backgroundColor.blue());
    // painter.drawText(QPoint(0,0),msg);
}

void ColorBox::setColor(QColor &color)
{
    m_backgroundColor = color;
}

QSize ColorBox::minimumSizeHint() const
{
        return QSize(100,100);
}

QSize ColorBox::sizeHint() const
{
        return QSize(350,100);
}

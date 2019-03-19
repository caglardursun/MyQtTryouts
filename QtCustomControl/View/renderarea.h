#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QObject>
#include <QWidget>


class QPainter;

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
signals:

public slots:
        
};

#endif // RENDERAREA_H
#ifndef COLORBOX_H
#define COLORBOX_H

#include <QWidget>
#include <QObject>
#include <QColor>

//Take a look @ https://github.com/caglardursun/MyQtTryouts/blob/master/QtCustomControl/View/renderarea.h

class ColorBox : public QWidget
{
    Q_OBJECT
public:
    explicit ColorBox(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    void setColor(QColor& color);
protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

private:
    QColor m_backgroundColor;
    QColor m_foregroundColor;

signals:

public slots:
};

#endif // COLORBOX_H

#ifndef THEWIDGETITEM_H
#define THEWIDGETITEM_H

#include <QWidget>
#include <QColor>
#include "colorbox.h"

namespace Ui {
    class thewidgetitem;
}

class thewidgetitem : public QWidget
{
    Q_OBJECT

public:
    explicit thewidgetitem(QWidget *parent = nullptr);
    ~thewidgetitem();
    void SetColor(QColor& color);

private:
    Ui::thewidgetitem *ui;

};

#endif // THEWIDGETITEM_H

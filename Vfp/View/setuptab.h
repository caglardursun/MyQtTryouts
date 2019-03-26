#pragma once
#include <QWidget>

namespace Ui {
class SetupTab;
}

namespace Ps {

    class SetupTab : public QWidget
    {
        Q_OBJECT

    public:
        explicit SetupTab(QWidget *parent = nullptr);
        ~SetupTab();


    private:
        Ui::SetupTab *ui;
    };

}



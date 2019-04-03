#pragma once

#include <QObject>
#include <QToolBar>

namespace Miracle {

    class ToolBar : public  QToolBar
    {
        Q_OBJECT
        private:
            QMenu *m_Menu;
        public:
            ToolBar(const QString& title, QWidget* parent);
            ~ToolBar();
    };
}

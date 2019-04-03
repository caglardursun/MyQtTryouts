#include "toolbar.h"

#include <QMainWindow>
#include <QMenu>
#include <QPainter>
#include <QPainterPath>
#include <QSpinBox>
#include <QLabel>
#include <QToolTip>

namespace Miracle
{

  

    ToolBar::ToolBar(const QString& title, QWidget* parent)
        :QToolBar(parent)
    {
        setWindowTitle(title);
        setObjectName(title);
        //32 * 32 px icon
        setIconSize(QSize(32,32));

        //devicePixelRatioF comes from Q_OBJECT moc
        qreal dpr = devicePixelRatioF();
        m_Menu = new QMenu("One 4 Real", this);
        //m_Menu->setIcon(genIcon(iconSize(), 1, Qt::black, dpr));
        //m_Menu->setIcon(genIcon(iconSize(), 1, Qt::black, dpr));
        
        //addAction(menu->menuAction());
    }

    ToolBar::~ToolBar()
    {
    }    

    // void MainWindow::setupMenuBar()
    // {
    //     QMenu *menu = menuBar()->addMenu(tr("&File"));

    //     menu->addAction(tr("Save layout..."), this, &MainWindow::saveLayout);
    //     menu->addAction(tr("Load layout..."), this, &MainWindow::loadLayout);
    //     menu->addAction(tr("Switch layout direction"),this, &MainWindow::switchLayoutDirection);

    //     menu->addSeparator();
    //     menu->addAction(tr("&Quit"), this, &QWidget::close);

    //     mainWindowMenu = menuBar()->addMenu(tr("Main window"));
    // }

} // Miracle
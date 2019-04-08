#pragma once
#include <QWidget>

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include "basewindow.h"

// namespace Ui {
//     class MainViewer;
// }

class MainViewer : public QWidget
{
    Q_OBJECT

public:
    explicit MainViewer(QWidget *parent = 0);
    ~MainViewer();
    void Load(QString& str);

private:
    // Ui::MainViewer *ui;
    //QString& m_filePath;
        
    void SetRenderFocus(QRect rect);


protected:
    void keyPressEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent *event);

    void paintEvent(QPaintEvent * event);

private:
    QImage m_CachedImage;

    QRect m_RenderFocusZone;
    QSize m_AbsctractSize;
    QPoint m_OldPos;

    int m_x, m_y;
    float m_aspectRatio;
    float m_Zoom;
    bool m_bIsMouseDown;
};



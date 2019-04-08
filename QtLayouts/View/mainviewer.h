#pragma once
#include <QWidget>

namespace Ui {
    class MainViewer;
}

class MainViewer : public QWidget
{
    Q_OBJECT

public:
    explicit MainViewer(QWidget *parent = nullptr,QString& filePath = QString(""));
    ~MainViewer();

private:
    Ui::MainViewer *ui;
    QString& m_filePath;
};



#include "View/mainview.h"
#include "ui_mainview.h"
#include "View/setuptab.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    auto setup_tab = new SetupTab(this);
    ui->loSetupTab->addWidget(setup_tab);
}

MainView::~MainView()
{
    delete ui;
}

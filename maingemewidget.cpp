#include "maingemewidget.h"
#include "./ui_maingemewidget.h"

MainGameWidget::MainGameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGemeWidget)
{
    ui->setupUi(this);
}

MainGameWidget::~MainGameWidget()
{
    delete ui;
}


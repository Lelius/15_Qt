#include "maingemewidget.h"
#include "./ui_maingemewidget.h"

MainGemeWidget::MainGemeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGemeWidget)
{
    ui->setupUi(this);
}

MainGemeWidget::~MainGemeWidget()
{
    delete ui;
}


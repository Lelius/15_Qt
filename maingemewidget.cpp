#include "maingemewidget.h"
#include "./ui_maingemewidget.h"

#include <QGraphicsPixmapItem>
#include <QMouseEvent>

MainGameWidget::MainGameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGemeWidget)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    pixmapBox =  scene->addPixmap(QPixmap(":/image/box.png"));
    pixmapBox->setOffset(QPointF(0, 0));
    pixmapRestartButton = scene->addPixmap(QPixmap(":/image/reset.png"));
    pixmapRestartButton->setOffset(QPointF(0, 445));
    pixmapQuitButton = scene->addPixmap(QPixmap(":/image/X3.png"));
    pixmapQuitButton->setOffset(QPointF(333, 445));

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

}

MainGameWidget::~MainGameWidget()
{
    delete ui;
}


void MainGameWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (pixmapQuitButton->contains(event->pos()))
            MainGameWidget::close();
    }
    else
    {
        MainGameWidget::mousePressEvent(event);
    }
}

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
    pixmapRestartButton = scene->addPixmap(QPixmap(":/image/reset.png"));
    pixmapQuitButton = scene->addPixmap(QPixmap(":/image/X3.png"));
    pixmap_1_chip = scene->addPixmap(QPixmap(":/image/1_chip.png"));
    pixmap_2_chip = scene->addPixmap(QPixmap(":/image/2_chip.png"));
    pixmap_3_chip = scene->addPixmap(QPixmap(":/image/3_chip.png"));
    pixmap_4_chip = scene->addPixmap(QPixmap(":/image/4_chip.png"));
    pixmap_5_chip = scene->addPixmap(QPixmap(":/image/5_chip.png"));
    pixmap_6_chip = scene->addPixmap(QPixmap(":/image/6_chip.png"));
    pixmap_7_chip = scene->addPixmap(QPixmap(":/image/7_chip.png"));
    pixmap_8_chip = scene->addPixmap(QPixmap(":/image/8_chip.png"));
    pixmap_9_chip = scene->addPixmap(QPixmap(":/image/9_chip.png"));
    pixmap_10_chip = scene->addPixmap(QPixmap(":/image/10_chip.png"));
    pixmap_11_chip = scene->addPixmap(QPixmap(":/image/11_chip.png"));
    pixmap_12_chip = scene->addPixmap(QPixmap(":/image/12_chip.png"));
    pixmap_13_chip = scene->addPixmap(QPixmap(":/image/13_chip.png"));
    pixmap_14_chip = scene->addPixmap(QPixmap(":/image/14_chip.png"));
    pixmap_15_chip = scene->addPixmap(QPixmap(":/image/15_chip.png"));
    pixmapWellBlack = scene->addPixmap(QPixmap(":/image/well-black_380x350.png"));
    pixmapWellWhite = scene->addPixmap(QPixmap(":/image/well-white_380x350.png"));

    pixmapBox->setOffset(QPointF(0, 0));
    pixmapRestartButton->setOffset(QPointF(0, 445));
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

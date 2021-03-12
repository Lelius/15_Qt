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
    boxWithChips = new BoxWithChips(4);
    initPixmaps();

    pixmapItems["box"] = scene->addPixmap(pixmaps["box"]);
    pixmapItems["restartButton"] = scene->addPixmap(pixmaps["restartButton"]);
    pixmapItems["quitButton"] = scene->addPixmap(pixmaps["quitButton"]);

    pixmapItems["box"]->setOffset(QPointF(0, 0));
    pixmapItems["restartButton"]->setOffset(QPointF(0, 445));
    pixmapItems["quitButton"]->setOffset(QPointF(333, 445));

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

}

MainGameWidget::~MainGameWidget()
{
    delete boxWithChips;
    delete ui;
}


void MainGameWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (pixmapItems["quitButton"]->contains(event->pos()))
            MainGameWidget::close();
    }
    else
    {
        MainGameWidget::mousePressEvent(event);
    }
}


void MainGameWidget::initPixmaps()
{
    pixmaps["box"] = QPixmap(":/image/box.png");
    pixmaps["restartButton"] = QPixmap(":/image/reset.png");
    pixmaps["quitButton"] = QPixmap(":/image/X3.png");
    pixmaps["1_chip"] = QPixmap(":/image/1_chip.png");
    pixmaps["2_chip"] = QPixmap(":/image/2_chip.png");
    pixmaps["3_chip"] = QPixmap(":/image/3_chip.png");
    pixmaps["4_chip"] = QPixmap(":/image/4_chip.png");
    pixmaps["5_chip"] = QPixmap(":/image/5_chip.png");
    pixmaps["6_chip"] = QPixmap(":/image/6_chip.png");
    pixmaps["7_chip"] = QPixmap(":/image/7_chip.png");
    pixmaps["8_chip"] = QPixmap(":/image/8_chip.png");
    pixmaps["9_chip"] = QPixmap(":/image/9_chip.png");
    pixmaps["10_chip"] = QPixmap(":/image/10_chip.png");
    pixmaps["11_chip"] = QPixmap(":/image/11_chip.png");
    pixmaps["12_chip"] = QPixmap(":/image/12_chip.png");
    pixmaps["13_chip"] = QPixmap(":/image/13_chip.png");
    pixmaps["14_chip"] = QPixmap(":/image/14_chip.png");
    pixmaps["15_chip"] = QPixmap(":/image/15_chip.png");
    pixmaps["wellBlack"] = QPixmap(":/image/well-black_380x350.png");
    pixmaps["wellWhite"] = QPixmap(":/image/well-white_380x350.png");

}

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
    addPixmapItems();
    isVisibleWellBlack = false;
    isVisibleWellWhite = false;

    boxWithChips->randomChips();
    updateGraphicsScene();

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


void MainGameWidget::updateGraphicsScene()
{
    setOffsetMainItems();

    isVisibleWellBlack ? pixmapItems["wellBlack"]->show() : pixmapItems["wellBlack"]->hide();
    isVisibleWellBlack ? pixmapItems["wellWhite"]->show() : pixmapItems["wellWhite"]->hide();

    for (int j = 0; j < boxWithChips->getYNum(); j++){
        for (int i = 0; i < boxWithChips->getXNum(); i++){
            int numberChip = boxWithChips->getBoxWithChips()[i + (j * boxWithChips->getXNum())];
            if (numberChip == 0)
                break;
            QString nameItem = QString::number(numberChip) + "_chip";
            pixmapItems[nameItem]->setOffset(QPointF((qreal) 15 + (105 * i), (qreal) 15 + (105 * j)));
        }
    }
}


void MainGameWidget::setOffsetMainItems()
{
    pixmapItems["box"]->setOffset(QPointF((qreal) 0, (qreal) 0));
    pixmapItems["restartButton"]->setOffset(QPointF((qreal) 0, (qreal) 445));
    pixmapItems["quitButton"]->setOffset(QPointF((qreal) 333, (qreal) 445));
}


void MainGameWidget::addPixmapItems()
{
    pixmapItems["box"] = scene->addPixmap(pixmaps["box"]);
    pixmapItems["restartButton"] = scene->addPixmap(pixmaps["restartButton"]);
    pixmapItems["quitButton"] = scene->addPixmap(pixmaps["quitButton"]);
    pixmapItems["1_chip"] = scene->addPixmap(pixmaps["1_chip"]);
    pixmapItems["2_chip"] = scene->addPixmap(pixmaps["2_chip"]);
    pixmapItems["3_chip"] = scene->addPixmap(pixmaps["3_chip"]);
    pixmapItems["4_chip"] = scene->addPixmap(pixmaps["4_chip"]);
    pixmapItems["5_chip"] = scene->addPixmap(pixmaps["5_chip"]);
    pixmapItems["6_chip"] = scene->addPixmap(pixmaps["6_chip"]);
    pixmapItems["7_chip"] = scene->addPixmap(pixmaps["7_chip"]);
    pixmapItems["8_chip"] = scene->addPixmap(pixmaps["8_chip"]);
    pixmapItems["9_chip"] = scene->addPixmap(pixmaps["9_chip"]);
    pixmapItems["10_chip"] = scene->addPixmap(pixmaps["10_chip"]);
    pixmapItems["11_chip"] = scene->addPixmap(pixmaps["11_chip"]);
    pixmapItems["12_chip"] = scene->addPixmap(pixmaps["12_chip"]);
    pixmapItems["13_chip"] = scene->addPixmap(pixmaps["13_chip"]);
    pixmapItems["14_chip"] = scene->addPixmap(pixmaps["14_chip"]);
    pixmapItems["15_chip"] = scene->addPixmap(pixmaps["15_chip"]);
    pixmapItems["wellBlack"] = scene->addPixmap(pixmaps["wellBlack"]);
    pixmapItems["wellWhite"] = scene->addPixmap(pixmaps["wellWhite"]);
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

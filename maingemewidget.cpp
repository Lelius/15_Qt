#include "maingemewidget.h"
#include "./ui_maingemewidget.h"
#include "keypressfilter.h"

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

    startNewGameScene();

    ui->graphicsView->setScene(scene);
    KeyPressFilter *keyPressFilter = new KeyPressFilter(ui->graphicsView);
    ui->graphicsView->installEventFilter(keyPressFilter);
    connect(keyPressFilter, &KeyPressFilter::keyPressSignal, this, &MainGameWidget::keyPressArrows);
    ui->graphicsView->show();
}

MainGameWidget::~MainGameWidget()
{
    delete boxWithChips;
    delete ui;
}


void MainGameWidget::keyPressArrows(int arrow)
{
    switch (arrow) {
    case Qt::Key_Left:
        boxWithChips->toTheLeftChip();
        break;
    case Qt::Key_Right:
        boxWithChips->toTheRightChip();
        break;
    case Qt::Key_Up:
        boxWithChips->toTheUpChip();
        break;
    case Qt::Key_Down:
        boxWithChips->toTheBottomChip();
        break;
    default:
        break;
    }
    setOffsetChipsItems();
}


void MainGameWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
        boxWithChips->toTheLeftChip();
        break;
    case Qt::Key_D:
        boxWithChips->toTheRightChip();
        break;
    case Qt::Key_W:
        boxWithChips->toTheUpChip();
        break;
    case Qt::Key_S:
        boxWithChips->toTheBottomChip();
        break;
    default:
        break;
    }
    setOffsetChipsItems();
}


void MainGameWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (pixmapItems["quitButton"]->contains(event->pos()))
            MainGameWidget::close();
        if (pixmapItems["restartButton"]->contains(event->pos())){
            boxWithChips->randomChips();
        }
        for (int i = 0; i < 15; i++){
            QString numbChip = QString::number(i + 1) + "_chip";
            if (pixmapItems[numbChip]->contains(event->pos())){
                //
                int posEmpty = boxWithChips->getPosEmptyPlace();
                int posChip = boxWithChips->getPosChip(i + 1);

                if (posEmpty == (posChip - 1)){
                    boxWithChips->toTheLeftChip();
                }
                if (posEmpty == (posChip + 1)){
                    boxWithChips->toTheRightChip();
                }
                if (posEmpty == (posChip - boxWithChips->getXNum())){
                    boxWithChips->toTheUpChip();
                }
                if (posEmpty == (posChip + boxWithChips->getXNum())){
                    boxWithChips->toTheBottomChip();
                }
            }
        }
        setOffsetChipsItems();
    }
    /*else
    {
        MainGameWidget::mousePressEvent(event);
    }*/
}


void MainGameWidget::startNewGameScene()
{
    setOffsetMainItems();
    boxWithChips->randomChips();
    setOffsetChipsItems();
    pixmapItems["wellBlack"]->hide();
    pixmapItems["wellWhite"]->hide();
}


void MainGameWidget::setOffsetChipsItems()
{
    for (int j = 0; j < boxWithChips->getYNum(); j++){
        for (int i = 0; i < boxWithChips->getXNum(); i++){
            int numberChip = boxWithChips->getBoxWithChips()[i + (j * boxWithChips->getXNum())];
            if (numberChip == 0)
                continue;
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
    pixmapItems["wellBlack"]->setOffset(QPointF((qreal) 35, (qreal) 45));
    pixmapItems["wellWhite"]->setOffset(QPointF((qreal) 35, (qreal) 45));
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

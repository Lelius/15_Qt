#ifndef MAINGEMEWIDGET_H
#define MAINGEMEWIDGET_H

#include <QWidget>
#include <QGraphicsPixmapItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainGemeWidget; }
QT_END_NAMESPACE

class MainGameWidget : public QWidget
{
    Q_OBJECT

public:
    MainGameWidget(QWidget *parent = nullptr);
    ~MainGameWidget();

    void mousePressEvent(QMouseEvent *);

private:
    Ui::MainGemeWidget *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapBox;
    QGraphicsPixmapItem *pixmapRestartButton;
    QGraphicsPixmapItem *pixmapQuitButton;
    QGraphicsPixmapItem *pixmap_1_chip;
    QGraphicsPixmapItem *pixmap_2_chip;
    QGraphicsPixmapItem *pixmap_3_chip;
    QGraphicsPixmapItem *pixmap_4_chip;
    QGraphicsPixmapItem *pixmap_5_chip;
    QGraphicsPixmapItem *pixmap_6_chip;
    QGraphicsPixmapItem *pixmap_7_chip;
    QGraphicsPixmapItem *pixmap_8_chip;
    QGraphicsPixmapItem *pixmap_9_chip;
    QGraphicsPixmapItem *pixmap_10_chip;
    QGraphicsPixmapItem *pixmap_11_chip;
    QGraphicsPixmapItem *pixmap_12_chip;
    QGraphicsPixmapItem *pixmap_13_chip;
    QGraphicsPixmapItem *pixmap_14_chip;
    QGraphicsPixmapItem *pixmap_15_chip;
    QGraphicsPixmapItem *pixmapWellBlack;
    QGraphicsPixmapItem *pixmapWellWhite;
};
#endif // MAINGEMEWIDGET_H

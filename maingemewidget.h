#ifndef MAINGEMEWIDGET_H
#define MAINGEMEWIDGET_H

#include "BoxWithChips.h"

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainGemeWidget; }
QT_END_NAMESPACE

class MainGameWidget : public QWidget
{
    Q_OBJECT

public:
    MainGameWidget(QWidget *parent = nullptr);
    ~MainGameWidget();

    void initPixmaps();
    void addPixmapItems();
    void setOffsetMainItems();
    void setOffsetChipsItems();
    void startNewGameScene();

protected:
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyPressArrows(int);

private:
    Ui::MainGemeWidget *ui;
    QGraphicsScene *scene;
    QMap<QString, QPixmap> pixmaps;
    QMap<QString, QGraphicsPixmapItem *> pixmapItems;
    BoxWithChips *boxWithChips;
};
#endif // MAINGEMEWIDGET_H

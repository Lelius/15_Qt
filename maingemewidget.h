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
};
#endif // MAINGEMEWIDGET_H

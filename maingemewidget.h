#ifndef MAINGEMEWIDGET_H
#define MAINGEMEWIDGET_H

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

    void mousePressEvent(QMouseEvent *);
    void initPixmaps();

private:
    Ui::MainGemeWidget *ui;
    QGraphicsScene *scene;
    QMap<QString, QPixmap> pixmaps;
    QMap<QString, QGraphicsPixmapItem *> pixmapItems;
};
#endif // MAINGEMEWIDGET_H

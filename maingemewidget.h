#ifndef MAINGEMEWIDGET_H
#define MAINGEMEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainGemeWidget; }
QT_END_NAMESPACE

class MainGameWidget : public QWidget
{
    Q_OBJECT

public:
    MainGameWidget(QWidget *parent = nullptr);
    ~MainGameWidget();

private:
    Ui::MainGemeWidget *ui;
};
#endif // MAINGEMEWIDGET_H

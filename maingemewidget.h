#ifndef MAINGEMEWIDGET_H
#define MAINGEMEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainGemeWidget; }
QT_END_NAMESPACE

class MainGemeWidget : public QWidget
{
    Q_OBJECT

public:
    MainGemeWidget(QWidget *parent = nullptr);
    ~MainGemeWidget();

private:
    Ui::MainGemeWidget *ui;
};
#endif // MAINGEMEWIDGET_H

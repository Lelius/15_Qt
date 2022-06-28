#ifndef KEYPRESSFILTER_H
#define KEYPRESSFILTER_H

#include <QObject>

class KeyPressFilter : public QObject
{
    Q_OBJECT
public:
    explicit KeyPressFilter(QObject *parent = nullptr);

signals:
    void keyPressSignal(int);

protected:
    virtual bool eventFilter(QObject *, QEvent *);

};

#endif // KEYPRESSFILTER_H

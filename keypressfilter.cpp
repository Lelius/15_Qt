#include <QtWidgets>

#include "keypressfilter.h"

KeyPressFilter::KeyPressFilter(QObject *parent)
    : QObject{parent}
{

}


bool KeyPressFilter::eventFilter(QObject *ob, QEvent *ev)
{
    if (ev->type() == QEvent::KeyPress){
        if (static_cast<QKeyEvent *>(ev)->key() == Qt::Key_Left){
            emit keyPressSignal(Qt::Key_Left);
            return true;
        }
        if (static_cast<QKeyEvent *>(ev)->key() == Qt::Key_Right){
            emit keyPressSignal(Qt::Key_Right);
            return true;
        }
        if (static_cast<QKeyEvent *>(ev)->key() == Qt::Key_Up){
            emit keyPressSignal(Qt::Key_Up);
            return true;
        }
        if (static_cast<QKeyEvent *>(ev)->key() == Qt::Key_Down){
            emit keyPressSignal(Qt::Key_Down);
            return true;
        }
        if (static_cast<QKeyEvent *>(ev)->key() == Qt::Key_Space){
            emit keyPressSignal(Qt::Key_Space);
            return true;
        }
        if (static_cast<QKeyEvent *>(ev)->key() == Qt::Key_Escape){
            emit keyPressSignal(Qt::Key_Escape);
            return true;
        }
        if (static_cast<QKeyEvent *>(ev)->key() == Qt::Key_Enter){
            emit keyPressSignal(Qt::Key_Enter);
            return true;
        }
        if (static_cast<QKeyEvent *>(ev)->key() == Qt::Key_Return){
            emit keyPressSignal(Qt::Key_Return);
            return true;
        }
    }
    return false;
}

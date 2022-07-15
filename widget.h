#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QGridLayout>

#include "box.h"

#include <ctime>
#include <iostream>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QGridLayout *layout;

    box boxes[9][9];

    QString randomColor_style();

    void changeColor();
};
#endif // WIDGET_H

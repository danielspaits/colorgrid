#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this -> setWindowTitle("Color grid");

    this -> layout = new QGridLayout(this);

    int x_position = 0, y_position = 0;

    for (int i = 0; i < 9; i ++)
    {
        for (int j = 0; j < 9; j ++)
        {
            boxes[i][j].setGeometry(50, 50, x_position, y_position);

            boxes[i][j].setProperty("row", i);
            boxes[i][j].setProperty("column", j);

            this -> layout -> addWidget(&boxes[i][j], i, j, 1, 1);

            connect(&boxes[i][j], &QPushButton::clicked, this, &Widget::changeColor);

            y_position += 50;
        }
        x_position += 50;
    }
}

Widget::~Widget()
{
}

QString Widget::randomColor_style()
{
    srand(time(0));

    int rand_r, rand_g, rand_b;

    rand_r = rand() % 255;
    rand_g = rand() % 255;
    rand_b = rand() % 255;

    QString color = "background-color: rgb(" + QString::number(rand_r) + ", " + QString::number(rand_g) + ", " + QString::number(rand_b) + ");";

    return color;
}

void Widget::changeColor ()
{
    int row = sender() -> property("row").toInt();
    int column = sender() -> property("column").toInt();

    for (int i = 0; i < 9; i ++)
        boxes[row][i].setStyleSheet(randomColor_style());

    for (int j = 0; j < 9; j ++)
        boxes[j][column].setStyleSheet(randomColor_style());
}

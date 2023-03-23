#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>

class Snake : public QWidget
{
    Q_OBJECT

public:
    Snake(QWidget *parent = nullptr);
    ~Snake();

protected:
    void keyPressEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    //board height and width
    static const int BOARD_H = 600;
    static const int BOARD_W = 600;

    //size of the dots and the amount of them
    static const int DOT_SIZE = 20;
    static const int DOTS_COUNT = 900;

    //used to calculate random position
    static const int RAND_POS = 29;

    int timerId;
    int timerDelay;

    //amount of body segments
    int segments;

    //QImage files for head, segments and apple
    QImage head;
    QImage body;
    QImage apple;

    //apple's x and y
    int apple_x;
    int apple_y;

    //x and y coords
    int x[DOTS_COUNT];
    int y[DOTS_COUNT];

    //direction enum and
    enum direction_enum
    {
        LEFT_DIRECTION,
        RIGHT_DIRECTION,
        UP_DIRECTION,
        DOWN_DIRECTION
    } direction = UP_DIRECTION;

    bool inGame = false;

    //functions
    void move();
    void doDrawing();
    void loadImages();
    void setApple();
    void hitApple();
    void checkCollisions();

};

#endif // SNAKE_H

#include "snake.h"
#include <iostream>
#include <QTime>
#include <cstdlib>

Snake::Snake(QWidget *parent) : QWidget(parent)
{
    //constructer
    inGame = true;

    //will be changed by the difficulty setting in main screen
    timerDelay = 100;

    //set the size of the window
    setFixedSize(BOARD_W, BOARD_H);

    //load the images
    head.load("nickhead.jpg");
    body.load("rainbow.jpg");
    apple.load("kitkat.jpg");

    //scale the images
    head = head.scaled(20,20);
    body = body.scaled(20,20);
    apple = apple.scaled(20,20);

    //starting segments
    segments = 3;

    //starting x and y coords
    for (int n = 0; n < segments; n++)
    {
        x[n] = 100 - n * 10;
        y[n] = 200;
    }

    //set the apple
    setApple();

    //start timer
    timerId = startTimer(timerDelay);
}

Snake::~Snake()
{
    //deconstructer
}

void Snake::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    doDrawing();
}

void Snake::doDrawing()
{
    QPainter qp(this);

    if (inGame)
    {
        qp.drawImage(apple_x,apple_y,apple);

        for (int n = 0; n < segments; n++)
        {
            if (n==0)
            {
                qp.drawImage(x[n],y[n],head);
            }
            else
            {
                qp.drawImage(x[n],y[n],body);
            }
        }
        printf("drawing\n");
    }
    else if(!inGame)
    {
        //draw end of game stuff
        QString message = "Game over";
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.horizontalAdvance(message);

        qp.setFont(font);
        int h = height();
        int w = width();

        qp.translate(QPoint(w/2, h/2));
        qp.drawText(-textWidth/2, 0, message);
    }

}

void Snake::loadImages()
{

    printf("Images load function\n");
}

void Snake::move() {

    for (int z = segments; z > 0; z--) {
        x[z] = x[(z - 1)];
        y[z] = y[(z - 1)];
    }

    switch(direction)
    {
        case LEFT_DIRECTION:
            x[0] -= DOT_SIZE;
            break;
        case RIGHT_DIRECTION:
            x[0] += DOT_SIZE;
            break;
        case UP_DIRECTION:
            y[0] -= DOT_SIZE;
            break;
        case DOWN_DIRECTION:
            y[0] += DOT_SIZE;
            break;
    }
    printf("move\n");

}

void Snake::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    if (inGame)
    {

        hitApple();
        checkCollisions();
        move();
    }

    update();
}

void Snake::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();

    std::cout << key;
    printf(" <- key pressed\n");

    if ((key == Qt::Key_Left) && (direction != RIGHT_DIRECTION)) {
        direction = LEFT_DIRECTION;
    }

    if ((key == Qt::Key_Right) && (direction != LEFT_DIRECTION)) {
        direction = RIGHT_DIRECTION;
    }

    if ((key == Qt::Key_Up) && (direction != DOWN_DIRECTION)) {
        direction = UP_DIRECTION;
    }

    if ((key == Qt::Key_Down) && (direction != UP_DIRECTION)) {
        direction = DOWN_DIRECTION;
    }

    QWidget::keyPressEvent(e);
}

void Snake::setApple()
{
    QTime time = QTime::currentTime();
    srand((uint) time.msec());

    int r = rand() % RAND_POS;
    apple_x = (r * DOT_SIZE);

    r = rand() % RAND_POS;
    apple_y = (r * DOT_SIZE);
}

void Snake::hitApple()
{
    if ((x[0] == apple_x) && (y[0] == apple_y))
    {
        segments++;
        setApple();
    }
}

void Snake::checkCollisions()
{
    for (int z = segments; z > 0; z--) {

        if ((z > 4) && (x[0] == x[z]) && (y[0] == y[z])) {
            inGame = false;
        }
    }

    if (y[0] >= BOARD_H) {
        inGame = false;
    }

    if (y[0] < 0) {
        inGame = false;
    }

    if (x[0] >= BOARD_W) {
        inGame = false;
    }

    if (x[0] < 0) {
        inGame = false;
    }

    if(!inGame) {
        killTimer(timerId);
    }
}

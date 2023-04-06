#include "snake.h"
#include <iostream>
#include <QBackingStore>
#include <cstdlib>
#include "mainwindow.h"


Snake::Snake(QWidget *parent, Difficulty *diff, Players *pla) : QWidget(parent)
{
    //constructer
    inGame = true;

    //will be changed by the difficulty setting in main screen
    if (*diff == SLOW)
    {
        timerDelay = 70;
    }
    else if (*diff == HARD)
    {
        timerDelay = 150;
    }
    else
    {
        timerDelay = 100;
    }

    printf("did this work?");

    //set the size of the window
    setFixedSize(BOARD_W, BOARD_H);

    //load the images
    nickhead.load("nickhead.jpg");
    body.load("rainbow.jpg");
    apple.load("khadka-mahesh.jpg");
    matthead.load("matthead.jpg");

    //scale the images
    nickhead = nickhead.scaled(20,20);
    body = body.scaled(20,20);
    apple = apple.scaled(20,20);
    matthead = matthead.scaled(20,20);

    //starting nicksegments
    nicksegments = 3;

    //is it twoplayer?
    if (*pla == MULTIPLAYER)
    {
        twoplayer = true;
    }
    else
    {
        twoplayer = false;
    }

    //starting x and y coords
    for (int n = 0; n < nicksegments; n++)
    {
        nickx[n] = 500 - n * 10;
        nicky[n] = 200;
    }
    if (twoplayer == true)
    {
        mattsegments = 3;
        for (int n = 0; n < mattsegments; n++)
        {
            mattx[n] = 100 - n * 10;
            matty[n] = 200;
        }
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

    QPainter qp(this);

    if (inGame)
    {
        qp.drawImage(apple_x,apple_y,apple);

        for (int n = 0; n < nicksegments; n++)
        {
            if (n==0)
            {
                qp.drawImage(nickx[n],nicky[n],nickhead);
            }
            else
            {
                qp.drawImage(nickx[n],nicky[n],body);
            }
        }

        if (twoplayer == true)
        {
            for (int n = 0; n < mattsegments; n++)
            {
                if (n==0)
                {
                    qp.drawImage(mattx[n],matty[n],matthead);
                }
                else
                {
                    qp.drawImage(mattx[n],matty[n],body);
                }
            }
        }
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

        //close
        hide();
        MainWindow *win = new MainWindow;
        win->show();
    }
}

void Snake::move() {

    //move the segments
    for (int z = nicksegments; z > 0; z--)
    {
        nickx[z] = nickx[(z - 1)];
        nicky[z] = nicky[(z - 1)];
    }

    //find directions of the head.
    switch(nickdirection)
    {
        case LEFT_DIRECTION:
            nickx[0] -= DOT_SIZE;
            break;
        case RIGHT_DIRECTION:
            nickx[0] += DOT_SIZE;
            break;
        case UP_DIRECTION:
            nicky[0] -= DOT_SIZE;
            break;
        case DOWN_DIRECTION:
            nicky[0] += DOT_SIZE;
            break;
    }

    if (twoplayer == true)
    {
        for (int z = mattsegments; z > 0; z--) {
            mattx[z] = mattx[(z - 1)];
            matty[z] = matty[(z - 1)];
        }

        switch(mattdirection)
        {
            case LEFT_DIRECTION:
                mattx[0] -= DOT_SIZE;
                break;
            case RIGHT_DIRECTION:
                mattx[0] += DOT_SIZE;
                break;
            case UP_DIRECTION:
                matty[0] -= DOT_SIZE;
                break;
            case DOWN_DIRECTION:
                matty[0] += DOT_SIZE;
                break;
        }
    }

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

    if ((key == Qt::Key_Left) && (nickdirection != RIGHT_DIRECTION)) {
        nickdirection = LEFT_DIRECTION;
    }

    if ((key == Qt::Key_Right) && (nickdirection != LEFT_DIRECTION)) {
        nickdirection = RIGHT_DIRECTION;
    }

    if ((key == Qt::Key_Up) && (nickdirection != DOWN_DIRECTION)) {
        nickdirection = UP_DIRECTION;
    }

    if ((key == Qt::Key_Down) && (nickdirection != UP_DIRECTION)) {
        nickdirection = DOWN_DIRECTION;
    }

    if ((key == Qt::Key_A) && (mattdirection != RIGHT_DIRECTION)) {
        mattdirection = LEFT_DIRECTION;
    }

    if ((key == Qt::Key_D) && (mattdirection != LEFT_DIRECTION)) {
        mattdirection = RIGHT_DIRECTION;
    }

    if ((key == Qt::Key_W) && (mattdirection != DOWN_DIRECTION)) {
        mattdirection = UP_DIRECTION;
    }

    if ((key == Qt::Key_S) && (mattdirection != UP_DIRECTION)) {
        mattdirection = DOWN_DIRECTION;
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
    if ((nickx[0] == apple_x) && (nicky[0] == apple_y))
    {
        nicksegments++;
        setApple();
    }
    if (twoplayer == true)
    {
        if ((mattx[0] == apple_x) && (matty[0] == apple_y))
        {
            mattsegments++;
            setApple();
        }
    }
}

void Snake::checkCollisions()
{
    //check nick snake dying
    for (int z = nicksegments; z > 0; z--)
    {
        if (((z > 4) && ((nickx[0] == nickx[z])) && (nicky[0] == nicky[z])) || ((mattx[0] == nickx[z]) && (matty[0] == nicky[z])))
        {
            inGame = false;
        }
    }

    if ((nicky[0] >= BOARD_H) || (nicky[0] < 0) || (nickx[0] >= BOARD_W) || (nickx[0] < 0)) {
        inGame = false;
    }

    //check matt snake dying
    for (int z = mattsegments; z > 0; z--)
    {
        if ((z > 4) && (((mattx[0] == mattx[z]) && (matty[0] == matty[z])) || ((nickx[0] == mattx[z]) && (nicky[0] == matty[z]))))
        {
            inGame = false;
        }
    }

    if (((matty[0] < 0) || (matty[0] >= BOARD_H)) || ((mattx[0] < 0) || (mattx[0] >= BOARD_W)))
    {
        inGame = false;
    }

    if(!inGame) {
        killTimer(timerId);
    }
}

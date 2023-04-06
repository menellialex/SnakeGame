#include "mainwindow.h"
#include "snake.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //boots straight into the snake window
    //Snake window;
    //window.setWindowTitle("Shlippery Shlithering Shneaky Shnake");
    //window.show();

    MainWindow w;
    w.show();


    return a.exec();
}

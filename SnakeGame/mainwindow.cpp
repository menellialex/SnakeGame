#include "mainwindow.h"
#include "optionswindow.h"
#include "snake.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Difficulty diff = Slow;
    Players pla = SinglePlayer;

    this->difficultyLocation = &diff;
    this->playersLocation = &pla;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    //(new GameWindow(this))->show();
    Snake window(this, this->difficultyLocation, this->playersLocation);
    window.setWindowTitle("Shlippery Shlithering Shneaky Shnake");
    window.show();
}


void MainWindow::on_settingsButton_clicked()
{

}

void MainWindow::on_exitButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_4_clicked()
{

}


void MainWindow::on_optionsButton_clicked()
{
    (new OptionsWindow(this, this->difficultyLocation, this->playersLocation))->show();
}


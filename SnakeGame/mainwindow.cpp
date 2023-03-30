#include "mainwindow.h"
#include "optionswindow.h"
#include "gamewindow.h"
#include "ui_mainwindow.h"

Difficulty *difficultyLocation;
Players *playersLocation;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    (new GameWindow(this))->show();
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
    (new OptionsWindow(this, difficultyLocation, playersLocation))->show();
}


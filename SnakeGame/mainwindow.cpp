#include "mainwindow.h"
#include "optionswindow.h"
#include "snake.h"
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
   hide();
   OptionsWindow *ow = new OptionsWindow();
   ow->show();
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

}


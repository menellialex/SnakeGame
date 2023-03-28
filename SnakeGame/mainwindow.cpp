#include "mainwindow.h"
#include "optionsdialog.h"
#include "ui_gamewindow.h"
#include "ui_mainwindow.h"

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
    Ui::GameWindow gameWindow;
    gameWindow.setupUi(this);

}


void MainWindow::on_settingsButton_clicked()
{
    OptionsDialog dialogWindow;
    dialogWindow.exec();
}

void MainWindow::on_exitButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_4_clicked()
{

}






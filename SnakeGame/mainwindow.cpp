#include "mainwindow.h"
#include "optionswindow.h"
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
   hide();
   OptionsWindow *ow = new OptionsWindow();
   ow->show();
}



void MainWindow::on_exitButton_clicked()
{
    this->close();
}



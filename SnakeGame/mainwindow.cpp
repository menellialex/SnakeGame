#include "mainwindow.h"
#include "optionswindow.h"
#include "snake.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Sets default values for game settings in memory
    Difficulty diff = Slow;
    Players pla = SinglePlayer;

    //Keep track of the settings by assigning the memory locations to pointers
    this->difficultyLocation = &diff;
    this->playersLocation = &pla;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Button starts the game by creating new window and leaving the menu window
void MainWindow::on_startButton_clicked()
{
    //Creates
    Snake window(this, this->difficultyLocation, this->playersLocation);
    window.setWindowTitle("Shlippery Shlithering Shneaky Shnake");
    window.show();
}

//Opens new window for configuring and saving options
void MainWindow::on_optionsButton_clicked()
{
    (new OptionsWindow(this, this->difficultyLocation, this->playersLocation))->show();
}

//Closes menu window
void MainWindow::on_exitButton_clicked()
{
    this->close();
}

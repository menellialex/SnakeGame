#include "optionswindow.h"
#include "ui_optionswindow.h"
#include "snake.h"

OptionsWindow::OptionsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OptionsWindow)
{
    ui->setupUi(this);
}

OptionsWindow::~OptionsWindow()
{
    delete ui;
}


void OptionsWindow::on_playButton_clicked()
{
    Difficulty *diff = nullptr;
    Players *pla = nullptr;
    if(ui->radioButtonSlug->isChecked())
    {
        *diff = SLOW;
    }
    else if (ui->radioButtonPython->isChecked())
    {
        *diff = HARD;
    }
    else
    {
        *diff = MEDIUM;
    }

    if (ui->radioButtonMulti->isChecked())
    {
        *pla = MULTIPLAYER;
    }
    else
    {
        *pla = SINGLEPLAYER;
    }

    delete ui;
    hide();
    Snake *window = new Snake(this, diff, pla);
    window->setWindowTitle("Shlippery Shlithering Shneaky Shnake");
    window->show();
}


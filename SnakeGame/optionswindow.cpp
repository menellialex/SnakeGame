#include "optionswindow.h"
#include "ui_optionswindow.h"
#include <fstream>
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
    std::fstream file;
    file.open("options.config", std::ios::out);
    if(ui->radioButtonSlug->isChecked())
    {
        file << 1;
    }
    else if (ui->radioButtonPython->isChecked())
    {
        file << 2;
    }
    else
    {
        file << 3;
    }

    if (ui->radioButtonMulti->isChecked())
    {
        file << 2;
    }
    else
    {
        file << 1;
    }

    file.close();
    Snake *window = new Snake;
    window->activateWindow();
    window->setWindowTitle("Shlippery Shlithering Shneaky Shnake");
    window->show();
}


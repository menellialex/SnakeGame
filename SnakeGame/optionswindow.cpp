#include "optionswindow.h"
#include "ui_optionswindow.h"
#include <iostream>

OptionsWindow::OptionsWindow(QWidget *parent, Difficulty *diff, Players *pla) :
    QMainWindow(parent),
    ui(new Ui::OptionsWindow)
{
    ui->setupUi(this);
    this->diff = diff;
    this->pla = pla;

    //Sets the default radio button states based on what settings are remain in the proper memory locations

    //For difficulty
    switch (*this->diff)
    {
        case Slow:
            ui->radioButtonSlug->setChecked(true);
            break;
        case Medium:
            ui->radioButtonWorm->setChecked(true);
            break;
        case Fast:
            ui->radioButtonPython->setChecked(true);
            break;
        default:
            ui->radioButtonSlug->setChecked(true);
            break;
    }

    //For number of players
    switch (*this->pla)
    {
        case SinglePlayer:
            ui->radioButtonSingle->setChecked(true);
            break;
        case MultiPlayer:
            ui->radioButtonMulti->setChecked(true);
            break;
        default:
            ui->radioButtonSingle->setChecked(true);
            break;
    }
}

OptionsWindow::~OptionsWindow()
{
    delete ui;
}

void OptionsWindow::on_saveButton_clicked()
{
    //Check which difficulty button is checked
    //and stick the appropriate enum into the variable pointed to
    if(ui->radioButtonSlug->isChecked())
    {
        *this->diff = Slow;
    } else if (ui->radioButtonWorm->isChecked())
    {
        *this->diff = Medium;
    } else if (ui->radioButtonPython->isChecked())
    {
        *this->diff = Fast;
    } else
    {
        std::cout << "Difficulty Error";
        exit(1);
    }

    //Check which number of players button is checked
    //and stick the appropriate enum into the variable pointed to
    if(ui->radioButtonSingle->isChecked())
    {
        *this->pla = SinglePlayer;
    } else if (ui->radioButtonMulti->isChecked())
    {
        *this->pla = MultiPlayer;
    } else
    {
        std::cout << "Players Error";
        exit(1);
    }

    //Close options window after saving
    this->close();
}

void OptionsWindow::on_exitButton_clicked()
{
    this->close();
}

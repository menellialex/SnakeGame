#include "optionswindow.h"
#include "ui_optionswindow.h"

OptionsWindow::OptionsWindow(QWidget *parent, Difficulty *diff, Players *pla) :
    QMainWindow(parent),
    ui(new Ui::OptionsWindow)
{
    ui->setupUi(this);
    this->diff = diff;
    this->pla = pla;
}

OptionsWindow::~OptionsWindow()
{
    delete ui;
}

void OptionsWindow::on_pushButton_clicked()
{
    delete ui;
}


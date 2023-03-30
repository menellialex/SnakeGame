#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include "snakeEnums.h"
#include <QMainWindow>

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OptionsWindow(QWidget *parent = nullptr, Difficulty *diff = nullptr, Players *pla = nullptr);
    ~OptionsWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OptionsWindow *ui;
    Difficulty *diff;
    Players *pla;
};

#endif // OPTIONSWINDOW_H

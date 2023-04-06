#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QMainWindow>
#include <QApplication>

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QMainWindow
{
    Q_OBJECT

public:
    OptionsWindow(QWidget *parent = nullptr);
    ~OptionsWindow();

private slots:
    void on_playButton_clicked();

private:
    Ui::OptionsWindow *ui;
};

#endif // OPTIONSWINDOW_H

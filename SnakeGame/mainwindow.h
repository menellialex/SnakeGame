#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "snakeEnums.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_exitButton_clicked();

    void on_startButton_clicked();

    void on_settingsButton_clicked();

    void on_optionsButton_clicked();

private:
    Ui::MainWindow *ui;
    Difficulty *difficultyLocation;
    Players *playersLocation;
};
#endif // MAINWINDOW_H

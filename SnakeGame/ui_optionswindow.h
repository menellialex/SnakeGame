/********************************************************************************
** Form generated from reading UI file 'optionswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWINDOW_H
#define UI_OPTIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButtonSlug;
    QRadioButton *radioButtonWorm;
    QRadioButton *radioButtonPython;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonSingle;
    QRadioButton *radioButtonMulti;
    QHBoxLayout *horizontalLayout;
    QPushButton *playButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *playersGroup;
    QButtonGroup *difficultyGroup;

    void setupUi(QMainWindow *OptionsWindow)
    {
        if (OptionsWindow->objectName().isEmpty())
            OptionsWindow->setObjectName("OptionsWindow");
        OptionsWindow->resize(380, 240);
        OptionsWindow->setMinimumSize(QSize(380, 240));
        OptionsWindow->setMaximumSize(QSize(380, 259));
        OptionsWindow->setContextMenuPolicy(Qt::PreventContextMenu);
        OptionsWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));
        centralwidget = new QWidget(OptionsWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setEnabled(true);
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        radioButtonSlug = new QRadioButton(centralwidget);
        difficultyGroup = new QButtonGroup(OptionsWindow);
        difficultyGroup->setObjectName("difficultyGroup");
        difficultyGroup->addButton(radioButtonSlug);
        radioButtonSlug->setObjectName("radioButtonSlug");
        radioButtonSlug->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(radioButtonSlug);

        radioButtonWorm = new QRadioButton(centralwidget);
        difficultyGroup->addButton(radioButtonWorm);
        radioButtonWorm->setObjectName("radioButtonWorm");

        verticalLayout->addWidget(radioButtonWorm);

        radioButtonPython = new QRadioButton(centralwidget);
        difficultyGroup->addButton(radioButtonPython);
        radioButtonPython->setObjectName("radioButtonPython");

        verticalLayout->addWidget(radioButtonPython);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        radioButtonSingle = new QRadioButton(centralwidget);
        playersGroup = new QButtonGroup(OptionsWindow);
        playersGroup->setObjectName("playersGroup");
        playersGroup->addButton(radioButtonSingle);
        radioButtonSingle->setObjectName("radioButtonSingle");

        verticalLayout_2->addWidget(radioButtonSingle);

        radioButtonMulti = new QRadioButton(centralwidget);
        playersGroup->addButton(radioButtonMulti);
        radioButtonMulti->setObjectName("radioButtonMulti");

        verticalLayout_2->addWidget(radioButtonMulti);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(playButton);


        verticalLayout_3->addLayout(horizontalLayout);

        OptionsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OptionsWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 380, 26));
        OptionsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(OptionsWindow);
        statusbar->setObjectName("statusbar");
        OptionsWindow->setStatusBar(statusbar);

        retranslateUi(OptionsWindow);
        QObject::connect(playButton, &QPushButton::clicked, OptionsWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(OptionsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OptionsWindow)
    {
        OptionsWindow->setWindowTitle(QCoreApplication::translate("OptionsWindow", "Options", nullptr));
        label->setText(QCoreApplication::translate("OptionsWindow", "Difficulty Modes", nullptr));
        label_2->setText(QCoreApplication::translate("OptionsWindow", "--------------------------", nullptr));
        radioButtonSlug->setText(QCoreApplication::translate("OptionsWindow", "Slug (slowest)", nullptr));
        radioButtonWorm->setText(QCoreApplication::translate("OptionsWindow", "Worm (medium)", nullptr));
        radioButtonPython->setText(QCoreApplication::translate("OptionsWindow", "Python (fastest)", nullptr));
        radioButtonSingle->setText(QCoreApplication::translate("OptionsWindow", "Single Player", nullptr));
        radioButtonMulti->setText(QCoreApplication::translate("OptionsWindow", "Multi-Player", nullptr));
        playButton->setText(QCoreApplication::translate("OptionsWindow", "Play!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsWindow: public Ui_OptionsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWINDOW_H

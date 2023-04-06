QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    optionswindow.cpp \
    snake.cpp

HEADERS += \
    gamewindow.h \
    mainwindow.h \
    optionswindow.h \
    snake.h \
    snakeEnums.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui \
    optionswindow.ui

RESOURCES += \
    nickhead.jpg \
    kitkat.jpg \
    rainbow.jpg \
    matthead.jpg \
    khadka-mahesh.jpg

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

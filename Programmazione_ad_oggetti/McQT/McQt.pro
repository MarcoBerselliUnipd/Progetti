#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T15:42:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = McQt
TEMPLATE = app
CONFIG += c++11
CONFIG += terminal

SOURCES += main.cpp\
        mainwindow.cpp \
    acqua.cpp \
    birra.cpp \
    hamburger.cpp \
    maccarne.cpp \
    macvegetariano.cpp \
    menu.cpp \
    panino.cpp \
    prodotto.cpp \
    scontrino.cpp \
    toast.cpp \
    vegetariano.cpp \
    bibita.cpp \
    patatina.cpp \
    controller.cpp

HEADERS  += mainwindow.h \
    acqua.h \
    birra.h \
    hamburger.h \
    maccarne.h \
    macvegetariano.h \
    menu.h \
    panino.h \
    prodotto.h \
    scontrino.h \
    toast.h \
    vegetariano.h \
    bibita.h \
    patatina.h \
    controller.h

FORMS    += mainwindow.ui

RESOURCES += \
    immagini.qrc

DISTFILES +=

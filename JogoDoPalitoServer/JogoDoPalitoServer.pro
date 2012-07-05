#-------------------------------------------------
#
# Project created by QtCreator 2012-07-04T21:04:59
#
#-------------------------------------------------

QT       += core gui network

TARGET = JogoDoPalitoServer
TEMPLATE = app


SOURCES += main.cpp\
        serverwindow.cpp \
    player.cpp \
    basketserver.cpp

HEADERS  += serverwindow.h \
    player.h \
    basketserver.h

FORMS    += serverwindow.ui

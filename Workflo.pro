#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T19:05:54
#
#-------------------------------------------------

QT       += core gui qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Workflo
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    screenlock.cpp \
    screenlockdisplay.cpp \
    activitysequence.cpp \
    activity.cpp

HEADERS  += mainwindow.h \
    screenlock.h \
    screenlockdisplay.h \
    activitysequence.h \
    activity.h \
    jsonpersistence.h

DEFINES += "TIME_BASE=60000"

RESOURCES += \
    qml.qrc

DISTFILES += \
    example-file.json

#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T19:05:54
#
#-------------------------------------------------

QT       += core gui qml quick widgets

TARGET = Workflo
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    screenlock.cpp \
    screenlockdisplay.cpp \
    activitysequence.cpp \
    activity.cpp \
    activitymodel.cpp

HEADERS  += mainwindow.h \
    screenlock.h \
    screenlockdisplay.h \
    activitysequence.h \
    activity.h \
    jsonpersistence.h \
    activitymodel.h

DEFINES += TIME_BASE=60000
DEFINES += SW_VERSION=\\\"3.0.1\\\"

RESOURCES += \
    qml.qrc

DISTFILES += \
    example-file.json

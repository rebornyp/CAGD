#-------------------------------------------------
#
# Project created by QtCreator 2017-02-18T14:24:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicFinalWork
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        dialog.cpp \
    surfacepart.cpp \
    curvemainwindow.cpp \
    curve.cpp \
    info.cpp \
    basicfuncwindows.cpp \
    point.cpp \
    sfmainwindow.cpp \
    surfaceinfo.cpp

HEADERS  += dialog.h \
    surfacepart.h \
    curvemainwindow.h \
    curve.h \
    info.h \
    basicfuncwindows.h \
    point.h \
    sfmainwindow.h \
    surfaceinfo.h

FORMS    += dialog.ui \
    surfacepart.ui \
    curvemainwindow.ui \
    curve.ui \
    basicfuncwindows.ui \
    sfmainwindow.ui

RESOURCES += \
    res.qrc

QT += opengl

RC_FILE = app.rc

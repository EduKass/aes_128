TEMPLATE = app
TARGET = gui_aes

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    aes.cpp \
    gui_app.cpp \
    main.cpp

HEADERS += \
    aes.h \
    gui_app.h

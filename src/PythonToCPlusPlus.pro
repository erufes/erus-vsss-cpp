TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    agent.cpp \
    player.cpp \
    teamplayer.cpp \
    ball.cpp \
    campo.cpp \
    ponto.cpp \
    lado.cpp \
    camera.cpp

HEADERS += \
    agent.h \
    player.h \
    teamplayer.h \
    ball.h \
    campo.h \
    ponto.h \
    lado.h \
    camera.h

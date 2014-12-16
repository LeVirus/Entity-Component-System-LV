TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++14



QMAKE_CXXFLAGS_DEBUG += -Wall -Wextra -Wpedantic -Og

#LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += main.cpp \
    entity.cpp \
    engine.cpp \
    systemmanager.cpp \
    displaysystem.cpp \
    system.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    entity.hpp \
    engine.hpp \
    systemmanager.hpp \
    system.hpp \
    component.hpp \
    node.hpp \
    displaycomponent.hpp \
    constantes.hpp \
    positioncomponent.hpp \
    displaysystem.hpp


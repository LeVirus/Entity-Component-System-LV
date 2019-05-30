CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++17

QMAKE_CXXFLAGS_DEBUG += -Wall -Wextra -Wpedantic -Og


TARGET = ./libGen/ECS
TEMPLATE = lib

DEPENDPATH += $${HEADERS}

SOURCES += \
    entity.cpp \
    engine.cpp \
    systemmanager.cpp \
    system.cpp \
    componentmanager.cpp

include(deployment.pri)
qtcAddDeployment()
HEADERS += \
    entity.hpp \
    engine.hpp \
    systemmanager.hpp \
    system.hpp \
    component.hpp \
    componentmanager.hpp


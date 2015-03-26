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
    system.cpp \
    componentmanager.cpp \
    iasystem.cpp \
    gravitysystem.cpp \
    inputsystem.cpp \
    vector2D.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    entity.hpp \
    engine.hpp \
    systemmanager.hpp \
    system.hpp \
    component.hpp \
    displaycomponent.hpp \
    positioncomponent.hpp \
    displaysystem.hpp \
    componentmanager.hpp \
    ECSconstantes.hpp \
    iasystem.hpp \
    physicscomponent.hpp \
    moveablecomponent.hpp \
    behaviorcomponent.hpp \
    gravitysystem.hpp \
    inputsystem.hpp \
    inputcomponent.hpp \
    groundcomponent.hpp \
    vector2D.hpp \
    ringbehaviorcomponent.hpp


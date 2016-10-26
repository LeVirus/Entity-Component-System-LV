#TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++14

QMAKE_CXXFLAGS_DEBUG += -Wall -Wextra -Wpedantic -Og


TARGET = ECS
TEMPLATE = lib
#INCLUDEPATH += ../../LibInc/HeadLib/

#LIBS += -lColl -L ../../LibInc/Lib/

DEPENDPATH += $${HEADERS}

SOURCES += main.cpp \
    vector2D.cpp \
    rectbox.cpp \
    segment.cpp \
    entity.cpp \
    engine.cpp \
    systemmanager.cpp \
    displaysystem.cpp \
    system.cpp \
    componentmanager.cpp \
    iasystem.cpp \
    gravitysystem.cpp \
    inputsystem.cpp \
    collisionsystem.cpp \
    bitset2d.cpp \
    geometriefreefunctions.cpp

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
    ringbehaviorcomponent.hpp \
    sinusoidbehaviorcomponent.hpp \
    roundtripbehaviorcomponent.hpp \
    collsegmentcomponent.hpp \
    collisionsystem.hpp \
    bitset2d.hpp \
    collrectboxcomponent.hpp \
    vector2D.hpp \
    rectbox.hpp \
    segment.hpp \
    geometriefreefunctions.hpp


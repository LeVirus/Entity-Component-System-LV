TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS *= -Wall -Wextra -pedantic -g

SOURCES += main.cpp \
    entity.cpp \
    engine.cpp \
    systemmanager.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    entity.hpp \
    engine.hpp \
    systemmanager.hpp \
    system.hpp \
    component.hpp \
    node.hpp


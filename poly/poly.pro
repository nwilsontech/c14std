TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++14
SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()


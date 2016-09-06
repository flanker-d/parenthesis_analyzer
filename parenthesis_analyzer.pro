TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Analyzer.cpp \
    TokenMap.cpp

HEADERS += \
    data_types.h \
    Analyzer.h \
    TokenMap.h

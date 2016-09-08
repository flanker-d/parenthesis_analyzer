TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Analyzer.cpp \
    TokenMap.cpp \
    ErrorHandler.cpp

HEADERS += \
    Analyzer.h \
    TokenMap.h \
    DataTypes.h \
    ErrorHandler.h

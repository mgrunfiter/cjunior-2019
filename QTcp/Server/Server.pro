QT       += core gui
QT       += core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE     = app
SOURCES	     = main.cpp \
               MyServer.cpp

HEADERS      = MyServer.h
win32:TARGET = ../MyServer

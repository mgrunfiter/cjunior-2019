QT       += core gui
QT       += core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE     = app
SOURCES	     = main.cpp \
               MyClient.cpp
HEADERS      = MyClient.h
win32:TARGET = ../MyClient


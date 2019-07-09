QT += testlib core
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
TARGET = miniGmpTests

SOURCES +=  tst_arithmetictests.cpp

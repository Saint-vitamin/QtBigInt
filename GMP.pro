QT       -= core gui

TARGET = MiniGMP
TEMPLATE = lib

DEFINES += MINIGMP_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS

VERSION = 6.0.0

DISTFILES += \
    README \
    gen_export.sh

HEADERS += \
    bigint.h \
    mini-gmp.h \
    minigmp_global.h

SOURCES += \
    bigint.cpp \
    mini-gmp.c

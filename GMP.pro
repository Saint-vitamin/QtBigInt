#
# Copyright (C) 2018-2019 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
           src \
           tests

include($$PWD/tests/test.pri)
VERSION = 6.1.2

src.file = src/GMP.pro
tests.file = tests/tests.pro

#
# Copyright (C) 2018-2019 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

unix:exec = $$PWD/tests/build/release/Qt-SecretTest,$$PWD/src/Qt-AES/build/release/QAESEncryption
win32:exec = $$PWD/tests/build/release/Qt-SecretTest.exe,$$PWD/src/Qt-AES/build/release/QAESEncryption.exe


contains(QMAKE_HOST.os, Linux):{
    DEPLOYER=cqtdeployer
} else {
    DEPLOYER=%cqtdeployer%
}

deployTest.commands = $$DEPLOYER -bin $$exec clear -qmake $$QMAKE_QMAKE -targetDir $$PWD/deployTests -libDir $$PWD -recursiveDepth 5

unix:test.commands = $$PWD/deployTests/miniGmpTests.sh
win32:test.commands = $$PWD/deployTests/miniGmpTests.exe

contains(QMAKE_HOST.os, Linux):{
    DEPLOYER=cqtdeployer
    win32:test.commands = wine $$PWD/deployTests/miniGmpTests.exe

} else {
    DEPLOYER=%cqtdeployer%
}

test.depends += deployTest

QMAKE_EXTRA_TARGETS += \
    deployTest \
    test

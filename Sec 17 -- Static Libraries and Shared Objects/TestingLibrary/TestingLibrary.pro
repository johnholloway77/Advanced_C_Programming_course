TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../myLib/release/ -lmylib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../myLib/debug/ -lmylib
else:unix: LIBS += -L$$PWD/../myLib/ -lmylib

INCLUDEPATH += $$PWD/../myLib
DEPENDPATH += $$PWD/../myLib

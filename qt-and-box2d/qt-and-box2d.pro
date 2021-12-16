QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SceneWidget.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    SceneWidget.h

FORMS += \
    MainWindow.ui



macx: LIBS += -L$$PWD/../box2d-master/build/bin/ -lbox2d

INCLUDEPATH += $$PWD/../box2d-master/include
DEPENDPATH += $$PWD/../box2d-master/include

macx: PRE_TARGETDEPS += $$PWD/../box2d-master/build/bin/libbox2d.a


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Golden-Retriever-Puppy-PNG.png \
    alien1.png

RESOURCES +=

win32: LIBS += -L$$PWD/box2d/build/ -lbox2d

INCLUDEPATH += $$PWD/box2d/include
DEPENDPATH += $$PWD/box2d/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/box2d/build/box2d.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/box2d/build/libbox2d.a

QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cube.cpp \
    CubeFace.cpp \
    CubeWidget.cpp \
    Model.cpp \
    ViewCube.cpp \
    controller2dcube.cpp \
    main.cpp \
    RubiksEdu.cpp \
    model2dcube.cpp \
    view2dcube.cpp \
    window3dcube.cpp

HEADERS += \
    Cube.h \
    CubeFace.h \
    CubeWidget.h \
    Model.h \
    RubiksEdu.h \
    ViewCube.h \
    controller2dcube.h \
    model2dcube.h \
    view2dcube.h \
    window3dcube.h

FORMS += \
    RubiksEdu.ui \
    controller2dcube.ui \
    window3dcube.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

macx: {
LIBS += -L$$PWD/mac/box2d-master/build/bin/ -lbox2d

INCLUDEPATH += $$PWD/mac/box2d-master/include
DEPENDPATH += $$PWD/mac/box2d-master/include

PRE_TARGETDEPS += $$PWD/mac/box2d-master/build/bin/libbox2d.a
}

win32: {
LIBS += -L$$PWD/windows/box2d-master/build/bin/ -lbox2d

INCLUDEPATH += $$PWD/windows/box2d-master/include
DEPENDPATH += $$PWD/windows/box2d-master/include

PRE_TARGETDEPS += $$PWD/windows/box2d-master/build/bin/libbox2d.a
}

RESOURCES +=

DISTFILES +=


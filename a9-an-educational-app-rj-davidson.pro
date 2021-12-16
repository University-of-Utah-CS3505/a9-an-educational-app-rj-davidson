QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cube.cpp \
    CubeBuilder.cpp \
    CubeCelebration.cpp \
    CubeController.cpp \
    CubeFace.cpp \
    Model3DCube.cpp \
    TutorialBrowser.cpp \
    ViewCube.cpp \
    main.cpp \
    RubiksEdu.cpp

HEADERS += \
    Cube.h \
    CubeBuilder.h \
    CubeCelebration.h \
    CubeController.h \
    CubeFace.h \
    Model3DCube.h \
    RubiksEdu.h \
     TutorialBrowser.h \
     ViewCube.h

FORMS += \
    CubeCelebration.ui \
    RubiksEdu.ui


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

RESOURCES += \
    tutorial-html/resources.qrc

QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cube.cpp \
    CubeFace.cpp \
    CubeWidget.cpp \
    Model.cpp \
    ViewCube.cpp \
    main.cpp \
    RubiksEdu.cpp \
    window3dcube.cpp

HEADERS += \
    Cube.h \
    CubeFace.h \
    CubeWidget.h \
    Model.h \
    RubiksEdu.h \
    ViewCube.h \
    window3dcube.h

FORMS += \
    RubiksEdu.ui \
    window3dcube.ui


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

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
    qml.qrc \
    shaders.qrc

DISTFILES +=


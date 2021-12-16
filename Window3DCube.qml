import QtQuick 2.0
import QtQuick.Window 2.14
import QtQuick3D 1.15


//Item {

//}

//Window {
//    width: 640
//    height: 480
//    visible: true

//    title: qsTr("Hello World")
//    Item {
//        Rectangle {
//            color: "red"
//            width: 100; height: 100
//            Rectangle {
//                color: "blue"
//                x: 50; y: 50; width: 100; height: 100
//            }
//        }
//    }
//}

//Window {
//    visible: true
//    width: 800
//    height: 600
//    Text {
//        id: dummy
//    }

//    ListView {
//        id: view
//        anchors.fill: parent
//        focus: true

//        currentIndex: 10

//        model: remoteModel

//        snapMode: ListView.SnapToItem
//        highlightFollowsCurrentItem: true
//        highlightMoveDuration: 0

//        delegate: Rectangle {
//            width: view.width
//            height: dummy.font.pixelSize * 2
//            color: _color
//            Text {
//                anchors.centerIn: parent
//                text: _text
//            }
//        }
//        Keys.onPressed: {
//            switch (event.key) {
//            case Qt.Key_Home:
//                view.currentIndex = 0;
//            break;
//            case Qt.Key_PageUp:
//                currentIndex -= Math.random() * 300;
//                if (currentIndex < 0)
//                    currentIndex = 0;
//                break;
//            case Qt.Key_PageDown:
//                currentIndex += Math.random() * 300;
//                if (currentIndex >= count)
//                    currentIndex = count - 1;
//                break;
//            case Qt.Key_End:
//                currentIndex = count - 1;
//            break;
//            }
//        }
//    }
//}

Window {
    id: window
    width: 640
    height: 640
    visible: true
    color: "black"

    Rectangle {
        id: qt_logo
        width: 230
        height: 230
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10
        color: "transparent"

        layer.enabled: true

        Rectangle {
            anchors.fill: parent
            color: "black"

//            Image {
//                anchors.fill: parent
//                source: "qt_logo.png"
//            }
            Text {
                id: text
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: "white"
                font.pixelSize: 17
                text: qsTr("The Future is Written with Qt")
            }

            transform: Rotation {
                id: rotation
                origin.x: qt_logo.width / 2
                origin.y: qt_logo.height / 2
                axis { x: 1; y: 0; z: 0 }
            }

            PropertyAnimation {
                id: flip1
                target: rotation
                property: "angle"
                duration: 600
                to: 180
                from: 0
            }
            PropertyAnimation {
                id: flip2
                target: rotation
                property: "angle"
                duration: 600
                to: 360
                from: 180
            }
        }
    }

//    View3D {
//        id: view
//        anchors.fill: parent
//        camera: camera
//        renderMode: View3D.Overlay

//        PerspectiveCamera {
//            id: camera
//            position: Qt.vector3d(0, 200, 300)
//            eulerRotation.x: -30
//        }

//        DirectionalLight {
//            eulerRotation.x: -30
//        }

//        Model {
//            id: cube
//            visible: true
//            position: Qt.vector3d(0, 0, 0)
//            source: "#Cube"
//            materials: [ DefaultMaterial {
//                    diffuseMap: Texture {
//                        id: texture
//                        sourceItem: qt_logo
//                    }
//                }
//            ]
//            eulerRotation.y: 90

//            SequentialAnimation on eulerRotation {
//                loops: Animation.Infinite
//                PropertyAnimation {
//                    duration: 5000
//                    from: Qt.vector3d(0, 0, 0)
//                    to: Qt.vector3d(360, 0, 360)
//                }
//            }
//        }
//    }

    MouseArea {
        id: mouseArea
        anchors.fill: qt_logo

        Text {
            id: clickme
            anchors.top: mouseArea.top
            anchors.horizontalCenter: mouseArea.horizontalCenter
            font.pixelSize: 17
            text: "Click me!"
            color: "white"

            SequentialAnimation on color {
                loops: Animation.Infinite
                ColorAnimation { duration: 400; from: "white"; to: "black" }
                ColorAnimation { duration: 400; from: "black"; to: "white" }
            }

            states: [
                State {
                    name: "flipped";
                    AnchorChanges {
                        target: clickme
                        anchors.top: undefined
                        anchors.bottom: mouseArea.bottom
                    }
                }
            ]
        }

        onClicked: {
            if (clickme.state == "flipped") {
                clickme.state = "";
                flip2.start();
            } else {
                clickme.state = "flipped";
                flip1.start();
            }
        }
    }
}



import QtQuick
import QtQuick.Controls 2.12

Rectangle {

    property int index: 0

    width: 200
    height: 200
    anchors.leftMargin: 1
    anchors.topMargin: 1
    Image {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: 130
        height: 130
        source: game.sources[index]
    }

    MouseArea {
        anchors.fill: parent
        onClicked: game.onFieldClicked(index)
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
    }
}

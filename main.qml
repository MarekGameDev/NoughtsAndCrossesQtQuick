import QtQuick
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts

Window {
    visible: true
    width: 1024
    height: 720
    maximumHeight: 720
    maximumWidth: 1024
    minimumHeight: 720
    minimumWidth: 1024
    title: qsTr("QML Signals and Slots")

    Label {
        text: game.result
        visible: game.gameFinished
        font.pixelSize: 30
        anchors {
                          top: parent.top
                          horizontalCenter: parent.horizontalCenter
                          topMargin: 10

                      }
    }

    Label {
        id: label1
        text: "Player 1 (O)"
        font.pixelSize: 30
        anchors {
                          top: parent.top
                          left: parent.left
                          topMargin: 10
                          leftMargin: 30
                      }
    }
    Label {
        text: game.playerPoints[0]
        horizontalAlignment : Text.AlignHCenter
        font.pixelSize: 30
        anchors {
                          top: parent.top
                          horizontalCenter: label1.horizontalCenter
                          topMargin: 80

                      }
    }
    Label {
        id: label2
        text: "Player 2 (X)"
        font.pixelSize: 30
        anchors {
                          top: parent.top
                          right: parent.right
                          topMargin: 10
                          rightMargin: 30
                      }
    }
    Label {
        text: game.playerPoints[1]
        font.pixelSize: 30
        anchors {
                          top: parent.top
                          horizontalCenter: label2.horizontalCenter
                          topMargin: 80

                      }
    }

    Rectangle {
        width:604
        height:604

        color: "black"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        GridLayout {

            id: board
            columns: 3

            width:602
            height:602
            columnSpacing: 1
            rowSpacing: 1

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            GameField { index: 0 }
            GameField { index: 1 }
            GameField { index: 2 }
            GameField { index: 3 }
            GameField { index: 4 }
            GameField { index: 5 }
            GameField { index: 6 }
            GameField { index: 7 }
            GameField { index: 8 }
        }
    }

    Button {
        text: "PLAY AGAIN"
        onClicked: game.onStartGame()
        font.pixelSize: 20
        visible: game.gameFinished
        anchors {
            bottom: parent.bottom
            horizontalCenter : parent.horizontalCenter
            bottomMargin: 10
        }
    }

}





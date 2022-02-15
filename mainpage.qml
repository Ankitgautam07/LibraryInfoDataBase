import QtQuick.Controls 2.0
import QtQml 2.6
import QtQuick.Controls.Styles 1.4
import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Window 2.1


Rectangle
{
    id:mainscreen
    color:"black"
    border.color:"yellow"

    Item {
        id:mainbuttons
        anchors.centerIn: parent
        ColumnLayout{
            anchors.centerIn: parent
            spacing: 25

            Button{
                id:insert
                text: "SUBMIT"
                font.bold: true
                font.family: "roboto"
                font.pointSize: 15
                width: 120
                height:50

                background: Rectangle {
                       implicitWidth: insert.width
                       implicitHeight:insert.height
                       color: "#4287f5"
                       opacity: enabled ? 1 : 0.3
                       border.color: "white"
                       border.width: 1
                       radius: 3
                   }
                onClicked:
                {
                    mystackview.push("submit.qml")

                }
            }

            Button{
                id:mview
                text: "View"
                font.bold: true
                font.family: "roboto"
                font.pointSize: 15
                width: 123
                height:50
                background: Rectangle {
                       implicitWidth: mview.width
                       implicitHeight:mview.height
                       color: "#00ccff"
                       opacity: enabled ? 1 : 0.3
                       border.color: "white"
                       border.width: 1
                       radius: 3
                   }

                onClicked: {

                    mystackview.push("view.qml")

                }
            }
            Button{
                id:deletebutton
                text: "Delete"
                font.bold: true
                font.family: "roboto"
                font.pointSize: 15
                width: 123
                height:50
                background: Rectangle {
                       implicitWidth: deletebutton.width
                       implicitHeight:deletebutton.height
                       color: "yellow"
                       opacity: enabled ? 1 : 0.3
                       border.color: "white"
                       border.width: 1
                       radius: 3
                   }

                onClicked: {

                    mystackview.push("delete.qml")

                }
            }
        }
    }
}

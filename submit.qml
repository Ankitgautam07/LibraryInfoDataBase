import QtQuick.Controls 2.0
import QtQml 2.6
import QtQuick.Controls.Styles 1.4
import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Window 2.1
import QtQml.Models 2.2


Rectangle{

    id:insertitem
    width: 640
    height: 480
    color:"#ccff66"

 Rectangle
    {
        id:rectMain
        width:550
        height:425
        color:"#000000"
        border.color:"blue"
        anchors.centerIn: parent
        Column
        {
            spacing: 25
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 35

            Row
            {
                spacing: 45
                Rectangle
                {
                    id:recttextpersonname
                    width:220
                    height:40
                    color:"Transparent"
                    Text {
                        anchors.centerIn: parent
                        text:"Person Name:"
                        font.bold: true
                        color:"white"
                        font.pixelSize: 25
                        font.family: "roboto"
                    }

                }
                TextField {
                    id:npersonname
                    height:45
                    width:195
                    font.bold: true

                }

            }
            Row
            {
                spacing: 45
                Rectangle
                {
                    id:recttextid
                    width:220
                    height:40
                    color:"Transparent"
                    Text {
                        anchors.centerIn: parent
                        text:"Person Id:"
                        color:"white"
                        font.bold: true
                        font.pixelSize: 25
                        font.family: "roboto"
                    }

                }
                TextField {
                    id:npersonid
                    height:45
                    width:195
                    font.bold: true

                }
            }
            Row
            {
                spacing: 45
                Rectangle
                {
                    id:recttextbookname
                    width:220
                    height:40
                    color:"Transparent"
                    Text {
                        anchors.centerIn: parent
                        text:"Book Name:"
                        color:"white"
                        font.bold: true
                        font.pixelSize: 25
                        font.family: "roboto"
                    }

                }
                TextField {
                    id:nbookname
                    height:45
                    width:195
                    font.bold: true

                }

            }
            Row
            {
                spacing: 45
                Rectangle
                {
                    id:recttextauthor
                    width:220
                    height:40
                    color:"Transparent"
                    Text {
                        anchors.centerIn: parent
                        text:"Book Author:"
                        color:"white"
                        font.bold: true
                        font.pixelSize: 25
                        font.family: "roboto"
                    }

                }
                TextField {
                    id:nbookauthor
                    height:45
                    width:195
                    font.bold: true

                }

            }


        }

        Button{
            id:msubmit
            text:"Submit"
            font.family: "roboto"
            font.pointSize: 15
            anchors
            {
                bottom: parent.bottom
                bottomMargin: 20
            }
            anchors.horizontalCenter: parent.horizontalCenter
            width: 120
            height:45
            background: Rectangle {
                id:submitrect
                implicitWidth: msubmit.width
                implicitHeight:msubmit.height
                color: "grey"
                border.color: "black"
                opacity: enabled ? 1 : 0.3
                border.width: 1
                radius: 3
            }

            onClicked: {
                //console.log("=====================> hhhj")
                dbasefolder.msubmit(npersonname.text,npersonid.text,nbookname.text,nbookauthor.text)

                mystackview.pop()

            }
            onPressed:{
                submitrect.color="green"
            }
            onReleased: {
                submitrect.color="grey"
            }
        }

    }
}


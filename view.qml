import QtQuick.Controls 2.0
import QtQml 2.6
import QtQuick.Controls.Styles 1.4
import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Window 2.1

Item {
    id: myTable

    width: parent.width
    height: parent.height


    ListModel{   //data model
        id:sourceModel
        Component.onCompleted: {


            for(var i = 0;i<dbasefolder.updateid.length;i++){
                sourceModel.append({
                                       "id":dbasefolder.updateid[i],
                                       "personname": dbasefolder.updatepersonname[i],
                                       "personid": dbasefolder.updatepersonid[i],
                                       "bookname": dbasefolder.updatebookname[i],
                                       "bookauthor": dbasefolder.updatebookauthor[i]
                                   })
            }
        }
    }






    function resetData() //reset data model
    {
        sourceModel.clear()
        dbasefolder.mread()


        for(var i = 0;i<dbasefolder.updateid.length;i++){
            hh.append({
                                 "id":dbasefolder.updateid[i],
                                 "personname": dbasefolder.updatepersonname[i],
                                 "personid": dbasefolder.updatepersonid[i],
                                 "bookname": dbasefolder.updatebookname[i],
                                 "bookauthor": dbasefolder.updatebookauthor[i]
                               })
        }

    }


    ColumnLayout {
        Layout.fillWidth: true

        Frame {

            implicitWidth: 680
            implicitHeight: 450

            ListView {//mvc --> model view controller //mvd -->
                id:myListData
                anchors.fill: parent
                ScrollBar.vertical: ScrollBar {active: true}
                ScrollBar.horizontal: ScrollBar {active: true}
                clip: true
                model: sourceModel
                delegate: RowLayout {
                    id:mrow
                    width: parent.width

                    TextField {
                        id:mid
                        text: id
                        visible: false
                    }

                    TextField {
                        id:mpersonname
                        text: personname
                        font.bold: true
                        Layout.fillWidth: true
                    }

                    TextField {
                        id:mpersonid
                        text: personid
                        font.bold: true
                        Layout.fillWidth: true
                    }
                    TextField {
                        id:mbookname
                        text:bookname
                        font.bold: true
                        Layout.fillWidth: true
                    }
                    TextField {
                        id:mbookauthor
                        text:bookauthor
                        font.bold: true
                        Layout.fillWidth: true
                    }


                }

                header: Rectangle {
                    border {color: "#000000"; width: 2}
                    width:650 ; height: 30


                    Row {
                        anchors.verticalCenter: parent.verticalCenter
                        Column {
                            width: 125
                            Label{
                                text: "  Person Name"
                                font.pixelSize: 18
                                font.bold: true
                                color: "#000000"

                            }
                        }

                        Column {
                            width: 125
                            Label{
                                text: "\t  Person Id."
                                font.pixelSize: 18
                                font.bold: true
                                color: "#000000"
                            }
                        }
                        Column {
                            width: 125
                            Label{
                                text: "\t   Book Name"
                                font.pixelSize: 18
                                font.bold: true
                                color: "#000000"
                            }
                        }
                        Column {
                            width: 125
                            Label{
                                text: "\t    Book Author"
                                font.pixelSize: 18
                                font.bold: true
                                color: "#000000"
                            }
                        }

                    }

                }
            }
        }
    }


    Button{
        id:back
        text:"Back"

        font.family: "roboto"
        font.pointSize: 15
        anchors
        {
            bottom: parent.bottom
            bottomMargin: 60
        }
        anchors.horizontalCenter: parent.horizontalCenter
        width: 120
        height:45
        background: Rectangle {
            id:backrect
            implicitWidth: back.width
            implicitHeight:back.height
            color: "grey"
            border.color: "#ffffff"
            opacity: enabled ? 1 : 0.3
            border.width: 1
            radius: 3
        }

        onClicked: {

            mystackview.pop()

        }
        onPressed:{
            backrect.color="blue"
        }
        onReleased: {
            backrect.color="grey"
        }
    }

    Component.onCompleted: {

        resetData()

    }

}

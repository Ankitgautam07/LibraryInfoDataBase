import QtQuick.Controls 2.0
import QtQml 2.6
import QtQuick.Controls.Styles 1.4
import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Window 2.1


Window {
    id:mmainwindow
    width: 680
    height: 500
    visible: true
    color:"#FFFFFF"
    title: qsTr("Library Info")

    property int flag: 0



    StackView{
        id:mystackview
        anchors.fill: parent
        initialItem: "mainpage.qml"
    }


}

import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Material.theme : Material.Dark
    Material.accent:Material.Red

    RadioButton{
        anchors.centerIn: parent
    }

    Text {
        id: element
        x: 170
        y: 85
        width: 317        
        height: 73                
        color: "#D16806"
        text: qsTr("Hello There !")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }
    
}

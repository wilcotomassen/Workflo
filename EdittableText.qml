import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
	id: editableText
	property string text

	states: [
		State {
			name: "editMode"
			PropertyChanges {target: displayText; visible: false}
			PropertyChanges {target: editText; visible: true }
		},
		State {
			name: "displayMode"
			PropertyChanges {target: displayText; visible: true}
			PropertyChanges {target: editText; visible: false }
		}
	]
	state: "displayMode"

	Item {
		id: displayText
		anchors.fill: parent
		Text {
			leftPadding: 5
			anchors.fill: parent
			text: editableText.text
			color: "white"
			verticalAlignment: Text.AlignVCenter
			font {
				family: rubikLight.name
				pixelSize: 12
			}
			MouseArea {
				enabled: true
				anchors.fill: parent
				hoverEnabled: true
				cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
				onDoubleClicked: {
					editableText.state = "editMode";
				}
			}
		}
	}

	TextField {
		id: editText
		anchors.fill: parent
		text: editableText.text
		placeholderText: "Enter name"
		onEditingFinished: {
			editableText.state = "displayMode";
			if (text !== parent.text) {
				parent.text = text;
			}
		}
		onVisibleChanged: {
			if (visible) {
				this.forceActiveFocus();
			}
		}		
		font {
			family: rubikLight.name
			pixelSize: 12
		}
		style: TextFieldStyle {
			textColor: "black"
			background: Rectangle {
				color: "white"
				anchors.fill: parent
			}
		}
	}

}

import QtQuick 2.0
import QtQuick.Controls 1.4

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

	Text {
		id: displayText
		anchors.fill: parent
		text: editableText.text
		color: "white"
		font {
			family: rubikLight.name
			pixelSize: 12
		}
		MouseArea {
			enabled: true
			anchors.fill: parent
			onDoubleClicked: {
				console.log("YAY");
				editableText.state = "editMode";
			}
		}
	}

	TextField {
		id: editText
		anchors.fill: parent
		text: editableText.text
		placeholderText: qsTr("Enter name")
		onEditingFinished: {
			console.log("EDIT DONE");
			editableText.state = "displayMode";
			parent.text = text
		}
		onVisibleChanged: {
			if (visible) {
				this.forceActiveFocus();
			}
		}

	}

}

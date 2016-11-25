import QtQuick 2.0

Rectangle {
	id: pane

	property string textLabel: "<LABEL>"
	property string paneId: "<PANE_ID>"
	property bool active: false

	states: [
		State {
			name: "active"
			when: active
			PropertyChanges {target: pane; visible: true}
		},
		State {
			name: "inactive"
			when: !active
			PropertyChanges {target: pane; visible: false}
		}
	]

	state: "inactive"
	anchors.fill: parent
	color: "#111111"

	Text {
		width: pane.width
		height: 60
		anchors {
			top: pane.top
			left: pane.left
			topMargin: 20
			leftMargin: 60
		}
		color: "#ffffff"
		text: textLabel
		font {
			family: poppinsLight.name
			capitalization: Font.AllUppercase
			pixelSize: 22
		}
	}

}

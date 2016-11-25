import QtQuick 2.0

Rectangle {
	id: button

	property string textLabel: "<LABEL>"
	property string paneId: "<PANE_ID>"
	property bool active: false
	signal click()

	states: [
		State {
			name: "active"
			when: active
			PropertyChanges {target: activeIndicator; visible: true}
			PropertyChanges {target: button; color: "#333333" }
		},
		State {
			name: "inactive"
			when: !active
			PropertyChanges {target: activeIndicator; visible: false}
			PropertyChanges {target: button; color: "transparent" }
		}
	]

	state: "inactive"
	width: parent.width
	height: 30
	color: "transparent"

	Rectangle {
		id: activeIndicator
		width: 4
		height: button.height
		color: "#666666"
		anchors.left: button.left
	}

	Text {
		anchors.fill: button;
		anchors.leftMargin: 20
		color: "#ffffff"
		text: textLabel
		verticalAlignment: Text.AlignVCenter

		font {
			family: poppinsLight.name
			capitalization: Font.AllUppercase
			pixelSize: 14
		}
	}

	MouseArea {
		anchors.fill: button
		hoverEnabled: true
		onClicked: button.click();
	}

}

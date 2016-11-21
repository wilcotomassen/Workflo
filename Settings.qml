import QtQuick 2.7

Rectangle {
	id: root
	color: "#cccccc"

	ListView {
		anchors.fill: parent
		model: activitySequence;

		delegate: Rectangle {
			height: 25;
			width: parent.width
			color: "red"
			Text {
				anchors.fill: parent
				text: name
				color: "white"
			}
		}

	}

}

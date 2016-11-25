import QtQuick 2.0
import QtQuick.Layouts 1.3

SettingsPane {

	Item {
		anchors.fill: parent
		anchors.topMargin: 80
		anchors.leftMargin: 60
		anchors.rightMargin: 35

		ColumnLayout {
			anchors.fill: parent

			Rectangle {
				Layout.fillWidth: true
				Layout.preferredHeight: 25
				z:  99
				color: "#111111"
				Row {
					anchors.fill: parent
					Text {
						width: parent.width * 0.5
						text: " Activity"
						color: "white"
						font {
							family: poppinsLight.name
							capitalization: Font.AllUppercase
							pixelSize: 12
						}
					}
					Text {
						width: parent.width * 0.25
						text: "Duration"
						color: "white"
						font {
							family: poppinsLight.name
							capitalization: Font.AllUppercase
							pixelSize: 12
						}
						horizontalAlignment: Text.AlignHCenter
					}
					Text {
						width: parent.width * 0.25
						text: "Lock display"
						color: "white"
						font {
							family: poppinsLight.name
							capitalization: Font.AllUppercase
							pixelSize: 12
						}
						horizontalAlignment: Text.AlignHCenter
					}

				}
				Rectangle {
					width: parent.width
					height: 1
					y: parent.height - height - 3
					color: "#7fffffff"
				}
			}


			ListView {
				model: activitySequence;
				Layout.fillWidth: true
				Layout.fillHeight: true

				delegate: Item {
					height: 25;
					width: parent.width
					Row {
						anchors.fill: parent
						EdittableText {
							width: parent.width * 0.5
							height: 25
							text: name
						}
						Text {
							width: parent.width * 0.25
							text: duration.toString() + " m"
							color: "white"
							horizontalAlignment: Text.AlignHCenter
							font {
								family: rubikLight.name
								pixelSize: 12
							}
						}
						Text {
							width: parent.width * 0.25
							text: "YES"
							color: "white"
							horizontalAlignment: Text.AlignHCenter
							font {
								family: rubikLight.name
								pixelSize: 12
							}
						}
					}


				}

			}
		}

	}
}

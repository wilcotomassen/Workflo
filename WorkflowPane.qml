import QtQuick 2.0
import QtQuick.Layouts 1.3
import ActivityModelEnums 1.0

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
						width: parent.width * 0.40
						text: " Activity"
						color: "white"
						font {
							family: poppinsLight.name
							capitalization: Font.AllUppercase
							pixelSize: 12
						}
					}
					Text {
						width: parent.width * 0.20
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
						width: parent.width * 0.20
						text: "Notify"
						color: "white"
						font {
							family: poppinsLight.name
							capitalization: Font.AllUppercase
							pixelSize: 12
						}
						horizontalAlignment: Text.AlignHCenter
					}
					Text {
						width: parent.width * 0.20
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
							width: parent.width * 0.40
							height: 25
							text: name
							onTextChanged: {
								activitySequence.setData(index, text, ActivityRoles.NameRole);
							}
						}
						Text {
							width: parent.width * 0.20
							text: duration.toString() + " m"
							color: "white"
							horizontalAlignment: Text.AlignHCenter
							font {
								family: rubikLight.name
								pixelSize: 12
							}
						}
						Text {
							width: parent.width * 0.20
							color: "white"
							horizontalAlignment: Text.AlignHCenter
							font {
								family: rubikLight.name
								pixelSize: 12
							}
							MouseArea {
								anchors.fill: parent
								hoverEnabled: true
								cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
								onDoubleClicked: {
									activitySequence.setData(index, !notifying, ActivityRoles.NotifyingRole);
									parent.updateLabel();
								}
							}

							function updateLabel() {
								text =  notifying ? "YES" : "NO"
							}
							Component.onCompleted: updateLabel();
						}
						Text {
							width: parent.width * 0.20
							color: "white"
							horizontalAlignment: Text.AlignHCenter
							font {
								family: rubikLight.name
								pixelSize: 12
							}
							MouseArea {
								anchors.fill: parent
								hoverEnabled: true
								cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
								onDoubleClicked: {
									activitySequence.setData(index, !locking, ActivityRoles.LockingRole);
									parent.updateLabel();
								}
							}

							function updateLabel() {
								text =  locking ? "YES" : "NO"
							}
							Component.onCompleted: updateLabel();
						}
					}

				}

			}

			Item {
				Layout.fillWidth: true
				Layout.preferredHeight:40

				Rectangle {
					anchors.top: parent.top
					anchors.left: parent.left
					width: 30
					height: width
					radius:width / 2
					border.width: 2
					border.color: "#ffffff"
					color: "transparent"

					Text {
						x: 8
						y: 1
						color: "#ffffff"
						text: "+"
						font.pixelSize: 20
						horizontalAlignment: Text.AlignHCenter
						verticalAlignment: Text.AlignVCenter
					}

					MouseArea {
						anchors.fill: parent
						onClicked: activitySequence.addNewActivity()
					}
				}
			}
		}

	}
}

import QtQuick 2.7

Item {
	id: root

	FontLoader { id: poppinsSemibold; source: "qrc:/resources/fonts/Poppins-SemiBold.ttf" }
	FontLoader { id: poppinsLight; source: "qrc:/resources/fonts/Poppins-Light.ttf" }
	FontLoader { id: rubikLight; source: "qrc:/resources/fonts/Rubik-Light.ttf" }

	// List of items
	Rectangle {

		width: parent.width * 0.25
		height: parent.height
		anchors.left: parent.left
		color: "#222222"

		Column {
			id: menuList
			anchors.fill: parent
			anchors.topMargin: 60
			spacing: 0
			ListButton {
				paneId: "workflow"
				textLabel: "Workflow"
				onClick: activatePane(paneId)
			}
			ListButton {
				paneId: "lockscreen"
				textLabel: "Lock screen"
				onClick: activatePane(paneId)
			}
			ListButton {
				paneId: "about"
				textLabel: "About"
				onClick: activatePane(paneId)
			}
		}
	}

	// Content pane
	Item {
		id: contentPane
		width: parent.width * 0.75
		height: parent.height
		anchors.right: parent.right

		WorkflowPane {
			paneId: "workflow"
			textLabel: "Workflow"
		}
		SettingsPane {
			paneId: "lockscreen"
			textLabel: "Lock screen"
		}
		AboutPane {
			paneId: "about"
			textLabel: "About"
		}

	}

	function activatePane(paneId) {

		var menuItems = menuList.children;
		for (var i = 0 ; i < menuItems.length; i++) {
			var menuItem = menuItems[i];
			menuItem.active = (menuItem.paneId === paneId)
		}

		var panes = contentPane.children;
		for (var i = 0 ; i < menuItems.length; i++) {
			var pane = panes[i];
			pane.active = (pane.paneId === paneId)
		}

	}

	Component.onCompleted: activatePane("workflow")

}

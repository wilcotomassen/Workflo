import QtQuick 2.0

SettingsPane {

	Item {
		anchors.fill: parent
		anchors.topMargin: 80
		anchors.leftMargin: 60
		anchors.rightMargin: 35

		Text {
			width: parent.width
			color: "#ffffff"
			text: "Workflo version: " + version
			font {
				family: poppinsLight.name
				pixelSize: 12
			}
		}

		Text {
			width: parent.width
			y: 40
			color: "#ffffff"
			wrapMode: Text.WordWrap
			textFormat: Text.StyledText
			text: "<p>This application is provided free of charge, but also comes without any warranty. If you enjoy using this application consider making a contribution, either by contributing code or by making a donation.</p>
					<p>In case of issues, bugs, feature requests, please add them to the issue tracker: https://bitbucket.org/wilcotomassen/workflo/issues for other reasons to reach out, contact me via e-mail: wilco@wilcotomassen.nl</p>
					<p>This application uses Qt 5.7.0 under the GNU LGPL V3 Licence. In complience with this license, full source code access and/or the complete license agreement are publicly available at the code repository at https://github.com/wilcotomassen/workflo</p>"
			font {
				family: rubikLight.name
				pixelSize: 12
			}
		}
	}


}

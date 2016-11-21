#include "screenlock.h"
#include <QDebug>

#include <QApplication>
#include <QDesktopWidget>
#include "screenlockdisplay.h"

ScreenLock::ScreenLock(QObject *parent) : QObject(parent) {}

/**
 * Lock the display(s)
 */
void ScreenLock::lock() {

	if (!locked) {

		QDesktopWidget* dw = QApplication::desktop();
		for (int i = 0; i < dw->screenCount(); i++) {

			// Show display
			QRect displayGeometry = dw->availableGeometry(i);
			ScreenLockDisplay* display = new ScreenLockDisplay();
			display->move(displayGeometry.topLeft());
			display->showFullScreen();

			// Connect display
			connect(display, SIGNAL(unlockTriggered()), this, SLOT(unlock()));
			displays.append(display);

			// Set focus on first display (to catch key events)
			if (i == 0) {
				display->activateWindow();
				display->setFocus();
			}

		}

		locked = true;

	}

}

/**
 * Unlock the display(s)
 */
void ScreenLock::unlock() {

	if (locked) {

		foreach(ScreenLockDisplay* display, displays) {
			display->hide();
		}
		qDeleteAll(displays);
		displays.clear();

		locked = false;

	}

}


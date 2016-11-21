#include "screenlockdisplay.h"
#include <QPainter>
#include <QKeyEvent>
#include <math.h>
#include <QTimer>
#include <QDebug>

ScreenLockDisplay::ScreenLockDisplay(QWidget *parent) : QWidget(parent) {
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	QTimer* t = new QTimer();
	connect(t, SIGNAL(timeout()), this, SLOT(update()));
	t->setSingleShot(false);
	t->start(16);
	theta = 0;
}

void ScreenLockDisplay::paintEvent(QPaintEvent*) {

	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing, true);

	// Draw background
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::black);
	painter.drawRect(geometry());

	// Draw shapes
	painter.translate(width() * 0.5, height() * 0.5);
	QPen pen;
	pen.setColor(Qt::white);
	pen.setWidth(4);
	pen.setCapStyle(Qt::RoundCap);
	painter.setPen(pen);

	for (int i = 0; i < num; i++) {
		float sz = i * 40;
		float offset = 6.28f / (float) num * (float) i;
		float arcEnd = map(sin(theta + offset), -1, 1, 0 * 16, 360 * 16);
		painter.drawArc(-sz / 2, -sz / 2, sz, sz, 0 * 16, arcEnd);
	}

	theta += .0223f;

	painter.end();

}

/**
 * Capture key presses
 * @param e
 */
void ScreenLockDisplay::keyPressEvent(QKeyEvent* e) {
	if (e->key() == Qt::Key_Escape) {
		unlockTriggered();
	}
}

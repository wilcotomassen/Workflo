#ifndef SCREENLOCKDISPLAY_H
#define SCREENLOCKDISPLAY_H

#include <QWidget>

class ScreenLockDisplay : public QWidget {
	Q_OBJECT

public:
	explicit ScreenLockDisplay(QWidget *parent = 0);

signals:
	void unlockTriggered();

private:
	void keyPressEvent(QKeyEvent* e);
	void paintEvent(QPaintEvent*);

	static float map(float x, float in_min, float in_max, float out_min, float out_max) {
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}

	int num = 20;
	float theta;

};

#endif // SCREENLOCKDISPLAY_H

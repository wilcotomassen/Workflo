#ifndef SCREENLOCK_H
#define SCREENLOCK_H

#include <QObject>

class ScreenLockDisplay;

class ScreenLock : public QObject {
	Q_OBJECT

public:
	ScreenLock(QObject *parent = 0);

	bool isLocked() const { return locked; }

public slots:
	void lock();
	void unlock();

private:
	QList<ScreenLockDisplay*>	displays;
	bool						locked;


};

#endif // SCREENLOCK_H

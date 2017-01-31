#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>
#include <QObject>

class Activity : public QObject{
	Q_OBJECT

public:
	Activity(const QString& name, int duration, bool isLocking);

	void setName(const QString& name);
	QString getName() const;

	void setDuration(int duration);
	int getDuration() const;

	void setLocking(bool locking);
	bool isLocking() const;

	void setNotifying(bool notifying);
	bool isNotifying() const;

signals:
	void nameChanged(QString name);
	void durationChanged(int duration);
	void isLockingChanged(bool locking);
	void isNotifyingChanged(bool notifying);

private:
	QString name;
	int duration;
	bool _isLocking;
	bool _isNotifying;

};

#endif // ACTIVITY_H

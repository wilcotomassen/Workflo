#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>
#include <QObject>

class Activity : public QObject{
	Q_OBJECT

	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(long duration READ getDuration WRITE setDuration NOTIFY durationChanged)

public:
	Activity(const QString& name, long duration, bool isLocking);

	void setName(const QString& name);
	QString getName() const;

	void setDuration(long duration);
	long getDuration() const;

	bool isLocking() const;

signals:
	void nameChanged(QString name);
	void durationChanged(long duration);

private:
	QString name;
	long duration;
	bool _isLocking;

};

#endif // ACTIVITY_H

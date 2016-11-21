#ifndef ACTIVITYSEQUENCE_H
#define ACTIVITYSEQUENCE_H

#include <QObject>
#include <QList>

class QTimer;
class Activity;

class ActivitySequence : public QObject {
	Q_OBJECT

public:
	explicit ActivitySequence(QObject *parent = 0);
	void setActivities(const QList<Activity*> activities);

	Activity*	getCurrentActivity();
	float		getCurrentActivityProgress();

signals:
	void activityTriggered(Activity* activity);

public slots:
	void start();

private slots:
	void gotoNextActivity();

private:
	QList<Activity*>	activities;
	QTimer*				activityTimer;
	int					currentActivityIndex;

};

#endif // ACTIVITYSEQUENCE_H

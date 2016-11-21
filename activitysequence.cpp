#include "activitysequence.h"

#include "activity.h"
#include <QTimer>
#include <QDebug>

ActivitySequence::ActivitySequence(QObject *parent) : QObject(parent) {
	activityTimer = new QTimer();
	activityTimer->setSingleShot(true);
	connect(activityTimer, SIGNAL(timeout()), this, SLOT(gotoNextActivity()));
	this->currentActivityIndex = 0;
}

void ActivitySequence::setActivities(const QList<Activity*> activities) {
	this->activities = activities;
	this->currentActivityIndex = 0;
}

void ActivitySequence::gotoNextActivity() {

	// Fetch next activity
	int nextIndex = (currentActivityIndex < activities.size() - 1) ? currentActivityIndex + 1 : 0;
	Activity* newActivity = activities.at(nextIndex);

	// Set new activity active
	activityTimer->start(newActivity->getDuration() * TIME_BASE);
	currentActivityIndex = nextIndex;
	activityTriggered(newActivity);

}

void ActivitySequence::start() {
	if (activities.size() > 0) {
		gotoNextActivity();
	}
}

Activity* ActivitySequence::getCurrentActivity() {
	if (currentActivityIndex < activities.size()) {
		return activities.at(currentActivityIndex);
	} else {
		return NULL;
	}
}

float ActivitySequence::getCurrentActivityProgress() {

	if (!activityTimer->isActive()) {
		return 0;
	}

	Activity* currentActivity = getCurrentActivity();
	if (currentActivity == NULL) {
		return 0;
	}

	float remaining = (float) (activityTimer->remainingTime());
	float total = (float) (currentActivity->getDuration() * TIME_BASE);
	return (total - remaining) / total;

}

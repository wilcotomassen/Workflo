#include "activity.h"

Activity::Activity(const QString& name, long duration, bool isLocking) {
	this->name = name;
	this->duration = duration;
	this->_isLocking = isLocking;
}

void Activity::setName(const QString& name) {
	if (name != this->name) {
		this->name = name;
		emit nameChanged(this->name);
	}
}

QString Activity::getName() const {
	return name;
}

void Activity::setDuration(long duration) {
	if (duration != this->duration) {
		this->duration = duration;
		emit durationChanged(this->duration);
	}
}

long Activity::getDuration() const {
	return duration;
}

bool Activity::isLocking() const {
	return _isLocking;
}

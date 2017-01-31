#include "activity.h"
#include <QDebug>

Activity::Activity(const QString& name, int duration, bool isLocking) {
	this->name = name;
	this->duration = duration;
	this->_isLocking = isLocking;
	this->_isNotifying = false;
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

void Activity::setDuration(int duration) {
	if (duration != this->duration) {
		this->duration = duration;
		emit durationChanged(this->duration);
	}
}

int Activity::getDuration() const {
	return duration;
}

void Activity::setLocking(bool locking) {
	if (locking != _isLocking) {
		_isLocking = locking;
		emit isLockingChanged(_isLocking);
	}
}

bool Activity::isLocking() const {
	return _isLocking;
}

void Activity::setNotifying(bool notifying) {
	if (notifying != _isNotifying) {
		_isNotifying = notifying;
		emit isNotifyingChanged(_isNotifying);
	}
}

bool Activity::isNotifying() const {
	return _isNotifying;
}

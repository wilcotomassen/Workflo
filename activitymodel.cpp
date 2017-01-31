#include "activitymodel.h"

ActivityModel::ActivityModel(QObject* parent) : QAbstractListModel(parent) {}

void ActivityModel::addActivity(Activity* activity) {
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	activities.append(activity);
	endInsertRows();
}

int ActivityModel::rowCount(const QModelIndex & parent) const {
	Q_UNUSED(parent);
	return activities.count();
}

QVariant ActivityModel::data(const QModelIndex& index, int role) const {
	if (index.row() < 0 || index.row() >= activities.count()) {
		return QVariant();
	}

	Activity* activity = activities[index.row()];
	if (role == NameRole) {
		return activity->getName();
	} else if (role == DurationRole) {
		return activity->getDuration();
	} else if (role == LockingRole) {
		return activity->isLocking();
	} else if (role == NotifyingRole) {
		return activity->isNotifying();
	} else {
		return QVariant();
	}
}

void ActivityModel::setData(const int& index, const QVariant &value, int role) {

	if (index < 0 || index >= activities.count()) {
		return;
	}

	Activity* activity = activities[index];
	if (role == NameRole) {
		activity->setName(value.toString());
	} else if (role == DurationRole) {
		activity->setDuration(value.toInt());
	} else if (role == LockingRole) {
		activity->setLocking(value.toBool());
	} else if (role == NotifyingRole) {
		activity->setNotifying(value.toBool());
	}
}

QHash<int, QByteArray> ActivityModel::roleNames() const {
	QHash<int, QByteArray> roles;
	roles[NameRole] = "name";
	roles[DurationRole] = "duration";
	roles[LockingRole] = "locking";
	roles[NotifyingRole] = "notifying";
	return roles;
}

#ifndef ACTIVITYMODEL_H
#define ACTIVITYMODEL_H

#include <QAbstractListModel>
#include <QByteArray>
#include <QHash>
#include <QtQml>
#include "activity.h"

class ActivityModel : public QAbstractListModel {
	Q_OBJECT

public:
	enum ActivityRoles {
		NameRole = Qt::UserRole + 1,
		DurationRole,
		LockingRole,
		NotifyingRole
	};
	Q_ENUMS(ActivityRoles)
	static void declareQML() {
		qmlRegisterType<ActivityModel>("ActivityModelEnums", 1, 0, "ActivityRoles");
	}

	ActivityModel(QObject* parent = 0);

	void addActivity(Activity* activity);
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public slots:
	void setData(const int& index, const QVariant &value, int role);

protected:
	QHash<int, QByteArray> roleNames() const;

private:
	 QList<Activity*>	activities;


	 // Do not forget to declare your class to the QML system.


};


#endif // ACTIVITYMODEL_H

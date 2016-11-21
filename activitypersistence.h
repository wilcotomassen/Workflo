#ifndef ACTIVITYPERSISTENCE_H
#define ACTIVITYPERSISTENCE_H

#include <activity.h>
#include <QJsonObject>

class ActivityPersistence {

public:
	static Activity* loadFromJsonObject(const QJSonObject& object) {
		return NULL;
	}

	static QJSonObject saveAsJsonObject(const Activity* const activity) {

	}

};

#endif // ACTIVITYPERSISTENCE_H

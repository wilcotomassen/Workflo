#ifndef JSONPERSISTENCE_H
#define JSONPERSISTENCE_H

#include <activity.h>
#include <QList>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>

class JsonPersistence {

public:
	static QList<Activity*> readFromFile(const QString& file, QString* error = NULL) {

		try {

			// Read file to JSON Document
			QFile jsonFile(file);
			if (!jsonFile.open(QIODevice::ReadOnly)) {
				throw "Failed to open file";
			}
			QJsonParseError error;
			QJsonDocument document = QJsonDocument::fromJson(jsonFile.readAll(), &error);
			jsonFile.close();
			if (document.isNull()) {
				throw QString("Failed to parse settings file: %1").arg(error.errorString());
			}

			// Fetch activities array
			QJsonObject rootObj = document.object();
			QJsonValue activitiesValue = rootObj.value("activities");
			if (!activitiesValue.isArray()) {
				throw "Failed to find valid activities array";
			}
			QJsonArray activitiesArray = activitiesValue.toArray();

			// Fetch list of activities
			QList<Activity*> activities;
			for (int i = 0; i < activitiesArray.size(); i++) {
				QJsonValue activityValue = activitiesArray.at(i);
				if (!activityValue.isObject()) {
					throw QString("Invalid activity object at index: %1").arg(QString::number(i));
				}

				Activity* activity = loadActivityFromJsonObject(activityValue.toObject());
				activities.append(activity);

			}

			return activities;

		} catch (QString errorString) {
			if (error != NULL) {
				error = errorString;
			}
			return NULL;
		}

	}

	static bool	writeToFile(const ActivitySequence* const activitySequence, const QString& file, QString* error = NULL) {

		// Create JSON structure
		QJsonObject rootObject;

		QJsonArray activities;
		rootObject.insert("activities", activities);


		// Write JSON to file


		return false;
	}

	static Activity* loadActivityFromJsonObject(const QJSonObject& object, QString* error = NULL) {

		return NULL;
	}

	static QJSonObject saveActivityAsJsonObject(const Activity* const activity) {

	}

};

#endif // JSONPERSISTENCE_H

#include "activitymodel.h"
#include <QDebug>
#include <QMessageBox>

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

	saveActivitiesToFile(qApp->applicationDirPath() + "/activities.xml");
}

QHash<int, QByteArray> ActivityModel::roleNames() const {
	QHash<int, QByteArray> roles;
	roles[NameRole] = "name";
	roles[DurationRole] = "duration";
	roles[LockingRole] = "locking";
	roles[NotifyingRole] = "notifying";
	return roles;
}

void ActivityModel::loadActivitiesFromFile(const QString& filename) {

	// Open file
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly)) {

		QMessageBox::critical(0, "Failed to open settings file", QString("Failed to open settings file at: '%1', possibly the file is corrupt or non-readable %2").arg(filename, file.errorString()));
		return;
	}

	// Start parsing of XML
	QXmlStreamReader xmlReader;
	xmlReader.setDevice(&file);

	// Read all activities into list (keep in memory, otherwise
	// the model will attempt to save the xml file we are currently
	// reading)
	QList<Activity*> tmpActivities;
	if (xmlReader.readNextStartElement() && xmlReader.name() == "activities") {
		while (xmlReader.readNextStartElement()) {

			// Parse activity
			if (xmlReader.name() == "activity") {

				Activity* activity = new Activity("", 0, false);
				foreach (QXmlStreamAttribute attribute, xmlReader.attributes()) {
					if (attribute.name() == "duration") {
						activity->setDuration(attribute.value().toInt());
					} else if (attribute.name() == "locking") {
						activity->setLocking((bool) attribute.value().toInt());
					} else if (attribute.name() == "notifying") {
						activity->setNotifying((bool) attribute.value().toInt());
					}
				}
				activity->setName(xmlReader.readElementText());
				tmpActivities.append(activity);

			}

		}
	}

	if (xmlReader.hasError()) {
		qDebug() << "XML error: " << xmlReader.errorString().data();
	}

	// Close file
	file.close();

	// Add all activities to model
	foreach (Activity* activity, tmpActivities) {
		addActivity(activity);
	}

}

void ActivityModel::addNewActivity() {
	addActivity(new Activity("Untitled activity", 10, false));
}

void ActivityModel::saveActivitiesToFile(const QString& filename) {

	// Open file
	QFile file(filename);
	if (!file.open(QIODevice::WriteOnly)) {
		QMessageBox::critical(0, "Failed to open settings file", QString("Failed to open settings file at: '%1', possibly the file is corrupt or non-writable").arg(filename));
		return;
	}

	// Start XML document
	QXmlStreamWriter xmlWriter;
	xmlWriter.setAutoFormatting(true);
	xmlWriter.setDevice(&file);
	xmlWriter.writeStartDocument();
	xmlWriter.writeStartElement("activities");

	// Write activity
	foreach(Activity* activity, activities) {
		xmlWriter.writeStartElement("activity");
		xmlWriter.writeAttribute("duration", QString::number(activity->getDuration()));
		xmlWriter.writeAttribute("locking", QString::number(activity->isLocking()));
		xmlWriter.writeAttribute("notifying", QString::number(activity->isNotifying()));
		xmlWriter.writeCharacters(activity->getName());
		xmlWriter.writeEndElement();
	}

	// Finalize XML document
	xmlWriter.writeEndElement();
	xmlWriter.writeEndDocument();

	// Close file
	file.close();

}

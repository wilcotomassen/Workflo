#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screenlock.h"

class QSystemTrayIcon;
class QMenu;
class ActivitySequence;
class Activity;
class ActivityModel;

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void showMessage();
	void updateIcon();
	void handleActivityChange(Activity* activity);

private:
	QSystemTrayIcon*	icon;
	QMenu*				menu;
	ScreenLock*			screenLock;
	ActivitySequence*	sequence;
	ActivityModel*		activityModel;

};

#endif // MAINWINDOW_H

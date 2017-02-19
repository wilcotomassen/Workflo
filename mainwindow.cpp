#include "mainwindow.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QQuickView>
#include <QQmlContext>
#include <QDir>

#include "activitysequence.h"
#include "activitymodel.h"
#include "activity.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

	QPixmap iconFile(64, 64);
	iconFile.fill(Qt::black);

	setMinimumSize(600, 400);

	// Initialize
	screenLock = new ScreenLock(this);

	QAction* settingsAction = new QAction(tr("&Settings"), this);
	connect(settingsAction, &QAction::triggered, this, &MainWindow::show);

	QAction* quitAction = new QAction(tr("&Quit"), this);
	connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

	menu = new QMenu();
	menu->addAction(settingsAction);
	menu->addSeparator();
	menu->addAction(quitAction);

	icon = new QSystemTrayIcon(QIcon(iconFile), this);
	icon->setContextMenu(menu);
	icon->show();

	// Create sequence
	activityModel = new ActivityModel(this);
	ActivityModel::declareQML();
	activityModel->loadActivitiesFromFile(ActivityModel::getActivityFile());

	sequence = new ActivitySequence(this);
	sequence->setActivities(activityModel->getActivities());
	connect(sequence, &ActivitySequence::activityTriggered, this, &MainWindow::handleActivityChange);
	sequence->start();

	QQuickView* qmlView = new QQuickView();
	qmlView->setResizeMode(QQuickView::SizeRootObjectToView);

	QQmlContext* qmlContext = qmlView->rootContext();
	qmlContext->setContextProperty("activitySequence", activityModel);
	qmlContext->setContextProperty("version", QString(SW_VERSION));
	qmlView->setSource(QUrl("qrc:/Settings.qml"));

	QWidget* qmlWidget = QWidget::createWindowContainer(qmlView, this);
	qmlWidget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	qmlWidget->setMinimumSize(200, 200);
	qmlWidget->setFocusPolicy(Qt::TabFocus);
	setCentralWidget(qmlWidget);

	// Start update timer for the icon
	QTimer* iconTimer = new QTimer(this);
	iconTimer->setSingleShot(false);
	iconTimer->setInterval(100);
	connect(iconTimer, SIGNAL(timeout()), this, SLOT(updateIcon()));
	iconTimer->start();

}

MainWindow::~MainWindow() {}

void MainWindow::updateIcon() {

	QPixmap iconFile(16, 16);
	iconFile.fill(Qt::transparent);

	QPainter painter(&iconFile);
	painter.setRenderHint(QPainter::Antialiasing, true);

	// Draw progress background
	QPen pen;
	pen.setColor(QColor(255, 255, 255, 60));
	pen.setWidth(2);
	painter.setPen(pen);
	painter.drawEllipse(1, 1, 14, 14);

	// Draw progress
	pen.setColor(QColor(255, 255, 255, 255));
	painter.setPen(pen);
	painter.drawArc(1, 1, 14, 14, 90 * 16, sequence->getCurrentActivityProgress() * (float) (-360 * 16));
	painter.end();

	icon->setIcon(QIcon(iconFile));

}

void MainWindow::handleActivityChange(Activity* activity) {

	screenLock->unlock();
	icon->setToolTip(activity->getName());
	if (activity->isLocking()) {
		screenLock->lock();
	}

}

void MainWindow::showMessage() {

	screenLock->lock();

//	QWidget* b = new QWidget(this);
//	b->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

//	QDesktopWidget* dw = QApplication::desktop();
//	QRect geom = dw->availableGeometry();
//	b->resize(100, 300);
//	b->move(geom.right() - b->width() - 10, geom.bottom() - b->height() - 10);
//	b->show();

//	qDebug() << "MSG";
//	icon->showMessage("The title", "Some Message");

}

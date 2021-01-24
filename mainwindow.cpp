#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controllerplaybackwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller_playback_window(new ControllerPlaybackWindow(Q_NULLPTR, &graphicsScene)),
    scene_headset(new SceneHeadset(&graphicsScene))
{
    graphicsScene.addRect(QRect(0,0,1,1));

    ui->setupUi(this);
    connect(ui->controller_playback_button, SIGNAL (released()), this, SLOT(handleControllerPlaybackButton()));
    update_timer = startTimer(1000);
}


MainWindow::~MainWindow()
{
    killTimer(update_timer);
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    qDebug( "beep");
    scene_headset->update();
}

void MainWindow::handleControllerPlaybackButton()
{
    controller_playback_window->show();
}

#include "controllerplaybackwindow.h"
#include "ui_controllerplaybackwindow.h"

ControllerPlaybackWindow::ControllerPlaybackWindow(QWidget *parent, QGraphicsScene *graphicsScene) :
    QMainWindow(parent),
    ui(new Ui::ControllerPlaybackWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(graphicsScene);
}

ControllerPlaybackWindow::~ControllerPlaybackWindow()
{
    delete ui;
}

void ControllerPlaybackWindow::startRecordingButtonPressed()
{
    qDebug( "startRecording");
}

void ControllerPlaybackWindow::replayButtonPressed()
{
    qDebug( "replay");
}


#ifndef CONTROLLERPLAYBACKWINDOW_H
#define CONTROLLERPLAYBACKWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class ControllerPlaybackWindow;
}

class ControllerPlaybackWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControllerPlaybackWindow(QWidget *parent, QGraphicsScene *);
    ~ControllerPlaybackWindow();

private slots:
    void startRecordingButtonPressed();
    void replayButtonPressed();

private:
    Ui::ControllerPlaybackWindow *ui;

};

#endif // CONTROLLERPLAYBACKWINDOW_H

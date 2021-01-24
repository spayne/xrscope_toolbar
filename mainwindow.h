#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QRectF>
#include <QGraphicsRectItem>

namespace Ui {
class MainWindow;

}

class ControllerPlaybackWindow;


// bind a headset in the graphics Scene to a headset in xr space
struct SceneHeadset
{
    SceneHeadset(QGraphicsScene *graphicsScene)
    {
        m_lastRect = QRectF(0,0,10,10);
        m_rect = graphicsScene->addRect(m_lastRect);
    }
    void update()
    {
        m_lastRect.moveRight(m_lastRect.x()+1.0f);
        m_rect->setRect(m_lastRect);
    }

    QRectF m_lastRect;
    QGraphicsRectItem *m_rect;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleControllerPlaybackButton();

private:
    void timerEvent(QTimerEvent *event);

    Ui::MainWindow *ui;
    QGraphicsScene graphicsScene;

    ControllerPlaybackWindow *controller_playback_window;
    SceneHeadset *scene_headset;
    int update_timer;

};

#endif // MAINWINDOW_H

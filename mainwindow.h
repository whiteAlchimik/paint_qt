#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QTimer>

#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void slotTimer();

private:
    Ui::MainWindow *ui;

    PaintScene *_ptrPaintScene;

    QTimer *_ptrTimer;

    const int _delayRendering = 50;
};

#endif // MAINWINDOW_H

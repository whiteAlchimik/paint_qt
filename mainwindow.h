#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QColorDialog>

#include "paintscene.h"

#include <QDebug>

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

signals:
    void signalChangeColor(const QColor &);

private slots:
    void slotTimer();

    void on_actionPencil_triggered();

    void on_actionBrush_triggered();

    void on_actionBucket_triggered();

    void on_actionText_triggered();

    void on_actionEraser_triggered();

    void on_actionPalette_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    PaintScene *_ptrPaintScene;
    QTimer *_ptrTimer;
    const int _delayRendering = 50;
};

#endif // MAINWINDOW_H

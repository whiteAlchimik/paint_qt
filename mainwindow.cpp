#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    _ptrPaintScene = new PaintScene(this);

    ui->graphicsView->setScene(_ptrPaintScene);

    _ptrTimer = new QTimer(this);
    connect(_ptrTimer, SIGNAL(timeout()), this, SLOT(slotTimer()));
    _ptrTimer->start(_delayRendering);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    _ptrTimer->start(_delayRendering);
    QWidget::resizeEvent(event);
}

void MainWindow::slotTimer()
{
    _ptrTimer->stop();
    _ptrPaintScene->setSceneRect(0,
                                 0,
                                 ui->graphicsView->width() - 20,
                                 ui->graphicsView->height() - 20);
}

void MainWindow::on_actionPencil_triggered()
{
    qDebug() << "on_actionPencil_triggered";
}

void MainWindow::on_actionBrush_triggered()
{

}

void MainWindow::on_actionBucket_triggered()
{

}

void MainWindow::on_actionText_triggered()
{

}

void MainWindow::on_actionEraser_triggered()
{

}

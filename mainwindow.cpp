#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-color: rgba(255, 0, 0, 155);");

    setWindowFlag(Qt::FramelessWindowHint, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_AlwaysStackOnTop, true);
    setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (!maximized)
        {
            dragPosition = event->globalPos() - frameGeometry().topLeft();
            event->accept();
        }
    }
}

void  MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        if (!maximized)
        {
            move(event->globalPos() - dragPosition);
            event->accept();
        }
    }
}

void  MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
}

void  MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    maximized = !maximized;

    if (maximized)
    {
        slot_maximized();
    }
    else
    {
        slot_restored();
    }
}

void  MainWindow::slot_minimized()
{
    setWindowState(Qt::WindowMinimized);
}

void  MainWindow::slot_restored()
{
    setWindowState(Qt::WindowNoState);
}

void  MainWindow::slot_maximized()
{
    setWindowState(Qt::WindowMaximized);
}

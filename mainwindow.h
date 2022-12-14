#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void  mousePressEvent(QMouseEvent *event);

    void  mouseMoveEvent(QMouseEvent *event);

    void  mouseReleaseEvent(QMouseEvent *event);

    void  mouseDoubleClickEvent(QMouseEvent *event);

    void  slot_minimized();

    void  slot_restored();

    void  slot_maximized();

private:
    Ui::MainWindow *ui;
    QPoint          dragPosition;
    bool            maximized = false;
};

#endif // MAINWINDOW_H

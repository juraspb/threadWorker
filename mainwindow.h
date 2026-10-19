// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QThread>

#include "worker.h"   // <-- ЭТОГО НЕ ХВАТАЛО

class MainWindow : public QMainWindow
{
    Q_OBJECT


private:
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QPushButton *startButton;
    QThread *workerThread;
    Worker *worker;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartButtonClicked();
    void onWorkFinished();
};
#endif // MAINWINDOW_H

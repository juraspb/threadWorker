// mainwindow.cpp
#include "mainwindow.h"
#include "worker.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);
    startButton = new QPushButton("Start Work", this);

    layout->addWidget(startButton);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);


    // Создаём поток и worker
    workerThread = new QThread(this);
    worker = new Worker();

    // Перемещаем worker в поток
    worker->moveToThread(workerThread);


    // Настраиваем связи
    connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(workerThread, &QThread::started, worker, [this]() { worker->doWork(10); });
    connect(worker, &Worker::workFinished, this, &MainWindow::onWorkFinished);
    connect(worker, &Worker::workFinished, workerThread, &QThread::quit);
    connect(workerThread, &QThread::finished, worker, &Worker::deleteLater);
    connect(workerThread, &QThread::finished, workerThread, &QThread::deleteLater);
}


MainWindow::~MainWindow()
{
    if (workerThread && workerThread->isRunning()) {
        workerThread->quit();
        workerThread->wait();
    }
}

void MainWindow::onStartButtonClicked()
{
    // qDebug() << "Starting work in thread:" << workerThread->threadId();
    // ПРАВИЛЬНО: статический метод класса
    qDebug() << "Worker running in thread ID:" << workerThread->isRunning();

    startButton->setEnabled(false);
    workerThread->start();
}

void MainWindow::onWorkFinished()
{
    qDebug() << "Work finished!";
    startButton->setEnabled(true);
}

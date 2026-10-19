// worker.cpp
#include "worker.h"
#include <QDebug>
#include <QThread>

Worker::Worker(QObject *parent) : QObject(parent) {}

/*
void Worker::doWork(int value)
{
    qDebug() << "Worker started in thread:" << QThread::currentThreadId();

    for (int i = 0; i < value; ++i) {
        // Имитация тяжёлой работы (сегментация, инференс, обработка кадра и т.п.)
        qDebug() << "Working..." << i;

        // Важно: не используйте QThread::sleep() — он блокирует поток.
        // Для имитации задержки используйте msleep().
        QThread::msleep(500);

        // Здесь можно добавить логику прерывания по флагу, если нужно
        // if (m_stopRequested) { emit workFinished(); return; }
    }

    qDebug() << "Work completed.";
    emit workFinished();
}
*/
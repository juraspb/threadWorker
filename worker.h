// worker.h
#ifndef WORKER_H
#define WORKER_H


#include <QObject>
#include <QDebug>
#include <QThread>


class Worker : public QObject
{
    Q_OBJECT

public:
    explicit Worker(QObject *parent = nullptr);

public slots:
    void doWork(int value) {
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


signals:
    void workFinished();
};
#endif // WORKER_H

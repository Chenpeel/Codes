#ifndef STUDENT_H
#define STUDENT_H
#include<QObject>

class student : public QObject{
    
    Q_OBJECT
public:
    explicit student(QObject *parent=0);
    ~student();
signals:
public slots:
void free_time_move();
void free_time_move(QString restTime);
};
#endif

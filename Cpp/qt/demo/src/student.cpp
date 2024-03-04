#include "../headers/student.h"

#include <QDebug>
#include <QObject>
student::student(QObject *parent) {}
student::~student() {}
void student::free_time_move() { qDebug() << "自由活动"; }
void student::free_time_move(QString restTime) {
  qDebug() << "自由活动: " << restTime.toUtf8().data();  // QString to char*
}
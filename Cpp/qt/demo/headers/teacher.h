#ifndef TEACHER_H
#define TEACHER_H

#include<QObject>

class teacher:public QObject
{
    Q_OBJECT
public:
    explicit teacher(QObject *parent=0);
    ~teacher();
signals:
    void free_time();    
    void free_time(QString restTime);
public slots:
    void onClassEndClicked(bool checked);
};
#endif 
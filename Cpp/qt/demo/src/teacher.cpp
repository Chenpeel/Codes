#include "../headers/teacher.h"

#include <QObject>

teacher::teacher(QObject *parent){

}
teacher::~teacher(){

}
void teacher::onClassEndClicked(bool checked) {
  QString restTime = "10 mins";
  emit free_time(restTime);
}
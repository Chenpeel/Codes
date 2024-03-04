#include "../headers/widget.h"

#include <QPushButton>
#include <QString>

#include "../headers/mypushbutton.h"
#include "../headers/student.h"
#include "../headers/teacher.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {

  // QPushButton *btn = new QPushButton;
  // btn->setParent(this); // 默认以顶层弹出，要把它放入widget
  // QString text = "hello"; //设置文字
  // btn->setText(text);
  // btn->move(80,60); //移动btn位置
  // resize(1000,618); //设置窗口大小
  // this->setWindowTitle("demo - title"); // 标题更改
  // this->setFixedSize(1000,618);// 固定无法更改窗口大小
  // mypushbutton *my_btn = new mypushbutton();
  // my_btn->setParent(this);
  // my_btn->setText("self hello");
  // my_btn->move(80,0);
  // connect(my_btn,&mypushbutton::clicked,this,&Widget::close);//点击即关闭窗口

  this->resize(1000, 618);
  QPushButton *class_end_btn = new QPushButton(this);
  QPushButton *end_window = new QPushButton("end",this);
  end_window->move(600,400);
  connect(end_window,&QPushButton::clicked,[=](){this->close();});

  class_end_btn->setText("下课");
  class_end_btn->setParent(this);
  class_end_btn->move(900, 580);
  zt = new teacher(this);
  st = new student(this);

  // connect(zt,&teacher::free_time,st,&student::free_time_move);


  void (teacher::*teacherSignals)(QString) = &teacher::free_time;
  void (student::*studentSlot)(QString) = &student::free_time_move;
  connect(zt, teacherSignals, st, studentSlot);
  // classIsOver();
  connect(class_end_btn, &QPushButton::clicked, zt, &teacher::onClassEndClicked);
  connect(class_end_btn, &QPushButton::clicked, this, &QWidget::close);
  // disconnect(zt,teacherSignals,st,studentSlot);
}
void Widget::classIsOver() {
  QString restTime = "10 mins";
  emit zt->free_time(restTime);  // 触发
}


Widget::~Widget() { delete ui; }

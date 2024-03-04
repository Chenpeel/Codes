#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include<QPushButton>

class mypushbutton : public QPushButton 
{
    Q_OBJECT

public:
    explicit mypushbutton(QWidget *parent=0);
    ~mypushbutton();

};


#endif
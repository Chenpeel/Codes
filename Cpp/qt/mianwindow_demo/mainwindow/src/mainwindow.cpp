#include "../headers/mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
#include <QIcon>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->resize(1000,618);
    // 菜单栏9
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    QMenu *fileMenu = bar->addMenu("File");
    QAction *createFile = fileMenu->addAction("Create new file");
    fileMenu->addSeparator();
    QAction *openFile = fileMenu->addAction("Open existed file");
    // ui->openFile->setIcon(QIcon(":/res/icon/icon.png"));//设置Icon
    connect(openFile,&QAction::triggered,this,[=](){
        // QDialog dlg;
        // dlg.exec();  //模态，阻塞，无法对其它窗口操作

        // QDialog *dlg = new QDialog(this); //堆区，不自动释放
        // dlg->show();       
        // dlg->setAttribute(Qt::WA_DeleteOnClose);  // 通过此操作自动从堆区释放
        
        // 常用静态对话框
        // QMessageBox::critical(this,"error","error");
        // QMessageBox::question(this,"yes_no","yes?",QMessageBox::No|QMessageBox::Save,QMessageBox::Yes);
        // QMessageBox::warning(this,"warning","warning");
        // QString file_name = QFileDialog::getOpenFileName(this,"open file","./res/icon","*.png");

        QColor color = QColorDialog::getColor(QColor(255,0,0));
        qDebug() <<color.red() << color.blue() << color.green();

        qDebug() << "debug";
    });


    QMenu *editMenu = bar->addMenu("Edit");
    QAction *editFile = editMenu->addAction("edit");

    // 工具栏
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::RightToolBarArea,toolBar); //默认位置
    toolBar->setFloatable(true);//浮动
    toolBar->setMovable(true); //移动

    QPushButton * btn  =new QPushButton("close",this);
    toolBar->addWidget(btn);
    QAction *closeOp = toolBar->addAction("close");

    connect(closeOp,&QAction::triggered,toolBar,&QToolBar::close);
    connect(btn,&QPushButton::clicked,toolBar,&QToolBar::close);
    
    
    // 状态栏
    QStatusBar * statusBar = new QStatusBar();
    setStatusBar(statusBar);
    QLabel *left_label = new QLabel(this);
    left_label->setText("左侧状态");   
    statusBar->addWidget(left_label);
    QLabel * right_label = new QLabel("右侧状态",this);
    statusBar->addPermanentWidget(right_label);

    // 浮动窗口
    QDockWidget *dock = new QDockWidget("dock",this);
    addDockWidget(Qt::BottomDockWidgetArea,dock);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    // 核心
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);
}
// 析构
MainWindow::~MainWindow(){  delete ui;  }

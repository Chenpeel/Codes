#include "mainwindow.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  const QString hostName = "localhost";
  const QString userName = "root";
  const QString pswd = "12345678";
  // Sql
  QStringList list = QSqlDatabase::drivers();
  qDebug() << list;
  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName(hostName);
  db.setUserName(userName);
  db.setPassword(pswd);
  db.setPort(3306);
  if (!db.open()) {
    qDebug() << "Database error occurred";
    qDebug() << db.lastError().text();
    return;
  } else {
    // db.setDatabaseName("mine_sweeper");
    qDebug() << "Database opened successfully";
  }
}

MainWindow::~MainWindow() { delete ui; }

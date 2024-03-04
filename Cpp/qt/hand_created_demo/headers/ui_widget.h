#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
class Ui_Widget {
 public:
  QLabel *LabDemo;
  QPushButton *btnClose;

  void setupUi(QWidget *Widget) {
    if (Widget->objectName().isEmpty()) {
      Widget->setObjectName(QStringLiteral("Widget"));
    }
    Widget->resize(450, 300);
    LabDemo = new QLabel(Widget);
    LabDemo->setObjectName(QStringLiteral("LabDemo"));
    LabDemo->setGeometry(QRect(50, 20, 201, 51));
    // 字体设置
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    font.setWeight(font.Weight::Thin);
    LabDemo->setFont(font);
    // 关闭钮设置
    btnClose = new QPushButton(Widget);
    btnClose->setObjectName(QStringLiteral("btnClose"));
    btnClose->setGeometry(QRect(150, 120, 75, 23));
    // 窗体信息
    retranslateUi(Widget);
    // 链接
    QObject::connect(btnClose, SIGNAL(clicked()), Widget, SLOT(close()));
    QMetaObject::connectSlotsByName(Widget);
  }

  void retranslateUi(QWidget *Widget) {
    Widget->setWindowTitle(
        QApplication::translate("Widget", "Demo", Q_NULLPTR));
    LabDemo->setText(
        QApplication::translate("Widget", "Hello, World!", Q_NULLPTR));
    btnClose->setText(QApplication::translate("Widget", "Close", Q_NULLPTR));
  }

};
namespace Ui {
class Widget : public Ui_Widget {};
}  // namespace Ui
QT_END_NAMESPACE
#endif

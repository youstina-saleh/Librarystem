/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_adminpage
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QRadioButton *radioButton_member;
    QRadioButton *radioButton_librarian;
    QPushButton *pushButton_add;
    QTableWidget *tableWidget;
    QPushButton *pushButton_load;

    void setupUi(QDialog *adminpage)
    {
        if (adminpage->objectName().isEmpty())
            adminpage->setObjectName("adminpage");
        adminpage->resize(394, 396);
        label = new QLabel(adminpage);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 51, 16));
        label_2 = new QLabel(adminpage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 51, 16));
        label_3 = new QLabel(adminpage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 41, 21));
        lineEdit_username = new QLineEdit(adminpage);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(70, 30, 113, 20));
        lineEdit_password = new QLineEdit(adminpage);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(70, 60, 113, 20));
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);
        radioButton_member = new QRadioButton(adminpage);
        radioButton_member->setObjectName("radioButton_member");
        radioButton_member->setGeometry(QRect(70, 90, 68, 17));
        radioButton_librarian = new QRadioButton(adminpage);
        radioButton_librarian->setObjectName("radioButton_librarian");
        radioButton_librarian->setGeometry(QRect(70, 110, 68, 17));
        pushButton_add = new QPushButton(adminpage);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(250, 100, 91, 21));
        tableWidget = new QTableWidget(adminpage);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 141, 191, 191));
        pushButton_load = new QPushButton(adminpage);
        pushButton_load->setObjectName("pushButton_load");
        pushButton_load->setGeometry(QRect(260, 300, 91, 21));

        retranslateUi(adminpage);

        QMetaObject::connectSlotsByName(adminpage);
    } // setupUi

    void retranslateUi(QDialog *adminpage)
    {
        adminpage->setWindowTitle(QCoreApplication::translate("adminpage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("adminpage", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("adminpage", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("adminpage", "Role", nullptr));
        radioButton_member->setText(QCoreApplication::translate("adminpage", "Member", nullptr));
        radioButton_librarian->setText(QCoreApplication::translate("adminpage", "Librarian", nullptr));
        pushButton_add->setText(QCoreApplication::translate("adminpage", "Add User", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("adminpage", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("adminpage", "Role", nullptr));
        pushButton_load->setText(QCoreApplication::translate("adminpage", "Load Users", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminpage: public Ui_adminpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H

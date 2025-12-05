/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_username;
    QLabel *label_password;
    QLabel *label_empty_error;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        label_username = new QLabel(centralwidget);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(240, 230, 291, 61));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_username->setFont(font);
        label_username->setScaledContents(false);
        label_password = new QLabel(centralwidget);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(240, 300, 211, 51));
        label_password->setFont(font);
        label_empty_error = new QLabel(centralwidget);
        label_empty_error->setObjectName("label_empty_error");
        label_empty_error->setGeometry(QRect(280, 450, 411, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_empty_error->setFont(font1);
        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(370, 240, 181, 51));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_username->setFont(font2);
        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(370, 300, 181, 51));
        lineEdit_password->setFont(font2);
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton_login = new QPushButton(centralwidget);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(310, 390, 161, 61));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        pushButton_login->setFont(font3);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 20, 671, 61));
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setUnderline(false);
        font4.setStrikeOut(false);
        font4.setKerning(true);
        label->setFont(font4);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 170, 341, 51));
        QFont font5;
        font5.setPointSize(9);
        font5.setBold(true);
        label_2->setFont(font5);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(270, 100, 351, 41));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setUnderline(true);
        label_3->setFont(font6);
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        label_username->setText(QCoreApplication::translate("LoginWindow", "Username:", nullptr));
        label_password->setText(QCoreApplication::translate("LoginWindow", "Password:", nullptr));
        label_empty_error->setText(QString());
        pushButton_login->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Knowledge is power and can only be found in books!", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Please log in with your username and password!", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "Welcome to Paper & Pencil Library", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

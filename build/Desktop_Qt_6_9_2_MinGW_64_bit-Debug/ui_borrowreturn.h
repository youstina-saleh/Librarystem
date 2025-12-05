/********************************************************************************
** Form generated from reading UI file 'borrowreturn.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWRETURN_H
#define UI_BORROWRETURN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_BorrowReturn
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *selectlabel_2;
    QLabel *selectlabel_3;
    QLabel *selectlabel_4;
    QLabel *selectlabel_5;
    QLabel *statusLabel;
    QLineEdit *returnID;
    QLineEdit *borrowID;
    QPushButton *borrowButton;
    QPushButton *returnButton;

    void setupUi(QDialog *BorrowReturn)
    {
        if (BorrowReturn->objectName().isEmpty())
            BorrowReturn->setObjectName("BorrowReturn");
        BorrowReturn->resize(846, 570);
        tableWidget = new QTableWidget(BorrowReturn);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(170, 90, 501, 211));
        label = new QLabel(BorrowReturn);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 10, 231, 61));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        selectlabel_2 = new QLabel(BorrowReturn);
        selectlabel_2->setObjectName("selectlabel_2");
        selectlabel_2->setGeometry(QRect(40, 360, 91, 31));
        selectlabel_3 = new QLabel(BorrowReturn);
        selectlabel_3->setObjectName("selectlabel_3");
        selectlabel_3->setGeometry(QRect(40, 460, 91, 31));
        selectlabel_4 = new QLabel(BorrowReturn);
        selectlabel_4->setObjectName("selectlabel_4");
        selectlabel_4->setGeometry(QRect(20, 310, 111, 31));
        selectlabel_5 = new QLabel(BorrowReturn);
        selectlabel_5->setObjectName("selectlabel_5");
        selectlabel_5->setGeometry(QRect(20, 410, 121, 31));
        statusLabel = new QLabel(BorrowReturn);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(50, 510, 711, 41));
        returnID = new QLineEdit(BorrowReturn);
        returnID->setObjectName("returnID");
        returnID->setGeometry(QRect(130, 460, 201, 28));
        borrowID = new QLineEdit(BorrowReturn);
        borrowID->setObjectName("borrowID");
        borrowID->setGeometry(QRect(130, 360, 201, 28));
        borrowButton = new QPushButton(BorrowReturn);
        borrowButton->setObjectName("borrowButton");
        borrowButton->setGeometry(QRect(350, 360, 90, 29));
        returnButton = new QPushButton(BorrowReturn);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(350, 460, 90, 29));

        retranslateUi(BorrowReturn);

        QMetaObject::connectSlotsByName(BorrowReturn);
    } // setupUi

    void retranslateUi(QDialog *BorrowReturn)
    {
        BorrowReturn->setWindowTitle(QCoreApplication::translate("BorrowReturn", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BorrowReturn", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BorrowReturn", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BorrowReturn", "Author ", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BorrowReturn", "Copies", nullptr));
        label->setText(QCoreApplication::translate("BorrowReturn", "Borrow / Return Page", nullptr));
        selectlabel_2->setText(QCoreApplication::translate("BorrowReturn", "Book ID: ", nullptr));
        selectlabel_3->setText(QCoreApplication::translate("BorrowReturn", "Book ID: ", nullptr));
        selectlabel_4->setText(QCoreApplication::translate("BorrowReturn", "Borrow a Book: ", nullptr));
        selectlabel_5->setText(QCoreApplication::translate("BorrowReturn", "Return a Book ", nullptr));
        statusLabel->setText(QCoreApplication::translate("BorrowReturn", "Status: ", nullptr));
        borrowButton->setText(QCoreApplication::translate("BorrowReturn", "Borrow", nullptr));
        returnButton->setText(QCoreApplication::translate("BorrowReturn", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BorrowReturn: public Ui_BorrowReturn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWRETURN_H

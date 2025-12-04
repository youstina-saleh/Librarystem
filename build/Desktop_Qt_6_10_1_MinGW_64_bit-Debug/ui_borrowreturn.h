/********************************************************************************
** Form generated from reading UI file 'borrowreturn.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
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
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_BorrowReturn
{
public:
    QLabel *selectlabel;
    QTableWidget *tableWidget;

    void setupUi(QDialog *BorrowReturn)
    {
        if (BorrowReturn->objectName().isEmpty())
            BorrowReturn->setObjectName("BorrowReturn");
        BorrowReturn->resize(401, 400);
        selectlabel = new QLabel(BorrowReturn);
        selectlabel->setObjectName("selectlabel");
        selectlabel->setGeometry(QRect(30, 30, 91, 31));
        tableWidget = new QTableWidget(BorrowReturn);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 80, 231, 192));

        retranslateUi(BorrowReturn);

        QMetaObject::connectSlotsByName(BorrowReturn);
    } // setupUi

    void retranslateUi(QDialog *BorrowReturn)
    {
        BorrowReturn->setWindowTitle(QCoreApplication::translate("BorrowReturn", "Dialog", nullptr));
        selectlabel->setText(QCoreApplication::translate("BorrowReturn", "Select a Book", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BorrowReturn", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BorrowReturn", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BorrowReturn", "Availability", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BorrowReturn: public Ui_BorrowReturn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWRETURN_H

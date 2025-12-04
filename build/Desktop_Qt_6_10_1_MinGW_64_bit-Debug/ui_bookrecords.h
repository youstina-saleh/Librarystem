/********************************************************************************
** Form generated from reading UI file 'bookrecords.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKRECORDS_H
#define UI_BOOKRECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_BookRecords
{
public:
    QLabel *searchlabel;
    QLineEdit *searchlineEdit;
    QComboBox *comboBox;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *addpushButton;
    QPushButton *deletepushButton;
    QPushButton *editpushButton;
    QLabel *errorlabel;

    void setupUi(QDialog *BookRecords)
    {
        if (BookRecords->objectName().isEmpty())
            BookRecords->setObjectName("BookRecords");
        BookRecords->resize(403, 404);
        searchlabel = new QLabel(BookRecords);
        searchlabel->setObjectName("searchlabel");
        searchlabel->setGeometry(QRect(20, 80, 71, 21));
        searchlineEdit = new QLineEdit(BookRecords);
        searchlineEdit->setObjectName("searchlineEdit");
        searchlineEdit->setGeometry(QRect(80, 80, 111, 31));
        comboBox = new QComboBox(BookRecords);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(80, 30, 111, 31));
        label = new QLabel(BookRecords);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 51, 21));
        tableWidget = new QTableWidget(BookRecords);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 120, 381, 192));
        addpushButton = new QPushButton(BookRecords);
        addpushButton->setObjectName("addpushButton");
        addpushButton->setGeometry(QRect(30, 330, 71, 21));
        deletepushButton = new QPushButton(BookRecords);
        deletepushButton->setObjectName("deletepushButton");
        deletepushButton->setGeometry(QRect(110, 330, 81, 21));
        editpushButton = new QPushButton(BookRecords);
        editpushButton->setObjectName("editpushButton");
        editpushButton->setGeometry(QRect(200, 330, 81, 21));
        errorlabel = new QLabel(BookRecords);
        errorlabel->setObjectName("errorlabel");
        errorlabel->setGeometry(QRect(80, 360, 251, 31));

        retranslateUi(BookRecords);

        QMetaObject::connectSlotsByName(BookRecords);
    } // setupUi

    void retranslateUi(QDialog *BookRecords)
    {
        BookRecords->setWindowTitle(QCoreApplication::translate("BookRecords", "Dialog", nullptr));
        searchlabel->setText(QCoreApplication::translate("BookRecords", "Search", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("BookRecords", "title", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("BookRecords", "author", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("BookRecords", "category", nullptr));

        label->setText(QCoreApplication::translate("BookRecords", "Search by", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BookRecords", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BookRecords", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BookRecords", "Author ", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BookRecords", "Category ", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("BookRecords", "Availability ", nullptr));
        addpushButton->setText(QCoreApplication::translate("BookRecords", "Add", nullptr));
        deletepushButton->setText(QCoreApplication::translate("BookRecords", "Delete", nullptr));
        editpushButton->setText(QCoreApplication::translate("BookRecords", "Edit", nullptr));
        errorlabel->setText(QCoreApplication::translate("BookRecords", "ALERT MESSAGE \"EMPTY UNTIL STH HAPPANS\" stock<3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookRecords: public Ui_BookRecords {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKRECORDS_H

/********************************************************************************
** Form generated from reading UI file 'report.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORT_H
#define UI_REPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Report
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topButtons;
    QPushButton *btnBorrowed;
    QPushButton *btnOverdue;
    QPushButton *btnMostBorrowed;
    QTableWidget *tableReports;
    QHBoxLayout *exportLayout;
    QSpacerItem *leftSpacer;
    QPushButton *btnExportCSV;
    QSpacerItem *rightSpacer;

    void setupUi(QDialog *Report)
    {
        if (Report->objectName().isEmpty())
            Report->setObjectName("Report");
        Report->resize(650, 480);
        verticalLayout = new QVBoxLayout(Report);
        verticalLayout->setObjectName("verticalLayout");
        topButtons = new QHBoxLayout();
        topButtons->setObjectName("topButtons");
        btnBorrowed = new QPushButton(Report);
        btnBorrowed->setObjectName("btnBorrowed");

        topButtons->addWidget(btnBorrowed);

        btnOverdue = new QPushButton(Report);
        btnOverdue->setObjectName("btnOverdue");

        topButtons->addWidget(btnOverdue);

        btnMostBorrowed = new QPushButton(Report);
        btnMostBorrowed->setObjectName("btnMostBorrowed");

        topButtons->addWidget(btnMostBorrowed);


        verticalLayout->addLayout(topButtons);

        tableReports = new QTableWidget(Report);
        tableReports->setObjectName("tableReports");
        tableReports->setColumnCount(0);
        tableReports->setRowCount(0);

        verticalLayout->addWidget(tableReports);

        exportLayout = new QHBoxLayout();
        exportLayout->setObjectName("exportLayout");
        leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        exportLayout->addItem(leftSpacer);

        btnExportCSV = new QPushButton(Report);
        btnExportCSV->setObjectName("btnExportCSV");

        exportLayout->addWidget(btnExportCSV);

        rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        exportLayout->addItem(rightSpacer);


        verticalLayout->addLayout(exportLayout);


        retranslateUi(Report);

        QMetaObject::connectSlotsByName(Report);
    } // setupUi

    void retranslateUi(QDialog *Report)
    {
        Report->setWindowTitle(QCoreApplication::translate("Report", "Reports Page", nullptr));
        btnBorrowed->setText(QCoreApplication::translate("Report", "Borrowed Books", nullptr));
        btnOverdue->setText(QCoreApplication::translate("Report", "Overdue Books", nullptr));
        btnMostBorrowed->setText(QCoreApplication::translate("Report", "Most Borrowed", nullptr));
        btnExportCSV->setText(QCoreApplication::translate("Report", "Export as CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Report: public Ui_Report {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORT_H

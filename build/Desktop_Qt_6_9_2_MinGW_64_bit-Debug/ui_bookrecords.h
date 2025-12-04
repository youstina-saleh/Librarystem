/********************************************************************************
** Form generated from reading UI file 'bookrecords.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKRECORDS_H
#define UI_BOOKRECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookRecords
{
public:
    QVBoxLayout *verticalLayout_main;

    // header
    QHBoxLayout *layout_header;
    QLabel *label_header;
    QSpacerItem *spacer_header;
    QPushButton *btnRefresh;

    // search area
    QHBoxLayout *layout_search;
    QComboBox *comboSearchType;
    QLineEdit *lineSearch;
    QPushButton *btnSearch;
    QPushButton *btnClearSearch;

    // table
    QTableWidget *tableBooks;

    // actions
    QHBoxLayout *layout_actions;
    QPushButton *btnAddBook;
    QPushButton *btnEditBook;
    QPushButton *btnDeleteBook;
    QPushButton *btnLowStock;
    QSpacerItem *spacer_actions;

    void setupUi(QWidget *BookRecords)
    {
        if (BookRecords->objectName().isEmpty())
            BookRecords->setObjectName("BookRecords");
        BookRecords->resize(850, 600);

        verticalLayout_main = new QVBoxLayout(BookRecords);
        verticalLayout_main->setObjectName("verticalLayout_main");

        // HEADER
        layout_header = new QHBoxLayout();
        layout_header->setObjectName("layout_header");

        label_header = new QLabel(BookRecords);
        label_header->setObjectName("label_header");
        layout_header->addWidget(label_header);

        spacer_header = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        layout_header->addItem(spacer_header);

        btnRefresh = new QPushButton(BookRecords);
        btnRefresh->setObjectName("btnRefresh");
        layout_header->addWidget(btnRefresh);

        verticalLayout_main->addLayout(layout_header);

        // SEARCH AREA
        layout_search = new QHBoxLayout();
        layout_search->setObjectName("layout_search");

        comboSearchType = new QComboBox(BookRecords);
        comboSearchType->setObjectName("comboSearchType");
        layout_search->addWidget(comboSearchType);

        lineSearch = new QLineEdit(BookRecords);
        lineSearch->setObjectName("lineSearch");
        layout_search->addWidget(lineSearch);

        btnSearch = new QPushButton(BookRecords);
        btnSearch->setObjectName("btnSearch");
        layout_search->addWidget(btnSearch);

        btnClearSearch = new QPushButton(BookRecords);
        btnClearSearch->setObjectName("btnClearSearch");
        layout_search->addWidget(btnClearSearch);

        verticalLayout_main->addLayout(layout_search);

        // BOOKS TABLE
        tableBooks = new QTableWidget(BookRecords);
        tableBooks->setObjectName("tableBooks");
        tableBooks->setColumnCount(6);
        QStringList headers;
        headers << QStringLiteral("ID")
                << QStringLiteral("Title")
                << QStringLiteral("Author")
                << QStringLiteral("Category")
                << QStringLiteral("Copies")
                << QStringLiteral("Status");
        tableBooks->setHorizontalHeaderLabels(headers);
        verticalLayout_main->addWidget(tableBooks);

        // ACTION BUTTONS
        layout_actions = new QHBoxLayout();
        layout_actions->setObjectName("layout_actions");

        btnAddBook = new QPushButton(BookRecords);
        btnAddBook->setObjectName("btnAddBook");
        layout_actions->addWidget(btnAddBook);

        btnEditBook = new QPushButton(BookRecords);
        btnEditBook->setObjectName("btnEditBook");
        layout_actions->addWidget(btnEditBook);

        btnDeleteBook = new QPushButton(BookRecords);
        btnDeleteBook->setObjectName("btnDeleteBook");
        layout_actions->addWidget(btnDeleteBook);

        btnLowStock = new QPushButton(BookRecords);
        btnLowStock->setObjectName("btnLowStock");
        layout_actions->addWidget(btnLowStock);

        spacer_actions = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        layout_actions->addItem(spacer_actions);

        verticalLayout_main->addLayout(layout_actions);

        retranslateUi(BookRecords);

        QMetaObject::connectSlotsByName(BookRecords);
    } // setupUi

    void retranslateUi(QWidget *BookRecords)
    {
        BookRecords->setWindowTitle(QCoreApplication::translate("BookRecords", "Book Records", nullptr));
        label_header->setText(QCoreApplication::translate("BookRecords", "Book Records", nullptr));
        btnRefresh->setText(QCoreApplication::translate("BookRecords", "Refresh", nullptr));

        comboSearchType->clear();
        comboSearchType->addItem(QCoreApplication::translate("BookRecords", "Title", nullptr));
        comboSearchType->addItem(QCoreApplication::translate("BookRecords", "Author", nullptr));
        comboSearchType->addItem(QCoreApplication::translate("BookRecords", "Category", nullptr));

        lineSearch->setPlaceholderText(QCoreApplication::translate("BookRecords", "Enter search text...", nullptr));
        btnSearch->setText(QCoreApplication::translate("BookRecords", "Search", nullptr));
        btnClearSearch->setText(QCoreApplication::translate("BookRecords", "Clear", nullptr));

        btnAddBook->setText(QCoreApplication::translate("BookRecords", "Add Book", nullptr));
        btnEditBook->setText(QCoreApplication::translate("BookRecords", "Edit Book", nullptr));
        btnDeleteBook->setText(QCoreApplication::translate("BookRecords", "Delete Book", nullptr));
        btnLowStock->setText(QCoreApplication::translate("BookRecords", "Low Stock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookRecords: public Ui_BookRecords {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKRECORDS_H

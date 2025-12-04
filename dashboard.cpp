#include "dashboard.h"
#include "ui_dashboard.h"
#include "bookrecords.h"
#include "borrowreturn.h"
#include "report.h"
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QDebug>
#include <QDir>
#include <QDate>
#include <QFile>
#include <fstream>
#include <sstream>
#include <vector>

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
    , currentUsername("")
    , currentUserRole("")
{
    ui->setupUi(this);
    setupDashboard();
}

Dashboard::Dashboard(const QString& username, const QString& role, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
    , currentUsername(username)
    , currentUserRole(role)
{
    ui->setupUi(this);
    setupDashboard();
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::setupDashboard()
{
    this->setWindowTitle("Library Management System - Dashboard");

    QList<QLabel*> labels = this->findChildren<QLabel*>();

    for (QLabel* label : labels) {
        QString objName = label->objectName();

        if (objName.contains("welcome", Qt::CaseInsensitive) ||
            label->text().contains("Welcome", Qt::CaseInsensitive)) {
            label->setText("Welcome, " + currentUsername + "!");
        }
        else if (objName.contains("role", Qt::CaseInsensitive) ||
                 label->text().contains("Role", Qt::CaseInsensitive)) {
            QString roleDisplay = currentUserRole;
            roleDisplay[0] = roleDisplay[0].toUpper();
            label->setText("Role: " + roleDisplay);
        }
    }

    configureRoleBasedAccess();
    loadStatistics();
}

void Dashboard::configureRoleBasedAccess()
{
    if (currentUserRole.toLower() == "member") {
        QPushButton* recordsBtn = this->findChild<QPushButton*>("recordspushButton");
        if (recordsBtn) {
            recordsBtn->setEnabled(false);
            recordsBtn->setToolTip("Only librarians and administrators can manage book records");
            recordsBtn->setStyleSheet("QPushButton:disabled { background-color: #cccccc; color: #666666; }");
        }
    }
}

Dashboard::BookStatistics Dashboard::calculateStatistics()
{
    BookStatistics stats;

    QString booksPath = "C:/Users/wassi/Downloads/Librarystem-main (1)/Librarystem-main/build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/books.txt";
    QString transPath = "C:/Users/wassi/Downloads/Librarystem-main (1)/Librarystem-main/build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/transactions.txt";

    std::ifstream booksFile(booksPath.toStdString());
    if (!booksFile.is_open()) {
        QMessageBox::warning(this, "File Error",
                             "Could not load books database.\nExpected location:\n" + booksPath);
        return stats;
    }

    std::string line;
    while (std::getline(booksFile, line)) {
        if (line.empty()) continue;

        stats.totalBooks++;

        std::istringstream iss(line);
        std::vector<std::string> fields;
        std::string token;

        while (std::getline(iss, token, '|')) {
            fields.push_back(token);
        }

        if (fields.size() >= 6) {
            try {
                int totalCopies = std::stoi(fields[4]);
                int availableCopies = std::stoi(fields[5]);
                stats.borrowedBooks += (totalCopies - availableCopies);
            } catch (const std::exception&) {}
        }
    }
    booksFile.close();

    std::ifstream transFile(transPath.toStdString());
    if (!transFile.is_open()) {
        return stats;
    }

    QDate currentDate = QDate::currentDate();

    while (std::getline(transFile, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::vector<std::string> fields;
        std::string token;

        while (std::getline(iss, token, '|')) {
            fields.push_back(token);
        }

        if (fields.size() >= 8) {
            std::string isReturnedStr = fields[7];

            if (isReturnedStr == "0" || isReturnedStr == "false") {
                std::string dueDateStr = fields[4];
                QDate dueDate = QDate::fromString(QString::fromStdString(dueDateStr), "yyyy-MM-dd");

                if (dueDate.isValid() && dueDate < currentDate) {
                    stats.overdueBooks++;
                }
            }
        }
    }
    transFile.close();

    return stats;
}

void Dashboard::loadStatistics()
{
    BookStatistics stats = calculateStatistics();
    updateStatisticsDisplay(stats.totalBooks, stats.borrowedBooks, stats.overdueBooks);
}

void Dashboard::updateStatisticsDisplay(int totalBooks, int borrowedBooks, int overdueBooks)
{
    QTableWidget* tableWidget = this->findChild<QTableWidget*>("tableWidget");

    if (!tableWidget) {
        QList<QTableWidget*> tables = this->findChildren<QTableWidget*>();
        if (!tables.isEmpty()) {
            tableWidget = tables.first();
        } else {
            return;
        }
    }

    if (tableWidget->rowCount() == 0 || tableWidget->columnCount() < 3) {
        return;
    }

    QTableWidgetItem* totalItem = tableWidget->item(0, 0);
    if (!totalItem) {
        totalItem = new QTableWidgetItem();
        tableWidget->setItem(0, 0, totalItem);
    }
    totalItem->setText(QString::number(totalBooks));
    totalItem->setTextAlignment(Qt::AlignCenter);
    totalItem->setForeground(QBrush(QColor("#2c3e50")));
    QFont totalFont = totalItem->font();
    totalFont.setPointSize(16);
    totalFont.setBold(true);
    totalItem->setFont(totalFont);

    QTableWidgetItem* borrowedItem = tableWidget->item(0, 1);
    if (!borrowedItem) {
        borrowedItem = new QTableWidgetItem();
        tableWidget->setItem(0, 1, borrowedItem);
    }
    borrowedItem->setText(QString::number(borrowedBooks));
    borrowedItem->setTextAlignment(Qt::AlignCenter);
    borrowedItem->setForeground(QBrush(QColor("#3498db")));
    QFont borrowedFont = borrowedItem->font();
    borrowedFont.setPointSize(16);
    borrowedFont.setBold(true);
    borrowedItem->setFont(borrowedFont);

    QTableWidgetItem* overdueItem = tableWidget->item(0, 2);
    if (!overdueItem) {
        overdueItem = new QTableWidgetItem();
        tableWidget->setItem(0, 2, overdueItem);
    }
    overdueItem->setText(QString::number(overdueBooks));
    overdueItem->setTextAlignment(Qt::AlignCenter);

    if (overdueBooks > 0) {
        overdueItem->setForeground(QBrush(QColor("#e74c3c")));
    } else {
        overdueItem->setForeground(QBrush(QColor("#27ae60")));
    }

    QFont overdueFont = overdueItem->font();
    overdueFont.setPointSize(16);
    overdueFont.setBold(true);
    overdueItem->setFont(overdueFont);
}

void Dashboard::on_recordspushButton_clicked()
{
    BookRecords *bookRecordsPage = new BookRecords(this);
    bookRecordsPage->setWindowTitle("Book Records Management");
    bookRecordsPage->setModal(true);

    bookRecordsPage->exec();
    delete bookRecordsPage;

    loadStatistics();
}

void Dashboard::on_borrowReturnpushButton_2_clicked()
{
    BorrowReturn *borrowReturnPage = new BorrowReturn(this);
    borrowReturnPage->setWindowTitle("Borrow/Return Books");
    borrowReturnPage->setModal(true);

    borrowReturnPage->exec();
    delete borrowReturnPage;

    loadStatistics();
}

void Dashboard::on_pushButton_3_clicked()
{
    Report *reportPage = new Report(this);
    reportPage->setWindowTitle("Library Reports");
    reportPage->setModal(true);

    reportPage->exec();
    delete reportPage;
}

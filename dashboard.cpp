#include "dashboard.h"
#include "ui_dashboard.h"
#include "bookrecords.h"
#include "borrowreturn.h"
#include "report.h"

#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTableWidgetItem>

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    currentUsername = "Guest";
    currentUserRole = "";
    setupDashboard();
    loadStatistics();
}

Dashboard::Dashboard(const QString& username, const QString& role, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
    , currentUsername(username)
    , currentUserRole(role)
{
    ui->setupUi(this);
    setupDashboard();
    loadStatistics();
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::setupDashboard()
{
    // Show welcome message with current username
    ui->welcomelabel->setText(QString("Welcome %1").arg(currentUsername));

    // Configure role-based access
    configureRoleBasedAccess();

    // Configure the summary table based on user role
    ui->tableWidget->setRowCount(1);
    if (currentUserRole == "member") {
        // Members see only Borrowed and Overdue
        ui->tableWidget->setColumnCount(2);
        QStringList headers;
        headers << "Borrowed" << "Overdue";
        ui->tableWidget->setHorizontalHeaderLabels(headers);
    } else {
        // Librarians/admins see Total Books, Borrowed, and Overdue
        ui->tableWidget->setColumnCount(3);
        QStringList headers;
        headers << "Total Books" << "Borrowed" << "Overdue";
        ui->tableWidget->setHorizontalHeaderLabels(headers);
    }
}

Dashboard::BookStatistics Dashboard::calculateStatistics()
{
    BookStatistics stats;

    // Only calculate total books for non-member users (librarians/admins)
    if (currentUserRole != "member") {
        // Read books.txt (supports '|' or ',' separated lines)
        QFile booksFile("books.txt");
        if (booksFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&booksFile);
            while (!in.atEnd()) {
                const QString line = in.readLine().trimmed();
                if (line.isEmpty())
                    continue;

                QStringList parts = line.split('|');
                if (parts.size() < 4) {
                    parts = line.split(','); // fallback for comma format
                }

                if (!parts.isEmpty()) {
                    stats.totalBooks += 1;
                    // try to add copies if available (column 4 for '|' format, 3 for ',' format)
                    bool ok = false;
                    if (parts.size() >= 5) {
                        int copies = parts.at(4).trimmed().toInt(&ok);
                        if (ok) stats.totalBooks += (copies - 1); // include extra copies
                    } else if (parts.size() >= 4) {
                        int copies = parts.at(3).trimmed().toInt(&ok);
                        if (ok) stats.totalBooks += (copies - 1);
                    }
                }
            }
        }
    }

    // Read borrow.txt (per-user stats)
    QFile borrowFile("borrow.txt");
    if (borrowFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&borrowFile);
        const QDate today = QDate::currentDate();
        while (!in.atEnd()) {
            const QString line = in.readLine().trimmed();
            if (line.isEmpty())
                continue;

            const QStringList parts = line.split(',');
            if (parts.size() != 3)
                continue;

            // parts: username, bookID, dueDate
            const QString borrower = parts.at(0).trimmed();
            if (borrower != currentUsername)
                continue; // only count current user

            stats.borrowedBooks += 1;
            const QDate due = QDate::fromString(parts.at(2).trimmed(), "yyyy-MM-dd");
            if (due.isValid() && due < today)
                stats.overdueBooks += 1;
        }
    }

    return stats;
}

void Dashboard::updateStatisticsDisplay(int totalBooks, int borrowedBooks, int overdueBooks)
{
    if (currentUserRole == "member") {
        // Members see only Borrowed and Overdue (2 columns)
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(borrowedBooks)));
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(overdueBooks)));
    } else {
        // Librarians/admins see Total Books, Borrowed, and Overdue (3 columns)
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(totalBooks)));
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(borrowedBooks)));
        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(overdueBooks)));
    }
}

void Dashboard::loadStatistics()
{
    BookStatistics stats = calculateStatistics();
    updateStatisticsDisplay(stats.totalBooks, stats.borrowedBooks, stats.overdueBooks);
}

void Dashboard::on_recordspushButton_clicked()
{
    // Members don't have access to book records
    if (currentUserRole == "member") {
        return;
    }
    
    // BookRecords is a QWidget - create it as a separate window
    BookRecords *records = new BookRecords(nullptr); // No parent to make it independent
    records->setAttribute(Qt::WA_DeleteOnClose);
    records->setWindowFlags(Qt::Window); // Make it a proper window
    records->setWindowTitle("Book Records");
    records->show();
}


void Dashboard::on_borrowReturnpushButton_2_clicked()
{
    // BorrowReturn is a QDialog and expects the current username.
    BorrowReturn *dialog = new BorrowReturn(currentUsername, this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setModal(false); // Make it non-modal so dashboard stays visible
    dialog->show();
    
    // Connect to dialog's finished signal to refresh stats when it closes
    connect(dialog, &QDialog::finished, this, [this]() {
        loadStatistics();
    });
}


void Dashboard::configureRoleBasedAccess()
{
    // Hide Book Records and Reports buttons for members
    if (currentUserRole == "member") {
        ui->recordspushButton->setVisible(false);
        ui->pushButton_3->setVisible(false);
    } else {
        // Show buttons for librarians/admins
        ui->recordspushButton->setVisible(true);
        ui->pushButton_3->setVisible(true);
    }
}

void Dashboard::on_pushButton_3_clicked()
{
    // Members don't have access to reports
    if (currentUserRole == "member") {
        return;
    }
    
    Report* report = new Report(this);
    report->setAttribute(Qt::WA_DeleteOnClose);
    report->setModal(false); // Make it non-modal so dashboard stays visible
    report->show();
}


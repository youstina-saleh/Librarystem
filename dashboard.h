#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    explicit Dashboard(const QString& username, const QString& role, QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_recordspushButton_clicked();
    void on_borrowReturnpushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Dashboard *ui;
    QString currentUsername;
    QString currentUserRole;

    // Private methods
    void setupDashboard();
    void loadStatistics();
    void updateStatisticsDisplay(int totalBooks, int borrowedBooks, int overdueBooks);
    void configureRoleBasedAccess();

    // Statistics calculation
    struct BookStatistics {
        int totalBooks = 0;
        int borrowedBooks = 0;
        int overdueBooks = 0;
    };
    BookStatistics calculateStatistics();
};

#endif // DASHBOARD_H

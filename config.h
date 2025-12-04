#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QDir>
#include <QFile>

class Config {
public:
    // File paths - Using your actual paths
    static QString getBooksFilePath() {
        return "C:/Users/wassi/Downloads/Librarystem-main (1)/Librarystem-main/build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/books.txt";
    }

    static QString getTransactionsFilePath() {
        return "C:/Users/wassi/Downloads/Librarystem-main (1)/Librarystem-main/build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/transactions.txt";
    }

    static QString getUsersFilePath() {
        return "C:/Users/wassi/Downloads/Librarystem-main (1)/Librarystem-main/build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/users.txt";
    }

    // Application settings
    static constexpr int MIN_PASSWORD_LENGTH = 8;
    static constexpr int MAX_BORROW_DAYS = 14;
    static constexpr double OVERDUE_FINE_PER_DAY = 1.0;

    // UI settings
    static QString getApplicationTitle() {
        return "Library Management System";
    }

    // Helper to check if all files exist
    static bool validateFilePaths() {
        QStringList paths = {
            getBooksFilePath(),
            getTransactionsFilePath(),
            getUsersFilePath()
        };

        bool allExist = true;
        for (const QString& path : paths) {
            if (!QFile::exists(path)) {
                qWarning() << "File not found:" << path;
                allExist = false;
            } else {
                qDebug() << "File found:" << path;
            }
        }
        return allExist;
    }

    // Get the base directory
    static QString getBaseDirectory() {
        return "C:/Users/wassi/Downloads/Librarystem-main (1)/Librarystem-main/build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/";
    }

    // Create file if it doesn't exist
    static bool ensureFileExists(const QString& filePath) {
        if (!QFile::exists(filePath)) {
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly)) {
                file.close();
                qDebug() << "Created file:" << filePath;
                return true;
            } else {
                qWarning() << "Failed to create file:" << filePath;
                return false;
            }
        }
        return true;
    }

    // Initialize all required files
    static bool initializeFiles() {
        return ensureFileExists(getBooksFilePath()) &&
               ensureFileExists(getTransactionsFilePath()) &&
               ensureFileExists(getUsersFilePath());
    }
};

#endif // CONFIG_H

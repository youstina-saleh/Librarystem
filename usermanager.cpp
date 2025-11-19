#include "usermanager.h"
#include <cctype>

UserManager::UserManager() {
    addTestAdmin();
}

void UserManager::addTestAdmin() {
    users.emplace_back("admin", "admin1234", "Admin");
}

bool UserManager::login(const string& username, const string& password, string& outRole) {
    for (const auto& u : users) {
        if (u.getUsername() == username && u.getPassword() == password) {
            outRole = u.getRole();
            return true;
        }
    }
    return false;
}

bool UserManager::isDuplicateUser(const string& username) const {
    for (const auto& u : users) {
        if (u.getUsername() == username) return true;
    }
    return false;
}

bool UserManager::isValidPassword(const string& password) const {
    if (password.size() < 8) return false;
    bool hasDigit = false;
    for (char c : password)
        if (std::isdigit((unsigned char)c))
            hasDigit = true;
    return hasDigit;
}

void UserManager::addUser(const string& username, const string& password, const string& role) {
    users.emplace_back(username, password, role);
}

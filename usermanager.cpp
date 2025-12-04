#include "usermanager.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <algorithm>

using namespace std;

//done
UserManager::UserManager(const string& filePath) {
    this->filePath = filePath;

    ifstream file(filePath);
    if (!file.is_open()) {
        // Create the file
        ofstream newFile(filePath);
        if (!newFile.is_open())
            throw runtime_error("Cannot create users file: " + filePath);
}
}
bool UserManager::validatePassword(const std::string& password){
    if (password.length() < 8)
        return false;

    bool hasDigit = false;
    for (char c : password)
        if (isdigit(c))
            hasDigit = true;

    return hasDigit;
}

bool UserManager::usernameExists(const std::string& username) {
    std::vector<User> users = loadUsers();
    for (auto& u : users)
        if (u.getUsername() == username)
            return true;
    return false;
}

//done
vector<User> UserManager::loadUsers() {
    vector<User> users;
    ifstream inFile(filePath);
    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string u, p, r;
        if (!(iss >> u >> p >> r)) continue; // skip bad lines
        users.emplace_back(u, p, r);
    }
    return users;
}

bool UserManager::saveAllUsers(const std::vector<User>& users) {
    std::ofstream outFile(filePath, std::ios::trunc);
    if (!outFile.is_open()) return false;

    for (auto& u : users)
        outFile << u.getUsername() << " " << u.getPassword() << " " << u.getRole() << "\n";

    return true;
}

bool UserManager::addUser(const User& user) {
    if (usernameExists(user.getUsername()))
        return false;

    if (!validatePassword(user.getPassword()))
        return false;

    ofstream out(filePath, ios::app);
    if (!out.is_open()) {
        return false;
    }

    out << user.getUsername() << " "
        << user.getPassword() << " "
        << user.getRole() << "\n";

    return true;
}

bool UserManager::deleteUser(const string& username) {
    std::vector<User> users = loadUsers();

    // Find the user to check their role because we need to prevent
    //deleting the admin in this way.
    auto it = std::find_if(users.begin(), users.end(),
                           [&](const User& u){ return u.getUsername() == username; });

    if (it == users.end())
        return false; // user not found

    if (it->getRole() == "admin")
        return false;

    //size_t usually used for itirators
    //we here move the selected user to the end of the vector.
    users.erase(remove_if(users.begin(), users.end(),
                               [&](const User& u){ return u.getUsername() == username; }),
                users.end());

    return saveAllUsers(users);
}

bool UserManager::login(const std::string& username, const std::string& password, std::string& roleOut) {
    vector<User> users = loadUsers();
    for (auto& u : users) {
        if (u.getUsername() == username && u.getPassword() == password) {
            roleOut = u.getRole();
            return true;
        }
    }
    return false;
}

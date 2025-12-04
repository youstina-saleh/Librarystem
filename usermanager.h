#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "user.h"
#include <vector>
#include <string>
using namespace std;

class UserManager {
private:
    string filePath;

public:
    UserManager(const string& filePath);

    bool addUser(const User& user);
    bool usernameExists(const string& username);
    bool validatePassword(const string& password);
    vector<User> loadUsers();
    bool saveAllUsers(const vector<User>& users);
    bool deleteUser(const string& username);
    bool login(const string& username, const string& password, string& roleOut);
};

#endif

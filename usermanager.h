#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <string>
#include "user.h"

using std::vector;
using std::string;

class UserManager {
private:
    vector<User> users;

public:
    UserManager();

    bool login(const string& username, const string& password, string& outRole);
    bool isDuplicateUser(const string& username) const;
    bool isValidPassword(const string& password) const;
    void addUser(const string& username, const string& password, const string& role);

    //I am waiting for member3 who will handle the files
    void loadUsersFromFile(const std::string& filename);
    void saveUsersToFile(const std::string& filensame) const;



    void addTestAdmin();
};

#endif // USERMANAGER_H

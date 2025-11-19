#ifndef USER_H
#define USER_H

#include <string>
using std::string;

class User {
private:
    string username;
    string password;
    string role;

public:
    User() = default;
    User(const string& u, const string& p, const string& r);

    string getUsername() const;
    string getPassword() const;
    string getRole() const;

    void setData(const string& u, const string& p, const string& r);

    // for file storage or debugging
    string toString() const;
};

#endif

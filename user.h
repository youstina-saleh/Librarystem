#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string username;
    string password;
    string role;

public:
    User() {}
    User(const string& u, const string& p, const string& r);

    string getUsername() const;
    string getPassword() const;
    string getRole() const;

    void setData(const string& u, const string& p, const string& r);
    string toString() const;
};

#endif

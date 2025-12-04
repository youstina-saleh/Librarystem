#include "user.h"

User::User(const string& u, const string& p, const string& r)
    : username(u), password(p), role(r) {}

string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

string User::getRole() const {
    return role;
}

void User::setData(const string& u, const string& p, const string& r) {
    username = u;
    password = p;
    role = r;
}

string User::toString() const {
    return username + " " + password + " " + role;
}

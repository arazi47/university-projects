#ifndef SESSION_H
#define SESSION_H

#include "Observer.h"
#include "UserWnd.h"

class Repository {
public:
       Repository(Session &s) {
           // Read users
            ifstream f("/home/sysadmin/PracticExamOOP/users");
            string username;

            while (f >> username) {
                users.emplace_back(new UserWnd(username, s));
            }
       }

      const vector<UserWnd*> &getUsers() const { return users; }
private:
    vector<UserWnd*> users;
};

#endif // SESSION_H

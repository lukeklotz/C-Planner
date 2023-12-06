#include <iostream>
#include "linkedlist.h"
using namespace std;

class userMngr
{
    private:
        userInfo user;
        linkedlist list;
    public:
        bool isValidUser(userInfo userFile);
        bool doesUserExist(userInfo userFile);
        void createNewAccount();
        void writeNewProfile();
        void loadUserData(linkedlist& list);
        userInfo enterUserInfo();
};
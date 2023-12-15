#include <iostream>
#include "linkedlist.h"
using namespace std;

class userMngr
{
    private:
        userInfo user;
        linkedlist list;
    public:
       
	bool isAvailableUser(userInfo userFile);
        bool doesUserExist(userInfo userFile);
	bool isValidUser(userInfo userFile);
	
        void createNewAccount();
        void writeNewProfile();
        void loadUserData(linkedlist& list);
        void writeUserData(linkedlist& list, userInfo newUser);
	
        userInfo enterUserInfo();
};

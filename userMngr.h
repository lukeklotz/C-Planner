#include <iostream>
#include "userInfo.h"
using namespace std;

class userMngr
{
    private:
        userInfo user;
    public:
        bool isValidUser(userInfo userFile); 
        void createNewAccount();
};
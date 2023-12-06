#include <iostream>
using namespace std;

class userInfo
{
    private:
        char* username;
        char* password;
    public:
        userInfo();
        void setUserInfo(char* username, char* password);
        char* getUsername();
        char* getPassword();
        void printCurrUser(); //test function
};
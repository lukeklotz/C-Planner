#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "userMngr.h"

using namespace std;

int main() {
    
    
    const int maxSize = 255;

    char username[maxSize];
    char password[maxSize];

    cout << "username: ";
    cin.getline(username, maxSize, '\n');

    cout << "password: ";
    cin.getline(password, maxSize, '\n');

    userInfo info;
    info.setUserInfo(username, password);

    userMngr mngr;
    if(mngr.isValidUser(info)){
        cout << "true" << endl;
    } else {
        cout << "flase" << endl;
    }
    

}
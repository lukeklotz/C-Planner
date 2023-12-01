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

    char* createNewAcc;
   
    while(createNewAcc != "Y" || createNewAcc != "N"){
        cout << "Create new account? Enter Y/N: ";
        cin >> createNewAcc;
        if(createNewAcc == "Y"){
            //create new account
        } else {
            break;
        }
    }

    cout << "username: ";
    cin.getline(username, maxSize, '\n');

    cout << "password: ";
    cin.getline(password, maxSize, '\n');

    userInfo info;
    info.setUserInfo(username, password);

    userMngr mngr;
    bool isValid = false;
    isValid = mngr.isValidUser(info);

        do {
            mngr.isValidUser(info);

            if (!isValid) {
                cout << "Invalid credentials! Please try again or create a new account" << endl;

                cout << "username: ";
                cin.getline(username, maxSize, '\n');

                cout << "password: ";
                cin.getline(password, maxSize, '\n');

            }

        } while (!mngr.isValidUser(info));

    cout << "Welcome!" << endl;
    

}
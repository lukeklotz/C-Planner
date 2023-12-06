#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "userMngr.h"

using namespace std;


int main() {
    
    //const int maxSize = 255;

    //char username[maxSize];
    //char password[maxSize];

    char createNewAcc;

    // load current user data
    userMngr dataFile;
    linkedlist dataList;

    dataFile.loadUserData(dataList);

    while (createNewAcc != 'Y' && createNewAcc != 'N') {
        cout << "Create new account? Enter Y/N: ";
        cin >> createNewAcc;
        if (createNewAcc == 'Y') {
            // create new account

        } else {
            break;
        }
    }

    cin.ignore(101, '\n');

    userInfo info;
    userMngr newUser;

    info = newUser.enterUserInfo(); 
    info.printCurrUser();

    bool isValid = false;
    isValid = newUser.isValidUser(info);

        do {
            if (!isValid) {
                cout << "That name is already taken. Please choose a differnt username: " << endl;

                info = newUser.enterUserInfo(); 

                break;
            }

        } while (!newUser.isValidUser(info));

    cout << "Welcome!" << endl;
    

}
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "userMngr.h"

using namespace std;


int main() {

    userMngr dataFile;
    linkedlist dataList;

    dataFile.loadUserData(dataList);

    char createNewAcc;
    
    
    userMngr newUser;
    userInfo info;
    
    
    bool isValid = false;

    /****************************/
    /*                          */
    /*------CREATE ACCOUNT------*/
    /*                          */
    /****************************/

    while (createNewAcc != 'Y' && createNewAcc != 'N') {
        cout << "Create new account? Enter Y/N: ";
        cin >> createNewAcc;
        if (createNewAcc == 'Y') {
            // create new account
            cin.ignore(101, '\n');
            info = newUser.enterUserInfo();
            isValid = newUser.isAvailableUser(info);
            do {
                if (!isValid) {
                    cout << "That name is already taken. Please choose a differnt username: " << endl;
                    info = newUser.enterUserInfo(); 
                    isValid = newUser.isAvailableUser(info);
                }
            } while (!newUser.isAvailableUser(info));
            //write new user data
            newUser.writeUserData(dataList, info);
        } else {
            break;
        }
    }


    /****************************/
    /*                          */
    /*----------LOGIN-----------*/
    /*                          */
    /****************************/

    //cin.ignore(101, '\n');

    //info = newUser.enterUserInfo(); 
    //info.printCurrUser();


    /*
    isValid = newUser.isValidUser(info);
        do {
            if (!isValid) {
                cout << "That name is already taken. Please choose a differnt username: " << endl;

                info = newUser.enterUserInfo(); 

                break;
            }

        } while (!newUser.isValidUser(info));
    */

    cout << "Welcome!" << endl;
    

}
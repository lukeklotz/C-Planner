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

    char hasAccount;
    cout << "Have an account? Enter Y/N:";
    cin >> hasAccount;
    if(hasAccount == 'Y'){
	
	cin.ignore(101, '\n');
	info = newUser.enterUserInfo();
	isValid = newUser.isValidUser(info); 

	if(isValid == false) {
		while(isValid == false){
			cout << "username already taken!" << endl;
			
			info = newUser.enterUserInfo();
			isValid = newUser.isValidUser(info);	
		}	
	}	
   
    } else { //create new account
	
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
    }

	cout << "welcome!" << endl;

 }

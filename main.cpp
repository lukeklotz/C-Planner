#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string>
#include "userMngr.h"

using namespace std;



int main() {

    userMngr dataFile;
    linkedlist dataList;

    dataFile.loadUserData(dataList);

    char createNewAcc;
    
    
    userMngr newUser;
    userInfo info;

    dataList.printList();    


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
			cout << "The username or password you entered is incorrect!" << endl;
			
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
            } while (!newUser.isAvailableUser(info) || newUser.quit(info));
            //write new user data
            newUser.writeUserData(dataList, info);
		
	
	    dataList.append(info);
	    dataList.printList();     
	
	
        } else {
            break;
      	}
    	}
    }

	cout << "welcome!" << endl;
	
	string userInput;
	 
	while (userInput != "q") {
        	cout << "Enter 'q' to quit: ";
        	cin >> userInput;
   	}	
}

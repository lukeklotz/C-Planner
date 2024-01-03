#include <iostream>
#include <fstream>
#include <cstring>
#include "userMngr.h"

using namespace std;

bool userMngr::isAvailableUser(userInfo userFile){
    
    ifstream inputFile("usernames.txt");

    if (!inputFile.is_open()) {
        cerr << "Could not open the file!" << std::endl;
        return 1; 
    }

    //return username from user object  
    
    char* name = userFile.getUsername();
    char* pass = userFile.getPassword();

    char passOnFile[101];
    char nameOnFile[101];


    while(!inputFile.eof()){
        
        inputFile.getline(nameOnFile, 101, ';');
        inputFile.getline(passOnFile, 101, '\n');

        if(strcmp(nameOnFile, name) == 0) {
            inputFile.close(); // Close the file before returning
            return false;      // Return false if the username is already taken
        }

    }
    inputFile.close();
    return true;
}

bool userMngr::isValidUser(userInfo userFile)
{
	ifstream inputFile("usernames.txt");
	
	if(!inputFile.is_open()) {
		cerr << "Count not open the file!" <<std::endl;
		return 1;	
	}
	
	char* name = userFile.getUsername();
	char* pass = userFile.getPassword();
	
	char nameOnFile[101];
	char passOnFile[101];

	while(!inputFile.eof())
	{
		inputFile.getline(nameOnFile, 101, ';');
		inputFile.getline(passOnFile, 101, '\n');

		if(strcmp(nameOnFile, name) == 0 && strcmp(passOnFile, pass) == 0){
			return true;
		}
	}
	inputFile.close();
	return false;
}
void userMngr::createNewAccount(){
    
    char username[101];
    char password[101];
    
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    userInfo newUser;

    newUser.setUserInfo(username, password);

}
void userMngr::loadUserData(linkedlist& userList){

    
    ifstream inputFile("usernames.txt");

    if (!inputFile.is_open()) {
        cerr << "Could not open the file!" << std::endl;
    }

    char nameOnFile[101];
    char passOnFile[101];

    while(!inputFile.eof()){

        
        inputFile.getline(nameOnFile, 101, ';');
        inputFile.getline(passOnFile, 101, '\n');

        userInfo newUser;

        newUser.setUserInfo(nameOnFile, passOnFile);

        userList.append(newUser);

    }
    inputFile.close();
    
}

void userMngr::writeUserData(linkedlist& userList, userInfo newUser){
    // Assuming 'userList' is not used in this function

    // Open the file in append mode
    ofstream outputFile("usernames.txt", ios::app);

    if (outputFile.is_open()) {
        // Write the username and password to the file
	cout << "here" << endl;
        outputFile << newUser.getUsername() << ";";
        outputFile <<newUser.getPassword() << "\n";

        // Close the file
        outputFile.close();
        cout << "User data written successfully.\n";
    } else {
        cerr << "Error opening the file.\n";
    }
}
userInfo userMngr::enterUserInfo(){

    const int maxSize = 255;

    char username[maxSize];
    char password[maxSize];

    cout << "username: ";
    cin.getline(username, maxSize, '\n');

    cout << "password: ";
    cin.getline(password, maxSize, '\n');

    userInfo info;
    info.setUserInfo(username, password);

    return info;
}

bool userMngr::quit(userInfo newUser)
{
	if(strcmp(newUser.getUsername(), "q") == 0){
		return true;
	}	

	return false;
}





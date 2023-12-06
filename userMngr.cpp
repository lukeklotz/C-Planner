#include <iostream>
#include <fstream>
#include <cstring>
#include "userMngr.h"

using namespace std;

bool userMngr::isValidUser(userInfo userFile){
    
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

        if(strcmp(passOnFile, pass) == 0 && strcmp(nameOnFile, name) == 0) {
            inputFile.close(); // Close the file before returning
            return true;      // Return true if the user is valid
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
    userMngr checkUser;

    newUser.setUserInfo(username, password);

    /*while(!checkUser.doesUserExist(newUser)){ // TODO: create this function !!
        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;
    }*/
    

    //create current users in file list
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
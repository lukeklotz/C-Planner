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

    inputFile.getline(nameOnFile, 101, ';');

    while(!inputFile.eof()){
        
        inputFile.getline(passOnFile, 101, '\n');

        if(strcmp(passOnFile, pass) == 0 && strcmp(nameOnFile, name) == 0) {
            inputFile.close(); // Close the file before returning
            return true;      // Return true if the user is valid
        }

        inputFile.getline(passOnFile, 101, ';');

    }

    return false;
};
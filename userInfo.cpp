#include "userInfo.h"
#include <cstring>
using namespace std;


userInfo::userInfo(){
    username = nullptr;
    password = nullptr;
}

void userInfo::setUserInfo(char* new_username, char* new_password){
    username = new char[strlen(new_username) + 1];
    password = new char[strlen(new_password) + 1];

    strcpy(username, new_username);
    strcpy(password, new_password);
    
}

char* userInfo::getUsername(){
    return username;
}

char* userInfo::getPassword(){
    return password;
}

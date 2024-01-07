#include "person.h"
#include<iostream>

Person::Person(){}

Person::Person(const string& names, int ages, const string& usernames, const string& passwords ):
name(names), age(ages), username(usernames), password(passwords){}

void Person::setName(const string& newName){
    
    name=newName;
}

string Person::getName() const {
    return name;
}

void Person::setAge(int newAge){
    age = newAge;
}

int Person::getAge() const{
    return age;
}

void Person::setUsername(string& newUsername){
    username = newUsername;
}
string Person::getUsername() const{
    return username;
}

void Person::setPassword(string& newPassword){
    password = newPassword;
}

string Person::getPassword() const {
    return password;
}

bool Person::login(){}

void Person::logout(){}
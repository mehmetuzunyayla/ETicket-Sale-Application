#ifndef PERSON_H
#define PERSON_H

#include<string>

using namespace std;

class Person {
public:

    Person();
    Person(const string& name, int age, const string& username, const string& password);
    
    void setName(const string& newName);
    string getName() const ;

    void setAge(int newAge);
    int getAge() const;

    virtual void setUsername(const string& newUsername) ;
    string getUsername() const;

    virtual void setPassword(const string& newPassword);
    string getPassword() const;

    virtual bool login();

    virtual void logout();

public:
    string name;
    int age;
    string username;
    string password;
};
#endif 
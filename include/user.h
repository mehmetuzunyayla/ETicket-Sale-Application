#ifndef USER_H
#define USER_H

#include <vector>
#include "person.h"
#include "ticket.h"


class User: public Person {
public:

User();
User(const string& name, int age, const string& username, const string& password);

bool login(const vector<User>& users);
void logout() override;
void registerAccount(vector<User>& users);
void deleteAccount(vector<User>& users);
void buyTicket(vector<Ticket>& tickets);
void cancelTicket();
void searchTicket();
void changePassword(vector<User>& users);


private:
vector<Ticket> purchasedTickets;  // Vector to store purchased tickets
};

void userMenu(vector<User>& users, vector<Ticket>& tickets);

#endif
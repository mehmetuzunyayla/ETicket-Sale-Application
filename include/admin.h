#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include "person.h"
#include "ticket.h"

class Admin : public Person {
public:
    Admin(const Admin&) = delete;            // Delete copy constructor
    Admin& operator=(const Admin&) = delete; // Delete copy assignment operator

    void initialize(const string& name, int age, const string& username, const string& password);
    static Admin& getInstance();
    bool login() override;
    void logout() override;
    void defineTicket(Ticket& ticket);
    void salesReports(const vector<Ticket>& tickets);
    void changePassword();
    void setUsername(const string& newUsername) override;
    void setPassword(const string& newPassword) override;


private:
    Admin(); // Private constructor
    // Other private members, if any
};

void adminMenu(vector<Ticket>& tickets);

#endif // ADMIN_H

#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include "person.h"
#include "ticket.h"

class Admin : public Person{
public:
    Admin();
    Admin(const string& name, int age, const string& username, const string& password);

    bool login() override;

    void logout() override;

    void defineTicket(Ticket& ticket);

    void salesReports(const vector<Ticket>& tickets);

    void changePassword();

private:


};

void adminMenu(Admin& admin, vector<Ticket>& tickets);

#endif // ADMIN_H
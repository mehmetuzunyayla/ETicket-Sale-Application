#include <iostream>
#include "person.h"
#include "admin.h"
#include "user.h"
#include "ticket.h"
#include "functions.h"


int main(){
    Admin admin("Mehmet", 22, "mehmet1", "123456");
    Ticket ticket1("Interstellar","2024-01-05 20:00", 20, 65);
    Ticket ticket2("Inception","2024-01-02 19:00", 20, 55);
    User user1("Alp", 24, "alp1", "123456");

    vector<Ticket> tickets;
    vector<User> users;

    tickets.push_back(ticket1);
    tickets.push_back(ticket2);

    users.push_back(user1);

    int choice;

    do {
        printMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                if(admin.login()){
                adminMenu(admin,tickets);
                } else{
                    cout << "Admin login failed. Please try again." << endl;
                }
                break;
            case 2:
                userMenu(users,tickets);
                break;
            case 3:
                cout << "Exiting the application.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
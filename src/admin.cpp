#include "admin.h"
#include<iostream>
#include <iomanip> // For std::setprecision and std::fixed
#include "ticket.h"

Admin::Admin(){};

Admin:: Admin(const string& names, int ages, const string& usernames, const string& passwords)
: Person(names,ages,usernames,passwords){}


bool Admin::login() {
    string enteredUsername, enteredPassword;
    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;

    if (enteredPassword == password && enteredUsername == username) {
        cout << "Admin login successful.\n";
        return true;
    } else {
        cout << "Incorrect password. Login failed.\n";
        return false;
    }
}

void Admin::logout() {
    cout << "Admin logout successful.\n";
}

void Admin::defineTicket(Ticket& ticket) {
    cout << "Enter activity name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, ticket.activity);

    cout << "Enter activity time (e.g., 2023-12-20 18:00): ";
    getline(cin, ticket.time);

    cout << "Enter ticket price: ";
    cin >> ticket.price;

    cout << "Enter available stock: ";
    cin >> ticket.stock;

    cout << "Ticket defined successfully.\n";
}

void Admin::salesReports(const vector<Ticket>& tickets) {
    if (tickets.empty()) {
        cout << "No tickets available.\n";
        return;
    }

    bool soldTicketsFound = false;
    double totalRevenue = 0.0;

    cout << "\n-------------------------\n";
    cout << "Sales Report for Sold Tickets\n";
    cout << "-------------------------\n";

    for (const Ticket& ticket : tickets) {
        if (ticket.getStock() < ticket.getInitialStock()) {
            soldTicketsFound = true;
            int ticketsSold = ticket.getInitialStock() - ticket.getStock();
            double revenueFromTicket = ticketsSold * ticket.getPrice();
            totalRevenue += revenueFromTicket;

            cout << "Activity: " << ticket.getActivity() << "\n";
            cout << "Time: " << ticket.getTime() << "\n";
            cout << "Price: $" << ticket.getPrice() << "\n";
            cout << "Tickets Sold: " << ticketsSold << "\n";
            cout << "Revenue from this Ticket: $" << revenueFromTicket << "\n";
            cout << "Remaining Stock: " << ticket.getStock() << "\n";
            cout << "-------------------------\n";
        }
    }

    if (!soldTicketsFound) {
        cout << "No tickets have been sold yet.\n";
    }else {
        cout << "Total Revenue from Sold Tickets: $" << totalRevenue << "\n";
        cout << "-------------------------\n";
    }

}

void Admin::changePassword() {
    string currentPassword, newPassword, confirmPassword;
    
    cout << "Enter current password: ";
    cin >> currentPassword;

    if (currentPassword != this->password) {
        cout << "Incorrect password.\n";
        return;
    }

    cout << "Enter new password: ";
    cin >> newPassword;

    cout << "Confirm new password: ";
    cin >> confirmPassword;

    if (newPassword != confirmPassword) {
        cout << "Passwords do not match.\n";
        return;
    }

    // Update the password in the current admin instance
    this->password = newPassword;
    cout << "Password successfully changed.\n";
}


void adminMenu(Admin& admin, vector<Ticket>& tickets) {
    int choice;

    do {
        cout << "\n-------------------------\n";
        cout << "Admin Menu\n";
        cout << "-------------------------\n";
        cout << "1. Define Ticket\n";
        cout << "2. Generate Sales Report\n";
        cout << "3. Change Password\n";
        cout << "4. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Ticket ticket("", "", 0.0, 0);
                admin.defineTicket(ticket);
                tickets.push_back(ticket);
                break;
            }
            case 2:
                admin.salesReports(tickets);
                break;
            case 3:
                admin.changePassword();
                break;
            case 4:
                cout << "Admin logout successful.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}
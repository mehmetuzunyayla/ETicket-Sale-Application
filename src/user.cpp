#include <iostream>
#include <algorithm>
#include "user.h"

User::User() : Person() {}

User::User(const std::string& names, int ages, const std::string& usernames, const std::string& passwords)
    : Person(names, ages, usernames, passwords) {}

bool User::login(const std::vector<User>& users) {
    string enteredUsername, enteredPassword;
    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;

    auto it = find_if(users.begin(), users.end(), [enteredUsername, enteredPassword](const User& user) {
        return user.username == enteredUsername && user.password == enteredPassword;
    });

    if (it != users.end()) {
        // Update the current user's information
        *this = *it;  // Copy the found user's information to the current user

        std::cout << "User login successful.\n";
        return true;
    } else {
        std::cout << "Incorrect username or password. Login failed.\n";
        return false;
    }
}


void User::logout() {
    cout << "Logout successful.\n";
}

void User::registerAccount(std::vector<User>& users ) {
    string newName, newPassword, newUsername;
    int newAge;

    cout << "Enter your name: ";
    cin.ignore(); // Clear the input buffer
    getline(std::cin, newName);

    cout << "Enter your age: ";
    cin >> newAge;

    cout << "Choose a username: ";
    cin >> newUsername;

    cout << "Choose a password: ";
    cin >> newPassword;

    // Check if the username already exists
    auto it = find_if(users.begin(), users.end(), [newUsername](const User& user) {
        return user.username == newUsername;
    });

    if (it == users.end()) {
        User newUser(newName, newAge, newUsername, newPassword);
        users.push_back(newUser);
        cout << "User created.\n";
    } else {
        cout << "Username already exists. Please choose another username.\n";
    }
}

void User::deleteAccount(vector<User>& users) {
    char confirmDelete;
    cout << "Do you want to delete your account? (Y/N): ";
    cin >> confirmDelete;

    if (confirmDelete == 'Y' || confirmDelete == 'y') {
        // Print all usernames for debugging
        cout << "Usernames in the vector:\n";
        for (const auto& user : users) {
            cout << user.getUsername() << "\n";
        }

        // Print the current user's information for debugging
        cout << "Current User's Information:\n";
        cout << "Name: " << this->getName() << "\n";
        cout << "Age: " << this->getAge() << "\n";
        cout << "Username: " << this->getUsername() << "\n";
        cout << "Password: " << this->getPassword() << "\n";

        // Search for the user by username
        auto it = find_if(users.begin(), users.end(), [this](const User& user) {
            return user.getUsername() == this->getUsername();
        });

        if (it != users.end()) {
            users.erase(it);
            cout << "User account canceled.\n";
        } else {
            cout << "Error: User not found.\n";
        }
    } else {
        cout << "Account not deleted.\n";
    }
}

void User::buyTicket(vector<Ticket>& tickets) {
    if (!tickets.empty()) {
        int ticketChoice;
        cout << "Select a ticket to buy:\n";
        for (size_t i = 0; i < tickets.size(); ++i) {
            cout << i + 1 << ". " << tickets[i].activity << " - " << tickets[i].time << " - $" << tickets[i].price << "\n";
        }
        cout << "Enter the ticket number: ";
        cin >> ticketChoice;

        if (ticketChoice >= 1 && ticketChoice <= static_cast<int>(tickets.size())) {
            Ticket& selectedTicket = tickets[ticketChoice - 1];

            int numTicketsToBuy;
            cout << "How many tickets do you want to buy? ";
            cin >> numTicketsToBuy;

            if (numTicketsToBuy > 0 && numTicketsToBuy <= selectedTicket.stock) {
                cout << "Tickets purchased for " << selectedTicket.activity << " on " << selectedTicket.time << ".\n";
                selectedTicket.stock -= numTicketsToBuy;

                // Assign the purchased ticket to the user's ticket variable
                for (int i = 0; i < numTicketsToBuy; ++i) {
                    purchasedTickets.push_back(selectedTicket);
                }

            } else if (numTicketsToBuy == 0) {
                cout << "You selected to buy 0 tickets. No tickets were purchased.\n";
            } else {
                cout << "Invalid number of tickets or insufficient stock.\n";
            }
        } else {
            cout << "Invalid ticket choice.\n";
        }
    } else {
        cout << "No tickets available.\n";
    }
}



void User::cancelTicket() {
    if (purchasedTickets.empty()) {
        cout << "No ticket purchased. Nothing to cancel.\n";
        return;
    }

    // Display all purchased tickets for the user to select which to cancel
    for (size_t i = 0; i < purchasedTickets.size(); ++i) {
        cout << i + 1 << ". " << purchasedTickets[i].activity << " - " << purchasedTickets[i].time << " - $" << purchasedTickets[i].price << "\n";
    }

    int ticketChoice;
    cout << "Enter the ticket number to cancel: ";
    cin >> ticketChoice;

    if (ticketChoice >= 1 && ticketChoice <= static_cast<int>(purchasedTickets.size())) {
        // Decrement available stock when canceling the ticket
        purchasedTickets[ticketChoice - 1].stock += 1;

        // Remove the ticket from the user's purchasedTickets vector
        purchasedTickets.erase(purchasedTickets.begin() + ticketChoice - 1);
        cout << "Ticket canceled successfully.\n";
    } else {
        cout << "Invalid ticket choice.\n";
    }
}


void User::searchTicket() {
    if (purchasedTickets.empty()) {
        cout << "No ticket purchased.\n";
        return;
    }

    cout << "Your Purchased Tickets:\n";
    for (const Ticket& ticket : purchasedTickets) {
        cout << "Activity: " << ticket.activity << "\n";
        cout << "Time: " << ticket.time << "\n";
        cout << "Price: $" << ticket.price << "\n";
        cout << "-------------------------\n";
    }
}

void User::changePassword(vector<User>& users) {
    string currentPassword, newPassword, confirmPassword;
    
    cout << "Enter current password: ";
    cin >> currentPassword;

    // Check if the entered current password is correct
    if (currentPassword != this->password) {
        cout << "Incorrect password.\n";
        return;
    }

    cout << "Enter new password: ";
    cin >> newPassword;

    cout << "Confirm new password: ";
    cin >> confirmPassword;

    // Check if the new password and confirm password match
    if (newPassword != confirmPassword) {
        cout << "Passwords do not match.\n";
        return;
    }

    // Update the password
    for (auto& user : users) {
        if (user.getUsername() == this->getUsername()) {
            user.setPassword(newPassword); // Assuming setPassword is a method to update password
            break;
        }
    }
    cout << "Password successfully changed.\n";
}

void userMenu(vector<User>& users, vector<Ticket>& tickets) {
    int choice;
    User currentUser;

    do {
        cout << "\n-------------------------\n";
        cout << "User Menu\n";
        cout << "-------------------------\n";
        cout << "1. Login\n";
        cout << "2. Register Account\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                bool loggedIn = false;
                do {
                    loggedIn = currentUser.login(users);
                } while (!loggedIn);
                break;
            }
            case 2:
                currentUser.registerAccount(users);
                break;
            case 3:
                cout << "Exiting...\n";
                return;
            default:
                cout << "Invalid choice. Try again.\n";
                continue;
        }

        // Display menu options after login or register
        do {
            cout << "\n-------------------------\n";
            cout << "User Menu\n";
            cout << "-------------------------\n";
            cout << "1. Delete Account\n";
            cout << "2. Buy Ticket\n";
            cout << "3. Search Ticket\n";
            cout << "4. Cancel Ticket\n";
            cout << "5. Change Password\n";
            cout << "6. Logout\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    currentUser.deleteAccount(users);
                    break;
                case 2:
                    currentUser.buyTicket(tickets);
                    break;
                case 3:
                    currentUser.searchTicket();
                    break;
                case 4:
                    currentUser.cancelTicket();
                    break;
                case 5:
                    currentUser.changePassword(users);
                    break;    
                case 6:
                    currentUser.logout();
                    break;
                case 7:
                    cout << "Exiting...\n";
                    return;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 5 && choice != 1);

    } while (true);  // Loop indefinitely until the user chooses to exit
}


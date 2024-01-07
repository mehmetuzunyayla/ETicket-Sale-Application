#ifndef TICKET_H
#define TICKET_H

#include <string>
using namespace std;

class Ticket {
public:

    Ticket();
    Ticket(const string& activity, const string& time, double price, int stock);

    string getActivity() const;
    void setActivity(string newActivity);

    string getTime() const;
    void setTime(string newTime);

    double getPrice() const;
    void setPrice(double newPrice);

    int getStock() const;
    void setStock(int newStock);
    int getInitialStock() const;

public:

    string activity;
    string time;
    double price;
    int stock;
    int initialStock;  // Added to track the initial stock of tickets
};

#endif
#include "ticket.h"

Ticket::Ticket(const std::string& activity, const std::string& time, double price, int stock)
    : activity(activity), time(time), price(price), stock(stock), initialStock(stock) {}

Ticket::Ticket(){}



string Ticket:: getActivity() const{
    return activity;
}
void Ticket:: setActivity(string newActivity){
    activity = newActivity;
}

string Ticket:: getTime() const{
    return time;
}
void Ticket:: setTime(string newTime){
    time = newTime;
}

double Ticket:: getPrice() const{
    return price;
}
void Ticket:: setPrice(double newPrice){
    price = newPrice;
}

int Ticket:: getStock() const{
    return stock;
}
void Ticket:: setStock(int newStock){
    stock = newStock;
}

int Ticket::getInitialStock() const {
    return initialStock;
}
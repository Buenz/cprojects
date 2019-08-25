
#include <iostream>
#include "money.h"






using namespace std;

int main()
{
    Money moneyOne, moneyTwo;
    unsigned int dollars, cents;
    
    /*Prompting the user to enter a monetary value.*/
    cout << "This serves as a test program for the Money class." << endl;
    cout << "Monetary Value One" << endl
    << "Please enter the number of dollars: ";
    cin >> dollars;
    cout << "Please enter the number of cents: ";
    cin >> cents;
    
    /*Entering collected data into a Money instance.*/
    moneyOne.setDollars(dollars);
    moneyOne.setCents(cents);
    
    /*Spitting out dollars and cents to confirm that
     our setters and getters are functioning appropriately.*/
    cout << "You entered " << moneyOne.getDollars() << " dollars and "
    << moneyOne.getCents() << " cents." << endl;
    
    cout << "Monetary Value Two" << endl
    << "Please enter the number of dollars: ";
    cin >> dollars;
    cout << "Please enter the number of cents: ";
    cin >> cents;
    
    /*Entering collected data into a Money instance.*/
    moneyTwo.setDollars(dollars);
    moneyTwo.setCents(cents);
    
    /*Spitting out dollars and cents to confirm that
     our setters and getters are functioning appropriately.*/
    cout << "You entered " << moneyTwo.getDollars() << " dollars and "
    << moneyTwo.getCents() << " cents." << endl;
    
    /*Testing double getMoney() const by displaying full monetary values.*/
    cout << "Monetary Value One: $" << moneyOne.getMoney() << endl;
    cout << "Monetary Value Two: $" << moneyTwo.getMoney() << endl;
    
    return 0;
}

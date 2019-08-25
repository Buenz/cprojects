#include "money.h"

/*Gets the number of dollars in this money amount.*/
unsigned int Money::getDollars() const
{
    return dollars;
}

/*Sets the number of dollars for this money amount.*/
void Money::setDollars(unsigned int dollars)
{
    this->dollars = dollars;
}

/*Gets the number of cents in this money amount.*/
unsigned int Money::getCents() const
{
    return cents;
}

/*Sets the number of cents for this money amount.*/
void Money::setCents(unsigned int cents)
{
    this->cents = cents;
}

/*Retrieves a total amount in dollars and cents.*/
double Money::getMoney() const
{
    double monetaryTotal = 0.0;
    monetaryTotal = dollars + ((double) cents/100);
    return monetaryTotal;
}



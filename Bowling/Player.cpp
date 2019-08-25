// support functions for keeping statistics on a team of baseball players
#include "Player.h"
#include <iostream>
#include <iomanip>
using namespace std;

Player::Player()
{
	Number = Hits = Walks = Outs = 0;
}

int Player::getNumber() const
{
	return Number;
}

int Player::getHits() const
{
	return Hits;
}

int Player::getWalks() const
{
	return Walks;
}

int Player::getOuts() const
{
	return Outs;
}

void Player::setNumber(int n)
    {
	Number = n;
    }

void Player::setHits(int h)
{
	Hits = h;
}

void Player::setWalks(int w)
{
	Walks = w;
}

void Player::setOuts(int o)
{
	Outs = o;
}

    // support for assignments
const Player& Player::operator=(const Player & p)
{
	// bypass self assignment
	if (this != &p)
	{
		Number = p.Number;
		Hits = p.Hits;
		Walks = p.Walks;
		Outs = p.Outs;
	}
	return *this;
}

    // support for output to the monitor 
ostream& operator<<(ostream& out,  const Player & p)
{
	out << setw(2) << p.Number << "\t" 
	    << setw(2) << p.Hits << "\t" 
	    << setw(2) << p.Walks << "\t"
	    << setw(2) << p.Outs;
	return out;
}

// end of the class member functions

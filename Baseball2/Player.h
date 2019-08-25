// delcaration of class to support baseball players
#ifndef PLAYER
   #define PLAYER

#include <iostream>
using namespace std;

class Player
{
 public: // member functions
  // constructor
  Player();
  // extractors
  int getNumber() const;
  int getHits() const;
  int getWalks() const;
  int getOuts() const;
  // mutators
  void setNumber(int);
  void setHits(int);
  void setWalks(int);
  void setOuts(int);
    // support for assignments and output to the monitor 
  const Player& operator=(const Player &);
  friend ostream& operator<<(ostream&, const Player & );

 private: // data attributes
 int Number, Hits, Walks, Outs;
};

// end of the class
#endif

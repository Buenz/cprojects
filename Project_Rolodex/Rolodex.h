#ifndef ROLODEX_H_INCLUDED
#define ROLODEX_H_INCLUDED
#include <iostream>
#include "RolodexEntry.h"
using std::size_t;
using std::string;
const size_t MAX_ENTRIES = 100;
class Rolodex
{
    RolodexEntry list[MAX_ENTRIES];
    size_t current;
public:
    bool full(void) const {return current == MAX_ENTRIES;}
    RolodexEntry get(size_t index) const;
    bool set(size_t index, const RolodexEntry& new_entry);
    bool add(const RolodexEntry& new_entry);
    void eraseEntry(short index) ;
    void printList();
    size_t size();
    size_t findByName(string search);
    size_t findByAddress(string search);
    size_t findByPhone(short search);
    size_t findByEmail(string search);
};
#endif // ROLODEX_H_INCLUDED

#include "Rolodex.h"
#include <iostream>

using namespace std;

size_t Rolodex::size()
{
    return current;
}

RolodexEntry Rolodex::get(size_t index) const
{
    return list[index];
}
bool Rolodex::set(size_t index, const RolodexEntry& new_entry)
{
    if(index >= 0 && index < size())
    {
        list[index] = new_entry;
        return true;
    }
    else
        return false;
    
}
bool Rolodex::add(const RolodexEntry& new_entry)
{
    if(!full())
    {
        list[current++] = new_entry;
        return true;
    }
    else
        return false;
}

void Rolodex::eraseEntry(short index) {
    size_t k;
    if (index < size() && index >= 0) {
        for (k = index + 1; k != size(); k++) {
            list[k - 1] = list[k];
        }
        current--;
    } else {
        cout << "Out of bounds.";
    }
    return;
}

void Rolodex::printList()
{
    cout << '\n';
    for(size_t i = 0; i < size(); i++)
    {
        cout << i+1 << ".";
        list[i].printEntry();
    }
    return;
}

size_t Rolodex::findByName(string search)
{
    for(size_t i = 0; i < size(); i++)
    {
        if(list[i].getFName().find(search) != string::npos ||
           list[i].getLName().find(search) != string::npos)
        {
            return i;
        }
    }
    return -1;
}

size_t Rolodex::findByAddress(string search)
{
    for(size_t i = 0; i < size(); i++)
    {
        if(list[i].getStreet().find(search) != string::npos ||
           list[i].getTown().find(search) != string::npos ||
           list[i].getState().find(search) != string::npos)
        {
            return i;
        }
    }
    
    return -1;
}


size_t Rolodex::findByPhone(short search)
{
    for(size_t i = 0; i < size(); i++)
    {
        if(list[i].getArea() == search || list[i].getExchange() == search ||
           list[i].getPLine() == search)
        {
            return i;
        }
    }
    return -1;
}

size_t Rolodex::findByEmail(string search)
{
    for(size_t i = 0; i < size(); i++)
    {
        if(list[i].getEmail().find(search) != string::npos)
        {
            return i;
        }
        
    }
    return -1;
}

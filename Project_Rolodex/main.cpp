#include <iostream>
#include "RolodexEntry.h"
#include "Rolodex.h"

#include <climits>
#include <cctype>

using namespace std;
//function dec
void printMainMenu();
void printEditMenu(Rolodex & list);
void editContactSub(const short c, Rolodex & list);
void printSearchMenu(Rolodex & list);

int main(void)
{
    bool isRunning = true;
    Rolodex list;
    
    do
    {
        char c;
        printMainMenu();
        cin >> c;
        cin.ignore(INT_MAX, '\n');
        switch(tolower(c))
        {
            case '1': case 'a':
            {
                
                RolodexEntry newEntry;
                newEntry.readIn();
                list.add(newEntry);
                
                break;
            }
            case '2': case 'e':
            {
                printEditMenu(list);
                break;
            }
            case '3': case 'd':
            {
                list.printList();
                cout << "\nSelect Contact to delete:";
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                }
                short c;
                cin >> c;
                list.eraseEntry(c-1);//resizes
                break;
            }
            case '4': case 's':
            {
                printSearchMenu(list);
                break;
            }
            case '5': case 'p':
            {
                list.printList();
                break;
            }
            case '6': case 'q':
            {
                isRunning = false;
                break;
            }
            default:
            {
                cout << "Invalid selection.";
                break;
            }
        }
    }while(isRunning);
    return 0;
}
void printMainMenu()
{
    cout << "\nMain Menu\n\n"
    << "1. Add contact\n"
    << "2. Edit contact\n"
    << "3. Delete contact\n"
    << "4. Search contacts\n"
    << "5. Print all contacts\n"
    << "6. Quit\n";
    return;
}
void printEditMenu(Rolodex & list)
{
    cout << "\n\n";
    list.printList();
    cout << "\nSelect Contact to edit:";//read in choice
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
    }
    short c;
    cin >> c;
    cin.ignore(INT_MAX, '\n');
    editContactSub(c, list);
    return;
}
void editContactSub(const short c, Rolodex& list)//and work
{
    short index = c - 1;
    if(index >= 0 && index < list.size())//it's gooooood!
    {
        RolodexEntry edited = list.get(static_cast<short>(c)-1);
        //edit menu
        cout << "1. edit First name\n"
        << "2. edit Last name\n"
        << "3. edit Address\n"
        << "4. edit Phone number\n"
        << "5. edit Email\n";
        char sel;
        cin >> sel;
        cin.ignore(INT_MAX, '\n');
        switch(tolower(sel))
        {
            case '1': case 'f':
            {
                cout << "\nEnter new first name: ";
                string newName;
                cin >> newName;
                edited.setFName(newName);
                list.set(c - 1, edited);
                break;
            }
            case '2': case 'l':
            {
                cout << "\nEnter new last name: ";
                string newName;
                cin >> newName;
                edited.setLName(newName);
                list.set(c - 1, edited);
                break;
            }
            case '3': case 'a':
            {
                cout << "\nEnter new street number and street: ";
                string newStreet;
                cout.flush();
                if (cin.peek() == '\n')
                {
                    cin.ignore();
                }
                getline(cin, newStreet);
                edited.setStreet(newStreet);
                cout << "\nEnter new town: ";
                string newtown;
                cout.flush();
                if (cin.peek() == '\n')
                {
                    cin.ignore();
                }
                getline(cin, newtown);
                edited.setTown(newtown);
                cout << "\nEnter new state: ";
                string newstate;
                cout.flush();
                if (cin.peek() == '\n')
                {
                    cin.ignore();
                }
                getline(cin, newstate);
                edited.setState(newstate);
                cout << "\nEnter new zipcode: ";
                long newzip;
                cin >> newzip;
                if(newzip > 99999)//long zip
                {
                    edited.setZip(newzip);
                    edited.setSZipLong();//finds szip from long zip
                }
                else
                {
                    edited.setSZip(newzip);
                }
                list.set(c - 1, edited);
                break;
            }
            case '4': case 'p':
            {
                cout << "\nEnter new areacode: ";
                short newarea;
                cin >> newarea;
                edited.setArea(newarea);
                cout << "\nEnter new exchange number: ";
                short newex;
                cin >> newex;
                edited.setExchange(newex);
                cout << "\nEnter new line: ";
                short newLine;
                cin >> newLine;
                edited.setPLine(newLine);
                list.set(c - 1, edited);
                break;
            }
            case '5': case 'e':
            {
                cout << "\nEnter new email: ";
                string newemail;
                cin >> newemail;
                edited.setEmail(newemail);
                list.set(c - 1, edited);
                break;
            }
        }
    }
    else
    {
        cout << "Contact at this index does not exist.";
    }
    return;
}
void printSearchMenu(Rolodex & list)//and work
{
    cout << "1. search by Name\n"
    << "2. search by Address\n"
    << "3. search by Phone number\n"
    << "4. search by Email\n"
    << "5. Return to Main menu\n";
    char c;
    cin >> c;
    cin.ignore(INT_MAX, '\n');
    int index;
    RolodexEntry entry;
    switch(tolower(c))
    {
        case '1': case 'n':
        {
            cout << "\nEnter search term: ";
            string search;
            cout.flush();
            if (cin.peek() == '\n')
            {
                cin.ignore();
            }
            getline(cin, search);
            index = list.findByName(search);
            if(index != -1)
            {
                entry = list.get(index);
                entry.printEntry();
            }
            else
                cout << "No such name" << endl;
            break;
        }
        case '2': case 'a':
        {
            cout << "\nEnter search term: ";
            string search;
            cout.flush();
            if (cin.peek() == '\n')
            {
                cin.ignore();
            }
            getline(cin, search);
            index = list.findByAddress(search);
            if(index != -1)
            {
                entry = list.get(index);
                entry.printEntry();
            }
            else
                cout << "No such address." << endl;
            
            break;
        }
        case '3': case 'p':
        {
            cout << "\nEnter part of phone number (last four digits gives best results): ";
            short search;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cin >> search;
            index = list.findByPhone(search);
            if(index != -1)
            {
                entry = list.get(index);
                entry.printEntry();
            }
            else
                cout << "No such phone." << endl;
            break;
        }
        case '4': case 'e':
        {
            cout << "\nEnter email: ";
            string search;
            cout.flush();
            if (cin.peek() == '\n')
            {
                cin.ignore();
            }
            getline(cin, search);
            index = list.findByEmail(search);
            if(index != -1)
            {
                entry = list.get(index);
                entry.printEntry();
            }
            else
                cout << "No such email." << endl;
            break;
        }
        case '5': case 'q':
        {
            break;
        }
        default:
        {
            cout << "\nInvalid seletion.";
            break;
        }
    }
}

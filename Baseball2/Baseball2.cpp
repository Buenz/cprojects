/************************************************************************
 * Name: Harrison Bueno                                                  CSC 121
 * Date: 5.15.17                                                         Lab 10
 *************************************************************************
 * Calculate statistics for a baseball team using a vector of objects
 ************************************************************************/

// for file an monitor I/O
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// declaration of functions
int findNumber(vector<Player> team, int Number, int team_size);

void displayTeam(vector<Player> team, int team_size);
// implementation of the main program

void selectionSort(vector<Player> team, int team_size);

int main()
{
    //int teamSize= 0;// 1) declare and initialize objects
    
    ifstream fin("baseball.txt");// objects used to store data?
    
    const int LIST_LENGTH = 20;
    
    int number = 0;         // number, hits, walks, outs
    int hits, walks, outs, players, index, teamSize = 0;
    
    
    // 2) output descriptive messages
    cout << "This program tracks a baseball player's number "
    << "and their\nnumber of hits, walks, and outs for "
    << "each games in a season.\n";
    
    
    // 3) declare a vector of LIST_LENGTH players
    vector<Player> team(LIST_LENGTH);
    
    // 4) attempt to input the data for the first Player
    fin >> number >> hits >> walks >> outs;
    
    // 5) loop on end of file
    while (!fin.eof())
    {
        index=findNumber(team, number, teamSize);// 6) find the index of this Player's number
        
        if(index == -1)
        {// 7) if player number is not in the list
            team[teamSize].setNumber(number); // 7a) set the Number field for team[teamSize]
            team[teamSize].setHits(hits); // 7b) set the Hits field for team[teamSize]
            team[teamSize].setWalks(walks); // 7c) ste the Walks field for team[teamSize]
            team[teamSize].setOuts(outs);   // 7d) set the Outs field for team[teamSize]
            teamSize++;   // 7e) increase teamSize by 1
        }
        else
        {
            // 8) else player number is in the list
            team[index].setHits(hits + team[index].getHits());   // 8a) update the Hits field for team[index]
            team[index].setWalks(walks + team[index].getWalks());  // 8b) update the Walks field for team[index]
            team[index].setOuts(outs + team[index].getOuts());   // 8c) update the Outs field for team[index]
            
        }// 9) attempt to input the data for the next Player
	       fin >> number >> hits >> walks >> outs;
    }
    
    
    displayTeam(team, teamSize);// 10) display the results
    selectionSort(team, teamSize);
    
} // end of main

// *************************************************************************
// determine the position within a vector of Player of a player's index number
// performs a sequential search from the begining of the vector
// returns -1 on a failure to find an index within the vector
//**************************************************************************
int findNumber(vector<Player> team, int Number, int team_size)
{
    int save= -1;// 1) assume that this player_number is not in the list
    for(int i=0; i<=team_size-1;i++){
        
        // 2) loop over the list length
        if(Number==team[i].getNumber())// 3) exit the loop if the number is found
        {  save=i;
        }
    }
    return save;
}
// 4) update the index on successful search
// 5) return either the found index or -1

//************************************************************************
// display players in a vector of Player with formatting of
// Player #, Number of Hits, Number of Walks, Number of Outs
//************************************************************************
// 1) display headings of columns
void displayTeam(vector<Player> team, int team_size)
{
    cout << "\n\nPlayer\tHits\tWalks\tOuts\n"
    << "------\t----\t-----\t----\n";
    // 2) loop over team size
    for (int i=0; i < team_size; i++)
    {
        // 3) display i'th player
        cout << team[i] << endl;
    }
    
void selectionSort(vector<Player> team, int team_size)
    {
        int smallestIndex;
        int temp;
        for(int i=0; i<==team_size-2; i++)
        {
            smallestIndex=i;
            for(int minIndex= i+1; minIndex<==team_size-1;minIndex++)
            {
                if(team[minIndex.getNumber()<team[smallestIndex.getNumber()])
                        {
                        smallIndex=minIndex;
                        
                        }
                        
            
            }
                        if(i!=smallestIndex)
                        {
                        temp=team[i];
                        team[i]=team[smallestIndex];
                        temp=team[smallestIndex];
                        }
                        
        }
                        
    }

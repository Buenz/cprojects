/*************************************************************************
* Name: Your name CSC 121
* Date: Today’s date Lab 5
*************************************************************************
* Statement: Inventory for a hardware store is input by user and the
* program lists the tools displaying the total cost and number
* of tools
* Specifications:
* Input – Name of each tool (no spaces in the name) followed by the price
* Output- A list of tools, total cost and number of tools
*************************************************************************/
// header files for I/O objects
#include <iostream>
#include <string>
#include <iomanip>
#include<list>
using namespace std;

int main()
{
    int total_number=0;
    double total_cost=0;
    bool tool=true;
    
    cout<<"This program will have the user list the tools for sale and print \n"
    "a statement indicating each item and its cost. Additionally the\n"
    "program will display the sum of all of the costs and the total\n"
    "number of tools."<<endl;
    
    cout<<"Enter the name (without spaces of the first tool followed by\n"
    "the price (enter -1 to exit):"<<endl;
    cin>>tool_list;
    
    while (tool)
    {
        double cost;
        cin>>cost;
        
        if(tool_list ==-1)
            tool=false;
        else
        {
            total_cost=total_cost + cost;
            total_number++;
        }
        else
        {
            
        }
    }    ////incomplete :/ I will work on it tmrw 
        cout<<"Enter the name (without spaces) of the next tool followed by\n"
        "the price (enter -1 as the tool name when finished):"<<endl;
        
        cout<<"Enter the name (without spaces) of the next tool followed by\n"
        "the price (enter -1 as the tool name when finished):"<<endl;
        
        cout<<"Enter the name (without spaces) of the next tool followed by\n"
        "the price (enter -1 as the tool name when finished):"<<endl;
    }
    
    
    return 0;
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    // declaration of objects used to store data
    // name, cost, tool_list, total_number, total_cost
    // 1. Initialize accumulators (total_number, total_cost) to 0
    // 2. Display a descriptive message and the headings
    // 3. Prompt the user and input the first tool name
    // 4. Check for the sentinel value
    // 5. Input the tool cost (within while loop)
    // 6. Update the total cost and the total number of tools (within while loop)
        // 7. Concatenate the current tool name to tool_list (within while loop)
        // 8. Prompt the user and input another tool name (within while loop)
        // 9. List the tools
        // 10.Display the total number of tools and the total of the costs of the tools
    




    return 0;
    


}

/************************************************************************
 * Name: Harrison Bueno                                            CSC 121
 * Date: 04.17.17                                                  Lab 7
 *************************************************************************
 * Statement: Displays headings for a payroll report.
 * Specifications:
 * Input  - none
 * Output - Payroll report headings
 ************************************************************************/
#include <iostream>

//header files I/O, formatting, strings
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// function prototypes
// instructions()- describes the program usage to the user
void instructions();

// reportTitle() displays the payroll report titles in columnar format
void reportTitle();

void displayEmployeeInfo(const string& name, double hourly, double hours, double rate, double gross, double net);// displayEmployeeInfo() displays the information for each employee

void totalAmounts(double total_gross, double total_net);// totalAmounts() displays the total gross and net amounts

int main()
{
    string name;
    double hourly, hours, rate, gross, net;
    double total_gross, total_net=0;    // 1) initialize accumulaton variables
    
    // 2) display a descriptive message
    instructions();
    
    // 3) display column headings
    reportTitle();
    
    getline(cin, name, '#'); // 4) attempt to input the name on the first input line
    
    while(name.length()>0)  // 5) test that name contains at least one character
    
    {
        cin >> hourly >> hours >> rate; // 6) input the remaining doubles on the input line
        
        cin.ignore(100, '\n'); // 7) set input beyond the current line
        
        if(hours>40)    // 8) test hours >= 40
            gross= 40*hourly+1.5*(hours-40.0)*hourly;
        else                            //  9) calculate gross & overtime
            gross=hours*hourly;       // 10) else calculate gross without overtime
        
        
        net=gross-gross*(rate)/100.00;    // 11) calculate net pay
        
        
        displayEmployeeInfo(name, hourly, hours, rate, gross, net);  // 12) display info for this employee
        
        // 13) update accumulation variables
        total_gross+=gross;
        total_net+=net;
        
        getline(cin, name, '#');// 14) attempt to input next name
        
    }
    
    
    totalAmounts(total_gross, total_net); // 15) display totals
    
}

// instructions() describes the program usage to the user
void instructions()
{
    // display program instructions
    cout << "This payroll program calculates an individual "
    << "employee pay and\ncompany totals "
    << "using data from a data file payroll.txt.\n"
    << "\n\nA payroll report showing payroll information "
    << " is displayed.\n\n";
}


// reportTitle() displays the payroll report titles in columnar format
void reportTitle()
{
    // set program formatting
    cout << setprecision(2) << fixed << showpoint << left;
    
    // display report titles
    cout << setw(20) << "Employee" << setw(10) << "Hourly"
    << setw(10) << "Hours" << setw(10) << "Tax" << setw(10)
    << "Gross" << setw(10) << "Net" << endl;
    
    cout << setw(20) << "Name" << setw(10) << "Rate"
    << setw(10) << "Worked" << setw(10) << "Rate" << setw(10)
    << "Amount" << setw(10) <<"Amount" << endl << endl;
}

// displayEmployeeInfo() displays payroll information for an employee
void displayEmployeeInfo(const string& name, double hourly, double hours, double rate, double gross, double net)
{
    cout << setw(20)<<name<<setw(10)<<hourly<<setw(10)<<hours<<setw(10)<<rate<<setw(10)<<gross<<setw(10)<<net<<endl;
}

// totalAmounts() displays total gross and total net for the input file
void totalAmounts(double total_gross, double total_net)// totalAmounts() displays the total gross and net amounts
{
    cout << setw(50) << "Totals" << setprecision(2) << fixed << showpoint << left
    << setw(10) << total_gross << setw(10) << total_net << endl;
}

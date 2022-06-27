/*///////////////////////////////////////////////////////////////////////////////////////////////////////////
/                                                                                                           /
/                                                                                                           /
/    Johnny Utah owns a surf shop on the beach called “Point Break Surf Shop”.                              /
/    Johnny sells surfboards in 3 three sizes: small (2 meters), medium (3 meters), and large (4 meters).   / 
/    The cost of one small surfboard is $175.00, one medium is $190.00, and one large is $200.00.           /
/    Write a program that will make the surf shop operational.                                              /  
/    Your program should allow the user to do the following:                                                /
/                                                                                                           /
/        1. Buy any surfboard in any size and in any quanity.                                               /
/        2. At any time show the total number of surfboards of each size sold.                              /
/        3. At any time show the total money made.                                                          /
/                                                                                                           /
/                                                                                                           /
//////////////////////////////////////////////////////////////////////////////////////////// BY ISSA HABEEB*/


#include <iostream>     // GIVES "cin" AND "cout"
#include <iomanip>      // GIVES "setfill(char)", "setw(int)" AND "setprecision(int)"
#include <string>       // GIVES DATA TYPE "string"
#include <algorithm>    // STRING MANIPULATION (LOWERCASE/UPPERCASE)
#include <stdlib.h>     // FOR "system("CLS")"

using namespace std;    // SO NO NEED TO DO "std::cout" OR "std::cin"


// A function to show the user how to use the program.
void ShowUsage() 
{        // Setting default fill for whitespace
    cout << setfill('*')
         // Introduction
         << setw(61) << "\n"
         << setw(55) << " Welcome to my Johnny Utah's PointBreak Surf Shop " << right << setw(6) << "\n"
         << setw(61) << "\n" << "\n" << "\n"
         // Options
         << "To show program usage 'S'" << "\n"
         << "To purchase a surfboard press 'P'" << "\n"
         << "To display current purchases press 'C'" << "\n"
         << "To display tolal amount due press 'T'" << "\n"
         << "To quit the program press 'Q'" << "\n" << endl;
}


// A function to sell surfboards.
void MakePurchase(int& iTotalXXXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge) // Int& bascially returns the variable without return statement
{
    cout << "Please enter the quanity and type(XXXS = squirrel, S = small, M = medium, L = large) of surfboard you would like to purchase:";

    // Initilizing variables
    int surfboard_quantity = 0;
    string surfboard_size;

    // Input
    cin >> surfboard_quantity >> surfboard_size;
    transform(surfboard_size.begin(), surfboard_size.end(), surfboard_size.begin(), tolower); // Lowercase
    cout << "\n" << endl;

    // Adds to variables (respective size and quantity) depending on user input


    if (surfboard_size == "xxxs")
        iTotalXXXS += surfboard_quantity;
    else if (surfboard_size == "s")
        iTotalSmall += surfboard_quantity;
    else if (surfboard_size == "m")
        iTotalMedium += surfboard_quantity;
    else if (surfboard_size == "l")
        iTotalLarge += surfboard_quantity;
}


// Function to show the number of surfboards of each size sold.
void DisplayPurchase(const int iTotalXXXS,const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    // Two decimal points and real numbers (not scientific notation)
    cout << setprecision(2) << fixed;

    // Checks if anything is purchased yet.
    if ((iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0))
        cout << "No purchases made yet." << endl;

    // All conditionals are executed, aka no else if statements (based off if quanitity is greater than 0)
    if (iTotalXXXS != 0)
        cout << "The total number of xxxs surfboards is " << iTotalXXXS << endl;
    if (iTotalSmall != 0) 
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    if (iTotalMedium != 0)
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    if (iTotalLarge != 0)
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    
    cout << endl;
}



// A function to show the total amount of money made.
void DisplayTotal(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    // Two decimal points and real numbers (not scientific notation)
    cout << setprecision(2) << fixed;

    // Constant variables for cost
    const double XXXS_COST = 50.00;
    const double SMALL_COST = 175.00;
    const double MEDIUM_COST = 190.00;
    const double LARGE_COST = 200.00;

    // Variables to determine cost for each size and quanitity
    double xxxs_cost = (iTotalXXXS * XXXS_COST);
    double small_total = (iTotalSmall * SMALL_COST);
    double medium_total = (iTotalMedium * MEDIUM_COST);
    double large_total = (iTotalLarge * LARGE_COST);

    // Outputs cost if quanitity is not 0 for each size.
    if (iTotalXXXS != 0)
        cout << "The total number of small surfboards is " << iTotalXXXS << " at a total of $" << xxxs_cost << endl;
    if (iTotalSmall != 0)
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << small_total << endl;
    if (iTotalMedium != 0)
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << medium_total << endl;
    if (iTotalLarge != 0)
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << large_total << endl;

    // Total
    double total_cost = xxxs_cost + small_total + medium_total + large_total;
    // Checks if purchases were made
    if (total_cost == 0)
        cout << "No purchases made yet." << "\n" << endl;
    // Total cost if purchases were made
    else
        cout << "Amount due: $" << total_cost << "\n" << endl;
}


// Main function (first read by the compiler)
int main()
{
    // Inititlizing variables (will be passed into arguments for functions)
    int iTotalXXXS   = 0;
    int iTotalSmall  = 0;
    int iTotalMedium = 0;
    int iTotalLarge  = 0;

    // Variable used as input for option selection
    string selection_input = " ";

    ShowUsage(); // Executes function

    // Forever loop
    while (true)
    {

        // Select option
        cout << "Please enter selection: ";
        cin >> selection_input;
        transform(selection_input.begin(), selection_input.end(), selection_input.begin(), tolower); // Lowercase


        // To show program usage 'S'
        if (selection_input == "s")
        {
            system("CLS"); // Clears console (found this on the internet)
            ShowUsage(); // Executes function
        }


        // To purchase a surfboard press 'P'
        else if (selection_input == "p")
        {
            MakePurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge); // Executes function
        }


        // To display current purchases press 'C'
        else if (selection_input == "c")
        {
            DisplayPurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge); // Executes function
        }


        // To display tolal amount due press 'T'
        else if (selection_input == "t")
        {
            DisplayTotal(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge); // Executes function
        }


        // To quit the program press 'Q'
        else if (selection_input == "q")
        {
            cout << "Thank you" << endl;
            break; // Breaks the loop
        }

    }

    // Pauses console and "int main()" return 0 after function completion. 
    system("pause");
    return 0;
}

/*

I was really confused on what "void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)" 
parameters do or the purpose of them was, so I had all of this in my main function until I found out int& acts like a return value.

-----------------------------------------------------------------------------------------------------------------------------------
    int surfboard_quantity = 0;
    string surfboard_size;

    cin >> surfboard_quantity >> surfboard_size;
    transform(surfboard_size.begin(), surfboard_size.end(), surfboard_size.begin(), tolower);
    cout << "\n" << endl;

    if (surfboard_size == "s")
        iTotalSmall += surfboard_quantity;
    else if (surfboard_size == "m")
        iTotalMedium += surfboard_quantity;
    else if (surfboard_size == "l")
        iTotalLarge += surfboard_quantity;
-----------------------------------------------------------------------------------------------------------------------------------

https://mathbits.com/MathBits/CompSci/Introduction/clear.htm#:~:text=Clearing%20the%20Screen%3A%20system(%22,standard%20library%20header%20file%20%3Cstdlib.
^^ This is where I found "system("CLS");" to clear the console

*/
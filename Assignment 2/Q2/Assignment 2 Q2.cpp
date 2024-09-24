#include <iostream>
#include <vector>
#include "Assignment 2 Q2.h"

using namespace std;

int main()
{
    // Creates a stack named userStack
    Stack userStack;

    // Creates a variable named functionSelection that will be used to store the user's input for the function that they want to use
    // throughout the program, and initializes it's value to 0
    int functionSelection = 0;

    // Creates a while loop that executes while the value of "functionSelection" is not equal to 7
    while (functionSelection != 7)
    {
        // Displays Main Menu Heading
        cout << "MAIN MENU" << endl << endl;

        // Displays the options for the functions that the user can select
        cout << "1. Check to see if the stack is empty" << endl;
        cout << "2. Insert an integer onto the stack" << endl;
        cout << "3. Remove an integer from the stack" << endl;
        cout << "4. Find the value of the element at the top of the stack" << endl;
        cout << "5. Find the average of the values of the stack's elements" << endl;
        cout << "6. Display the stack's elements" << endl;
        cout << "7. Exit" << endl << endl;

        // Asks the user to input a value and stores that value into the variable "functionSelection"
        cout << "Enter your selection: ";
        cin >> functionSelection;
        cout << endl;

        // Asks user to enter a new value to be stored in the varible "functionSelection" until the
        // value of "functionSelection" is between 1 and 7
        while (functionSelection < 1 || functionSelection > 7)
        {
            cout << "ERROR: You must enter a value between 1 and 7. Please enter a new value here: ";
            cin >> functionSelection;
            cout << endl;
        }

        // If "functionSelection" is equal to 1, the program calls the "empty" function and outputs
        // a message to the user telling them whether the function is or is not empty
        if (functionSelection == 1)
        {
            if (userStack.empty())
            {
                cout << "The stack is empty." << endl;
            }
            else 
            {
                cout << "The stack is not empty." << endl;
            }
        }

        // If "functionSelection" is equal to 2, the program asks the user to enter an integer value and calls the "push" 
        // function to push that value onto the stack
        else if (functionSelection == 2)
        {
            int value;
            cout << "Enter an integer to push onto the stack: ";
            cin >> value;
            userStack.push(value);
        }

        // If "functionSelection" is equal to 3, the program calls the "pop" function to remove the value at the top of the stack
        else if (functionSelection == 3)
        {
            userStack.pop();
        }

        // If "functionSelection" is equal to 4, the program calls the "getValueAtTop" function to obtain the value at the top of the stack,
        // but also includes try and catch blocks to tell the program how to handle a runtime_error if it is thrown by the function
        else if (functionSelection == 4)
        {
            try 
            {
                cout << "The value of the top element is: " << userStack.getValueAtTop() << endl;
            }
            catch (const runtime_error& e) 
            {
                cerr << e.what() << endl;
            }
        }

        // If "functionSelection" is equal to 5, the program calls the "calculateAverage" function to find the avearge value of the stack's
        // elements and output it to the user, but also includes try and catch blocks to tell the program how to handle a runtime_error 
        // if it is thrown by the function
        else if (functionSelection == 5)
        {
            try
            {
                cout << "The average of the stack's elements is: " << userStack.calculateAverage() << endl;
            }
            catch (const runtime_error& e)
            {
                cerr << e.what() << endl;
            }
        }

        // If "functionSelection" is eaul to 6, the program calls the "displayStackElements" function to display all the elements of 
        // "userStack"
        else if (functionSelection == 6)
        {
            userStack.displayStackElements();
        }

        // Executes the following code if the value of "functionSelection" is not equal to 7
        if (functionSelection != 7)
        {
            // Displays "Press Enter to Continue" and requires that the user press the enter key in order to
            // move on in the program
            cout << endl;
            string enterToContinue;
            cout << "Press Enter to Continue";
            enterToContinue = cin.get();
            cin.ignore();
            cout << endl;
        }
    }
}
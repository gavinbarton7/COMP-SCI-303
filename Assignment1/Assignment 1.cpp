#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
#include "Assignment 1.h"

int main()
{
    // Creates array of integers named "arr" and initializes every element to 0
    int arr[110] = { 0 };

    // Creates an int variable named "maxLength" that holds the value of 100, which is the
    // maximum length the array can be
    int maxLength = 110;

    // Opens the input file named "A1input.txt" 
    ifstream inputFile("A1input.txt");

    // Reads in every single number from the input file into the array
    for (int i = 0; i < 100; i++)
    {
        inputFile >> arr[i];
    }

    // Closes the input file
    inputFile.close();

    // Defines an int variable "arrLength" with an initial value of 100
    int currentLength = 100;
    cout << endl;

    // Defines and int variable "userInput" with an initial value of 0
    int userInput = 0;

    // Creates while loop that will continuously execute while the value of the "userInput" variable is 
    // not equal to 5
    while (userInput != 5)
    {
        // Displays array
        cout << "Array: " << endl;
        cout << setw(5) << "index" << setw(8) << "value" << endl;
        for (int i = 0; i < currentLength; i++)
        {
            cout << setw(5) << i << setw(8) << arr[i] << endl;
        }
        cout << endl;
        
        // Disaplays the main menu heading
        cout << "Main Menu:" << endl << endl;

        // Displays a message to the user telling them how many integers the array currently contains
        // and the maximum amount amount of integers it can contain
        cout << "The array currently has " << currentLength << " integers in it." << endl;
        cout << "The maximum amount of integers the array can contain is " << maxLength << "." << endl << endl;
        
        // Displays options to the user
        cout << "Options: " << endl;
        cout << "   1. Check to see if array contains a specific value." << endl;
        cout << "   2. Replace a value in the array with another specific value." << endl;
        cout << "   3. Add a value to the end of the array." << endl;
        cout << "   4. Remove a value from the array." << endl;
        cout << "   5. Exit program." << endl << endl;
            
            
        // Asks user to enter a choice between 1 and 5 and asks them to enter a choice again if the input isn't between 
        // 1 and 5 until they input a value between 1 and 5
        cout << "Enter a choice 1-5: ";
        cin >> userInput;
        while (userInput < 1 || userInput > 5)
        {
            cout << "Invalid choice. Please enter a value between 1 and 5: ";
            cin >> userInput;
        }

        // Executes the following code if the user inputs the value of 1
        if (userInput == 1)
        {
            // Calls the "findIndexWithValue" and stores it's return value in the newly defined int variable
            // "elementValue"
            int elementValue = findIndexWithValue(arr, currentLength);
            
            // Tells the user that the value they inputed is not in the array if the function "findIndexWithValue" returns -1
            if (elementValue == -1)
            {
                cout << "The value you entered is not in the array." << endl;
            }
            
            // If the function "findIndexWithValue" doesn't returns -1, tells the user which index the array value appears at
            else
            {
                cout << "The value you entered appears in the array at index " << elementValue << "." << endl;
            }
        }

        // Executes the following code if the user inputs the value of 2
        else if (userInput == 2)
        {
            // Calls the "changeValueInArray" function in order to update the value that the user desires
            changeValueInArray(arr, currentLength, maxLength);
        }

        // Executes the following code if the user inputs the value of 3
        else if (userInput == 3)
        {
            // Calls "addValueToArray" functions to add the value that the user chose to the end of the 
            // array and assigns it's return value to the newly defined "returnValue" varaible
            int returnValue = addValueToArray(arr, currentLength, maxLength);
            
            // Increases the value of the "currentLength" variable by 1 if the value of the "returnValue" variable
            // is not equal to 1.
            if (returnValue != 1)
            {
                currentLength++;
            }
        }

        // Executes the following code if the user inputs the value of 4
        else if (userInput == 4)
        {
            // Calls "removeValueFromArray" functions to add the value that the user chose to the end of the
            // array and assigns it's return value to the newly defined "returnValue" varaible
            int returnValue = removeValueFromArray(arr, currentLength, maxLength);
            
            // Decreases the value of the "currentLength" variable by 1 if the value of the "returnValue" variable
            // is not equal to 1.
            if (returnValue != 1)
            {
                currentLength--;
            }
        }

        if (4 >= userInput >= 1)
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

// This function is the function
int findIndexWithValue(int arr[], int currentLength)
{
    // Defines variable "value1" to hold the value that the user wants to search for in the array,
    // obtains that integer value through the user's input, and the stores it in the variable
    int value1;
    cout << "Enter an integer value: ";
    cin >> value1;
    
    // Creates a for loop that iterates through all values in the array to see if "value1" 
    // (the user's input value) appears in it and returns the index that "value1" appears at 
    for (int i = 0; i < currentLength; i++)
    {
        if (arr[i] == value1)
        {
            return i;
        }
    }
    // Returns -1 if "value1" is not in the array
    return -1;
}

int changeValueInArray(int arr[], int currentLength, int maxLength)
{
    // Defines string variable "userInput" that will be used to store the user input for the index
    // and and int variable index that will be used to store the value in after it is
    // converted to an integer with the stoi function
    string userInput;
    int index;

    // The following try and catch blocks are used to check to see if the user inputs an integer value
    // and if they do not input an integer, it gives them an error message and causes the function to return the
    // value of 1
    try
    {
        cout << "Enter the index of the value you would like to replace in the array: ";
        cin >> userInput;
        index = stoi(userInput);
    }

    catch (invalid_argument& ex)
    {
        cerr << "Invalid input: Not an integer." << endl;
        cerr << "The value of the index must be an integer." << endl;
        cerr << "Returning to Main Menu" << endl;
        return 1;
    }


    // calls the function "getValueInArray inside of a try block in order to assign it's return value to
    // the variable "oldValue, and the catch block below tells the program how to handle an "out_of_range" 
    // exception by outputting and error message and having the function return the value of 1
    try
    {
        getValueInArray(arr, index, currentLength);
    }

    catch (out_of_range& ex)
    {
        cerr << "Out of range exception occurred" << endl;
        cerr << ex.what() << endl;
        cerr << "Returning to Main Menu" << endl;
        return 1;
    }

    // Defines variable "oldValue" that will be used to store the original value of the element at the
    // given index before changing it and assigns it the current value at the index
    // that the user provided
    int oldValue = arr[index];

    // Defines string variable "userInput2" that will be used to store the value that the user wants to 
    // replace the existing value at the index withand an int variable index that will be used to 
    // store the value in after it is converted to an integer with the stoi function
    string userInput2;
    int value2;

    // The following try and catch blocks are used to check to see if the user inputs an integer value
    // and if they do not input an integer, it gives them an error message and causes the function to return the
    // value of 1
    try
    {
        cout << "Enter the the value you would like replace it with: ";
        cin >> userInput;
        value2 = stoi(userInput);
    }

    catch (invalid_argument& ex)
    {
        cerr << "Invalid input: Not an integer." << endl;
        cerr << "The value of the index must be an integer." << endl;
        cerr << "Returning to Main Menu" << endl;
        return 1;
    }
    
    // Assigns the value of the variable "value2" to the index equivalent to the value of the variable
    // "index" in the array "arr", then outputs both the old and new values at the index to the user
    arr[index] = value2;
    cout << "The old value at the given index is: " << oldValue << endl;
    cout << "The new value at the given index is: " << arr[index] << endl;
    return 0;
}


// This function is used to add values to the array
int addValueToArray(int arr[], int currentLength, int maxLength)
{
    // calls the functions "getValueInArray inside of a try block, and the catch block below
    // tells the program how to handle an "out_of_range" exception by printing our an error message to the user
    // and havign the function return the value of 1
    try 
    {
        isArrayFull(currentLength, maxLength);
    }

    catch (out_of_range& ex)
    {
        cerr << "Out of range exception occurred" << endl;
        cerr << ex.what() << endl;
        cerr << "You can not add any more than " << maxLength << " integers to the array." << endl;
        cerr << "Returning to main menu" << endl;
        return 1;
    }

    // Defines string variable "userInput" that will be used to store the users inputs
    // and and int variable value3 that will be used to store the value in after it is
    // converted to an integer with the stoi function
    string userInput;
    int value3;

    // The following try and catch blocks are used to check to see if the user inputs an integer value
    // and if they do not input an integer, it gives them an error message and causes the function to return the
    // value of 1
    try 
    {
        cout << "Enter the value you would like to add to the array: ";
        cin >> userInput;
        value3 = stoi(userInput);
    }

    catch (invalid_argument& ex)
    {
        cerr << "Invalid input: Not an integer." << endl;
        cerr << "The array can only contain integers." << endl;
        cerr << "Returning to Main Menu" << endl;
        return 1;
    }

    // Assigns the value of the variable "value3" to the index equivalent to the value of the variable
    // "currentLength" in the array "arr"
    arr[currentLength] = value3;

    return 0;
}

// This function is used to remove values from the array
int removeValueFromArray(int arr[], int currentLength, int maxLength)
{
    // Defines string variable "userInput" that will be used to store the user input for the index
    // and and int variable index that will be used to store the value in after it is
    // converted to an integer with the stoi function
    string userInput;
    int index;

    // The following try and catch blocks are used to check to see if the user inputs an integer value
    // and if they do not input an integer, it gives them an error message and causes the function to return the
    // value of 1
    try
    {
        cout << "Enter the index of the value you would like to remove from the array: ";
        cin >> userInput;
        index = stoi(userInput);
    }

    catch (invalid_argument& ex)
    {
        cerr << "Invalid input: Not an integer." << endl;
        cerr << "The value of the index must be an integer." << endl;
        cerr << "Returning to Main Menu" << endl;
        return 1;
    }


    // calls the function "getValueInArray inside of a try block in order to assign it's return value to
    // the variable "oldValue, and the catch block below tells the program how to handle an "out_of_range" 
    // exception by outputting and error message and having the function return the value of 1
    try
    {
        getValueInArray(arr, index, currentLength);
    }

    catch (out_of_range& ex)
    {
        cerr << "Out of range exception occurred" << endl;
        cerr << ex.what() << endl;
        cerr << "Returning to Main Menu" << endl;
        return 1;
    }

    // Assigns the value of "0" to the final element in the array
    arr[(currentLength - 1)] = 0;

    return 0;
}

// This function is used for error handling in the in the "changeValueInArray" function when
// the user inputs an index that is out of range
int getValueInArray(int arr[], int index, int currentLength)
{
    // if the value of the index is less than 0 or greater than/equal to the variable "maxLength", throw 
    // out_of_range exception
    if (index < 0 || index >= currentLength)
    {
        throw std::out_of_range("The value of the index is out of range.");
    }

    // returns the value at the index if the exception is not thrown
    else
    {
        return arr[index];
    }
}

// This function is used for error handling in the in the "addValueToArray" function when
// the the array is full
int isArrayFull(int currentLength, int maxLength)
{
    // if the value of the variable "currentLength" is greater than/equal to the variable "maxLength", 
    // throw out_of_range exception
    if (currentLength >= maxLength)
    {
        throw std::out_of_range("The array is full.");
    }

    // returns 0 if the exception is not thrown
    else
    {
        return 0;
    }
}
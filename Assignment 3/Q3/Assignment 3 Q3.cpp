#include <iostream>
#include "Assignment 3 Q3.h"
using namespace std;

int main()
{
	// Creates a "Single_Linked_List" object that uses the "int" value type
	Single_Linked_List<int> usersLinkedList;

	// Defines variable "functionSelection" and initializes it to 0. The point of this variable is to store the value that
	// the users input's when asked which of the programs functions they want to use
	int functionSelection = 0;

	// Executes the following code while the value of "functionSelection" is not equal to 11
	while (functionSelection != 13)
	{
		// Displays main menu heading
		cout << "MAIN MENU" << endl << endl;

		// Displays options to user
		cout << "1. Add item to the front of the linked list" << endl;
		cout << "2. Add item to the back of the linked list" << endl;
		cout << "3. Remove item from the front of the linked list" << endl;
		cout << "4. Remove item from the back of the linked list" << endl;
		cout << "5. Obtain the first value in linked list" << endl;
		cout << "6. Obtain the last value in linked list" << endl;
		cout << "7. Check to see if the linked list is empty" << endl;
		cout << "8. Insert a value into the linked list" << endl;
		cout << "9. Remove a value from the linked list" << endl;
		cout << "10. Find a value in the linked list" << endl;
		cout << "11. Display the values in the linked list" << endl;
		cout << "12. Sort the values in the linked list from least to greatest" << endl;
		cout << "13. Exit the program" << endl << endl;

		// Gets input from user for which function they would like to use
		cout << "Enter your selection here: ";
		cin >> functionSelection;
		cout << endl;

		// Asks user to enter a new value to be stored in the varible "functionSelection" until the
		// value of "functionSelection" is between 1 and 13
		while (functionSelection < 1 || functionSelection > 13)
		{
			cout << "ERROR: You must enter a value between 1 and 12. Please enter a new value here: ";
			cin >> functionSelection;
			cout << endl;
		}

		// If "functionSelection" is equal to 1, the program obtains an integer value from the user and calls the "push_front"
		// function to add the value to the front of the list
		if (functionSelection == 1)
		{
			int valueToBeAdded;
			cout << "Enter the integer value that you want to add to the front of the linked list: ";
			cin >> valueToBeAdded;
			usersLinkedList.push_front(valueToBeAdded);
		}

		// If "functionSelection" is equal to 2, the program obtains an integer value from the user and calls the "push_back"
		// function to add the value to the back of the list
		else if (functionSelection == 2)
		{
			int valueToBeAdded;
			cout << "Enter the integer value that you want to add to the back of the linked list: ";
			cin >> valueToBeAdded;
			usersLinkedList.push_back(valueToBeAdded);
		}

		// If "functionSelection" is equal to 3, calls the "pop_front" function to add the value to the front of the list
		else if (functionSelection == 3)
		{
			usersLinkedList.pop_front();
		}

		// If "functionSelection" is equal to 4, calls the "pop_back" function to add the value to the back of the list
		else if (functionSelection == 4)
		{
			usersLinkedList.pop_back();
		}

		// If "functionSelection" is equal to 5, calls the "front" function to obtain the value at the front of the list
		// but includes try and catch blocks to catch an "out_of_range" exceptions and tell the user if the linked list is empty
		else if (functionSelection == 5)
		{
			try
			{
				cout << "The value at the front of the linked list is: " << usersLinkedList.front() << endl;
			}
			catch (out_of_range& ex)
			{
				std::cerr << "Out of range exception occurred" << endl;
				cerr << ex.what() << endl;
			}
		}

		// If "functionSelection" is equal to 6, calls the "back" function to obtain the value at the back of the list
		// but includes try and catch blocks to catch an "out_of_range" exceptions and tell the user if the linked list is empty
		else if (functionSelection == 6)
		{
			try
			{
				cout << "The value at the back of the linked list is: " << usersLinkedList.back() << endl;
			}
			catch (out_of_range& ex)
			{
				std::cerr << "Out of range exception occurred" << endl;
				cerr << ex.what() << endl;
			}
		}

		// If "functionSelection" is equal to 7, calls the "empty" function and tells the user whether the linked list is or isn't
		// empty based on what value the function returns
		else if (functionSelection == 7)
		{
			if (usersLinkedList.empty() == true)
			{
				cout << "The linked list is empty." << endl;
			}

			else if (usersLinkedList.empty() == false)
			{
				cout << "The linked list is not empty." << endl;
			}
		}

		// If "functionSelection" is equal to 8, the program obtains a value from the user for the index and the
		// value that they want to inser and calls the "insert" function to insert the value into the linked list
		// at the index the user provided
		else if (functionSelection == 8)
		{
			size_t index;
			cout << "Enter the index where you want to insert the value into the linked list: ";
			cin >> index;

			int valueToBeInserted;
			cout << "Enter the integer value that you want to add to the linked list: ";
			cin >> valueToBeInserted;
			usersLinkedList.insert(index, valueToBeInserted);
		}

		// If "functionSelection" is equal to 9, the program obtains a value from the user for the index and calls the 
		// "remove" function to remove the value from the linked list at the index the user provided
		else if (functionSelection == 9)
		{
			size_t index;
			cout << "Enter the index of the value that you want to remove from the linked list: ";
			cin >> index;

			usersLinkedList.remove(index);
		}

		// If "functionSelection" is equal to 10, the program obtains a value from the user for the and calls the 
		// "find" function to find the index where the value first appears in the linked list. Also tells the user that if they got
		// a value that is equal to the size of the list, then that means that the value they entered is not in the linked list
		else if (functionSelection == 10)
		{
			int valueToBeFound;
			cout << "Enter the integer value that you want to look for in the linked list: ";
			cin >> valueToBeFound;
			cout << "The value you entered first appears at index: " << usersLinkedList.find(valueToBeFound) << endl;
			cout << "NOTE: If the program outputted a value equivalent to the size of the Linked List, then the value is not in the Linked List." << endl;
		}

		// Calls the "displayLinkedList" function to display all the values in the linked list "usersLinkedList"
		else if (functionSelection == 11)
		{
			usersLinkedList.displayLinkedList();
		}

		// Calls the "displayLinkedList" function to display all the values in the linked list "usersLinkedList"
		else if (functionSelection == 12)
		{
			usersLinkedList.insertion_sort();
		}

		// Executes the following code if "functionSelection" is not equal to 13
		if (functionSelection != 13)
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


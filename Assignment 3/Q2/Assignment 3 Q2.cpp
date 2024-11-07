#include <iostream>
#include <vector>
#include "Assignment 3 Q2.h"

using namespace std;

int main()
{
    // Creates a vector named userVector
    vector<int> userVector = { 2, 1, 8, 5, 4, 7, 6, 3, 9, 10, 3, 6, 10, 7, 5, 8, 9, 1, 2, 4 };
    
    // Creates a variable named target that will be used to store the value the user wants to search for in the vector and asks the user to
	// input the value they want to search for in the vector
    int target;
    cout << "What integer would you like to search for in the vector: ";
    cin >> target;
	cout << endl;

	// Calls the linear search function
    cout << "The last index that this integer appears at is: " << linear_search(userVector, target, (userVector.size() - 1)) << endl;
}

// Modified linear_search function designed to find the last instance of a particular value in a vector, 
// the first difference is that the third parameter is now called pos_last instead of pos_first since I am
// searching for the last instance of a specific value in the vector rather than the first
template<typename Item_Type>
int linear_search(const vector<Item_Type>& items, const Item_Type& target, size_t pos_last)
{
	// The function returns -1 if pos_last is equal to -1 since the only way pos_last can be -1 is if we have passed through
	// every inde of the vector with all the recursive function calls and haven't found the value in the vector.
	if (pos_last == -1)
	{
		return -1;
	}

	// Returns the value of the index that the "target" value is at if the functions finds the target value in the vector
	if (items[pos_last] == target)
	{
		return pos_last;
	}

	// Recursively calls the function with a pos_last parameter value of one less this time (pos_last - 1) if the function did not return the value
	// of pos_last or -1 from above 
	else
	{
		return linear_search(items, target, (pos_last - 1));
	}
}
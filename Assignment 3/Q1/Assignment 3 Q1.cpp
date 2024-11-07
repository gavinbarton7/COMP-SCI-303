#include "Assignment 3 Q1.h"
#include <iostream>
using namespace std;

int main() 
{
	// Creates a queue named prgramQueue that stores integer values
	Queue<int> programQueue;

	
	// Inserts the first 10 integers (1-10) into the queue
	for (int i = 1; i <= 10; i++)
	{
		programQueue.push(i);
	} 


	// Assigns the newly created variable "queueSize" the value of the current size of programQueue
	int queueSize = programQueue.size();

	// Display each of the values in programQueue in order from front to rear by output the front value, moving it to the rear, and
	// repeating the process as many times as the size of programQueue
	cout << "Oringinal Queue: ";
	for (int i = 0; i < queueSize; i++) 
	{ 
		cout << programQueue.front() << " ";
		programQueue.move_to_rear();
	} 
	cout << endl << endl;

	// Calls the "move_to_rear" function to move the value that is currently at the front of programQueue to the rear of programQueue
	programQueue.move_to_rear();

	// Display each of the values in programQueue in order from front to rear by output the front value, moving it to the rear, and
	// repeating the process as many times as the size of programQueue
	cout << "Queue with front element moved to rear: ";
	for (int i = 0; i < queueSize; i++) 
	{ 
		cout << programQueue.front() << " ";
		programQueue.move_to_rear();
	} 
	cout << endl;
	
	return 0;
}
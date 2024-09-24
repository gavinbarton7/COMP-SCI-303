#ifndef STACK
#define STACK

#include <iostream>
#include <vector>

using namespace std;

// Creates a class named "Stack" that will be used to create a stack object in this program
class Stack 
{
    private:
        // creates a vector named "stackElements" that is used to store the values of the stack's elements
        vector<int> stackElements;

    public:
        // This function inserts a value onto the stack using the "push_back" function of the vector data structure
        void push(int element) 
        {
            stackElements.push_back(element);
        }

        // This function removes an elements from the stack using the "pop_back" function of the vector data structure, but if the stack
        // is empty, this function outputs an error message telling the user so
        void pop() 
        {
            if (stackElements.empty())
            {
                cout << "ERROR: The stack is empty, so no value can be removed" << endl;
            }
            else
            {
                stackElements.pop_back();
            }
        }

        // This function is used to obtain the value at the top of the stack. It uses the back function of the vector data structure
        // to obtain this value, but also calls the empty function beforehand and throws a runtime_error if the stack is empty
        int getValueAtTop()
        {
            if (stackElements.empty())
            {
                throw runtime_error("ERROR: The stack is empty, so there is no value at the top.");
            }
            else 
            {
                return stackElements.back();
            }
        }

        // This function to check to if the stack is empty by using the "empty" function of the vector data structure
        bool empty() 
        {
            return stackElements.empty();
        }

        // This function is used to calculate the average value of the stack's elements and returns the average.
        // However, it also call the empty function beforehand to check to see if the stack is empty, and if the
        // empty function returns true, the program throws a runtime_error
        float calculateAverage()
        {
            if (stackElements.empty())
            {
                throw runtime_error("ERROR: The stack is empty, so there are no values to calculate the average of.");
            }

            else 
            {
                float sum = 0;
                for (int i = 0; i < stackElements.size(); i++)
                {
                    sum += stackElements[i];
                }

                float avg = sum / stackElements.size();
                return avg;
            }
        }

        // This function is used to display the elements of the stack, but also tells the user that the stack is empty if it is empty
        void displayStackElements()
        {
            if (stackElements.empty() == true)
            {
                cout << "ERROR: The stack is empty, so there are no elements to display." << endl;
            }

            else
            {
                cout << "The stack's elements in order from bottom to top are: ";
                for (int i = 0; i < stackElements.size(); i++)
                {
                    cout << stackElements[i] << " ";
                }
                cout << endl;
            }
        }
};

#endif
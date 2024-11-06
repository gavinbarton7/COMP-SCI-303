#ifndef QUEUE
#define QUEUE

#include <string>
#include <iostream>
using namespace std;

// creates class that will be used to create the queue in this program
template<typename Item_Type>
class Queue 
{
    private:
        // creates a structure named "Node" for the Queue's values (which will be stored using a linked list data structure)
        struct Node 
        {
            // Creates a variable that will be used to store the data in the node 
            Item_Type data;

            // Creates a pointer to the named "next" that stores the memory address of the next node
            Node* next;

            // This is the constructor for the node structure, it initializes the value of the "next" pointer of a node to nullptr
            Node(Item_Type val) : data(val), next(nullptr) {}
        };

        // Creates a pointer named "head" that will be used to store the memory address of the node for the first value in the queue
        Node* head = nullptr;

        // Creates a pointer named "tail" that will be used to store the memory address of the last node in the queue
        Node* tail = nullptr;

        // creates an int variable named "num_items" that is used to store the size of the Single Linked List
        int num_items;

    public:

        // Implementation of the "push" function
        void push(Item_Type value)
        {
            // creates a new node
            Node* newNode = new Node(value);

            // If the value of the "tail" pointer is not equal to nullptr, assigns the "newNode" pointer's value to
            // the next pointer of the last node (basically, it's adding a new node to the end of the queue that contains
            // the value stored at the memory address that the "newNode" pointer contains, but if the value of the tail pointer is "nullptr"
            // (the tail pointer doesn't point to any memory address) the program can skip this step and just assign the "tail" pointer 
            // the value of the "newNode pointer"
            if (tail != nullptr)
            {
                tail->next = newNode;
            }

            // Assign the "tail" pointer the same value as the "newNode" pointer
            tail = newNode;

            // If the value of the "head" pointer is nullptr, assigns the "head" pointer the same value as the "tail" pointer
            if (head == nullptr)
            {
                head = newNode;
            }

            // increases the value of the variable "num_items" by one
            num_items++;
        }

        // Implementation of the "pop" function
        void pop() 
        {
            // if "head" pointer is not equal to nullptr, executes the following code
            if (head != nullptr)
            {
                // Creates a pointer "previousHead" and assigns it the same value as the head pointer before changing the head pointer's value
                // to be the value stored in the next pointer of the node located at the memory address currently stored in the head pointer 
                // (before the value stored in the head pointer changes) 
                Node* previousHead = head;
                head = head->next;

                // Assigns the value of "nullptr" to the tail pointer if the value of the head pointer is now equal to "nullptr"
                if (head == nullptr)
                {
                    tail = nullptr;
                }

                // deletes the node located at the memory address stored in the "previousHead" pointer
                delete previousHead;

                // reduces the value of num_items by 1
                num_items--;
            }
        }

        // Implementation of the "front" function
        Item_Type front()
        {
            // returns the value of the "data" of the node located at the memory address stored in the "head" pointer 
            // if the value of the "head" pointer is not equal to nullptr
            if (head != nullptr)
            {
                return head->data;
            }

            // throws out of range exception if the "head" pointer's value is equal to nullptr
            else
            {
                throw out_of_range("Linked list is empty");
            }
        }

        // Implementation of the "size" function
        int size() 
        {
            // returns the value of the variable "num_items"
            return num_items;
        }

        // Implementation of the "empty" function
        bool empty()
        {
            // returns true is the value of the "head" node is nullptr, otherwise, it returns false
            return head == nullptr;
        }

        // Implementation of the "move_to_rear" function that moves the value at the the front of the queue to the rear of the queue
        void move_to_rear() 
        {
            // If the queue is not empty, executes the following code
            if (empty() == false) 
            {
                //Creates variable "frontValue" that is used to store the value that is currently at the front of the Queue
                Item_Type frontValue = front();                

                // Calls the pop function to remove the value at the fron of the queue
                pop();

                // Calls the push function to add the value previously at the front of the queue to the rear of the queue
                push(frontValue);
            }
        }
};

#endif
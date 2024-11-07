#ifndef LINKEDLIST
#define LINKEDLIST
#include <string>
#include <iostream>
using namespace std;

template <typename Item_Type>
class Single_Linked_List
{
    private:
        // Creates a structure named "Node" for the Linked List's nodes
        struct Node
        {
            // Creates a variable that will be used to store the data in the node 
            Item_Type data;

            // Creates a pointer to the named "next" that stores the memory address of the next node
            Node* next;

            // This is the constructor for the node structure, it initializes the value of the "next" pointer of a node to nullptr
            Node(const Item_Type& data_item, Node* next_ptr = nullptr) : data(data_item), next(next_ptr) {}
        };

        // Creates a pointer named "head" that will be used to store the memory address of the first node in the linked list
        Node* head = nullptr;

        // Creates a pointer named "tail" that will be used to store the memory address of the last node in the linked list
        Node* tail = nullptr;

        // Creates an int variable named "num_items" that is used to store the size of the Single Linked List
        int num_items;

    public:
        // Implementation of the "push_front" function
        void push_front(const Item_Type& item)
        {
            // Creates a new node and puts the new node at the front of the linked list
            head = new Node(item, head);

            // If the value of the "tail" pointer is nullptr, assigns the "tail" pointer the same memory address as the "head" pointer
            if (tail == nullptr)
            {
                tail = head;
            }

            // Increases the value of the variable "num_items" by one
            num_items++;
        }

        // Implementation of the "push_back" function
        void push_back(const Item_Type& item)
        {
            // Creates a new node and a pointer "newNode" for the node that will be added to the back
            Node* newNode = new Node(item);

            // If the value of the "tail" pointer is not equal to nullptr, assigns the "newNode" pointer's value to
            // the next pointer of the last node (basically, it's adding a new node to the end of the linked list that contains
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
                head = tail;
            }

            // Increases the value of the variable "num_items" by one
            num_items++;
        }

        // Implementation of the "pop_front" function
        void pop_front()
        {
            // If "head" pointer is not equal to nullptr, executes the following code
            if (head != nullptr)
            {
                // Creates a pointer "previousHead" and assigns it the same value as the head pointer before changing the head pointer's value
                // to be the value stored in the next pointer of the node located at the memory address currently stored in the head pointer 
                // (before the value stored in the head pointer changes) 
                Node* previousHead = head;
                head = head->next;

                // Deletes the node located at the memory address stored in the "previousHead" pointer
                delete previousHead;

                // Reduces the value of num_items by 1
                num_items--;
            }

            // Assigns the "tail" pointer the value of nullptr if the "head" pointers new value is nullptr (which implies that the linked list
            // is now empty since their was only one node before)
            if (head == nullptr)
            {
                tail = nullptr;
            }
        }

        // Implementation of the "pop_back" function
        void pop_back()
        {
            // If "tail" pointer is not equal to nullptr, executes the following code
            if (tail != nullptr)
            {
                // If the values of the "head" and "tail" pointers are equal to each other (which implies that there is only one Node in the 
                // Linked List), deletes the node located at the memory address stored in the "tail" pointer and assigns both the "tail"
                // and "head" pointers the value nullptr
                if (head == tail)
                {
                    delete tail;
                    tail = nullptr;
                    head = nullptr;
                }

                else
                {
                    // Creates a pointer named "currentNode" and assigns it the value of the "head" pointer
                    Node* currentNode = head;

                    // Continuously reassign the value of the "currentNode" pointer to be the memory address of the next node in the linked
                    // list until the memory address of the next node in the linked list is equal to the value stored
                    // in the "tail" pointer
                    while (currentNode->next != tail)
                    {
                        currentNode = currentNode->next;
                    }

                    // Deletes the node located at the memory address stored in the "tail" pointer
                    delete tail;

                    // Assigns the "tail" pointer the value stored in the "currentNode" pointer
                    tail = currentNode;

                    // Assigns the value of the next pointer for the Node located at the memory address stored in the "tail" pointer
                    // to be nullptr
                    tail->next = nullptr;
                }

                // Reduces the value of num_items by 1
                num_items--;
            }
        }

        // Implementation of the "front" function
        Item_Type front()
        {
            // Returns the value of the "data" of the node located at the memory address stored in the "head" pointer 
            // if the value of the "head" pointer is not equal to nullptr
            if (head != nullptr)
            {
                return head->data;
            }

            // Throws out of range exception if the "head" pointer's value is equal to nullptr
            else
            {
                throw out_of_range("Linked list is empty");
            }
        }

        // Implementation of the "back" function
        Item_Type back()
        {
            // Returns the value of the "data" of the node located at the memory address stored in the "tail" pointer 
            // if the value of the "tail" pointer is not equal to nullptr
            if (tail != nullptr)
            {
                return tail->data;
            }

            // Throws out of range exception if the "tail" pointer's value is equal to nullptr
            else
            {
                throw out_of_range("Linked list is empty");
            }
        }

        // Implementation of the "empty" function
        bool empty()
        {
            // Returns true is the value of the "head" node is nullptr, otherwise, it returns false
            return head == nullptr;
        }

        // Implementation of the "insert" function
        void insert(size_t index, const Item_Type& item)
        {
            // Uses the "push_front" function to add the value of "item" to the beginning of the linked list if the value of the
            // index is equal to 0
            if (index == 0)
            {
                push_front(item);
            }

            // Uses the "push_back" function to add value "item" to the end of the linked list if the value of the
            // index is greater than or equal to the size of the linked list
            else if (index >= num_items)
            {
                push_back(item);
            }

            else
            {
                // Creates a pointer "currentNode" and assigns it the value of the pointer "head"
                Node* currentNode = head;

                // Iterates through all the nodes up to the node with the index in order to assign the "currentNode" pointer
                // the value of the memory address of the next node in the linked list
                for (size_t i = 0; i < (index - 1); i++)
                {
                    currentNode = currentNode->next;
                }

                // Creates a pointer "newNode" and assigns it the memory address of a new Node that contains a data value equal to the value
                // of the "item" variable and whose "next" pointer value is equal to the value of the "next" pointer of the node located at the 
                // memory address stored in the pointer "currentNode"
                Node* newNode = new Node(item, currentNode->next);

                // Assigns the value of the "newNode" pointer to the value of the "next" pointer of the node located at the 
                // memory addres stored in the pointer "currentNode"
                currentNode->next = newNode;

                // Increases the value of num_items by 1
                num_items++;
            }
        }

        // Implementation of the "remove" function
        bool remove(size_t index)
        {
            // Uses the "pop_front" function to remove the value of at the beginning of the linked list if the value of the
            // index is equal to 0
            if (index == 0)
            {
                pop_front();
            }

            // Returns the value of false if the values of the index is greater than or equal the size of the linked list
            else if (index >= num_items)
            {
                return false;
            }

            else
            {
                // Creates a pointer "currentNode" and assigns it the value of the pointer "head"
                Node* currentNode = head;

                // Iterates through all the nodes up to the node with the index in order to assign the "currentNode" pointer
                // the value of the memory address of the next node in the linked list
                for (size_t i = 0; i < (index - 1); i++)
                {
                    currentNode = currentNode->next;
                }

                // Creates a pointer "nodeToBeRemoved" and assigns it the value of the next pointer of the node located at the
                // memory address stored in "currentNode"
                Node* nodeToBeRemoved = currentNode->next;

                // Assigns the value of the next pointer for the node located at the memory address stored in "nodeToBeRemoved" to the
                // next pointer of the node located at the memory address stored in the pointer "currentNode"
                currentNode->next = nodeToBeRemoved->next;

                // If the pointers "nodeToBeRemoved" and "tail" are equal to each other, assign the pointer "tail" the value of "currentNode"
                if (nodeToBeRemoved == tail)
                {
                    tail = currentNode;
                }

                // Deletes the node located at the memory address stored in the pointer "nodeToBeRemoved"
                delete nodeToBeRemoved;

                // Reduces the value of num_items by 1
                num_items--;
            }

            // Returns true if node is removed sucessfully
            return true;
        }

        // Implementation of the "find" function
        size_t find(const Item_Type& item)
        {
            // Creates a pointer "currentNode" and assigns it the value of the pointer "head"
            Node* currentNode = head;

            // Creates a variable "index" and initializes it's value to 0
            size_t index = 0;

            // Looks through all the nodes of the linked list and returns the index value of a node once it finds the node where
            // the value stored in the varaible "item" first appears
            while (currentNode != nullptr)
            {
                if (currentNode->data == item)
                {
                    return index;
                }
                currentNode = currentNode->next;
                index++;
            }

            // Returns the value of "num_items" if the node is not found
            return num_items;
        }

        // Implementation of the "displayLinkedList" function (this function is used to display all the values of the linked list to the user)
        void displayLinkedList()
        {
            // Outputs all the values in the linked list to the user if the value if the "header" pointer is not equal to nullptr
            if (head != nullptr)
            {
                // Creates a pointer "currentNode" and assigns it the value of the pointer "head"
                Node* current = head;

                // Output each of the values in the linked list
                while (current != nullptr)
                {
                    cout << current->data << " ==> ";
                    current = current->next;
                }

            }

            // If the linked list is empty, displays a message telling the user so
            else
            {
                cout << "The linked list is empty, so it cannot be displayed." << endl;
            }

            cout << endl;
        }

        // Implementation of the "insertion_sort" function (this function is used to sort the values in the linked list from smallest to largest using
        // the insertion sort algorithm)
        void insertion_sort()
        {
            // Creates a pointer named sortedHead that will be used to temporarily store the memory address of the new first node in the linked list 
            // after it is sorted
            Node* sortedHead = nullptr;
        
            // Creates a pointer named key that will be used to store the memory address of the current node that the sorting algorith is at 
            // and assigns it the value of the memory address stored in the head pointer
            Node* key = head;

            // executes the following code while the key pointer is not equal to nullptr
            while (key != nullptr)
            {
                // Creates a pointer named next that is used to store the memory address that is currently stored in the next pointer in of the 
                // pointer "key"
                Node* next = key->next;

                // Executs the following code if the value of the sortedHead pointer is equal to nullptr OR the data value stored in the Node located at the 
                // memory address stored in the sortedHead pointer is less than or equal to the data value stored in the Node located at the memory address 
                // stored in the key pointer
                if ((sortedHead == nullptr) || (sortedHead->data > key->data))
                {
                    // Assigns the next pointer of the node located at the memory address stored in the key pointer the value of the memory address 
                    // stored in the sortedHead pointer
                    key->next = sortedHead;
                    // Assigns the sortedHead pointer the value of the memory address stored in the key pointer, which is the memory address where the new
                    // first node of the linked list is at after this iteration of the insertion sort algorithm
                    sortedHead = key;
                }


                else
                {
                    // Creates a pointer named currentNode and assign it the memory address that is currently stored in the pointer "sortedHead". The
                    // purpose of the currentNode is that it is used to store each nodes memory address while traversing through the nodes of the 
                    // linked list to find a node where the data value of the node located at the memory address stored in it's next pointer (AKA that data 
                    // value of the node that comes after that node in the linked list) is less then the data value stored in the node located at the 
                    // key pointer so that it can insert that node at the positon right after the node that currently comes after it
                    Node* currentNode = sortedHead;
                    
                    // while loop that traverses through the linked list until it finds a node when the next nodes data value is either nullptr or smaller than
                    // current nodes value
                    while ((currentNode->next != nullptr) && (currentNode->next->data < key->data))
                    {
                        currentNode = currentNode->next;
                    }

                    // These two lines of code swap the positions of the nodes located at the memory address stored in the key and currentNode
                    // pointers within the linked by reassigning the memory address values that their next pointers point to
                    key->next = currentNode->next;
                    currentNode->next = key;
                }
                // Assigns the pointer key the value of the memory address stored in the pointer "next"
                key = next;
            }

            // Assigns the value of the memory address stored in the sortedHead pointer to the head pointer
            head = sortedHead;

            // If the value of the head pointer is nullptr, the program assigns the tail pointer the value of nullptr
            if (head == nullptr)
            {
                tail = nullptr;
            }

            // Executes this code if the value of the head pointer is not nullptr. In summation, it iterates through every node in the linked list
            // using a while loop and assigns it's memory address to tail until it gets to a point where the value of the next pointer of a node is 
            // nullptr, so it's purpose is to update the value of the tail pointer after the list is sorted if the linked list is not empty
            else
            {
                // Creates a new pointer named currentNode2 (that is seperate from the "currentNode" pointer defined in the while loop above 
                // and assigns it the memory address value stored in the head pointer
                Node* currentNode2 = head;

                // Iterates through every node in the linked list
                while (currentNode2->next != nullptr)
                {
                    currentNode2 = currentNode2->next;
                }

                // Assigns the tail pointer the value of the memory address stored in the pointer "currentNode"
                tail = currentNode2;
            }
        }
};

#endif
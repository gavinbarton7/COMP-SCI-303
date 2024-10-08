# Singly Linked List Program
This program allows you to create and modify a singly linked list with any of the following data types: integers, floats, strings, or booleans. The 11 functions of the program work the same regardless of which data type you choose, with the one exception being that the program will only accept inputs of the data type you chose at the beginning of the program when you try to add or look for values to the linked list, so when using the functions to add a value to the front, add a value to the back, add a value at a given index, or look for a value in the linked list, so remember to input a value of the type you selected at the beginning of the program when asked which value you would like to add to the linked list. The prompt will specify whether you should enter an "integer", "float", "string", or "boolean" to help you remember which data type you are using.

NOTE: Any time the program outputs "Press Enter to Continue", you must press the enter key to continue in the program

When you first open the program, it will look like this:
![image](https://github.com/user-attachments/assets/e30c59f8-4b56-454d-8dff-ce30f5560662)

If you enter a value outside the range of 1 and 4, you will get a message saying this:
![image](https://github.com/user-attachments/assets/31665139-ba9c-48a0-8043-2fd9926ae6b7)

You will continuously receive the same message until the value you input is between 1 and 4.

## Functions
For the purpose of these instructions, I will be using integers for my Singly Linked List. However, the program will have the same 11 functions with the same prompts and outputs, with the one exception being the part of the prompt where it specifies the data type for the linked list.

After you select the data type you would like to use, the program will output this:
![image](https://github.com/user-attachments/assets/3f480e44-0619-4841-b749-0a36aa68928a)
NOTE: If you enter a value outside the range of 1 and 12, you will be asked to enter a new value until the value you enter is between 1 and 12.

### 1. Add item to the front of the linked list
When you select this function, this is what it will display:
![image](https://github.com/user-attachments/assets/05254453-40db-44d8-a594-69163b5bc867)

NOTE: The word "integer" will be replaced with "float", "string" or "boolean value (0 for false, 1 for true)" if you are using a different data type for your linked list.

Enter an integer value into the prompt. And then you will be returned to the Main Menu

### 2. Add item to the back of the linked list
When you select this function, this is what it will display:
![image](https://github.com/user-attachments/assets/4656b3ef-8e34-4033-bee4-057677d79d25)

NOTE: The word "integer" will be replaced with "float", "string" or "boolean value (0 for false, 1 for true)" if you are using a different data type for your linked list.

Enter an integer value into the prompt. And then you will be returned to the Main Menu

### 3. Remove item from the front of the linked list
When you select this function, this is what it will display:
![image](https://github.com/user-attachments/assets/19ef08e2-03b6-47a0-b455-8c0361b5981b)

Since this function requires no input, you will be immediately returned to the main menu of the program

### 4. Remove item from the back of the linked list
When you select this function, this is what it will display:
![image](https://github.com/user-attachments/assets/f59d6ed3-d431-4472-b6c8-57e7716ba6dd)

Since this function requires no input, you will be immediately returned to the main menu of the program

### 5. Obtain the first value in linked list
If you select this function and there are no values in the linked list, this is what it will display:
![image](https://github.com/user-attachments/assets/61fd81b3-4eb7-459b-b662-3360e556a499)

However, if there is at least one value in the linked list, this is what it will display:
![image](https://github.com/user-attachments/assets/957e41a0-95c8-4c11-8a6c-aeb7ecc33faf)
NOTE: The value at the end will be whichever value is at the front of the linked list

### 6. Obtain the last value in linked list
If you select this function and there are no values in the linked list, this is what it will display:
![image](https://github.com/user-attachments/assets/6e325b3a-93c2-4355-b906-895149634381)

However, if there is at least one value in the linked list, this is what it will display:
![image](https://github.com/user-attachments/assets/f1bdefa9-dc90-465c-b83b-75d56226ffa4)
NOTE: The value at the end will be whichever value is at the back of the linked list

### 7. Check to see if the linked list is empty
This is what the program will display if the linked list is not empty
![image](https://github.com/user-attachments/assets/10e9e2c6-e69a-4437-8fc2-c835265f4de2)

This is what the program will display if the linked list is empty
![image](https://github.com/user-attachments/assets/dbdb4de3-df35-4232-85d8-3e301f7b2c5a)

### 8. Insert a value into the linked list
When you select this function, this is what it will display:
![image](https://github.com/user-attachments/assets/111c42d7-b7fe-46ca-b202-a82005887a8a)

After you enter the index, this is what it will display:
![image](https://github.com/user-attachments/assets/4a7bcc97-5001-4aba-96e4-d8be04a08829)

After you enter the value you want to insert, you will be returned to the main menu
NOTE: The word "integer" will be replaced with "float", "string" or "boolean value (0 for false, 1 for true)" if you are using a different data type for your linked list.
NOTE: If you enter a value for the index that is greater than or equal to the size of the Linked List, the program will assume that you intended to add it to the end of the linked list and insert it at the end

### 9. Remove a value from the linked list
When you select this function, this is what it will display:
![image](https://github.com/user-attachments/assets/f48e111f-9e6f-4419-b776-1212dc3c8ffa)

Since this function requires no input, you will be immediately returned to the main menu of the program

### 10. Find a value in the linked list
When you select this function, this is what it will display:
![image](https://github.com/user-attachments/assets/177fda4b-e5d2-4cd9-9258-085d94451a93)

When you enter the value that you want to look for, this is what will display
![image](https://github.com/user-attachments/assets/1b4ce621-1315-4f3f-802b-55bdf96813bb)
NOTE: As the prompt states, if the program outputted a value equivalent to the size of the Linked List, then the value is not in the Linked List. You can use the "Display" function below to see the size of your linked list.

### 11. Display the values in the linked list
When you select this function, it will display the linked list in the form of "element" ==> for each element, for example:
![image](https://github.com/user-attachments/assets/4ceee93f-0476-4e1b-a473-f56cb73aed54)

If the linked list is empty, the program will output a message telling you that it cannot be displayed.

### Exiting the program
Enter the number 12 in the main menu to exit the program



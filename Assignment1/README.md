# Array modifier program

This program reads 100 integer values from the file "A1input.txt" into an array, and allows you to modify the array by adding, removing, or replacing values in it. It also allows you to find out whether a specific integer value is in the array by searching through the array and providing you with the index where the integer is located. Make sure the "A1input.txt" is in the same folder as your .exe or .dmg file after you compile and run the code, otherwise, the data will not read into the program.

## Read this section before going to the instructions for running the code

Warning: Whenever this program asks you for input, only input integer values. If you input anything besides an integer value at any point in this program, you will get an error message, and you will have to restart from the beginning at the program's main menu. 

![image](https://github.com/user-attachments/assets/2f9baa27-b709-47ef-a42f-8bc275518134)


The three lines between the "Enter a choice 1-6: one" and "Press Enter to Continue" are the error messages. Although this screenshot depicts the error message being displayed after the user enters their choice in the main menu, you will get the same exact three-line error message any time you enter a letter, word, or non-numerical value when asked for input in this program.

Additionally, whenever you see the line "Press Enter to Continue", you must press the enter key to continue in the program.

## Instructions for running the code: 

### Main menu

When you first open the program, it should look like this:

![image](https://github.com/user-attachments/assets/d1ad0c3c-a194-453f-bf68-65a4f9cdb4b3)

To continue, you must enter a value between 1 and 5 based on which of the 5 functions you would like to use or enter 6 to exit the program. If you enter a value outside of the range of 1-6, this will happen:

![image](https://github.com/user-attachments/assets/8b774781-fdf7-4e8a-9eda-2a25db22dbf5)

You must then enter a value between 1 and 6 into the next prompt, otherwise, this will occur:

![image](https://github.com/user-attachments/assets/a82f4c2f-f888-4d4f-beef-3c93cdb6b27a)

You will continue to receive the same prompt infinitely until you enter a value that is between 1 and 6.

### Function 1: Check to see if the array contains a specific value

After you select this function in the main menu, this prompt will pop up:

![image](https://github.com/user-attachments/assets/2846acbd-276b-4e72-b252-9e61246650b8)

You must then enter an integer value into the prompt. If the integer you enter is in the array, you will get an output telling you which index it is at, such as this:

![image](https://github.com/user-attachments/assets/c98f6f8a-8c83-428b-8365-0e5a0748598d)

If the integer you enter is not in the array, you will get an output telling you so, such as this:

![image](https://github.com/user-attachments/assets/0455cefd-8c7c-4e13-8013-5f7816455877)

### Function 2: Replace a value in the array with another specific value.

After you select this function in the main menu, this prompt will pop up:

![image](https://github.com/user-attachments/assets/9d5d8c44-e6cc-435e-bd4f-e1eff1898cbe)

If you enter a valid index, the program will then ask you to enter the value that you would like to use to replace the existing value at the index provided:

![image](https://github.com/user-attachments/assets/51718ae0-03b2-4f1f-bf26-e3398d599960)

After you enter the replacement value, the program will output a message telling you what the old value and the new values at the index you chose to modify:

![image](https://github.com/user-attachments/assets/682b5dd1-c46f-473e-bbcd-30ac237a31f0)

However, if you do not enter a valid index, the program will output an error message telling you that the index you entered is out of range and will send you back to the main menu:

![image](https://github.com/user-attachments/assets/ab8fbac0-9851-419b-804e-f8745c1c6870)

### Function 3: Add a value to the end of the array.

After you select this function in the main menu, this prompt will pop up:

![image](https://github.com/user-attachments/assets/e8a3f048-aac4-4280-b6e1-a4d2f81a4cf2)

You must then enter an integer value into the prompt. After doing so, you will be returned to the main menu:

![image](https://github.com/user-attachments/assets/ab13a855-e827-455b-a4b7-ac487f10abd7)

However, before you select this function from the main menu, it is important to check the line in the main menu that tells you how many integers are currently in the array. As stated in the main menu, the array can only contain a maximum of 110 integers. If you select this function when there are already 110 integers in the array, you will get an error message shown in the image below and be returned to the main menu. The only way to modify the array in this scenario is to use function 2 to replace a value or function 4 to remove a value and then use this function to add a value to the end afterward. See the instructions for Function 2 above or Function 4 below for further details.

![image](https://github.com/user-attachments/assets/53a2d450-6a01-4d86-bf37-37f0409f0849)

### Function 4: Remove a value from the array.

After you select this function in the main menu, this prompt will pop up:

![image](https://github.com/user-attachments/assets/d2def779-3f99-40ba-90bc-5ced2d8c7f41)

You must then enter the index of the element you would like to remove. If you enter a valid index, you will be returned to the main menu.

![image](https://github.com/user-attachments/assets/067c8fdb-93a4-475c-b4ea-dfb1584f52b2)

If you do not enter a valid index, you receive the error message shown in the image below:

![image](https://github.com/user-attachments/assets/c249e1a7-b862-4aaf-9395-3abde8603be0)

### Function 5: Display Array elements

After you select this function in the main menu, every element of the array will be displayed, with the index in the column on the left, and the value in the column on the right.

Note: You might have to scroll up to see the values at the beginning of your array, depending on the size of your window and how many elements there are in the array.

Example output:

![image](https://github.com/user-attachments/assets/e735b536-0d14-48ba-8183-bbbe0a74697e)

![image](https://github.com/user-attachments/assets/db17c72b-6cd3-41b5-a241-36080520eb5e)

![image](https://github.com/user-attachments/assets/c7f37cd3-e947-472b-808b-1916e6923920)

### Exiting the program

Once you are finished, enter the value of 6 in the main menu to exit the program.




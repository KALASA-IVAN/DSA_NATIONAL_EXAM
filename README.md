# DSA_NATIONAL_EXAM
## RCA inventory system
###**Complete version of the DATA STRUCTURES AND ALGORITHMS NATIONAL EXAM**

(THE QUESTION)

```Rwanda coding academy is a special school which teaches coding to young people who have completed o level to become good software engineers not only on Rwandan market but also abroad.
It wants to develop an inventory system in which there is a module of recording items which get in and out of its store.
The data entered on local device are saved in csv file so that they can be moved to the RCA server after.

suppose you are in the team to work on this project, using c++ programming language, develop the features specified in the next list of requirements:

..1) The software should allow user to add a new item recorded at the first time in RCA inventory using "itemadd" command. The item's record is made of item_id, item_name, item_quantity, item_registration_date and their values are given at once, separated by spaces as arguments of itemadd command.

1.1) Define a function addItem() which receives values for item_id, item_name, item_quantity and item_registration_date as argument and put them in the created csv value.

2) The software should allow user to list items in the stock in alphabetically sorted order. using the "itemslist" command.

2.1)Define a function listItems() which displays all items from the csv file on console as indicated below:

----------------------------------------------------------
*
         Item ID: 2        Item Name: BedCover          Quantity: 23        Reg Date: 2023-01-01
         Item ID: 5        Item Name: Chalks            Quantity: 25        Reg Date: 2023-01-01
         Item ID: 3        Item Name: computer          Quantity: 16        Reg Date: 2023-01-01
         Item ID: 6        Item Name: MarkerPen         Quantity: 30        Reg Date: 2023-01-01
         Item ID: 1        Item Name: Mattress          Quantity: 10        Reg Date: 2023-01-01
         Item ID: 4        Item Name: Projector         Quantity: 20        Reg Date: 2023-01-01
         Item ID: 7        Item Name: RimOfPaper        Quantity: 35        Reg Date: 2023-01-01

Item ID : 1    Item Name : Mattress    Quantity : 10 Reg Date: 2023-01-01

3)"help" command is entered, the software should display the help for defined commands and the format to use them as indicated below:

----------------------------------------------------------
*                           Commands syntaxes            
         itemadd <item_id> <item_name> <quantity> <registration_date> 
         itemslist

4)The software should continue running (withour stopping) untill the "exit" command is entered to stop the process.

5)The used commands and entered data should not be case sensitive. 

6) If the entered command doesn't exit, the user should be notified by the software.```

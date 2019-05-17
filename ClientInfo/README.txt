This is a simple Console Application

ABOUT THE PROGRAM:
This program implementing a hash table, handles collisions, and uses hashing with a linear function. 
Hashing is a method that enables access to table items (for adding, deleting, searching and so forth) in time that is relatively constant and independent of the items in the table. 
Hashing uses a hash function to determine the location of an item.  
A problem with hashing occurs when the hash function returns the same value for two or more items (a hash function is a function that maps the search key of a table item into a location that will contain that item).  The situation is referred to as a collision. A collision occurs when a hash function maps two or more distinct search keys into the same location.

The program maintains the names, addresses, and telephone numbers of a group of clients, which serves as an address book. The user can enter the name of a data file that contains the original contents of the clients' address book (clients' information). 
The user can enter, delete, modify (addresses and phone numbers only), or search the data stored in the clients' address book. A client’s last name followed by the client's first name is the search key. 
The program saves the modified clients' address book for later use in alphabetical order in a file called "sorted_clients_address_bk.txt."

HOW TO USE:
 1) User inputs the name of a text file that contains contacts
	- the text file must be int he same directory as the project
 2) Main menu is displayed. User Inputs a character to the corresponding menu option
	  A) Add contact
		   1. Input FIRST NAME
		   2. Input LAST NAME
		   3. Input ADDRESS
		   4. Input PHONE NUMBER. Returns to Main Menu.
	  R) Remove a contact
	       1. Input FIRST NAME
		   2. Input LAST NAME. Returns to Main Menu.
	  M) Modify a contact
	       1. Input FIRST NAME
		   2. Input LAST NAME. 
		   3. Y or N: Modify ADDRESS
				Y) Input new ADDRESS. Returns to Main Menu.
				N) Y or N: Modify PHONE NUMBER
					Y) Input new PHONE NUMBER. Returns to Main Menu.
					N) Returns back to Main Menu.
	  S) Search for a contact
	       1. Input FIRST NAME
		   2. Input LAST NAME. Returns to Main Menu. 
	  D) Display all contacts then Returns back to Main Menu.
	  E) Exit & Save contacts 
		   - txt file created with sorted address in Project directory

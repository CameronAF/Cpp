This is a simple Console Application

This program implementing a hash table, handles collisions, and uses hashing with a linear function. 
Hashing is a method that enables access to table items (for adding, deleting, seaching and so forth) in time that is relatively constant and independent of the items in the table. 
Hashing uses a hash function to determine the location of an item.  
A problem with hashing occurs when the hash function returns the same value for two or more items (a hash function is a function that maps the search key of a table item into a location that will contain that item).  The situation is referred to as a collision. A collision occurs when a hash function maps two or more distinct search keys into the same location.

The program maintains the names, addresses, and telephone numbers of a group of clients, which serves as an address book. The user can enter the name of a data file that contains the original contents of the clients' address book (clients' information). 
The user can enter, delete, modify (addresses and phone numbers only), or search the data stored in the clients' address book. A client's last name, followed by the client's first name is the search key. 
The program saves the modified clients' address book for later use in alphabetical order in a file called "sorted_clients_address_bk.txt."
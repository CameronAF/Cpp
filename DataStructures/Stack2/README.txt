This is a simple Console Application

This program uses a stack to convert a postfix expression to the corresponding fully-parenthesized infix expression.  
Consider the following examples:
 - the postfix expression a b + c d - * will be converted to the infix ((a + b) * (c - d)) 
 - the postfix expression a b + will be converted to the infix (a + b)
 - the postfix expression a b / c d / / will be converted to infix ((a / b) / (c / d))

HOW TO USE:
The program asks the user for a postfix expression as input, and it output the corresponding fully-parenthesized infix expression. 
The program asks the user if they would like to do another conversion.  If so, the user can enter another postfix expression; otherwise the program terminates.

ABOUT THE PROGRAM:
This program implements a Stack class which
 - Consist of a pointer to Node which contains a string and a pointer to the next node
 - Manages dynamic memory (allocate and de-allocate memory)
 - Implements a default and copy constructor 
 - Implements a destructor,
 - Implements a push and pop method
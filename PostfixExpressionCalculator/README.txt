This is a simple Console Application

ABOUT THE PROGRAM:
This program reads mathematical expressions in postfix form to evaluate them.
A postfix expression is an expression in which each operator follows its operands. 
For example,

infix expression            postfix expression          result

5 * 6                       5  6  *                       30
5 * ( 6 + 1 )               5  6  1  +  *                 35
5 * 6 - 15                  5  6  *  15  -                15
(5 * 6 ) - 15               5  6  *  15  -                15
40 + ( 5 * 6 ) / 3          40 5  6  *  3  /  +           50

The file test2.txt contains the above postfix expressions.

Using stacks, the program reads a character and determine
 - if it is a new line, it is the end of the expression; print the value at the top of the stack
 - if it is a space, ignore it and continue with the next iteration
 - if it a digit, put it back on the input stream and read an int number
 - anything else should be an operator; the program pops the top two elements on the stack, compute the result, and push the result back on the stack.
	
	
HOW TO USE:
 1) User inputs the name of a text file that contains Postfix expressions
	- the text file must be in the same directory as the project
This is a simple Console Application

Main.cpp reads mathematical expressions in postfix form to evaluate them.
A postfix expression is an expression in which each operator follows its operands. 
For example,

infix expression            postfix expression          result

5 * 6                       5  6  *                       30
5 * ( 6 + 1 )               5  6  1  +  *                 35
5 * 6 - 15                  5  6  *  15  -                15
(5 * 6 ) - 15               5  6  *  15  -                15
40 + ( 5 * 6 ) / 3          40 5  6  *  3  /  +           50

The file test2.txt contains the above postfix expressions.
The output should look like test2.out

Using stacks, the program reads a character and determine
    -   if it is a new line, it is the end of the expression;
        print the value at the top of the stack

    -   if it is a space, ignore it and continue with the next
        iteration

    -   if it a digit, put it back on the input stream and read
        an int number

    -   anything else should be an operator; your program should
        them pop the top two elements on the stack, compute the
        result, and push the result back on the stack
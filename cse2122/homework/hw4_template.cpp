/*
File name: (your file name)
Created by: (your name)
Created on: (date)
Synopsis: (what your program does)
*/

#include <iostream>
#include <cstdlib>

using namespace std;

const char SENTINEL = ';';

struct Node {
    int data;
    Node *link;
};

// precondition: c is initialized
// postcondition: returns true if c is '+', '-', '*' or '/'
bool isOperator(char c);

// precondition: o1 and o2 are initialized and op is an operator
// postcondition: returns op(o1, o2), e.g. if op is '-' then returns o1-o2
int calculate(int o1, int o2, char op);

// precondition: c is a digit
// postcondition: returns the integer value of c
int charToInt(char c);

class Stack {

public:
    // default constructor
    // initializes the stack to an empty stack
    Stack();
	
    // default destructor
    // frees the memory used by dynamic node objects in the stack
    ~Stack();

    // this is a const function, meaning it cannot change any of the member variables
    // returns true if the stack is empty, false otherwise
    bool isEmpty() const;

    // this is a const function, meaning it cannot change any of the member variables
    // returns the value at the top of stack, does not modify the stack, does not check if the stack is empty or not
    int top() const;

    // adds data to the top of stack
    void push(int data);

    // removes the top value of stack, does not return it, does nothing if the stack is empty
    void pop();

private:
    Node *listHead; // pointer to the head of a linked list

};

int main() {
    char in;
    Stack operandStack;

    cout << "Enter a postfix expression (ending with " << SENTINEL << " and press Enter):" << endl;
    cin >> in ;
    while (in != SENTINEL) {
        if (isOperator( in )) {
            // pop two numbers from stack
            int n1, n2;
            if (operandStack.isEmpty()) {
                // print error message
                /*your code here*/
				
                exit(1); // end the program
            }
            n2 = operandStack.top();
            operandStack.pop();
            if (operandStack.isEmpty()) {
                // print error message
                /*your code here*/

                exit(1);
            }
            n1 = operandStack.top();
            operandStack.pop();

            // push the calculation result to the top of operandStack 
            /*your code here*/

        } else {
            // push the number to the top of opernadStack
			// (pay attention to the data type)
            /*your code here*/

        }
        cin >> in ;
    }

    // pop a number from the top of stack
    int result;
    result = operandStack.top();
    operandStack.pop();

    if (operandStack.isEmpty()) { // nothing left in the stack
        cout << "\nThe result is: " << result << endl;
    }
    else {// if there are still numbers in the stack, print an error message
        /*your code here*/
		
    }
	
    return 0;
}

Stack::Stack() {
    /*your code here*/
}

Stack::~Stack() {
    /*your code here*/
}

bool Stack::isEmpty() const {
    /*your code here*/
}

int Stack::top() const {
    /*your code here*/
}

void Stack::pop() {
    /*your code here*/
}

void Stack::push(int data) {
    /*your code here*/
}

int calculate(int o1, int o2, char op) {
    /*your code here*/
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int charToInt(char c) {
    return (static_cast<int>(c) - static_cast<int>('0'));
}

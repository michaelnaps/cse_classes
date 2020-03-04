// File name: postfix.cpp
// Created by: Michael Napoli
// Created on: 2/26/2020
// Last modified on:

/*
   Purpose:
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
   // initializes the stack to empty
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
      if (isOperator(in)) {
         // pop two numbers from stack
         int n1, n2;
         if (operandStack.isEmpty()) {
            // print error message
            cout << "ERROR: Stack is empty." << endl;

            exit(1); // end the program
         }
            n2 = operandStack.top();
            operandStack.pop();
            if (operandStack.isEmpty()) {
               // print error message
               cout << "ERROR: Stack is empty." << endl;

               exit(1);
            }
            n1 = operandStack.top();
            operandStack.pop();

            // push the calculation result to the top of operandStack
            /*your code here*/

         }
         else {
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
   else {
      cout << "ERROR: There are still values in the stack." << endl;
   }

   return 0;
}

// Constructor for Class type 'Stack'
// allocates memory for the head of a 'Stack' of integer values
Stack::Stack() {
   // allocate memory for the linked list first value
   listHead = new Node;

   // initialize 'data' and 'link' of the list head variable
   listHead->data = 0;
   listHead->link = NULL;  // first pointer set to NULL
}

// Destructor for Class type 'Stack'
// properly deallocate memory from the associated 'Stack' variable
// intput: pre-initialized Stack variable
Stack::~Stack() {
   Node *current;  // variable for current location of node
   Node *next;  // variable for the next variable in the linked list

   // initialize 'current' to the head of the linked list
   current = listHead;

   // until the end of the list is reached, delete nodes
   while (current != NULL) {
      // link of the next variable in the list
      next = current->link;

      // deallocate memory for the list variable
      delete current;

      // for next iteration of the loop
      current = next;
   }
}

// Member function: isEmpty()
// function which checks the given 'Stack' variable for values after
//    the head pointer
// input: pre-initialized 'Stack' variable
// output: boolean value
//    'true' - if given stack is empty
//    'false' - if given value is NOT empty
bool Stack::isEmpty() const {
   // return the output of the following boolean statement
   return (listHead->link == NULL);
}

// Member function: top()
// Function that returns the top value of a given 'Stack' variable
// input: pre-initialized 'Stack' variable
// output: value located at the head of the 'Stack' variable
int Stack::top() const {
   return (listHead->data);
}

// Member function: pop()
// Function deletes the head value from a given 'Stack' variable
// input: pre-initialized 'Stack' variable
// output: nothing
void Stack::pop() {
   // if list is empty, do nothing
   if (this->isEmpty()) {
      return;
   }

   Node *remove = listHead;  // temporary variable for removal of current head

   // set new head of stack to the next node
   listHead = listHead->link;

   // deallocate memory for the top of the stack
   delete remove;
}

// Member function: push()
// Function that adds a given variable to the head of a 'Stack' variable
// intput: pre-initialized 'Stack' variable
//    'data' - value to be intputted into the 'Stack'
// output: nothing
void Stack::push(int data) {
   Node *temp;  // temporary value for new node

   // allocate memory for new node
   temp = new Node;

   // set link of the new node to the location of the current head
   temp->data = data;
   temp->link = listHead;

   // set head to new node variable
   listHead = temp;
}

int calculate(int o1, int o2, char op) {
   if (op == '+') {
      return (o1 + o2);
   }
   else if (op == '-') {
      return (o1 - o2);
   }
   else if (op == '*') {
      return (o1 * o2);
   }
   else if (op == '/') {
      return (o1 / o2);
   }
   else {
      // if 'op' is not an operator symbol, return 0
      return 0;
   }
}

bool isOperator(char c) {
   return (c == '+' || c == '-' || c == '*' || c == '/');
}

int charToInt(char c) {
   return (static_cast<int>(c) - static_cast<int>('0'));
}

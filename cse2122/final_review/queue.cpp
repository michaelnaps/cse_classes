// File: queue.cpp
// Created by: Michael Napoli
// Created on: 4/28/2020

/*
   Purpose:
*/

#include <iostream>
using namespace std;

struct QueueNode {
   char data;
   QueueNode *link;
};

class Queue
{
public:
   Queue();  // default init. - empty queue
   Queue(const Queue& copyQ);  // copy constructor
   ~Queue();

   // function to add item to back of queue
   void add(const char& item);

   //Precondition: The queue is not empty.
   //Returns the item at the front of the queue and removes that
   //item from the queue.
   char remove();

   //Returns true if the queue is empty. Returns false otherwise.
   bool empty() const;

private:
   QueueNode *front; //Points to the head of a linked list.
   QueueNode *back; //Points to the node at the other end of the queue
};

int main()
{
   return 0;
}

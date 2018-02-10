//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Edgar Cruz
//Complier:  g++
//File type: queue implementation file
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

//PURPOSE: Constructor must initialize count to be 0, rear to be -1, and front to be 0 to begin with. 
queue::queue()
{
  count = 0;
  rear = -1;
  front = 0;
}

//PURPOSE: Destructor does not have to do anything since this is a static array.
queue::~queue()
{//nothing to do
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if (count == 0)//Queue is empty.
    return true;
  else //Queue is not empty.
    return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if (count == MAX_SIZE) //Queue is full.
    return true;
  else //Queue is not full.
    return false;

}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if(isFull())//Queue is full.
    throw Overflow();
  else //Queue is not full
  {
     rear = (rear+1)% MAX_SIZE;
     count ++;
     el[rear] = newElem;
  }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if (isEmpty())
    throw Underflow();
  else
  {
    removedElem = el[front];
      front = (front +1) % MAX_SIZE;
      count--;
  }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if (!isEmpty()) //queue is not empty 
    theElem = el[front];
  else //empty
    throw Underflow();
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;//Returns how many elements there are in the queue.
}

//PURPOSE: returns the front position to make it accessible to the 
//client caller
int queue::getFront()
{
  return front;//Returns the slot position where front is.
}

//PURPOSE: returns the rear position to make it 
//accessible to the client caller
int queue::getRear()
{
  return rear;//Returns the slot position where rear is.
}


// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
  if (isEmpty())
         cout << " [ empty ]" << endl;
  else
  {   
    int num = front;
    for (int i = 0; i < count; i++)
    {
      cout << el[num] << " " << endl;
      num = (num + 1) % MAX_SIZE;
    }
  }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{// ** comment a local variable
  if (isEmpty())
    throw Underflow();
  else if (count == 1)
    ;// Do nothing
  else 
  {
    el_t elem = el[front];//local variable (elem) to hold the front element.
    remove(elem);
    add(elem);
  }
 
 
 
}





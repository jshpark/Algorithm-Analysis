#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <array>

using namespace std;

template <class T>
class GenStack
{
public:
  GenStack() //default constructor
  {
    myArray = new T[10];
    size = 10;
    top = -1;
  }

  GenStack(int maxSize) //overloaded constructor
  {
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
  }

  ~GenStack()
  {
    //what do i need to do here?
    delete[] myArray;
  }

  void push(T d)
  {
    if (isFull()) //if the array is full, create a new array and resize it
    {
      T* tempArray = new T[size + 10];
      for (int i = 0; i < size; ++i) //copying array content
      {
        tempArray[i] = myArray[i];
      }
      size += 10;
      delete[] myArray; //deleting array
      myArray = tempArray; //settnig array to temp array
    }
    myArray[++top] = d;
  }

  T pop()
  {
    //error checks
    //check if IsEmpty
    if (isEmpty())
    {
      cout << "Stack is Empty." << endl;
    }
    return myArray[top--];
  }

  T peek()
  {
    if (top == -1)
    {
      cout << "Stack is Empty." << endl;
    }
    return myArray[top];
  }

  bool isFull()
  {
    return (top == size - 1);
  }
  bool isEmpty()
  {
    return (top == -1);

  }

  int getSize()
  {
    return size;
  }

  bool Contains(T data)
  {
    for (int i = 0; i < size; ++i)
    {
      if (myArray[i] == data)
      {
        return true;
      }
    }
    return false;
  }

private:
  int size;
  int top;

  T* myArray;
};

#endif

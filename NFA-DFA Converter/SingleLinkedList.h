#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "ListNodeSingle.h"
#include <iostream>

using namespace std;

template <class type>
class SingleLinkedList
{
public:
  SingleLinkedList() //constructor
  {
    size = 0;
    head = NULL;
  }
  SingleLinkedList(type d) //overlaoded constructor
  {
    size = 1;
    ListNodeSingle<type> *node = new ListNodeSingle<type>(d);
    node -> next = NULL;
    head = node;
  }
  ~SingleLinkedList() //desctructor
  {
    if (size != 0)
    {
      while (!(size == 0))
      {
        DeleteFront();
      }
    }
  }

  int getSize() //return size of list
  {
    return size;
  }

  void PrintList() //print the list
  {
    if (size == 0)
    {

    }
    else
    {
      int index = 0;
      ListNodeSingle<type> *current = head;
      ListNodeSingle<type> *previous = head;
      while (!(index == size))
      {
        previous = current;
        type temp = current -> data;
        current = current -> next;
        cout << temp << endl;
        index++;
      }
    }
  }

  bool contains(type d) //check if a value is in the list
  {
    int index = 0;
    ListNodeSingle<type> *current = head;
    ListNodeSingle<type> *previous = head;
    while (!(index == size))
    {
      if (d == current -> data)
      {
        break;
      }
      else
      {
        previous = current;
        current = current -> next;
        index++;
      }
    }
    if (index == size)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  void InsertFront(type d)// insert to the front
  {
    if (contains(d)) //checks if the desired value is already in the list
    {
    }
    else
    {
      size++;
      ListNodeSingle<type> *node = new ListNodeSingle<type>(d);
      node -> next = head;
      head = node;
    }
  }

  type DeleteFront() //delete the front
  {
    if (size == 0)
    {
    }
    else
    {
      ListNodeSingle<type> *old = head;
      size--;
      type temp = head -> data;
      head = head -> next;
      old -> next = NULL;
      delete old;
      return temp;
    }
  }

  void DeleteValue(type value) //this is to delete a value from the list
  {
    if (size == 0)
    {
      cout << "List is empty." << endl;
    }
    else
    {
      ListNodeSingle<type> *current = head;
      ListNodeSingle<type> *previous = head;
      int index = 0;
      if (current == head && (current -> data == value))
      {
        head = head -> next;
        size--;
        delete current;
      }
      else
      {
        while (!(index == size))
        {
          previous = current;
          current = current -> next;
          type temp = current -> data;
          if (temp == value)
          {
            break;
          }
          index++;
        }
        if (index == size) //checks if the desired value is in the list
        {
          cout << "List does not contain value." << endl;
        }
        else
        {
          if (size == 1)
          {
            delete current;
            size--;
          }
          else
          {
            if (current == head)
            {
              head = head -> next;
            }
            else
            {
              previous -> next = current -> next;
            }
            size--;
            delete current;
          }
        }
      }
    }
  }

  void InsertPosition(int position, type value) //insert a node at a position and delete that node
  {
    ListNodeSingle<type> *node = new ListNodeSingle<type>(value);
    ListNodeSingle<type> *current = head;
    ListNodeSingle<type> *previous = head;
    int index = 0;
    while (!(index == position))
    {
      previous = current;
      current = current -> next;
      index++;
    }
    previous -> next = node;
    node -> next = current -> next;
    current -> next = NULL;
    delete current;
  }
  type DeletePosition(int position) //delete a node at a given position
  {
    int index = 0;
    ListNodeSingle<type> *current = head;
    ListNodeSingle<type> *previous = head;
    while (!(index == position))
    {
      previous = current;
      current = current -> next;
      index++;
    }
    previous -> next = current -> next;
    current -> next = NULL;
    type dataa = current -> data;
    size--;
    delete current;
    return dataa;
  }

  type ReturnPosition(int position) //return the data at a given position
  {
    int index = 0;
    ListNodeSingle<type> *current = head;
    ListNodeSingle<type> *previous = head;
    while (!(index == position))
    {
      previous = current;
      current = current -> next;
      index++;
    }
    type dataa = current -> data;
    return dataa;
  }

private:
  int size; //size of the list
  ListNodeSingle<type> *head; //first node of the list
};
#endif

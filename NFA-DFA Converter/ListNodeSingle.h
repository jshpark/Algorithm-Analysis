#ifndef LISTNODESINGLE_H
#define LISTNODESINGLE_H

#include <iostream>
using namespace std;

template <class type>
class ListNodeSingle
{
public:
  ListNodeSingle() //constructor
  {
    data = 0;
    next = NULL;
  }
  ListNodeSingle(type d) //overloaded constructor
  {
    data = d;
    next = NULL;
  }
  ~ListNodeSingle() //destructor
  {
    next = NULL;
    delete next;
  }
  ListNodeSingle *next; //next node
  type data; //data in the node
};
#endif

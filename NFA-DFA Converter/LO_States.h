/*
.
.
LIST OF STATES (Q)
.
.
*/

#ifndef LO_STATES_
#define LO_STATES_

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class LO_States
{
private:
  string oldStates;
  string newStates;

public:
  LO_States(string old_Data); //make oldStates = old_Data ***cant to this until we read from file, so this constructor is useless
  string getNewState(); //accessor for newStates
  void Convert(); //convert list of states to new list of states
};
#endif

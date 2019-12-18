/*
.
.
Transition Function (delta)
.
.
*/

#ifndef TRANSITIONFUNC_H
#define TRANSITIONFUNC_H

#include <iostream>

using namespace std;

class TransitionFunc
{
private:
  string oldTransit;
  string newTransit;

public:
  TransitionFunc(string old_Data); //makes oldTransit = old_Data
  string getNewTransit(); //accessor for newTransit
  void Convert(ifstream& readFile, string fileName, string& start_State); //converts the NFA transition functions to DFA transition functions
};
#endif

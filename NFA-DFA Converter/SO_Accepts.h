/*
.
.
SET OF ACCEPT STATES (F)
.
.
*/

#ifndef SO_ACCEPTS_H
#define SO_ACCEPTS_H

#include <iostream>

using namespace std;

class SO_Accepts
{
private:
  string oldAccepts;
  string newAccepts;

public:
  SO_Accepts(string old_Data); //makes oldAccepts = old_Data
  string getNewAccept(); //accessor for newAccepts
  void Convert(ifstream& readFile, string fileName); //converts NFA accept states to DFA accept states
};
#endif

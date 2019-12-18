/*
.
.
LIST OF STATES (Q)
.
.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include "LO_States.h"

using namespace std;

LO_States::LO_States(string old_Data)
{
  oldStates = old_Data;
}

string LO_States::getNewState()
{
  return newStates;
}

void LO_States::Convert()
{
  //start of creating array of states from line 1
  int tabCount = 0;
  for (int i = 0; i < oldStates.length(); ++i)
  {
    if (oldStates[i] == '\t')
    {
      tabCount++;
    }
  }
  string stateArray[++tabCount];
  string line = oldStates;
  int index = 0;
  int lineCount = 0;
  for (int i = 0; i < line.length(); ++i)
  {
    if (line[i] != '\t')
    {
      stateArray[index] += line[i];
    }
    else
    {
      index++;
    }
  }
  //end of creating array of states from line 1

  //creating array of power set
  int powerSetLength = pow(2, tabCount); //grabbing the length of powerset
  string powerSetArray[powerSetLength]; //creating power set array
  for (int i = 0; i < powerSetLength; ++i)
  {
    for (int j = 0; j < tabCount; ++j)
    {
      if (i & (1 << j))
      {
        powerSetArray[i] += stateArray[j] + ',';
      }
    }
  }

  for (int i = 0; i < powerSetLength; ++i)
  {
    string temp = powerSetArray[i];
    temp = temp.substr(0, temp.size() - 1);
    powerSetArray[i] = temp;
  }
  //finished creating array of power set

  //creating one string of power set
  for (int i = 0; i < powerSetLength; ++i)
  {
    newStates += '{' + powerSetArray[i] + '}' + '\t';
  }
}

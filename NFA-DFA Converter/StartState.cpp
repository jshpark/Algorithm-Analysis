/*
.
.
Start State (q 0)
.
.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "StartState.h"
#include "GenStack.h"
#include "SingleLinkedList.h"

using namespace std;

StartState::StartState(string old_Data)
{
  oldStart = old_Data;
  newStart = oldStart;
}

string StartState::getNewStart()
{
  return newStart;
}

void StartState::Convert(ifstream& readFile, string fileName)
{
  GenStack<string> *stateStack = new GenStack<string>(50);
  SingleLinkedList<string> *stateList = new SingleLinkedList<string>();
  string finalAcceptStates = "";

  string line;
  string newLine;
  getline(readFile, line);
  for (int i = 0; i < line.length(); ++i)
  {
    if ((line[i] != '\n') && (line[i] != '\r'))
    {
      newLine += line[i];
    }
  }
  newLine.erase(remove(newLine.begin(), newLine.end(), '{'), newLine.end());
  newLine.erase(remove(newLine.begin(), newLine.end(), '}'), newLine.end());

  string previousAcceptState = newLine;
  stateList -> InsertFront(previousAcceptState); //obviously the previous state is part of the new accept state
  stateStack -> push(previousAcceptState);

  string throwAwayLine;
  getline(readFile, throwAwayLine);

  //reading from the 5th line to EOF
  bool epsBool = true;
  while (epsBool) //keeping going through loop until stack is empty
  {
    while(getline(readFile, line))
    {
      line.erase(remove(line.begin(), line.end(), '{'), line.end());
      line.erase(remove(line.begin(), line.end(), '}'), line.end());
      string tempPrevState = line.substr(0, line.find(',')); //grabbing the previous state
      string tempSymbol = line.substr(line.find(", ") + 2, line.find(" =") - 3); //grabbing the symbol
      string tempString = line.substr(line.find("= ") + 2); //grabbing the final state with the newline character
      string tempFinalState = ""; //grabbing the final state without the newline character
      for (int i = 0; i < tempString.length(); ++i) //this loop is to get rid of the new line character at the end
      {
        if ((tempString[i] != '\n') && (tempString[i] != '\r'))
        {
          tempFinalState += tempString[i];
        }
      }

      if (tempPrevState == previousAcceptState) //when going through the transition functions, and the state matches
      {
        if (tempSymbol == "EPS") //if the symbol is an epsilon transition
        {
          if (!(stateList -> contains(tempFinalState))) //if the list does not contain
          {
            stateList -> InsertFront(tempFinalState);
            stateStack -> push(tempFinalState);
          }
        }
      }
    }
    previousAcceptState = stateStack -> pop();
    if (stateStack -> isEmpty())
    {
      epsBool = false;
    }
    else
    {
      readFile.close();
      readFile.open(fileName);
      getline(readFile, throwAwayLine);
      getline(readFile, throwAwayLine);
      getline(readFile, throwAwayLine);
      getline(readFile, throwAwayLine);
    }
  }

  int firstCheck = 0;
  while (stateList -> getSize() != 0)
  {
    if (firstCheck == 0)
    {
      finalAcceptStates += stateList -> DeleteFront();
      firstCheck++;
    }
    else
    {
      finalAcceptStates += ", " + (stateList -> DeleteFront());
    }
  }

  newStart = "{" + finalAcceptStates + "}";



  delete stateList;
  delete stateStack;

  stateList = NULL;
  stateStack = NULL;
  cout << "test4" << endl;
}

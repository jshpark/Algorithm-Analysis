/*
.
.
Transition Function (delta)
.
.
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include "GenStack.h"
#include "SingleLinkedList.h"
#include "TransitionFunc.h"

using namespace std;

TransitionFunc::TransitionFunc(string old_Data)
{
  oldTransit = old_Data;
}

string TransitionFunc::getNewTransit()
{
  return newTransit;
}

void TransitionFunc::Convert(ifstream& readFile, string fileName, string& start_State)
{
  //i have the start_state so now i can start using the start state
  //format: 2, x = 5
  //create a linked list of previous states.
  ofstream writeFile;
  writeFile.open("tempFile.txt"); //creates a file so i can output the data to the temp file instead.
  SingleLinkedList<string> *stateList = new SingleLinkedList<string>(); //list for the previous states
  SingleLinkedList<string> *symbolList = new SingleLinkedList<string>(); //list for symbols
  GenStack<string> *stateStack = new GenStack<string>(50);
  SingleLinkedList<string> *newStateList = new SingleLinkedList<string>();
  SingleLinkedList<string> *stateRecord = new SingleLinkedList<string>();
  SingleLinkedList<string> *duplicateStateList = new SingleLinkedList<string>();
  SingleLinkedList<string> *finalDuplicateList = new SingleLinkedList<string>();
  GenStack<string> *palindromStack = new GenStack<string>(50);
  SingleLinkedList<string> *singleStateRecord = new SingleLinkedList<string>();

  string line;
  int stateCounter = 0;
  int symbolCounter = 0;
  readFile.close();
  readFile.open(fileName);
  getline(readFile, line);
  getline(readFile, line);
  getline(readFile, line);
  getline(readFile, line); //skipping until 5th line;
  while (getline(readFile, line)) //reading each line
  {
    line.erase(remove(line.begin(), line.end(), '{'), line.end());
    line.erase(remove(line.begin(), line.end(), '}'), line.end());
    string tempPrevState = line.substr(0, line.find(',')); //grabbing the previous state
    if (!stateList -> contains(tempPrevState)) //if the linked list does not have the previous state, put it in the list
    {
      stateList -> InsertFront(tempPrevState);
      stateCounter++; //counts how many states there are
    }
    string tempSymbol = line.substr(line.find(", ") + 2, line.find(" =") - 3); //grabbing the symbol
    if ((!symbolList -> contains(tempSymbol)) && (tempSymbol != "EPS"))
    {
      symbolList -> InsertFront(tempSymbol);
      symbolCounter++; //counts how many symbols there are
    }
  }

  string **NFATransition = new string *[stateCounter + 1];
  for (int i = 0; i < stateCounter + 1; ++i)
  {
    NFATransition[i] = new string[symbolCounter + 1];
  }

  //NFATransition[0][0] IS EMPTY
  //creation of row and column names
  int stateLength = stateCounter + 1;
  int symbolLength = symbolCounter + 1;

  for (int i = 1; i < stateLength; ++i)
  {
    NFATransition[i][0] = stateList -> DeleteFront();
  }
  for (int i = 1; i < symbolLength; ++i)
  {
    NFATransition[0][i] = symbolList -> DeleteFront();
  }
  //DONE


  readFile.close(); //restarting the file
  readFile.open(fileName); //this should be filename

  string throwAwayLine;
  getline(readFile, throwAwayLine);
  getline(readFile, throwAwayLine);
  getline(readFile, throwAwayLine);
  getline(readFile, throwAwayLine);

  while (getline(readFile, line)) //N^3 RUNTIME BECAUSE IT IS SIMILAR TO WARSHALL'S ALGORITHM
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


    for (int i = 1; i < stateLength; ++i) //mapping out all the transitions into a table for the NFA
    {
      if (NFATransition[i][0] == tempPrevState) //first checking if the state is the same
      {
          for (int j = 1; j < symbolLength; ++j) //if it its, then look for the symbol
          {
            if (NFATransition[0][j] == tempSymbol) //if the symbol matches
            {
              string epsTrans = "";
              string previousState = tempFinalState;
              newStateList -> InsertFront(previousState);
              stateStack -> push(previousState);

              ifstream readFileTemp;
              readFileTemp.open(fileName);
              getline(readFileTemp, throwAwayLine);
              getline(readFileTemp, throwAwayLine);
              getline(readFileTemp, throwAwayLine);
              getline(readFileTemp, throwAwayLine); //we can start reading from the fifth line

              string lineTwo;
              bool epsBool = true;
              while (epsBool)
              {
                while (getline(readFileTemp, lineTwo))
                {
                  lineTwo.erase(remove(lineTwo.begin(), lineTwo.end(), '{'), lineTwo.end());
                  lineTwo.erase(remove(lineTwo.begin(), lineTwo.end(), '}'), lineTwo.end());
                  string tempPrevStateTwo = lineTwo.substr(0, lineTwo.find(',')); //grabbing the previous state
                  string tempSymbolTwo = lineTwo.substr(lineTwo.find(", ") + 2, lineTwo.find(" =") - 3); //grabbing the symbol
                  string tempStringTwo = lineTwo.substr(lineTwo.find("= ") + 2); //grabbing the final state with the newline character
                  string tempFinalStateTwo = ""; //grabbingthe final state without the newline character
                  for (int i = 0; i < tempStringTwo.length(); ++i) //this loop is to get rid of the new line character at the end
                  {
                    if ((tempStringTwo[i] != '\n') && (tempStringTwo[i] != '\r'))
                    {
                      tempFinalStateTwo += tempStringTwo[i];
                    }
                  }


                  if (tempPrevStateTwo == previousState)
                  {
                    if (tempSymbolTwo == "EPS")
                    {
                      if (!(newStateList -> contains(tempFinalStateTwo)))
                      {
                        newStateList -> InsertFront(tempFinalStateTwo);
                        stateStack -> push(tempFinalStateTwo);
                      }
                    }
                  }
                }
                previousState = stateStack -> pop();
                if (stateStack -> isEmpty())
                {
                  epsBool = false;
                }
                else
                {
                  readFileTemp.close();
                  readFileTemp.open(fileName);
                  getline(readFileTemp, throwAwayLine);
                  getline(readFileTemp, throwAwayLine);
                  getline(readFileTemp, throwAwayLine);
                  getline(readFileTemp, throwAwayLine);
                }
              }

              while (newStateList -> getSize() != 0)
              {
                if (epsTrans == "")
                {
                  epsTrans += newStateList -> DeleteFront();
                }
                else
                {
                  epsTrans += ", " + (newStateList -> DeleteFront());
                }
              }
              if (NFATransition[i][j] != "") //if the space is not empty, then check if it already exists
              {
                if (NFATransition[i][j].find(tempFinalState) == string::npos) //if it doesn't exist then add
                {
                  NFATransition[i][j] += ", " + epsTrans;
                }
              }
              else //if the space is empty, then fill it
              {
                NFATransition[i][j] = epsTrans;
              }
            }
          }
        }
      }
    }

  //nested for loop to make put the empty slots to null (EM)
  for (int i = 1; i < stateLength; ++i)
  {
    for (int j = 1; j < symbolLength; ++j)
    {
      if (NFATransition[i][j] == "")
      {
        NFATransition[i][j] = "EM";
      }
    }
  }



//CREATE A STACK OF STRING SO WE CAN DO THE TRANSITION FUNCTIONS
//WE CAN TEST EACH STATE FOR EACH SYMBOL AND ONCE WE'RE DONE WITH STATE, POP IT
GenStack<string> *transFuncStack = new GenStack<string>(100);
//need to get the start state from other class.... but how? //

bool newTransBool = true;
string currentState = start_State;
currentState.erase(remove(currentState.begin(), currentState.end(), '{'), currentState.end());
currentState.erase(remove(currentState.begin(), currentState.end(), '}'), currentState.end());
transFuncStack -> push(currentState);
int EMCheck = 0;
while(newTransBool) //format if 1, a = 2
{
  currentState = transFuncStack -> pop();
  if (!(stateRecord -> contains(currentState)))
  {
    if (currentState.find(',') != string::npos)
    {
      stateRecord -> InsertFront(currentState);
    }
  }
  string stateAdd = "";
  if (currentState.find(',') != string::npos) //if the current state is a set of states with multiple states
  {
    //if found


    //putting all states in the set into an array
    int commaCount = 0;
    for (int i = 0; i < currentState.length(); ++i) //counts how many commas there are to see how many states there are
    {
      if (currentState[i] == ',')
      {
        commaCount++;
      }
    }
    int tempStateCount = commaCount + 1;
    string tempStringArray[tempStateCount]; //creates an array to sort the states
    int index = 0;
    string data;
    for (int i = 0; i < currentState.length(); ++i)
    {
      if (currentState[i] == ',')
      {
        tempStringArray[index++] = data;
        data = "";
      }
      else
      {
        if (currentState[i] != ' ')
        {
          data += currentState[i];
        }
      }
    }
    tempStringArray[index++] = data;
    index = 0;
    //finished

      for (int i = 1; i < symbolLength; ++i) //going through the symbol
      {
        stateAdd = "";
        for (int j = 0; j < tempStateCount; ++j) //going through the array (each state in the array)
        {
          for (int k = 1; k < stateLength; ++k) //going through the states
          {
            if (tempStringArray[j] == NFATransition[k][0]) //first state in the array equals the state in left column of the table
            {
              if (stateAdd.find(NFATransition[k][i]) == string::npos) //if it does not contain
              {
                if (j != (tempStateCount - 1)) //if its not the last element, add some commas
                {
                  if (!(duplicateStateList -> contains(NFATransition[k][i])))
                  {
                    duplicateStateList -> InsertFront(NFATransition[k][i]);
                  }
                }
                else
                {
                  if (!(duplicateStateList -> contains(NFATransition[k][i])))
                  {
                    duplicateStateList -> InsertFront(NFATransition[k][i]);
                  }
                }
                break;
              }
            }
          }
        }
        while (duplicateStateList -> getSize() != 0)
        {
          string tempState = duplicateStateList -> DeleteFront();
          string dataThree;
          for (int i = 0; i < tempState.length(); ++i)
          {
            if (tempState.find(',') != string::npos)
            {
              if (tempState[i] == ',')
              {
                if (!(finalDuplicateList -> contains(dataThree)))
                {
                  finalDuplicateList -> InsertFront(dataThree);
                }
                dataThree = "";
              }
              else
              {
                if (tempState[i] != ' ')
                {
                  dataThree += tempState[i];
                }
              }
            }
            else
            {
              if (!(finalDuplicateList -> contains(tempState)))
              {
                finalDuplicateList -> InsertFront(tempState);
                transFuncStack -> push(tempState); //i did this here
              }
            }
          }
        }
        if (finalDuplicateList -> getSize() == 0)
        {
          stateAdd = "EM";
        }

        while (finalDuplicateList -> getSize() != 0)
        {
          string palindCheckString = finalDuplicateList -> DeleteFront();
          if (stateAdd == "")
          {
            palindromStack -> push(palindCheckString);
            stateAdd += palindCheckString;
          }
          else
          {
            palindromStack -> push(palindCheckString);
            stateAdd += ", " + palindCheckString;
          }
        }

        string finalPalindromeCheck = "";
        while (!(palindromStack -> isEmpty()))
        {
          if (finalPalindromeCheck == "")
          {
            finalPalindromeCheck = palindromStack -> pop();
          }
          else
          {
            finalPalindromeCheck += ", " + (palindromStack -> pop());
          }
        }


        if (finalPalindromeCheck.find(',') != string::npos)
        {
          stateRecord -> InsertFront(finalPalindromeCheck);
        }

        writeFile << "{" + currentState + "}, " + NFATransition[0][i] + " = " + "{" + stateAdd + "}" << endl;
        if (!(stateRecord -> contains(stateAdd)))
        {
          transFuncStack -> push(stateAdd);
        }
      }

    }
    else //if it's a singular state
    {
      for (int i = 1; i < stateLength; ++i) //looks for the state
      {
        if ((currentState == "EM") && (EMCheck == 0))
        {
          for (int j = 1; j < symbolLength; ++j)
          {
            writeFile << currentState + ", " + NFATransition[0][j] + " = " + "EM" << endl;
          }
          transFuncStack -> pop();
          EMCheck++;
        }
        if (currentState == NFATransition[i][0]) //if the state is found
        {
          for (int j = 1; j < symbolLength; ++j) //goes through all the symbols
          {
            if (!(singleStateRecord -> contains(NFATransition[i][j])))
            {
              writeFile << "{" + currentState + "}, " + NFATransition[0][j] + " = " + "{" + NFATransition[i][j] + "}" << endl;
              singleStateRecord -> InsertFront(NFATransition[i][j]);
            }
          }
        }
      }
    }
    if (transFuncStack -> isEmpty())
    {
      newTransBool = false;
    }
  }



  delete transFuncStack;
  delete stateList;
  delete symbolList;
  delete stateStack;
  delete newStateList;
  delete stateRecord;
  delete duplicateStateList;
  delete palindromStack;
  delete singleStateRecord;
  for (int i = 0; i < stateLength; ++i)
  {
    delete[] NFATransition[i];
  }
  delete[] NFATransition;

  transFuncStack = NULL;
  stateList = NULL;
  symbolList = NULL;
  stateStack = NULL;
  newStateList = NULL;
  stateRecord = NULL;
  duplicateStateList = NULL;
  palindromStack = NULL;
  singleStateRecord = NULL;
  for (int i = 0; i < stateLength; ++ i)
  {
    NFATransition[i] = NULL;
  }
  NFATransition = NULL;



  writeFile.close();
  readFile.close();
}

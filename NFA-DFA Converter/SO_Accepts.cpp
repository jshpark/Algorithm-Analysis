/*
.
.
SET OF ACCEPT STATES (F)
.
.
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include "SO_Accepts.h"
#include "GenStack.h"
#include "SingleLinkedList.h"

using namespace std;

SO_Accepts::SO_Accepts(string old_Data)
{
  oldAccepts = old_Data;
}

string SO_Accepts::getNewAccept()
{
  return newAccepts;
}

void SO_Accepts::Convert(ifstream& readFile, string fileName)
{
  //need to find set of accept states ... how should we approach this?
  //maybe we can find the transition functions first AND THEN find out which following states include the accept state from the NFA

  readFile.close();
  readFile.open(fileName);

  string throwAwayLine;
  getline(readFile, throwAwayLine);
  getline(readFile, throwAwayLine);
  getline(readFile, throwAwayLine); //reads the third line sow e can start on the fourth line 

  string line;
  getline(readFile, line);

  line.erase(remove(line.begin(), line.end(), '{'), line.end());
  line.erase(remove(line.begin(), line.end(), '}'), line.end());

  string finalLine = "";
  for (int i = 0; i < line.length(); ++i) //this loop is to get rid of the new line character at the end
  {
    if ((line[i] != '\n') && (line[i] != '\r'))
    {
      finalLine += line[i];
    }
  }


  int commaCount = 0;
  for (int i = 0; i < finalLine.length(); ++i) //counts how many commas there are to see how many states there are
  {
    if (line[i] == ',')
    {
      commaCount++;
    }
  }
  int tempStateCount = commaCount + 1;
  string prevAcceptStates[tempStateCount];
  string data;
  int index = 0;
  for (int i = 0; i < finalLine.length(); ++i)
  {
    if (finalLine[i] == ',')
    {
      prevAcceptStates[index++] = data;
      data = "";
    }
    else
    {
      if (finalLine[i] != ' ')
      {
        data += line[i];
      }
    }
  }
  prevAcceptStates[index++] = data;

  ifstream tempReadFile;
  tempReadFile.open("tempFile.txt"); //name of the temp file

  string finalStates = "";

  string readLine;
  while(getline(tempReadFile, readLine))
  {
    readLine.erase(remove(readLine.begin(), readLine.end(), '{'), readLine.end());
    readLine.erase(remove(readLine.begin(), readLine.end(), '}'), readLine.end());
    string tempString = readLine.substr(readLine.find("= ") + 2); //grabbing the final state with the newline character
    string tempFinalState = ""; //grabbing the final state without the newline character
    for (int i = 0; i < tempString.length(); ++i) //this loop is to get rid of the new line character at the end
    {
      if ((tempString[i] != '\n') && (tempString[i] != '\r'))
      {
        tempFinalState += tempString[i];
      }
    }
    for (int i = 0; i < tempStateCount; ++i) //going through the array to match each final state
    {
      tempFinalState = "{" + tempFinalState + "}";
      string tempFin = prevAcceptStates[i];
      if (tempFinalState.find(tempFin) != string::npos) //if they do match
      {
        if (finalStates.find(tempFinalState) == string::npos)
        {
          finalStates += tempFinalState + '\t';
        }
      }
    }
  }
  newAccepts = finalStates;
}

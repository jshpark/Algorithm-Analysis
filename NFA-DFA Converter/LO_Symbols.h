/*
.
.
LIST OF SYMBOLS / AlPHABET (E)
.
.
*/

#ifndef LO_SYMBOLS_H
#define LO_SYMBOLS_H

#include <iostream>

using namespace std;

class LO_Symbols
{
private:
  string oldSymbols;
  string newSymbols;

public:
  LO_Symbols(string old_Data); //makes oldSymbols = old_Data
  string getSymbols(); //accessor for newSymbols
  void Convert(); //converts old symbols to new symbols (which is pretty much just spitting out the same thing)
};
#endif

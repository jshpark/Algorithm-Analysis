/*
.
.
LIST OF SYMBOLS / AlPHABET (E)
.
.
*/


#include "LO_Symbols.h"
#include <iostream>
#include <algorithm>

using namespace std;

LO_Symbols::LO_Symbols(string old_Data)
{
  oldSymbols = old_Data;
}

string LO_Symbols::getSymbols()
{
  return newSymbols;
}

void LO_Symbols::Convert()
{
  newSymbols = oldSymbols;
}

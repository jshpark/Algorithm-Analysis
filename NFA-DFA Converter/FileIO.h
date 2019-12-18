#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileIO
{
public:
  int CheckArg(int num); //function to check if the command argument is correct
  int ReadFileOpen(ifstream& new_file, string file_name);     //function to open read file
  void WriteFileOpen(ofstream& new_file, string file_name);    //function to open write file
private:
  bool writebool;
};

#endif

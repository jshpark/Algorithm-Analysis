#include "FileIO.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int FileIO::CheckArg(int num)
{
  if (num > 2) //checks if there are more than just a file name.
  {
    cout << "Too many arguments." << " Enter only a file name." << endl;
    return -1;
  }
  if (num == 1) //checks if the program ran with no arguments other than itself.
  {
    cout << "Please enter a file name." << endl;
    return -1;
  }
}

int FileIO::ReadFileOpen(ifstream& new_file, string file_name) //opening a read file
{
  new_file.open(file_name);
  if (!new_file.is_open())    //check if file is open
  {
    cout << "Please enter a valid file name." << endl;
    return -1;
  }
  else if (new_file.peek() == ifstream::traits_type::eof())   //checks if file is empty
  {
    cout << "Cannot enter an empty file. Please use file with data." << endl;
    return -1;
  }
  new_file.close();
  return 0;
}

void FileIO::WriteFileOpen(ofstream& new_file, string file_name) //opening a write file
{
  writebool = true;
  while (writebool)
  {
    new_file.open(file_name);
    if (!new_file.is_open()) // checks if the file is open
    {
      cout << "Please enter a valid file name." << endl;
      cin >> file_name;
    }
    else
    {
      writebool = false;
    }
  }
}

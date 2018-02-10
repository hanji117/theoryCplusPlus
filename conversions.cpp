// Run the program by typing ./a.out < inputfilename
// All inputs will come from the input file

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// integer is convered into a string via sstream
string to_string ( int Number)
{
  ostringstream ss;
  ss << Number;
  return ss.str();
}

// string to int via sstream
int to_int (string S)
{ int N;
  istringstream (S) >> N;
  return N; 
}

// keep on adding input to a string via sstream
string formstring ()
{ string S;
  ostringstream M;  
  while (cin >> S)
      M << S;
  return M.str();
}

int main()
{
  cout << formstring() << endl;  // string
  int X = to_int("1000"); cout << X << endl;  // int
  string S = to_string(X); cout << S;  // string
} 

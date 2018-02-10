//====================================================                        
//HW#: HW1B_recog-gen-PROG_w3F  
//Your name: Edgar Cruz                                                        
//Complier:  g++                                                               
//File type: implementation file                                         
//=====================================================                        

#include<iostream>
#include<string>
using namespace std;

// CS421 HW1 Write a recognizer in C++ for L = {x | x is a binary number}.
// Your name: Edgar Cruz

/*
PURPOSE: The recognizer function should return TRUE or FALSE 
         checking each character to make sure it is 0 or 1.
         (leading 0's are allowed).
PARAMETER: Provide a holder (s) for the string (pass by value)
ALGORITHM: Make two character local variables. One for 0 and one for 1.
           Make a for loop. Initialize i to 0 and set i is less than the 
           length of the string. Increment i. Compare the first character
	   of the string with zero and one. The moment the string contains
	   something other than 1 or 0 it will return false. Else return
	   true.
*/
bool recognizer(string s)
{
 char zero = '0';
 char one = '1';

 for(int i = 0; i < s.length(); i++ )
 {
    if (s[i] != zero && s[i] != one)
      return false;    
 }
  return true;
  
}

//PURPOSE: main: Given a string (from E) cined from the user, pass it to
//         the recognizer function.
//         Cout YES IN L or NO NOT IN L depending on what was returned.
//ALGORITHM: Create a string variable called num. Prompt the user. 
//          The variable num gets passed to the recognizer function. 
//          The recognizer function returns a boolean number.
//          It gets stored in result and if it is 1 cout YES IN
//          L else cout NO NOT IN L.
int main()
{
  string num;
  
  cout << "\nEnter a binary number: ";
  cin >> num;

  bool result = recognizer(num);
 
  if (result == true)
    cout << "YES IN L" << endl;
  else 
    cout << "NO NOT IN L" << endl;
  return 0;
}

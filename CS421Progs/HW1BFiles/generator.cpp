//====================================================                                
//HW#: HW1B_recog-gen-PROG_w3F                                                        
//Your name: Edgar Cruz                                                               
//Complier:  g++                                                                      
//File type: implementation file                                                      
//=====================================================  
#include <cstdlib>// added for exit()
#include<iostream>
#include<string>
#include"queue.h"// include queue.h or equivalent 
using namespace std;

// CS421 HW1 Write a generator in C++ for L = {x | x is a binary number}.
// Your name: Edgar Cruz

// Copy the recognizer function here from the other file.

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

// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   keeps on going until the queue overflows 
int main()
{
  queue q; //queue object
  el_t elem = "0";
  
  q.add(elem);
  elem = "1";
  q.add(elem);
  elem = "2";
  q.add(elem);

  while(!q.isEmpty())// loop -- indefinitely                              
  {
      try
	{
	  q.remove(elem);//remove parameter pass by ref                     
         
	  if (recognizer(elem))
	  cout << elem << endl;

	  el_t newElem = elem + "0"; // newElem gets the result of elem + 0.      
	  q.add (newElem);      //add function is not pass by ref           
	  el_t newElem2 = elem + "1";//newElem2 gets the result of elem + 1.      
	  q.add(newElem2);
	  el_t newElem3 = elem + "2";//newElem3 gets the result of elem + 2.      
	  q.add(newElem3);

	}//this closes try      

      catch (queue::Overflow)
	{
	  cerr << "Overflow! Cannot add anymore" << endl;
          exit(1);
	}
  }//end of while                                                               
  return 0;
}
  







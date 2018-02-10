#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// CS421 File fa.cpp for HW3
// Your name: Edgar Cruz

// ** Change this to fit the HW3C specification - look for **
// ** Must have the same types of tracing couts as mytoken.

// MYTOKEN DFA done by Rika Sensei has a sample
 // This FA is for a b^+
bool mytoken(string s)
{ 
  int state = 0;
  int charpos = 0;

  cout << "Trying the mytoken machine..." << endl;  
 
  while (s[charpos] != '\0') 
    {
      cout << "current state: " << state << endl;
      cout << "character: " << s[charpos] << endl;
 
      if (state == 0 && s[charpos] == 'a')
      state = 1;
      else
      if (state == 1 && s[charpos] == 'b')
      state = 2;
      else
      if (state == 2 && s[charpos] == 'b')
      state = 2;
      else
	{
	  cout << "I am stuck in state " << state << endl;
	  return(false);
	}
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
}


// IDENT DFA 
// This FA is for l(l|d|_)^*
/*
PURPOSE: Checks to see if a string is an identifier and that it follows
          l(l|d|_)^*
PARAMETER: an s variable of type string
ALGORITHM: Gets a string and checks it character by character. If it ends 
           up on state 1 (the final state) return true else false is 
           returned.
*/
bool ident_token(string s)
{
  // ** complete this based on mytoken
  int state = 0;
  int charpos = 0;

  cout << "Trying the identifier machine..." << endl;

  while (s[charpos] != '\0')
  {
      cout << "current state: " << state << endl;
      cout << "character: " << s[charpos] << endl;

      if (state == 0 && (s[charpos] == 'a'|| s[charpos] == 'b'))
	state = 1;
      else
      if (state == 1 && (s[charpos] == 'a' || s[charpos] == 'b' || s[charpos] == '2'|| s[charpos] == '3'|| s[charpos] == '_'))
	  state = 1;
      else
      {
        cout << "I am stuck in state " << state << endl;
        return(false);
      }
      charpos++;
  }//end of while                                                             

  // where did I end up????                                                     
  if (state == 1) return(true);  // end in a final state                        
  else return(false);

}


// REAL DFA 
// This FA is for d^* . d^+
/* 
PURPOSE: Checks to see if a string is a real number and that it follows
         d^* . d^+      
PARAMETER: a variable s of type string                                  
ALGORITHM: checks a string character by character. If it ends up on state 2
           it returns true else false is returned.
*/
bool real_token(string s)
{
  // ** complete this based on mytoken
  int state = 0;
  int charpos = 0;

  cout << "Trying the real machine..." << endl;

  while (s[charpos] != '\0')
  {
      cout << "current state: " << state << endl;
      cout << "character: " << s[charpos] << endl;

      if (state == 0 && (s[charpos] == '2'|| s[charpos] == '3'))
	state = 0;
      else
      if (state == 0 && (s[charpos] == '.'))
	  state = 1;
      else
      if (state == 1 && (s[charpos] == '2' || s[charpos] == '3'))
	  state = 2;
      else 
      if (state == 2 && (s[charpos] == '2' || s[charpos] == '3'))
	  state = 2;
      else
      {
         cout << "I am stuck in state " << state << endl;
         return(false);
      }
      charpos++;
  }//end of while                                                             

  // where did I end up????                                                     
  if (state == 2) return(true);  // end in a final state                        
  else return(false);
}


//INT DFA 
// This FA is for d^+
/*
PURPOSE: Checks to see if a string is an integer and if it follows d^+
PARAMETER: A variable s of type string.
ALGORITHM: Checks the string character by character and returns true if it 
           ends up on state 1 else false is returned.
*/
bool integer_token(string s)
{
  // ** complete this based on mytoken
  int state = 0;
  int charpos = 0;

  cout << "Trying the integer machine..." << endl;

  while (s[charpos] != '\0')
  {
      cout << "current state: " << state << endl;
      cout << "character: " << s[charpos] << endl;

      if (state == 0 && (s[charpos] == '2'|| s[charpos] == '3'))
	state = 1;
      else
      if (state == 1 && (s[charpos] == '2' || s[charpos] == '3'))
	  state = 1;
      else
      {
        cout << "I am stuck in state " << state << endl;
        return(false);
      }
      charpos++;
  }//end of while                                                             

  // where did I end up????                                                     
  if (state == 1) return(true);  // end in a final state                        
  else return(false);
}

enum tokentype {ERROR, MYTOKEN, IDENT, REAL, INT};
int scanner(tokentype& , string& );  // to be called by main
ifstream fin ("fain.txt", ios::in);  // input file stream


// The test-driver: to be completed **
/*
PURPOSE: Checks to see what type a string is and displays it. 
ALGORITHM: An array is created called tokens with 5 different possibilities.
           A tokentype variable thetype and a string variable theword are 
           created. Inside of a While loop a scanner function is called 
           and 2 arguments are passed to it. Displays the strings type.
*/
int main()
{


  string tokens[5] = {"ERROR", "MYTOKEN", "IDENT", "REAL", "INT"};
  tokentype thetype;
  string theword; 

  while (true)  // keep on going 
  {
       scanner(thetype, theword);  // the paramers will be set by Scanner
       if (theword == "EOF") break;

       cout << "Type is:" << tokens[thetype]  << endl;
  }

  fin.close();
}

/*
PURPOSE: To determine a strings type.
PARAMETER: Provide a tokentype and a string variable that will be passed by
           reference.
ALGORITHM: A tokentype variable and a string variable are passed by reference
           to the scanner. A string is grabbed from fain.txt. The word is then 
           displayed. Checks the word by calling ident_token function and 
           passes the word as a parameter. If false was returned, real_token 
           function is called and if false is returned integer_token function
           is called. If false is returned again then lexical error is 
           displayed. If one of the functions returns true the_type is 
           assigned the appropriate type and passed back to main along 
           with the word.
*/
int scanner(tokentype& the_type, string& w)
{
  
  // This goes through all machines one by one on the input string

  cout << ".....Scanner was called..." << endl;

  fin >> w;  // grab next word from fain.txt
  cout << "Word is:" << w << endl;   
  
  //   if (mytoken(w))
  //  { the_type = MYTOKEN; }
  
  // ** add other if-then's here in the right order to go through
  // all FAs one by one and set the_type to be IDENT, REAL or INT.
  
  //  else
  if (ident_token(w))
      {the_type = IDENT;}
 
  else
  if (real_token(w))
      {the_type = REAL;}
  else
  if (integer_token(w))
      {the_type = INT;}
  
  //===============================================================
  else //none of the FAs returned TRUE
   { cout << "Lexical Error: The string is not in my language" << endl;
      the_type = ERROR; }

}//the very end of scanner





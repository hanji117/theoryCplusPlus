#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: 13 
//=====================================================

// ** MYTOKEN DFA to be replaced by the WORD DFA
// ** Done by: Jesus Rivera
// ** RE: (vowel | vowel n| consonant vowel| consonant vowel n| consonant-pair vowel | consonant-pair vowel n)^+
/*
PURPOSE: Checks to see if a string is a Japanese word. 
PARAMETER: An s variable of type string.
ALGORITHM: Gets a string and checks it character by character. If it ends 
           up on state 6 or 7 return true else false is returned.
*/
bool myword(string s)
{
  int state = 0;
  int charpos = 0;
  //  cout << "Inside of the myword function" << endl;
  while (s[charpos] != '\0') 
  {
      if (state == 0 && (s[charpos] == 'a'||s[charpos] == 'e' || s[charpos] == 'E'|| s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'o' || s[charpos] == 'u'))
      state = 6;
      else
      if (state == 0 && (s[charpos] == 'b'||s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'|| s[charpos] == 'n' || s[charpos] == 'p'|| s[charpos] == 'r'))
      state = 5;
      else
      if (state == 0 && (s[charpos] == 'c'))
      state = 4;
      else
      if (state == 0 && (s[charpos] == 'd'||s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z'))
      state = 3;
      else 
      if (state == 0 && (s[charpos] == 's'))
	  state = 2;
      else
      if (state == 0 && (s[charpos] == 't'))
	state = 1;
      else
      if (state == 6 && (s[charpos] == 'a'||s[charpos] == 'e'||s[charpos] == 'E' || s[charpos] == 'i' || s[charpos] == 'I'|| s[charpos] == 'o' || s[charpos] == 'u'))
	state = 6;
      else
      if (state == 6  && (s[charpos] == 'n'))
	state = 7;
      else 
      if (state == 6  && (s[charpos] == 't'))
	state = 1;
      else
      if (state == 6 && (s[charpos] == 's'))
	state = 2;
      else
      if (state == 6 && (s[charpos] == 'b'||s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'|| s[charpos] == 'p' || s[charpos] == 'r'))
        state = 5;
      else 
      if (state == 6 && (s[charpos] == 'd'||s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z'))
	state = 3;
      else
      if (state == 6 && (s[charpos] == 'c'))
	state = 4;
      else
      if (state == 7 && (s[charpos] == 'a'||s[charpos] == 'e'||s[charpos] == 'E'||s[charpos] == 'i' || s[charpos] == 'I'|| s[charpos] == 'o' || s[charpos] == 'u'))
	state = 6;
      else 
      if (state == 7 && (s[charpos] == 't'))
	state = 1;
      else 
      if (state == 7 && (s[charpos] == 's'))
        state =2;
      else 
      if (state == 7 && (s[charpos] == 'd'||s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z'))
        state = 3;
      else 
      if (state == 7 && (s[charpos] == 'b'||s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'||s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
        state = 5;
      else 
      if (state == 7 && (s[charpos] == 'c'))
	state = 4;
      else 
      if (state == 1 && (s[charpos] == 'a'||s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u'))
        state = 6;
      else
      if (state == 2 && (s[charpos] == 'a'||s[charpos] == 'e' || s[charpos] == 'E'||s[charpos] == 'i' || s[charpos] == 'I'|| s[charpos] == 'o' || s[charpos] == 'u'))
        state = 6;
      else
      if (state == 3 && (s[charpos] == 'a'||s[charpos] == 'e' ||s[charpos] == 'E'|| s[charpos] == 'i'||s[charpos] == 'I' || s[charpos] == 'o' || s[charpos] == 'u'))
        state = 6;
      else 
      if (state == 1 && (s[charpos] == 's'))
	state = 3;
      else
      if (state == 2 && (s[charpos] == 'h'))
	state = 3;
      else 
      if (state == 4 && (s[charpos] == 'h'))
	state = 3;
      else 
      if (state == 5 && (s[charpos] == 'y'))
	state = 3;
      else 
      if (state == 5 && (s[charpos] == 'a' ||s[charpos] == 'e' ||s[charpos] == 'E'|| s[charpos] == 'i'||s[charpos] == 'I' || s[charpos] == 'o' || s[charpos] == 'u'))
	state = 6;
      else 
      {
	//	  cout << "I am stuck in state " << state << endl;
	  return false;
      }
      charpos++;
    }//end of while

  // where did I end up????
  //cout << "The final state is " << state << endl;
  if (state == 6 || state ==  7) 
    return true;  // end in a final state
  else 
    return false;
}

// ** Add the PERIOD DFA here
// ** Done by: Jesus Rivera
// ** RE: .^+
/*
PURPOSE: Checks to see if a string is a period.
PARAMETER: An s variable of type string.
ALGORITHM: Gets a string and checks it character by character. If it ends 
           up on state 1 (the final state) return true else false is 
           returned.
*/
bool period(string s)
{
  int state = 0;
  int charpos = 0;
  //cout << "Inside of the period function" << endl;
  //cout << "What is inside s[charpos] " << s[charpos] << endl;
  while (s[charpos] != '\0')
  {
    if (state == 0 && s[charpos] == '.')
      state = 1;
    else
    if (state == 1 && s[charpos] == '.')
      state = 1;
    else 
    {
	//	  cout << "I am stuck in state " << state << endl;
      return false;
    }
    charpos++; 
  }//end of while
  //cout << "State in period function is " << state << endl; 
  if (state == 1) 
      return true;
  else return false;

}

// ** Update the tokentype to be WORD1, WORD2, PERIOD and ERROR.
 enum tokentype {VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, WORD1, WORD2, PERIOD, ERROR};
enum englishtype {I, Me, You, He, Him, She, Her, It, Also, Then, However,\
 Therefore
};
// ** Need the lexicon to be set up here (to be used in Part C)
// ** Done by: Takuro

/*
PURPOSE: Checks to see if a string is a lexicon word.
PARAMETER: A variable of type englishtype and a variable of type 
           string.
ALGORITHM: Gets a string and compares it with the lexicon words. If the 
           string matches one, a type is assigned to it and it returns
           true. If the string doesn't match any of the lexicon words
           false is returned.
*/
bool lexiconWord(englishtype& english, string word)
{
  if(word == "watashi")
    {
      english = I;
      return true;
    }
  else
  if(word == "anata")
  {
      english = You;
      return true;
  }
  else
  if(word == "kare")
  {
      english = He;
      return true;
  }
  else
  if(word == "kanojo")
    {
      english = She;
      return true;
    }
  else
  if(word == "sore")
  {
      english = It;
      return true;
  }
  else
  if(word == "mata")
  {
      english = Also;
      return true;
  }
  else
  if(word == "soshite")
  {
      english = Then;
      return true;
  }
  else
  if(word == "shikashi")
  {
      english = However;
      return true;
  }
  else
  if(word == "dakara")
  {
      english = Therefore;
      return true;
  }
  else
      return false;
}
    
// ** Need the reservedwords list to be set up here
// ** Done by: Edgar Cruz
/*
PURPOSE: Checks to see if a string is a reserved word.
PARAMETER: A type variable of type tokentype and a word variable of type 
           string.
ALGORITHM: Gets a string and compares it with the reserved words. If the 
           string matches one, a type is assigned to it and it returns
           true. If the string doesn't match any of the reserved words
           false is returned.
*/
bool reservedWord(tokentype& type, string word)
{
  //cout << "Inside reservedWord function" << endl;
  if (word == "masu")
  {
    type = VERB;
    return true;
  }
  else 
  if (word == "masen")
  { 
    type = VERBNEG;
    return true;  
  }
  else
  if (word == "mashita")
  {  
    type = VERBPAST;
    return true;
  }
  else
  if(word == "masendeshita")
  {
    type = VERBPASTNEG;
    return true;
  }
  else
  if (word == "desu")
  {
    type = IS;
    return true;
  }
  else
  if (word == "deshita")
  {    
    type = WAS;
    return true;
  }
  else
  if (word == "o")
  {  
    type = OBJECT;
    return true;
  }
  else 
  if (word == "wa")
  {    
    type = SUBJECT;
    return true;
  }
  else 
  if (word == "ni")
  {
    type = DESTINATION;
    return true;
  }
  else 
  if (word == "watashi"|| word == "anata"|| word == "kare"|| word == "kanojo" || word == "sore") 
  {  
  type = PRONOUN;
  return true;
  }
  else
  if (word == "mata" || word == "soshite" || word == "shikashi" || word == "dakara")
    { 
    type = CONNECTOR;
    return true;
    }
  else 
  {
    //cout << "not a reserved word" << endl;
  return(false);
  }
}

// ** Do not require any file input for these.
// ** a.out should work without any additional files.

// Scanner processes only one word each time it is called
// ** Done by: Edgar Cruz
/*
PURPOSE: To determine a strings type.
PARAMETER: Provide a tokentype, a string, and an ifstream variable that
           will be passed by reference.
ALGORITHM: A string is grabbed from the file fin. The scanner function then 
           checks to see if the string is a Japanese word by passing 
           it to the myword function.
           If it is a word, it is then checked to see if it is a 
           reserved word by calling the reservedWord function. If it is not 
           a reserved word it goes through a while loop to determine 
           if it is WORD1 or WORD2. If the string is not a word it is
           tested by calling the period function. If it's not a 
           period then ERROR is returned as the tokentype.
*/
void scanner(tokentype& a, string& w, ifstream& fin)
{
  //  cout << ".....Scanner was called..." << endl;
  // ** Grab the next word from the file
          
       fin >> w;
       // cout << "Word is: " << w << endl;
       
  if (myword(w))
  {
    //cout << w << " is a word" << endl;

          if (reservedWord(a, w))
	    ;
          else
          {
             int pos = 0;
	     while (w[pos] != '\0')
	     {
	       if (w[pos] == 'I'||w[pos] == 'E')
               a = WORD2;
               else  
               a = WORD1;    
               pos++;
             }
         }
   }
   else
   if (period(w))
      a = PERIOD;          
    
   else 
   if (w == "eofm")
       a = ERROR;
   else //none of the FAs returned TRUE                            
   { 
         cout << "Lexical Error: " << w << " is not a valid token" << endl;
         a = ERROR;
   }

  /* 
  2. Call the token functions one after another (if-then-else)
     And generate a lexical error if both DFAs failed.
     Let the token_type be ERROR in that case.
  3. Make sure WORDs are checked against the reservedwords list
     If not reserved, token_type is WORD1 or WORD2.
  4. Return the token type & string  (pass by reference)
  */
}//the end

// The test driver to call the scanner repeatedly  
// ** Done by: Edgar Cruz  **
/*
PURPOSE: Checks to see what tokentype a string is and displays it.
ALGORITHM: An array is created called tokens with 15 different 
           tokentypes. Inside of a while loop the scanner fuction is 
           called and and 3 arguments are passed to it (a tokentype variable, 
           a string variable, and an ifstream variable). Then the word 
           and its tokentype are displayed.
*/

int main()
{
  string tokens[15] = {"VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR","WORD1","WORD2","PERIOD","ERROR"};
  tokentype thetype;
  string theword; 

  /*
1. get the input file name from the user
2. open the input file which contains a story written in Japanese (fin.open).
3. call Scanner repeatedly until the EOF marker is read, and
     each time cout the returned results
     e.g. STRING TOKEN-TYPE
          =====  ===========
          watashi PRONOUN  (from the first call)
          wa      SUBJECT  (from the second call)
          gakkou  WORD1
          etc.
  */
  ifstream fin;
  string userInput;
 
  cout << "Enter scannertest1 or scannertest2: ";
  getline(cin, userInput);

  fin.open(userInput.c_str());

  while (true)
  {
    scanner(thetype, theword, fin);  // call the scanner
    if(theword == "eofm") break;

    cout << "Word is: " << theword << " "    
         << "Token type is: " << tokens[thetype]<< endl << endl;


       // ** display the actual type instead of a number
  }
  // ** close the input file

   fin.close();

}// end




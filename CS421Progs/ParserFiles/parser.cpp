#include<iostream>
#include<fstream>
#include<string>
#include "stdio.h"
#include "scanner.h"
#include "stdlib.h"
using namespace std;
 
 
tokentype saved_token;//  global buffer for the scanner token
bool token_available; //  global flag indicating whether we have 
                      //  saved a token to eat up or not
ifstream fin;
string saved_lexeme;// global variable for the returned word from the scanner. 
string savedEnglishWord;
string tokens[15] = {"VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "WORD1", "WORD2", "PERIOD", "ERROR"};
 
void s();
void afterSubject();
void afterNoun();
void afterObject();
void noun();
void verb();
void be();
void tense();
bool lexiconWord();


 
// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
/*
** Done by: Edgar Cruz
 
PURPOSE: To generate an error message when match() fails.  
PARAMETER: An expected variable of type tokentype and a lexeme variable
           of type string.
ALGORITHM: Displays an error message to the screen and exits the program.
*/
void syntaxerror1(tokentype expected, string lexeme)
{
  cout << "SYNTAX ERROR: expected " << tokens[expected] << " but found " << lexeme << endl;
  exit(1);
}
 
//** Done by: Edgar Cruz
/*
PURPOSE: To generate an error message when afterSubject(), afterNoun(),
         afterObject(), noun(), be(), or tense() fail.
PARAMETER: A lexeme variable of type string and a parserFunction variable 
           of type string.
ALGORITHM: Displays an error message to the screen and exits the program.
*/
void syntaxerror2(string lexeme, string parserFunction)
{
  cout << "SYNTAX ERROR: unexpected " << lexeme << " found in " <<  parserFunction;
  exit(1);
}
 
//** Done by: Takuro Iwane
/*
PURPOSE: Looks ahead to see what token comes next from the scanner. 
ALGORITHM: Checks to see if the global variable, token_available, is false.
           If it's false, scanner is called. The token type returned from
           the scanner is stored in saved_token. The word returned from the scanner
           is stored in lexeme, and fin has the input file that the user
           input. Token_available is set to true. The lexeme is stored in 
           saved_lexeme. Returns the saved_token;
*/
tokentype next_token()
{
  string lexeme;
  if(!token_available)// if there is no saved token from the previous lookahead
    {
      cout << "Scanner was called....." << endl;
      scanner(saved_token, lexeme, fin);// call scanner to grab a new token.
                                        // saved_token is a global variable. 
      //      cout << "Scanner called using word: " << lexeme << endl;
      if(saved_token == ERROR)
	cout << "Lexical Error" << endl;
      token_available = true;// mark the fact that you have saved it.
                             // token_available is a global variable.
      saved_lexeme = lexeme;
    }
  return saved_token;//return the saved token
}
 
//** Done by: Takuro Iwane
/*
PURPOSE: Checks and eats up the expected token.
PARAMETER: A tokentype variable called expected.
ALGORITHM: If saved_lexeme is eofm the program will exit. If next_token 
           does not match the token type within the variable expected, 
           syntaxerror1 is called and the program exits. Otherwise, Matched 
           and the token type is displayed to the screen. Token_available 
           is set to false and true is returned.
*/
bool match(tokentype expected)
{
 
  if(saved_lexeme == "eofm")
    exit(1);
  if(next_token() != expected)
    {
      syntaxerror1(expected, saved_lexeme);
      exit(1);
    }
  else
    {
      cout << "Matched " << tokens[expected] << endl; //display the matched token_type
      token_available = false;
      return 1;
    }
}
 
// ** Make each non-terminal <> into a function here
// ** Be sure to put the corresponding grammar rule above each function
 
//** Done by: Edgar Cruz
/*
PURPOSE: <story> starts the parsing. 
ALGORITHM: Checks to see if the next_token() matches one of token types. Otherwise,
           the program ends. 
*/
//<story>::<s>{<s>}
void story()
{
 
  cout << "Processing Story" << endl << endl;
  s();
  while(true){
    switch(next_token())
      {
      case CONNECTOR: s();
	break;
      case WORD1: s();
	s();
	break;
      case PRONOUN: s();
	break;
      default:
	exit(1);;
 
      }// end of switch
  }//  end of loop
 
}//  end of story 
 
//** Done by: Edgar Cruz
/*
PURPOSE: Continue parsing.
ALGORITHM: If next_token matches CONNECTOR, match(saved_token) is called.
           Otherwise, noun(),
           match(SUBJECT), and afterSubject() called.
*/
//<s>::= [CONNECTOR] <noun> SUBJECT <afterSubject>
void s()
{
  cout << "\n========Processing <s>========" << endl;
  if(next_token() == CONNECTOR)
    {   
      match(saved_token);
      
    }
  noun();
  match(SUBJECT);
  afterSubject();
 
}//  end of s
 
//** Done by: Takuro Iwane
/*
PURPOSE: Next step in the parsing process
ALGORITHM: next_token() is called in a switch statement. next_token() 
           returns a token type and it is compared against the cases 
           WORD2, WORD1, and PRONOUN. If the token type that next_token()
           returns doesn't match any of the cases then syntaxerror2 is
           called.
*/
//<afterSubject>::= <verb> <tense> PERIOD | <noun> <afterNoun>
void afterSubject()
{
  cout << "Processing <X>" << endl;
  switch(next_token())
    {
    case WORD2:
      verb();
      tense();
      match(PERIOD);
      break;
    case WORD1:
    case PRONOUN:
      noun();
      afterNoun();
  
      break;
    default: syntaxerror2(saved_lexeme, "afterSubject");
    }//  end of switch
 
 
}//end of afterSubject
 
//** Done by: Takuro Iwane
/*
PURPOSE: Continues the parsing process.
ALGORITHM: next_token() is called in a switch statement. next_token() 
           returns a token type and it is compared against the cases 
           IS, WAS, DESTINATION, and OBJECT. If it finds a match with a 
           case, it will call the functions in it and break. If the 
           token type that next_token()returns doesn't match any of 
           the cases then syntaxerror2 is called.
*/
//<afterNoun>::= <be> PERIOD | DESTINATION <verb> 
//               <tense>  PERIOD | OBJECT  <afterOBJECT>
void afterNoun()
{
  cout << "Processing <Y>" << endl;
  switch(next_token())
    {
    case IS: 
    case WAS:
      be();
      match(PERIOD);
      break;
    case DESTINATION:
      match(DESTINATION);
      verb();
      tense();
      match(PERIOD);
      break;
    case OBJECT:
      match(OBJECT);
      afterObject();
      break;
    default:
      syntaxerror2(saved_lexeme, "afterNoun");
    }//  end of switch
 
}//  end of afterNoun
 
//** Done by: Jesus Rivera
/*
PURPOSE: To continue the parsing process. 
ALGORITHM: next_token() is called in a switch statement. next_token() 
           returns a token type and it is compared against the cases 
           WORD2, WORD1, and PRONOUN. If it finds a match with a 
           case, it will call the functions in it and break. If the 
           token type that next_token()returns doesn't match any of 
           the cases then syntaxerror2 is called.
*/
//<afterOBJECT>:: <verb> <tense> PERIOD | <noun> 
//                DESTINATION <verb> <tense> PERIOD
void afterObject()
{
 
  cout << "Processing <afterObject>" << endl;
  switch(next_token())
    {
    case WORD2:
      verb();
      tense();
      match(PERIOD);
      break;
    case WORD1:
    case PRONOUN:
      noun();
      match(DESTINATION);
      verb();
      tense();
      match(PERIOD);
      break;
    default: syntaxerror2(saved_lexeme, "afterObject");
    }//  end of switch
 
}//  end of afterObject
 
//** Done by: Jesus Rivera
/*
PURPOSE: Continues the parsing process
ALGORITHM: next_token() is called in a switch statement. next_token() 
           returns a token type and it is compared against the cases 
           WORD1 and PRONOUN. If it finds a match with a 
           case, it will call the functions in it and break. If the 
           token type that next_token()returns doesn't match any of 
           the cases then syntaxerror2 is called.
*/
//<noun>::= WORD1 | PRONOUN
void noun()
{
 
  cout << "Processing <noun>" << endl;
  switch(next_token())
    {
    case WORD1:
      match(WORD1);
      break;
    case PRONOUN:
      match(PRONOUN);
      break;
    default: syntaxerror2(saved_lexeme, "noun");
    }//  end of switch
 
}// end of noun
 
//** Done by: Edgar Cruz
/*
PURPOSE: Continues the parsing process
ALGORITHM: Displays processing <verb> to the screen. 
           match(WORD2) is called.
*/
//<verb>::= WORD2
void verb()
{
  cout << "Processing <verb>" << endl;
  match(WORD2);
}//  end of verb
 
//** Done by: Edgar Cruz
/*
PURPOSE: Continues the parsing process
ALGORITHM: Displays processing <be> to the screen. 
           next_token() is called in a switch statement. next_token() 
           returns a token type and it is compared against the cases 
           IS and WAS. If it finds a match with a 
           case, it will call the functions in it and break. If the 
           token type that next_token()returns doesn't match any of 
           the cases then syntaxerror2 is called.
*/
//<be>::= IS|WAS
void be()
{
 
  cout << "Processing <be>" << endl;
  switch(next_token())
    {
    case IS:
      match(IS);
      break;
    case WAS:
      match(WAS);
      break;
    default: syntaxerror2(saved_lexeme, "be");
    }//  end of switch
 
}//  end of be
 
//** Done by: Takuro Iwane
/*
PURPOSE: Continues the parsing process
ALGORITHM: Displays processing <tense> to the screen. 
           next_token() is called in a switch statement. next_token() 
           returns a token type and it is compared against the cases 
           VERBPAST, VERBPASTNEG, VERB, and VERBNEG. If it finds a match with a 
           case, it will call the function in it and break. If the 
           token type that next_token()returns doesn't match any of 
           the cases then syntaxerror2 is called.
*/
//<tense>::= VERBPAST|VERBPASTNEG|VERB|VERBNEG
void tense()
{
  cout << "Processing <tense>" << endl;
  switch(next_token())
    {
    case VERBPAST:
      match(VERBPAST);
      break;
    case VERBPASTNEG:
      match(VERBPASTNEG);
      break;
    case VERB:
      match(VERB);
      break;
    case VERBNEG:
      match(VERBNEG);
      break;
    default: syntaxerror2(saved_lexeme, "tense");
    }//  end of switch
 
}//  end of tense
 
// The test driver to start the parser
//** Done by: Jesus Rivera
 
/*
PURPOSE: To translate a Japanese word to an English word.
ALGORITHM: The user inputs the name of the file that contains
           the Japanese words. Open the input file and open 
           the output file that will contain the  
           Japanese words translated to English.           
*/
int main()
{
  string userInput;
  cout << "Please enter a file name: ";
  getline(cin, userInput);
  //- opens the input file
  fin.open(userInput.c_str());
  
  //- calls the <story> to start parsing
  story();
 
  //- closes the input file 
  fin.close();
  
 
}// end

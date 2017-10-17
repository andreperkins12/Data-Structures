#include <string>
#include <iostream>
#include "findMatch.h"

using namespace std;



findMatch::findMatch(){}


findMatch::~findMatch(){}




char findMatch::ourMatch(char theD){ //character matches


		switch(theD){ //look for potential matches 

			case '[':

				return ']';

			case '{':

				return '}';

			case '(' :

				return ')';

			default:
			
				return ' ' ;
		}

}



char findMatch::firstM(char theD){ //first character check


	return ((theD == '{') || (theD == '(') || (theD == '['));

}


char findMatch::lastM(char theD){ //second character check


 return ((theD == '}') || (theD == ')') || (theD == ']'));

}





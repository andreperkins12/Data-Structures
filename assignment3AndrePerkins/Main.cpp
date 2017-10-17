#include <string>
#include <iostream>
#include <fstream>
#include "theStack.h"
#include "theFile.h"
#include "findMatch.h"

using namespace std;


int main(int armyStackc, char** argv)
{
	getFile fileInput;
	char theAnswer;
	findMatch ourComp;
	string theLine;
	string myLine;
	theStack<char> myStack;
	int count = 0;


	if(argv[1] == NULL){

		cout << "Enter File: " << endl;

		return 1;
	}


		ifstream theTextFile(fileInput.executeFile(argv[1])); //returns file in string form
		

		try {


				while(getline(theTextFile,theLine)){ //reading file input 

						
					
					count++;

						for(char &theChar : theLine){
							
						   
							if (ourComp.firstM(theChar)) //first character 
							{
								myStack.push(theChar); //push elements to the Stack

								} else if(ourComp.lastM(theChar)){

										if (myStack.isEmpty()) 
										{
											cout << "Line: " << count << 

											" Found without open " << endl;

											break;
										}


								 if (ourComp.ourMatch(myStack.peek()) != theChar) 
									{

									cout << "Line: " << count  << " found " << theChar <<

									" Expected: " << ourComp.ourMatch(myStack.peek()) << endl;

									break;
										
									}

										myStack.pop();

								}


							}
							
						}	

						

								if(myStack.isEmpty()){

											cout << "There were No Errors, Good Job!" << endl;

											}else {

												cout << "End of File, you were missing :  " << myStack.peek()  << endl;

										}
									

		}catch(exception& e){

			cout << "There was an Error" << endl;
		}

			cout << "Would you like to enter another File (Y/N): " << endl;

				cin >> theAnswer;

					if(theAnswer == 'Y' || theAnswer == 'y'){

																

						cout << "Enter File: " << endl;

															
							return 1;
														

					}else {

						cout << "End Program...." << endl;

					}


	return 0;
}
#include <string>
#include <iostream>
#include <fstream>
#include "theFile.h"
#include "theCalc.h"


using namespace std;



readFile::readFile(){}


int readFile::getFileData(string theFile){ //read file and pass to Q
string ourData = " ";
toPass = 0;
counter = 0;


ifstream readF(theFile);


	if(readF.is_open()){

		while(getline(readF,ourData)){
			counter++;
			theLine = counter;

			toPass = std::stoi(ourData);
			//add to the Queue the numbers inside the file
			
			passForCalculations(theLine,toPass);

		} //end of while loop 






		} else {

		cout << "There was an error" << endl;

		return 1;

	} //end of else

	return 0 ;

}

void readFile::passForCalculations(int theLine, int toPass){

	this->theLine = theLine;
	this->toPass = toPass;

	theCalc passCalc;


	switch(theLine){ //pass to be calculated

		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:


		default:

			break;

	}



}

readFile::~readFile(){ }

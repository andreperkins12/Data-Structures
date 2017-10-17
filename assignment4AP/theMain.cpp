#include <string>
#include <iostream>
#include "theFile.h"



using namespace std;

int main(int argc, char const *argv[])
{
	readFile ourFile;

	if(argv[1] == NULL){

		cout << "Enter File: " << endl;

		return 1;
	}

	ourFile.getFileData(argv[1]); //take in file


	









	return 0;
}
#include <string>
#include <iostream>
#include <fstream>
#include "theHeader.h"

using namespace std;

int main(int argc, char const *argv[]) {	
	int theLines;
	string DNA;
	Assignment1 assignment;


	if (argv[1] == NULL) {
		cout << "Enter File Name: " << endl;
		return 1;
	}

	assignment.getTheString(argv[1]);
	
	assignment.thePairs();
	assignment.theOutput();
	assignment.theStrings();

	return 0;
}

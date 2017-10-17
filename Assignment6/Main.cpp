#include <string>
#include <iostream>

#include "Sorting.h"


using namespace std;

int main(int argc, char const *argv[])
{
	
	Sorting toSort;

	if(argv[1] == NULL){

		cout << "Enter File: " << endl;

		return 1;
	}	

	toSort.readFrom(argv[1]);
	
	return 0;
}
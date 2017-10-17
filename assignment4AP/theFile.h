#include <string>
#include <iostream>

using namespace std;

class readFile
{
public:
	readFile();
	~readFile();
	int theLine;
	int counter;
	int toPass;

	int getFileData(string theTextFile);
	void passForCalculations(int theCount, int data);

	
};
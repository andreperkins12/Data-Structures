#include <string>
#include <iostream>

using namespace std;



class findMatch
{
public:
	findMatch();

	bool firstDel;
	bool secondDel;
	bool thirdDel;

	char ourMatch(char data);

	char firstM(char data);
	char lastM(char data);


	~findMatch();
	
};
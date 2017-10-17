#include <string>
#include <iostream>

using namespace std;

class Assignment1 {
	public:
		Assignment1();
		~Assignment1();

		string userInput(string input, int lines);
		void getTheString(string textFile);
		void thePairs();
		void theOutput();
		void theStrings();


	private:
		string theRealDNA;
		float theMean;
		double theSD;
		double theVar;
		double theProb;
		double theCount;
		double theTotal;
		double theConstant;
		int linesWrote;

		//Prob
		float aProb;
		float cProb;
		float tProb;
		float gProb;

		float aaProb;
		float acProb;
		float atProb;
		float agProb;

		float gaProb;
		float ggProb;
		float gcProb;
		float gtProb;

		float caProb;
		float ccProb;
		float cgProb;
		float ctProb;

		float taProb;
		float tgProb;
		float tcProb; 
		float ttProb;


};

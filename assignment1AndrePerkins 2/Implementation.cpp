#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <cstdlib>

#include <string>
#include <ctime>
#include "theHeader.h"

Assignment1::Assignment1() {
}

Assignment1::~Assignment1() {
}




void Assignment1::getTheString(string textFile){ //read From Text File 
	string theString;
	int lineCount;
	ifstream myFile (textFile);  //read from DNA text file


	if (myFile.is_open())
	{
		string addStrings;
		while(getline(myFile, addStrings)){
			//cout<< theString << '\n' ;
		 theString += addStrings;
			lineCount++;
		}

		myFile.close();
	}

	cout << "DNA found in File : " << theString << endl;

	linesWrote = lineCount;
	theCount = theString.length(); //set to instance
	theRealDNA = theString;
}

///////////






 void Assignment1::thePairs(){ //Compute the Pairs and calculations
 
 	//Individual nueclotides
	int a = 0;
	int c = 0;
	int g = 0; 
	int t = 0;

	// The pairs
	int aa = 0;
	int ac = 0;
	int at = 0;
	int ag = 0;

	int ga = 0;
	int gg = 0;
	int gc = 0;
	int gt = 0;

	int ca = 0;
	int cc = 0;
	int cg = 0;
	int ct = 0;

	int ta = 0;
	int tg = 0;
	int tc = 0; 
	int tt = 0;

	int lineCount = 0;

 	for (int i = 0; i < theRealDNA.length(); ++i)  //want to get nueclotides and pairs counted in String (theRealDNA)
 	{
 				//A and a pairs
 		if(theRealDNA[i] == 'A'||theRealDNA[i] == 'a'){
				a++;
				if(theRealDNA[i+1] == 'A'||theRealDNA[i] == 'a'){
					aa++;
				}
				else if(theRealDNA[i+1] == 'C'||theRealDNA[i] == 'c'){
					ac++;
				}
				else if(theRealDNA[i+1] == 'T'|| theRealDNA[i] == 't'){
					at++;
				}
				else if(theRealDNA[i+1] == 'G'||theRealDNA[i] == 'g'){
					ag++;
				}
			}
				//C and C Pairs
				if(theRealDNA[i] == 'C'||theRealDNA[i] == 'c'){
				c++;
		
				if(theRealDNA[i+1] == 'A'||theRealDNA[i] == 'a'){
					ca++;
				}
				else if(theRealDNA[i+1] == 'C'||theRealDNA[i] == 'c'){
					cc++;
				}
				else if(theRealDNA[i+1] == 'T'|| theRealDNA[i] == 't'){
					ct++;
				}
				else if(theRealDNA[i+1] == 'G'||theRealDNA[i] == 'g'){
					cg++;
				}
			}
				//T and T pairs
				if(theRealDNA[i] == 'T'||theRealDNA[i] == 't'){
				t++;
		
				if(theRealDNA[i+1] == 'A'||theRealDNA[i] == 'a'){
					ta++;
				}
				else if(theRealDNA[i+1] == 'C'||theRealDNA[i] == 'c'){
					tc++;
				}
				else if(theRealDNA[i+1] == 'T'|| theRealDNA[i] == 't'){
					tt++;
				}
				else if(theRealDNA[i+1] == 'G'||theRealDNA[i] == 'g'){
					tg++;
				}
			}
				//G and g pairs
				if(theRealDNA[i] == 'G'||theRealDNA[i] == 'g'){
				g++;
		
				if(theRealDNA[i+1] == 'A'||theRealDNA[i] == 'a'){
					ga++;
				}
				else if(theRealDNA[i+1] == 'C'||theRealDNA[i] == 'c'){
					gc++;
				}
				else if(theRealDNA[i+1] == 'T'|| theRealDNA[i] == 't'){
					gt++;
				}
				else if(theRealDNA[i+1] == 'G'||theRealDNA[i] == 'g'){
					gg++;
				}
			}
 	}
	 	double total = a + c + t + g;
	 	theMean = total/ linesWrote; //MEAN
		double individualMeans = theMean / theCount;
		double eachLineMean = eachLineMean + individualMeans/ theCount;
	 	theVar = ((pow(a-eachLineMean,2))+(pow(c-eachLineMean,2))+(pow(t-eachLineMean,2))+(pow(g-eachLineMean,2))/4); //variance
		theSD = sqrt(theVar); //standard dev 
		theTotal = total;

			//All Probs
		 aProb = (a/theCount);
		 cProb = (c/theCount) ;
		 tProb = (t/theCount);
		 gProb = (g/theCount);

		 aaProb = (aa/theCount);
		 acProb = (ac/theCount);
		 atProb = (at/theCount);
		 agProb = (ag/theCount);

		 gaProb = (ga/theCount);
		 ggProb = (gg/theCount);
		 gcProb = (gc/theCount);
		 gtProb = (gt/theCount);

	 	 caProb = (ca/theCount);
		 ccProb = (cc/theCount);
		 cgProb = (cg/theCount);
	 	 ctProb = (ct/theCount);

		 taProb = (ta/theCount);
		 tgProb = (tg/theCount);
		 tcProb = (tc/theCount); 
		 ttProb = (tt/theCount);

		 cout << aProb << endl;
 	
}

void Assignment1::theOutput(){ //Output to File

		ofstream outputFile;
		
		outputFile.open("andrePerkins.out");

		if(outputFile.is_open()){
			cout<< "Andre Perkins" << endl;
			cout << "2267349" << endl;
			cout<< "2/7/17" <<endl;
			cout << "The Mean is : " << theMean <<endl;
			cout << "The SD is : " << theSD <<endl;
			cout << "The Variance is : " << theVar <<endl;
			

			cout << "The Probability for a is : " << aProb << endl;
			cout << "The Probability for c is : " << cProb << endl;
			cout << "The Probability for t is : " << tProb << endl;
			cout << "The Probability for g is : " << gProb << endl;

			cout << "The Probability for aa is : " << aaProb << endl;
			cout << "The Probability for ac is : " << acProb << endl;
			cout << "The Probability for at is : " << atProb << endl;
			cout << "The Probability for ag is : " << agProb << endl;

			cout << "The Probability for ca is : " << caProb << endl;
			cout << "The Probability for cc is : " << ccProb << endl;
			cout << "The Probability for ct is : " << ctProb << endl;
			cout << "The Probability for cg is : " << cgProb << endl;

			cout << "The Probability for ta is : " << taProb << endl;
			cout << "The Probability for tc is : " << tcProb << endl;
			cout << "The Probability for tt is : " << ttProb << endl;
			cout << "The Probability for tg is : " << tgProb << endl;

			cout << "The Probability for ga is : " << gaProb << endl;
			cout << "The Probability for gc is : " << gcProb << endl;
			cout << "The Probability for gt is : " << gtProb << endl;
			cout << "The Probability for gg is : " << ggProb << endl;

			

			// Output 1000 Strings
			
			//while (theyWantMore == true) {

				double firstRandom = ((double)rand()+1)/((double)RAND_MAX+2);
				//	cout << " FIRST: " << firstRandom << endl;
            		double secondRandom = ((double)rand()+1)/((double)RAND_MAX+2);
            	//	cout << " SECOND" << secondRandom << endl;

            		theConstant = sqrt(-2*log(firstRandom))*cos(2*M_PI*secondRandom);

            		//cout << "CONSTANT " << theConstant << endl;
            		double theD = (theConstant * theSD) + theMean;

            	//	cout << "THE MEAN: " << theMean << endl;
//
            	//	cout << "THE SD : " << theSD << endl;
 
            	//	cout << theD << endl;

            		


            		




            	//	} //END OF WHILE






		}


	}




	void Assignment1::theStrings(){

		ofstream outputFile;
		
		outputFile.open("andrePerkins.out");
		bool theyWantMore = true;

            		double between0and1;

            		//srand(time(NULL));
            		//while(theyWantMore == true){

            		if (outputFile.is_open())
            		{
            			
            			while( theyWantMore == true){

		            			for (int i = 0; i < 1000; ++i)
		            			{
		            				between0and1 = ((double)rand()+1)/((double)RAND_MAX+2);

		            				if(between0and1 < aProb){
		            					cout << "A";
		            					if ((i+1) == round(between0and1)) {
		                        			outputFile << endl;
		                    			}

		                    				continue;
		            				}

		            				between0and1 -= aProb;

		            				if(between0and1 < cProb){
		            					cout << "C";
		            					if ((i+1) == round(between0and1)) {
		                        			outputFile << endl;
		                    			}

		                    				continue;
		            				}


		            				between0and1 -= cProb;

		            				if(between0and1 < tProb){
		            					cout << "T";
		            					if ((i+1) == round(between0and1)) {
		                        			outputFile << endl;
		                    			}

		                    				continue;
		            				}


		            				between0and1 -= tProb;

		            				if(between0and1 < gProb){
		            					cout << "G";
		            					if ((i+1) == round(between0and1)) {
		                        			outputFile << endl;
		                    			}

		                    				continue;
		            				}


            					string answer;
            					cout<< "Enter (Y) to generate More Strings or (N) to end.." << endl;
            					cin >> answer;

            					if (answer == "Y")
            					{
            						continue;
            					} else if (answer == "N"){
            						theyWantMore = false;
            						outputFile.close();
            						break;
            					}

            				
            					



            				} // IF OPEN
            					string theAnswer;

            			cout << "    ENTER Y to generate more Strings or N to stop "<< endl;
            			cin >> theAnswer;

            			if (theAnswer == "Y")
            			{
            				theyWantMore = true;
            				continue; 
            			} else {
            				theyWantMore = false;
            				break;
            				outputFile.close();
            			}


            			} //END OF 1000
            			



            		} //END OF WHILE


	}









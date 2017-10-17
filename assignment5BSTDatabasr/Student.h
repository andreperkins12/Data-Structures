#include <string>
#include <iostream>
#include <fstream>
#include <stack>




using namespace std;
template <typename E>
struct rollBackStack{

	stack<E> studentStack;

};


struct studentStructure
{

	string theName;
	string level;
	string major;
	double theGpa;
	int advisorNumber;
	int studentID;
	bool rollBack;


	void studentFile(string name, string level, string major, double gpa, int advisorNumber, int id);
	void theNewStudent();

	void deleteTheStudet(); //delete not done yet

	string theMessage();

	int getID();





	
};


int getID(){

	string stringID;
	int theId;

	ifstream theFile("studentTable.txt");

	if (theFile.is_open())
	{
		
		while(getline(theFile, stringID)) {

			theId = std::stoi(stringID); //need to get specific place of comma to find ID

		}
	}


	return theId;

}


void studentStructure::studentFile(string name, string level, string major, double gpa, int advisorNumber, int id){

	ofstream myfile ("studentTable.txt", std::ios::app);


	if (myfile.is_open())
	{
		myfile << name << "," << 
		level << "," << 
		major << "," << 
		gpa << "," << 
		advisorNumber << "," << 
		id <<  endl;


		myfile.close();

		cout << "Student Data Stored in File is Success" << endl;

		}else {

		cout << "File Could Not Be Opened" << endl;

	}



}


string studentStructure::theMessage(){

	return "Error had occurred";
}

void studentStructure::theNewStudent(){

	bool goodToGo;
	
		try{

		

		cout << "Enter New Student ID: " << endl;

		cin >> studentID;

		cout << "Enter New Student Name: " << endl;

		cin >> theName;

		cout << "Enter New Student Major: " << endl;

		cin >> major;

		cout << "Enter New Student GPA: " << endl;

		cin >> theGpa;

		cout << "Enter New Student Advisor Number: " << endl;

		cin >> advisorNumber;

		cout << "Enter Year of Student(Ex: Freshman): " << endl;

		cin >> level;


		goodToGo = true;

		if (!cin && goodToGo == false)
		{
		
			throw "An Error had occurred";

			
 		} else if (goodToGo == true){

 			studentFile(theName,level,major,theGpa,advisorNumber,studentID);
 		

 		}
		
	}catch(const char* exception){

			cout << theMessage() << endl;



	}
	
	

}
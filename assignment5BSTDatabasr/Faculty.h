#include <string>
#include <iostream>
#include <fstream>

using namespace std;


struct facultyStruct
{

	int facID;
	string name;
	string facLevel;
	string department;

	void facFile(string name, string level, int id, string department);

	void newFac();




	
};

void facultyStruct::newFac(){


bool goodToGo;
	
		try{

		

		cout << "Enter New Faculty ID: " << endl;

		cin >> facID;

		cout << "Enter New Faculty Name: " << endl;

		cin >> name;

		cout << "Enter New Faculty level: " << endl;

		cin >> facLevel;

		cout << "Enter New department: " << endl;

		cin >> department;

		//need advisees for faculty


		goodToGo = true;

		if (!cin && goodToGo == false)
		{
		
			throw "An Error had occurred";

			
 		} else if (goodToGo == true){

 			facFile(name, facLevel,facID,department);
 		

 		}
		
	}catch(const char* exception){

			



	}





}

void facultyStruct::facFile(string name, string level, int id, string department){

	ofstream theFile("facultyTable.txt", std::ios::app);

		if (theFile.is_open())
	{
		theFile << name << "," << 
		level << "," << 
		id << "," << 
		department << "," << 
		//Advisees << "," << 
		id <<  endl;


		theFile.close();

		cout << "Faculty Data Stored in File is Success" << endl;

		}else {

		cout << "File Could Not Be Opened" << endl;

	}

}
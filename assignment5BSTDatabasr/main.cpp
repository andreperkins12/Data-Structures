#include <string>
#include <iostream>

#include "OutPutSelection.h"




int main(int argc, char const *argv[])
{
	outputMenu theSim;
	bool toContinue = true;
	int userChoice;


  		

	while(toContinue == true){

	cout << "--------------------------------------------------------------------------------" << endl;

	cout << " " << endl;
	cout << "Select from the Following: " << endl;
	cout << " " << endl;
	cout << "1.  Print all students and their information (sorted by ascending id #)" << endl
  	 << "2.  Print all faculty and their information (sorted by ascending id #)" << endl
     << "3.  Find and display student information given the students id" << endl
     << "4.  Find and display faculty information given the faculty id" << endl
     << "5.  Given a student’s id, print the name and info of their faculty advisor" << endl
     << "6.  Given a faculty id, print ALL the names and info of his/her advisees." << endl
     << "7.  Add a new student" << endl
     << "8.  Delete a student given the id" << endl
     << "9.  Add a new faculty member" << endl
     << "10. Delete a faculty member given the id." << endl
      << "11. Change a student’s advisor given the student id and the new faculty id." << endl
     << "12. Remove an advisee from a faculty member given the ids" << endl
     << "13. Rollback" << endl
     << "14. Exit" << endl << endl;

 		cin >> userChoice;

 		theSim.selectionSimulation(userChoice);

 		if (userChoice == 14)
 		{
 			toContinue = false;
 			break;
 		}

 	}

		




	return 0;
};
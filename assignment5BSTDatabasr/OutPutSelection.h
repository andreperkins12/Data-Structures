#include <string>
#include <iostream>

#include "Faculty.h"
#include "Student.h"

class outputMenu
{
public:
	outputMenu();
	~outputMenu();

	int userChoice;
	

	void selectionSimulation(int choice);
	
};


outputMenu::outputMenu(){}




void outputMenu::selectionSimulation(int c){ //Choice Selection 

	studentStructure student;
	facultyStruct faculty;
	
	switch(c){

		case 1:
			
			break;
		case 2:
		case 3:
			
		case 4:
		case 5:
		case 6:
		case 7:
		student.theNewStudent();
			break;
		
		case 8:
		case 9:
		faculty.newFac();
			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:

			
			break;

		default:
			break;


	}

}


outputMenu::~outputMenu(){}
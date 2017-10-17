#include <string>
#include <iostream>
#include "Student.h"


using namespace std;


class theNode{
public:
	theNode();
	theNode(string name, string level, string major, double gpa, int advisorNumber,int key);

	virtual ~theNode();

	theNode *leftChild;
	theNode *rightChild;

	int id;
	string name;
	string level;
	string major;
	double gpa;
	int advisorNumber;
};


theNode::theNode(){

	leftChild = NULL;
	rightChild = NULL;

}

theNode::theNode(string user, string lev, string maj, double gp, int advisorNum,int k){

	leftChild = NULL;
	rightChild = NULL;

	name = user;
	level = lev;
	major = maj;
	gpa = gp;
	advisorNumber = advisorNum;
	id = k;

}

theNode::~theNode(){}

template <typename E>
class studentBST
{
public:

	string theName;
	string level;
	string major;
	double theGpa;
	int advisorNumber;
	int studentID;


	studentBST();
	~studentBST();

	void addNode(string name, string level, string major, double gpa, int advisorNumber, int id); //DONE
	bool isEmpty(); //DONE

	void deleteNode(int id); //DONE

	void searchTree(int id); //DONE

	void findNode(string name, string level, string major, double gpa, int advisorNumber,int id);

	void inOrderTraversal(theNode* node); //DONE

	theNode* getSuccessor(theNode* node); //DONE

	theNode* getMax(); //NEED TO DO
	theNode getMin();

private:
	theNode* root;


	
	
};



template <typename E>
studentBST<E>::studentBST(){

	root = NULL;
	

}

template <typename E>
studentBST<E>::~studentBST(){}

template <typename E>
bool studentBST<E>::isEmpty(){ //Complete

	if (root == NULL)
	{
		cout << "EMPTY"  << endl;
		return true;
	}

	cout << "NOT EMPTY" << endl;

	return false;

}


template <typename E>
void studentBST<E>::addNode(string name, string level, string major, double gpa, int advisorNumber, int id){ //Complete


this->theName = name;
this->level = level;
this->major = major;
this->theGpa = gpa;
this->advisorNumber = advisorNumber;
this->studentID = id;

theNode* node = new theNode(name,level,major,gpa,advisorNumber,id);

	if (root == NULL)
	{
		root = node;
		//add to Student Table to Store

		///NEED TO COMPARE IDS STORED IN FILES to see what side it is

			cout << " THIS IS THE ROOT" << endl;
			//toFile.studentFile(theName,level,major,theGpa,advisorNumber,studentID); TO ADD TO STUDENTTABLE.TXT
 
		}else {

			theNode* current = root;
			theNode* parent;

			while(true){

				parent = current;

				if (id < current->id)
				{
					current = current->leftChild;

					cout << "On the Left" << endl;

				//	toFile.studentFile(theName,level,major,theGpa,advisorNumber,studentID);

					if (current == NULL)
					{
						parent->leftChild = node;

						break;
					}

				}else {

					current = current->rightChild;

					cout << "On the Right" << endl;

				//	toFile.studentFile(theName,level,major,theGpa,advisorNumber,studentID);

					if (current == NULL)
					{
						parent->rightChild = node;

						break;
					}
				}
			}
		}
}



template <typename E>
void studentBST<E>::searchTree(int id){ //Complete

	if (root == NULL)
	{
		cout << "Empty" << endl;

		} else {

			theNode* focusNode = root;

			while(focusNode->id != id){

				if (id < focusNode->id)
				{
					focusNode = focusNode->leftChild;

					cout << "Searching Left Side, and Found" << endl;

					cout << id << theName << endl;
					

				} else {

					focusNode = focusNode->rightChild;

					cout << "Searching Right Side, and Found" << endl;

					cout << id << theName << endl;
					
				}

				if (focusNode == NULL)
				{
					cout << "Found Nodes, but your Search does not Exist" << endl;

				break;
				}
			}

	}
}




template <typename E>
void studentBST<E>::findNode(string name, string level, string major, double gpa, int advisorNumber,int id){

theNode* focusNode = new theNode(name, level, major,gpa,advisorNumber,id);

	while(focusNode != NULL){
			if(focusNode == NULL){
				focusNode = NULL;
				cout << "Does not Exist" << endl;
			}
			if(id < focusNode->id){
				focusNode = focusNode->leftChild;

				cout << "FOUND ON LEFT" << name << level << id << endl;

			}else {
				focusNode = focusNode->rightChild;

				cout << "FOUND ON RIGHT" << name << level << id << endl;
			}
		}


}




template<typename E>
void studentBST<E>::inOrderTraversal(theNode* node){ //Complete

	if (node != NULL)
	{
		inOrderTraversal(node->leftChild);

		cout << node << endl;

		inOrderTraversal(node->rightChild);
	}




}


template <typename E>
void studentBST<E>::deleteNode(int v){ //DELTE NODE not done yet

	bool onLeft = false;

	if(root == NULL){

		cout << " EMPTY" << endl;

	} else {



		theNode* curr = root;
		theNode* parent = NULL;


		while(curr->id == v){

			parent = curr;
			if(curr->id < v){

				curr = curr->leftChild;

				onLeft = true;
				} else {

					curr = curr->rightChild;
					onLeft = false;

			}

				if (curr == NULL)
				{
					cout << " CURRENT IS NULL" << endl;
				}

		} //End of While

		//leaf

		if(curr->leftChild == NULL && curr->rightChild == NULL){

			if (curr == NULL)
			{
				root = NULL;

			}else if (onLeft){

				parent->leftChild = NULL;

			} else {


				parent->rightChild = NULL;

			} if(curr->rightChild == NULL){

				if(curr == root){

					root = curr->leftChild;

				}else if (onLeft){

					parent->leftChild = curr->leftChild;
				}else {

					parent->rightChild = curr->leftChild;
				}

			}




		} else {

			theNode* theSuccess = getSuccessor(curr); //getting error 


			cout << "Get Success" << endl;

			if(curr == root){

				root = theSuccess;

				cout << " At the ROOT " << endl;


			}else if (onLeft){

				parent->leftChild = theSuccess;

				cout << "Parent Left Child = Success" << endl;

			}else {

				parent->rightChild = theSuccess;

				cout << "Parent Right = success" << endl;


			}

		}


		cout << "Delete Node is SucessFull" << endl;

		


	}

}


template <typename E>
theNode* studentBST<E>::getSuccessor(theNode* node){

	theNode* successParent = node;
	theNode* successor = node;
	theNode* theCurr = node->rightChild;


	while(theCurr != NULL){

		successParent = successor;
		successor = theCurr;
		theCurr = theCurr->leftChild;

	}
	if (successor != node->rightChild)
	{
		
			successParent->leftChild = successor->rightChild;
			successor->rightChild = node->rightChild;

	}

	

	return successor;


}







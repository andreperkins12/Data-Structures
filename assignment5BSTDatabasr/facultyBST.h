#include <string>
#include <iostream>
#include "Faculty.h"

using namespace std;

struct facNode{

	facNode();
	facNode(int key);

	virtual ~facNode();

	facNode *leftChild;
	facNode *rightChild;

	int key;
};


facNode::facNode(){

	leftChild = NULL;
	rightChild = NULL;

}

facNode::facNode(int k){

	leftChild = NULL;
	rightChild = NULL;

	key = k;

}

facNode::~facNode(){}


template <typename E>
class facultyBST
{
public:

	int facID;
	string name;
	string facLevel;
	string department;
	//linked list faculty advisee ids


	facultyBST();
	~facultyBST();

	void addNode(string name, string level, int id, string department); //DONE
	bool isEmpty(); //DONE

	void deleteNode(int id);

	theNode* getSuccessor(theNode* node); 

	void searchTree(int id); //DONE

	void inOrderTraversal(facNode* node); //DONE

	facNode* getMax(); //NEED TO DO
	facNode getMin();

private:
	
	facNode* root;
	
	
};



template <typename E>
facultyBST<E>::facultyBST(){

	root = NULL;
	current = NULL;

}

template <typename E>
facultyBST<E>::~facultyBST(){}

template <typename E>
bool facultyBST<E>::isEmpty(){ //Complete

	if (root == NULL)
	{
		cout << "EMPTY"  << endl;
		return true;
	}

	cout << "NOT EMPTY" << endl;

	return false;

}


template <typename E>
void facultyBST<E>::addNode(string name, string level, int id, string department){ //Complete

this->name = name;
this->facLevel = level;
this->facID = id;
this->department = department;



facNode* node = new facNode(id);

	if (root == NULL)
	{
		root = node;

		cout << "First Node in Faculty BST it is the ROOT" << endl;

		cout << "ID: " << facID << " Name: " << name << 

		" Level: " << facLevel << " Department: " << department << endl;
 
		}else {

			facNode* current = root;
			facNode* parent;

			while(true){

				parent = current;

				if (id < current->key)
				{
					current = current->leftChild;

					cout << "On the Left" << endl;

					if (current == NULL)
					{
						parent->leftChild = node;

						break;
					}

				}else {

					current = current->rightChild;

					cout << "On the Right" << endl;

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
void facultyBST<E>::searchTree(int id){ //Complete

	if (root == NULL)
	{
		cout << "Empty" << endl;

		} else {

			facNode* focusNode = root;

			while(focusNode->key != id){

				if (id < focusNode->key)
				{
					focusNode = focusNode->leftChild;

					cout << "Searching Left Side, and Found" << endl;
					

				} else {

					focusNode = focusNode->rightChild;

					cout << "Searching Right Side, and Found" << endl;
					
				}

				if (focusNode == NULL)
				{
					cout << "Found Nodes, but your Search does not Exist" << endl;

				break;
				}
			}

	}
}


template<typename E>
void facultyBST<E>::inOrderTraversal(facNode* node){ //Complete

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



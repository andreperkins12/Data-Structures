
#include <iostream>
#include <string>



class theNode{
public:
	theNode();
	theNode(int key);

	virtual ~theNode();

	theNode *leftChild;
	theNode *rightChild;

	int key;
};


theNode::theNode(){

	leftChild = NULL;
	rightChild = NULL;

}

theNode::theNode(int k){

	leftChild = NULL;
	rightChild = NULL;

	key = k;

}

template <typename E>
class BSTBuild<E>
{
public:
	BSTBuild();
	~BSTBuild();

	void insert(int value);

	bool findNode(int value);
	bool deleteNode(int node);

	bool isEmpty();

	theNode getMax(); //rightMost
	theNode getMin(); //left 

	theNode* getSuccessor(theNode node); //get help with delete function

private:
	theNode* theRoot;
	theNode* current;

	
};

template <typename E>
BSTBuild<E>::BSTBuild(){

	theRoot = NULL;

	current = NULL;

}


template <typename E>
BSTBuild<E>::~BSTBuild(){

	//iterate and delete 
	//linear

}

template <typename E>
theNode BSTBuild<E>::getMax(){

	current = theRoot;

	if (theRoot == NULL)
	{
		
		return NULL;


	} 

		while(current->rightChild != NULL){

			current = current->rightChild;
		}

		return current; //return node
}

template <typename E>
theNode BSTBuild<E>::getMin(){

	current = theRoot;

	if (theRoot == NULL)
	{
		
		return NULL;


	} 

		while(current->leftChild != NULL){

			current = current->leftChild;
		}

		return current; //return node


}

template <typename E>
void BSTBuild<E>::insert(int val){

theNode* node = new theNode(val);

	if (theRoot == NULL)
	{
		theRoot = node;

	} else {

		theNode* parent;
		theNode* current = theRoot;


		while(true){
			
			parent = current;

			if (val < current->key) //go left
			{
				current = current->leftChild;

				if(current == NULL){  

					parent->leftChild = node;

					break;
				}

			}  else {

				current = current->rightChild;

				if(current == NULL){

					parent->rightChild = node;

					break;

				}
			}
		}
	}
}

template <typename E>
bool BSTBuild<E>::findNode(int value){ //FIND NODE

	if (theRoot == NULL)
	{
		return false;
	} else {

		theNode* focusNode = theRoot;

			while(focusNode->key != value){

				if (value < focusNode->key)
				{
					focusNode = focusNode->leftChild;

				} else {
					focusNode = focusNode->rightChild;
				}

				if (focusNode == NULL)
				{

					return false;
				}
			}
	}
	return true;	
}

template <typename E>
bool BSTBuild<E>::deleteNode(int v){ //DELTE NODE

	bool onLeft = false;

	if(theRoot == NULL){

		return false;

	} else {


		current = theRoot;
		parent = NULL;


		while(current->key == v){

			parent = current;
			if(current->key < v){

				current = current->leftChild;
				onLeft = true;
				} else {

					current = current->rightChild;
					onLeft = false;

			}

				if (current == NULL)
				{
					return false;
				}

		} //End of While

		//leaf

		if(current->leftChild == NULL && current->rightChild == NULL){

			if (current == NULL)
			{
				theRoot = NULL;

			}else if (onLeft){

				parent->leftChild = NULL;

			} else {


				parent->rightChild = NULL;

			} if(current->rightChild == NULL){

				if(current == theRoot){

					theRoot = current->leftChild;

				}else if (onLeft){

					parent->leftChild = current->leftChild;
				}else {

					parent->rightChild = current->leftChild;
				}

			}




		} else {

			theNode* theSuccess = getSuccessor(current);

			if(current == theRoot){

				theRoot = theSuccess;

			}else if (onLeft){

				parent->leftChild = theSuccess;

			}else {

				parent->rightChild = theSuccess;
			}

		}



		return true;


	}

}



bool BSTBuild::inClassDeleteNode(int v){

	//leaf Node 

	bool onTheLeft = true;

	if (theRoot == NULL)
	{
		return false;

	}else {
		
		theNode* theCurr = theRoot;
		theNode* theParent = NULL;

		while(theCurr->key != v){

			theParent = theCurr;


			if (v < theCurr->key)
			{
				theCurr = theCurr->leftChild;	

				onTheLeft = true;
			}else {

				theCurr = theCurr->rightChild;

				onTheLeft = false;

			}

			if (theCurr->key == NULL)
			{
				return false;

			}

		} // we had found theNode to delete


		if (theCurr->leftChild == NULL && theCurr->rightChild == NULL) //no children
		{
			if (theCurr == theRoot) /
			{
				theRoot = NULL;

				}
				else if (onTheLeft)
				{
					parent->leftChild = NULL;

				}else {

				parent->rightChild = NULL;
			}

		} 

		//check for on child

			else if (theCurr->rightChild == NULL)
			{
				
				if (theCurr == theRoot)
				{
					theRoot = theCurr->leftChild;

				}else if (onTheLeft){

					theParent->leftChild = theCurr->leftChild;

				}else {

					theParent->rightChild = theCurr->leftChild;
				}


			}


				else if (theCurr->leftChild == NULL)
			{
				
				if (theCurr == theRoot)
				{
					theRoot = theCurr->rightChild;

				}else if (onTheLeft){

					theParent->rightChild = theCurr->rightChild;

				}else {

					theParent->rightChild = theCurr->rightChild;
				}


			}

			//////check for 2 Nodes////////

			theNode* success = getSuccessor(current);


				if (current == theRoot)
				{
					theRoot = success;


				} else if (onLeft){

					parent->leftChild = success;


				}else {

					parent->rightChild = success;
				}


				success->leftChild = current->leftChild;

				return true;



	}




}



theNode* BSTBuild::getSuccessor(theNode* d){ //node to be deleted , get Successor method

	theNode* sp = d; //successors parent

	theNode* theSuccessor = d; //will be one right, all the way left 
	theNode* current = d->rightChild;

		while(current != NULL){

			sp = theSuccessor;
			theSuccessor = current;
			current = current->leftChild;

		}
		if (theSuccessor != d->rightChild)
		{
			
			sp->leftChild = theSuccessor->rightChild;
			theSuccessor->rightChild = d->rightChild;

		}
		return theSuccessor;
}



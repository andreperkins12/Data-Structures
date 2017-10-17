#include <string>
#include <iostream>

class listNode
{
public:
	listNode();
	int data;
	listNode *next;

	///for Double ended Linked List
	listNode *back;
	/////


	listNode(int d);
	~listNode();

	
};


listNode::listNode(){}

listNode::listNode(int d){
data = d;
next = NULL;

}

listNode::~listNode(){
	if (next != NULL){
		delete next;
	}
}
/////// NEW FILE
class naiveList{



private:
	listNode *front;	
	unsigned int size;

	public:
		naiveList();
		~naiveList();
		void insertFront(int data);
		void printList();

		int removeFirst();
		int find(int d);

		int deletePos(int pos);
		bool isEmpty();
		int getSize();


}


/////// naiveList implementation


naiveList::naiveList(){

	size = 0;
	front = NULL:



}

naiveList::~naiveList(){

	}

	naiveList::insertFront(int data){

		 ////need to check of list is empty

		size ++;
		listNode *node = new listNode(data);
		fornt = node;

		//if its NOT EMPTY

		node->next = front;
		front = node;


	}

	naiveList::removeFirst(int data){
		 //necessary checks if its empty

		size--;

		int theTemp = front->data;

		listNode *temp = front;

		front = front->next;

		temp->next = NUll;

		delete temp;
		returun temp;




	}

void	naiveList::printList(){


		listNode *current = front;

		while(current->next != NUll){

			cout << current->data << endl;

			current = current->next;

		}




	}


void naiveList:: find(int data){

	int idx = -1;

	listNode *current = front;

	while(current->next != NUll){

		++idx;


		if(current->data == data){
			break;

		} else{

			current = current->next;
		}
	}

	return idx;
}


int naiveList::deletePos(int pos){

	int idx = 0;

	listNode * current = front;
	listNode *prev = front;

	while(idx != pos){ // looping till we find it

		++idx;
		prev = current;
		current = current->next;

	}

	prev->next = current->next;

	current->next = NULL;
	int d = current->data;
	delete current;
	size--;
	return d;

	///found our position/node

}

void naiveList::insertBack(int data){

	if(front == NULL){
		front = node
	}else {
		back->next = node;
	}
}













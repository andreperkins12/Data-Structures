#include <string>
#include <iostream> 
#include "theDoubleLinked.h"
#include "Node.h"



template <typename E>
class theQueue
{
public:
	theQueue();
	~theQueue();
	void enqueue(const E& e);
	void dequeue();
	int theSize;
	bool isEmpty();
	 const E& front();
	
	theLinkedList<E> theList;
};

template <typename E>
theQueue<E>::theQueue(){}

template <typename E>
theQueue<E>::~theQueue(){}


template <typename E>
bool theQueue<E>::isEmpty(){

	if(theList.isEmpty()){

		return true;
	}

	return false;
}

template <typename E>
void theQueue<E>::enqueue(const E& e){

	if(theList.isEmpty()){

		theList.add(e);

		} else {

		theList.addBack(e);
	}
	
	theSize++;

}

template <typename E>
const E& theQueue<E>::front() {

	if(theList.isEmpty()){

		cout << "Empty, cant return front" << endl;
	}

	return theList.theHead->next->theData;
}

template <typename E>
void theQueue<E>::dequeue(){

	if(theList.isEmpty()){

		cout << "Cant Remove, Already Empty " << endl;

		} else {

		theList.removeFront();
	}

}




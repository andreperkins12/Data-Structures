#include <string>
#include <iostream>

using namespace std;

template <typename E> 


class theStack{

enum 
{
	DEF_CAPACITY = 150 ///Largest Capacity for Stack
};

public:

	theStack(int theCap = DEF_CAPACITY);
	~theStack();

	int theSize() const; //getsSize
	bool isEmpty() const; //checks
	void push(const E& d);

	const E& peek();
	const E& pop() ;
	

private:

E* theData;
int Capacity;
int theIndex;

};


template < typename E >
theStack<E>::theStack(int cap) : theData(new E[cap]), Capacity(cap), theIndex(-1){

}


template<typename E>
theStack<E>::~theStack(){ }


template< typename E >
int theStack<E>::theSize() const {

	return (theIndex + 1);

}

template < typename E >
void theStack<E>::push(const E& data)  {

	if(theSize() == Capacity){

		throw "The Stack is Full";

		Capacity *= Capacity; //Increase Stack Capacity if full multiplied by itseld
	}

	theData[++theIndex] = data; //add Data to the Stack
} 

template <typename E> 
bool theStack<E>::isEmpty() const{ //isEMpty Function
	
	if (theSize() == 0)
	{
		return true;
	}

	return false;
}

template<typename E>
const E& theStack<E>::pop()  { //pop stack

if(isEmpty()){
	
	throw "The Stack is Empty";
}

return theData[theIndex--]; //decrements size 
}

template <typename E>
const E& theStack<E>::peek()  { //Peek function 

    if (isEmpty()){

    	throw "The Stack is Empty";
    } 

    return theData[theIndex];
}




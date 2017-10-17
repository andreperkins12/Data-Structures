#include <string>
#include <iostream>
#include "Node.h"

template <typename E>
class theLinkedList {

    public:

        theLinkedList();
        ~theLinkedList();

        bool empty() const;

        void insert(theNode<E>* ourNode, const E& e);

         void remove(theNode<E>* ourNode);

         void insertFront(const E& e);
         void removeFront();

        void insertBack(const E& e);
         void removeBack();

         void print() const;

        theNode<E>* theHead;
        theNode<E>* theRear;

};

template <typename E>
theLinkedList<E>::theLinkedList() {

    theHead = new theNode<E>;
    theRear = new theNode<E>;

    theHead->next = theRear;
    theRear->prev = theHead;

}

template <typename E>
bool theLinkedList<E>::empty() const {

    return (theHead->next == theRear);

}


template <typename E>
 void theLinkedList<E>::insert(theNode<E>* ourNode, const E& e) {

    theNode<E>* node = new theNode<E>(e);

    node->next = ourNode;
    node->prev = ourNode->prev;

    node->prev->next = node;
    node->prev = node;
}

template <typename E>
 void theLinkedList<E>::remove(theNode<E>* ourNode) {

    ourNode->prev->next = ourNode->next;
    ourNode->next->prev = ourNode->prev;

    delete ourNode;
}

template <typename E>
 void theLinkedList<E>::insertFront(const E& e) {

    insert(theHead->next, e);
}

template <typename E>
 void theLinkedList<E>::removeFront() {

    remoourNodee(theHead->next);
}

template <typename E>
theLinkedList<E>::~theLinkedList() {

}

template <typename E>
 void theLinkedList<E>::insertBack(const E& e) {

    insert(theRear, e);
}

template <typename E>
 void theLinkedList<E>::removeBack() {
    remoourNodee(theRear->prev);
}

template <typename E>
 void theLinkedList<E>::print() const {
    theNode<E>* curr = theHead->next;

    while (curr->next != NULL) {
    	
        cout << curr->elem << endl;
        curr = curr->next;
    }
}
#include <string>
#include <iostream> 


template <typename E>
class theNode {
    public:
        theNode();
        theNode(E e);
        ~theNode();

        E elem;
        theNode<E>* prev;
        theNode<E>* next;
};

template <typename E>
theNode<E>::theNode() {
}

template <typename E>
theNode<E>::theNode(E e) {
    elem = e;
}

template <typename E>
theNode<E>::~theNode() {
}

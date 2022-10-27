#ifndef STACK_H_
#define STACK_H_

#define INT_MIN -999999

#include <stdexcept> 
#include "StackInterface.h"
#include "Node.h"

template <class T>

class Stack : public StackInterface<T>
{
private:
    Node<T> *head_;
    // int size = 0; // nums items

public:
    // create empty stack
    Stack(); 

    // Stack(const Stack<T> &other) { // copy constructor

    // }

    Stack<T> &operator=(const Stack<T> &other) { // check if values are the same
        // assign the other stack to the 
        if (this == &other) return *this;

        while (pop()) {} // remove all existing elements in the stack
        
        // push all elements from the other stack
        Node<T> *myListPtr = nullptr;
        // pointers for the two stacks
        Node<T> *otherPtr  = other->peek();
        // Add all nodes into the linked list
        while (otherPtr) { // Ignore the remainder of the longer stack
            auto prev = new Node<T>(otherPtr->getItem());
            prev->setNext(myListPtr);
            myListPtr = prev;
            otherPtr = otherPtr->getNext();
        }
        // the linked list we copied should be in reverse order
        // we need to reverse the linked list before we return. 
    }

    virtual ~Stack() {
        while (pop()) {
            // continuously removes items until empty
        }
    }

    bool isEmpty() const override {
        return head_; // head auto casts to boolean with bool return type
    }

    bool push(const T &newItem) override {
        head_ = new Node<T>(newItem, head_);
    }
    
    bool pop() override{ // No need to recalculate the values
        if (isEmpty()) { // if the Stack is empty
            return false;
        }
        Node<T> *prevPtr = head_;
        head_ = head_->getNext();
        delete prevPtr;
        return true;
    }
    
    T peek() const override {
        if (isEmpty()) throw std::underflow_error("peeking empty stack");
        return head_->getItem();
    }
    
    T max() const override {
        if (isEmpty()) throw std::underflow_error("checking max of empty stack");
        return head_->getMax(); // the values in the head_ will always be accuarate
    }
    
    T mean() const override {
        if (isEmpty()) throw std::underflow_error("checking mean of empty stack");
        return head_->getMean();
    }

    Stack<T> operator+(const Stack<T> &other) { // zip up the 2 stacks
        // Push all nodes into a linked list and then push them back into a new stack
        // we need a linked list because if we pushed all nodes directly into  
        // the stack then it'd be in reverse order. We don't use another stack
        // because then we'd be doing meaningless calculations of max, mean, ...etc
        
        // create the linked list
        Node<T> *myListPtr = nullptr;
        // pointers for the two stacks
        Node<T> *p1 = head_;
        Node<T> *p2 = other.peek();
        // Add all nodes into the linked list
        // Preconditions:
        // p1 points to the element in our stack to add
        // p2 points to the element in the other stack to add
        // myListPtr points to the combined list so far
        while (p1 && p2) { // Ignore the remainder of the longer stack
            auto prev = new Node<T>(p1->getItem());
            prev->setNext(myListPtr);
            myListPtr = prev;
            prev = new Node<T>(p2->getItem());
            prev->setNext(myListPtr);
            myListPtr = prev;
            p1 = p1->getNext();
            p2 = p2->getNext();
        }

        // push all items into the stack so the order is reversed
        Stack<T> zipperStack = new Stack<T>();
        while(myListPtr) { // change variable name or make another variable
            zipperStack.push(myListPtr->getItem());
            Node<T> *prev = myListPtr;
            myListPtr = myListPtr->getNext();
            delete prev;
        }
        return zipperStack;
    }

    void display() override;
};
#endif

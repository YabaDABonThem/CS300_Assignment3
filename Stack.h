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
        Node *otherPtr = other.peek();
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
        head_ = new Node(newItem, head_);
    }
    
    bool pop() override{ // No need to recalculate the values
        if (isEmpty()) { // if the Stack is empty
            return false;
        }
        Node *prevPtr = head_;
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
        Node *myListHead = new Node(head_); // use pointer of pointer?
        Node *myListPtr = myListHead; // CODE CURRENTLY WRONG
        // Should we use Node.h for the LinkedList? Use other "normal" nodes?
        // pointers for the two stacks
        Node *thisPtr = head_;
        Node *otherPtr = other.peek();
        // Add all nodes into the linked list
        while (!thisPtr && !otherPtr) {
            myListPtr.next = new Node(thisPtr.getValue());
            myListPtr = MyListPtr.next;
            myListPtr.next = new Node(otherPtr.getValue());
            myListPtr = MyListPtr.next;
        } // extra edge case (not tested): the zippered stacks are not the same length

        Stack zipperStack = new Stack();
        while(myListHead) { // change variable name or make another variable
            zipperStack.push(myListHead); // might need to push values or smth
            myListHead = myListhead.next;
        }

    }

    void display() override;
};
#endif

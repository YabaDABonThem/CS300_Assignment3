#ifndef STACK_H_
#define STACK_H_

#define INT_MIN -999999

#include "StackInterface.h"
#include "Node.h"

template <class T>

class Stack : public StackInterface<T>
{
private:
    Node<T> *topPtr;
    int count = 0;

public:
    Stack();

    Stack(const Stack<T> &other);
    Stack<T> &operator=(const Stack<T> &other);

    virtual ~Stack();

    bool isEmpty() const;
    bool push(const T &newItem);
    bool pop();
    T peek() const;
    T max() const;
    T mean() const;

    Stack<T> operator+(const Stack<T> &other);
    void display();
};
#endif

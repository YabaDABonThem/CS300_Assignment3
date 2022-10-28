#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_
template <class T>
class StackInterface
{
public:
    virtual bool isEmpty() const = 0;
    virtual bool push(const T &newEntry) = 0;
    virtual bool pop() = 0;
    virtual T peek() const = 0;
    virtual T max() const = 0;
    virtual T mean() const = 0;
    virtual void display() = 0;

    virtual ~StackInterface() {}
};

#endif
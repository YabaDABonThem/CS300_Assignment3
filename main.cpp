#include <iostream>
#include "MyRand.h"
// #include "Stack.cpp"
#include "Node.h"
// #include "Node.cpp"
using namespace std;
int score = 0;
void grade(bool condition, int points){
    if (condition){
        cout << "Pass" << endl;
        score += points;
    }
    else{
        cout << "Fail" << endl;
    }
}

void test1(){
    int points = 0;
    StackInterface<int> *stackPtr1 = new Stack<int>();
    stackPtr1->push(1);
    grade(stackPtr1->max() == 1, 1);
    grade(stackPtr1->mean() == 1, 1);
    stackPtr1->push(2);
    grade(stackPtr1->max() == 2, 1);
    grade(stackPtr1->mean() == 1, 2);
    stackPtr1->push(3);
    grade(stackPtr1->max() == 3, 1);
    grade(stackPtr1->mean() == 2, 2);
    delete stackPtr1;
}
void test2(){
    my_srand(0);
    StackInterface<int> *stackPtr = new Stack<int>();
    for (int i = 0; i < 1000; i++)
    stackPtr->push(my_rand() % 100 + i);
    int maxes[10] = {1020, 924, 924, 826, 808, 762, 734, 706, 688, 589};
    int means[10] = {513, 468, 464, 416, 408, 386, 379, 359, 353, 303};
    for (int i = 0; i < 10; i++){
        int popCounts = my_rand() % 100;
        for (int j = 0; j < popCounts; j++){
            stackPtr->pop();
        }
        grade(maxes[i] == stackPtr->max(), 1);
        grade(means[i] == stackPtr->mean(), 1);
    }
    delete stackPtr;
}
void test3(){
    Stack<int> stack1;
    Stack<int> stack2;
    stack1.push(4);
    stack1.push(2);
    stack1.push(6);
    stack1.push(10);
    stack1.push(8);
    stack2.push(5);
    stack2.push(1);
    stack2.push(3);
    stack2.push(9);
    stack2.push(7);
    Stack<int> stack = stack1 + stack2;
    stack.pop();
    grade(stack.max() == 10 && stack.mean() == 5, 1);
    for (int i = 0; i < 5; i++)
    stack.pop();
    grade(stack.max() == 5 && stack.mean() == 3, 1);
}

void test4(){
    my_srand(0);
    Stack<int> stack1;
    Stack<int> stack2;
    for (int i = 0; i < 1000; i++){
        stack1.push(my_rand() % 100 + i);
        stack2.push(my_rand() % 100 + i / 2);
    }
    Stack<int> result = stack1 + stack2;
    int maxes1[5] = {1044, 949, 893, 830, 759};
    int means1[5] = {523, 480, 450, 433, 393};
    int maxes2[5] = {563, 523, 491, 468, 439};

    int means2[5] = {285, 263, 248, 240, 219};
    int maxes[5] = {1066, 1020, 990, 961, 927};
    int means[5] = {414, 397, 386, 380, 364};
    for (int i = 0; i < 5; i++){
        int popCounts = my_rand() % 100;
        for (int j = 0; j < popCounts; j++){
            result.pop();
            stack1.pop();
            stack2.pop();
        }
    grade(stack1.max() == maxes1[i] &&
    stack1.mean() == means1[i] &&
    stack2.max() == maxes2[i] &&
    stack2.mean() == means2[i],1);
    grade(maxes[i] == result.max() &&
    means[i] == result.mean(),1);
    }
}

int main(){
    try{
        test1();
        test2();
        test3();
        test4();
    }

    catch (exception e){
        cout << e.what() << endl;
    }
    cout << "Your total correctness score is: " << score << endl;
    return 0;
}
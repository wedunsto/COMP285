#include <iostream>
#include "RecursiveTree.cpp"
using namespace std;

RecursiveTree test;

int main(){
    int n = 4;
    int results = test.FibonacciSequenceNew(n);
    cout<<"The fibonacci sequence for: "<<n<<" is: "<<results<<endl;
    int length = test.pathLength;
    int calls = test.calls;
    cout<<"The length of the recusive tree is: "<<length<<endl;
    cout<<"The number of function calls is: "<<calls<<endl;
}

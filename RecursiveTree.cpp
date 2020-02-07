#include <iostream>
using namespace std;
class RecursiveTree{
    public:
    int pathLength=0;
    int calls=0;
    int FibonacciSequenceNew(int n){
        if(n <= 1) return n;
        pathLength++;
        calls+=2;
        return FibonacciSequenceNew(n-1) + FibonacciSequenceNew(n-2);
    }
};

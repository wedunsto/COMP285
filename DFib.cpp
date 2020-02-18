//Objective: Utilize dynamic programming to recursively create a method
//that calculate the fibonnaci sequence given a number

#include<iostream>
using namespace std;

const int size = 50;//limits how big a number can be calculated
static int knownValues[size];//declares the array that will hold calculated fibonnaci values

int F(int n){
	if(n < 2) return knownValues[n] = n;
	if(knownValues[n] != 0) return knownValues[n];//F(n) has been calculated
	return knownValues[n] = F(n-1) + F(n-2);//calculate the fibonacci sequence
}

int main(int argc, char *argv[]){
	int num = atoi(argv[1]);//store the cmd line arg
	cout<<F(num)<<endl;
}

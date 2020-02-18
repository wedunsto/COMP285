//Objective: Utilize dynamic programming to recursively create a method
//that calculate the factorial sequence given a number

#include<iostream>
using namespace std;

const int size = 50;
static int knownValues[size];//declare array to hold calculated values

int Fact(int n){
	if(n < 2) return knownValues[n] = 1;
	if(knownValues[n] != 0) return knownValues[n];//if value has been calculated
	return knownValues[n] = n * Fact(n - 1);
}

int main(int argc, char *argv[]){
	int num = atoi(argv[1]);//stores the cmd line arg
	cout<<Fact(num)<<endl;
	cout<<argv[1]<<endl;
	char *ptr;
	char temp = '5';
	ptr = &temp;
	argv[1] = ptr;
	cout<<argv[1]<<endl;
}

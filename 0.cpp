//Objective: Create a command line postfix
#include<iostream>
#include"cstdlib"
#include"stack.cpp"//include Dr. Carr's stack
using namespace std;

int main(int argc, char *argv[]){
	stack<int>results(argc);//Creates a stack that stores all the postfix numbers 
	
	int firstNumber=0;//placeholder for sub and div
	int secondNumber=0;//placeholder for sub and div

	for(int i=1;i<argc;i++){//traverse all values on the command line
		
		string temp = string(argv[i]);//converts all values to string
		if(temp == "+") results.push(results.pop() + results.pop());//perform add
		else if(temp == "-"){//if a sub is found
			secondNumber = results.pop();//store the first pop in a variable 
			firstNumber = results.pop();//store the second pop in a variable
			results.push(firstNumber - secondNumber);//push the result back onto the stack
		}
		else if(temp == "x") results.push(results.pop() * results.pop());//perform mult
		else if(temp == "/"){//if a div is found
			secondNumber = results.pop();//store the first pop in a variable
			firstNumber = results.pop();//store the second pop in a variable
			results.push(firstNumber / secondNumber);//push the result back onto the stack
		}
		else results.push(atoi(argv[i]));//if a number is found store the integer on stack
	}

	cout<<results.pop()<<endl;//print out the final value
}

//Objective:
//Use itos() to convert integers to string

//Use only allowed imports
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string stringVersionOfDigit(int n){
	if (n == 0){
		return "0";
	}
	else if (n == 1){
		return "1";
	}
	else if (n == 2){
		return "2";
	}
	else if (n == 3){
		return "3";
	}
	else if (n == 4){
		return "4";
	}
	else if (n == 5){
		return "5";
	}
	else if (n == 6){
		return "6";
	}
	else if (n == 7){
		return "7";
	}
	else if (n == 8){
		return "8";
	}
	else{
		return "9";
	}
}

string itos(int n){//method used to convert int values to string
	string result = "";
	while(n / 10 != 0){
		result = stringVersionOfDigit(n%10) + result;
		n = n / 10;
	}
	result = stringVersionOfDigit(n%10) + result;
	return result;

}

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);//store command line argument into variable
	cout << "file "+ itos(n)+ " .txt" << endl;//print desired output
	return 0;
}

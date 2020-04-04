//Objective:
//Use itos() to convert integers to string

//Use only allowed imports
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string itos(int n){//method used to convert int values to string
	return to_string(n);
}

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);//store command line argument into variable
	cout << "file "+ itos(n)+ " .txt" << endl;//print desired output
	return 0;
}

//Objective: guess password in max number of attempts
#include <iostream>
#include <cmath>
#include "baser.cpp"

using namespace std;

int factorial(int n){//Helper function to determine number factorials
	if(n<3) return n;
	return n * factorial(n-1);
}

int powerSetSize(int set_size){//Obtains the set of power set
	if(set_size > 10) return -1;//if size is greater than allowable size
	return pow(2,set_size);	
}

int toBinary(int n) {
    int power = 0;
    int binary = 0;
    while (n != 0) {
        binary += n % 2 * (int) pow(10, power);
        n = n / 2;
        power++;
    }
    return binary;
}

int main(int argc, char* argv[]){
	int currentAttempt = 0;//stores the current attempt number
	//incremented everytime the program guesses a password
	string passwordString = argv[1];//Stores the value on the commandline
	int passwordLength = passwordString.length();//Stores the length of the password being guessed
	int maxAttempts = factorial(10) / factorial(10 - passwordLength);//Total number of possible passwords of length k
	string binaryResult = convert(passwordLength);//may be incorrect
	int power_set_size = powerSetSize(passwordLength);//maybe incorrect
	
	if(currentAttempt > maxAttempts) cout<<"Failure"<<endl;
	cout<<toBinary(20)<<endl;

}

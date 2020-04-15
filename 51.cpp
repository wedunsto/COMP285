#include<iostream>
using namespace std;

#include"pass.h"
#include<cmath>
#include <fstream>

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

string itos(int number, string result){
	if(number / 10 == 0) return result;
	return itos(number/10,stringVersionOfDigit(number % 10) + result);
}

int Convert(int number, int binaryResult, int power){
	if(number == 0) return binaryResult;
	return Convert(number/2, number%2*(int)pow(10,power), power++);
} 
int CountTheOnes(int number, int count){
	if(number == 0) return count;
	if(number%10 == 1) count++;
	return CountTheOnes(number/10,count);
}

void FirstPart(int arr[], int size, int &nextIndex){
	nextIndex = 0;
	int next;
	for(next=0;next<size-1;next++){
		if(arr[next] < arr[next + 1]){
			nextIndex = next;
		}
	}	
}

void SecondPart(int arr[], int size, int index, int &nextIndex){
	nextIndex = index + 1;
	int next;
	for(next=index+1;next<size;next++){
		if(arr[next] > arr[index]){
			if(arr[next] < arr[nextIndex]){
				nextIndex = next;
			}
		}
	}
}

void Swap(int arr[], int previous, int next){
	int temp = arr[previous];
	arr[previous] = arr[next];
	arr[next] = temp;
}

void Transp(int arr[], int index, int size){
	int arra[25];
	for(int next=index+1;next<size;next++){
		arra[next] = arr[size-next+(index+1)-1];
	}
	for(int next = index+1; next<size;next++){
		arr[next] = arra[next];	
	}
}

void Begin(int arr[], int size) {
    for (int next = 0; next < size; next++)
        arr[next] = next;
}

long Factorial(int number) {
    long results = 1;
    for (int next = 1; next <= number; next++)
        results = results * next;
    return results;
}

void permute(int arr[],int number) {
	int arra[10];
	Begin(arra, number);
	int i, j, y, permuted = 0;
	for (int next = 0; next <= number - 1; next++)
		fout<<arra[next];
		fout<<endl;
    
    for (int next = 1; next<Factorial(number); next++) {
        FirstPart(arra, number, i);
        SecondPart(arra, number, i, j);
        Swap(arra, i, j);
        Transp(arra,i,number);
        for (y = 0; y <= number - 1; y++)
		fout<<arra[y];
		fout<<endl;
    }
}

ofstream fout("solutions.txt");

int main(int argc, char* argv[]){
	int binaryResult = 0;
	int power = 0;
	int lowest=0;
	int highest=0;
	int count = 0;
	string results = "";

	if (argc > 1) {
		int passwordLength = atoi(argv[1]);
		int variations = Factorial(passwordLength);
		int *variationsArr = new int[variations];
		permute(variationsArr, passwordLength);
		fout.close();

		for (int i = 0; i < passwordLength; i++) {
			lowest += (int) pow(2, i);
        	}
        	for (int i = 9; i > (9 - passwordLength); i--) {
            		highest += (int) pow(2, i);
        	}

		int *subsetArr = new int[passwordLength];

		for (int i = lowest; i <= highest; i++) {
			int sub = Convert(i,binaryResult,power);
            		if (CountTheOnes(sub,count) == passwordLength) {
                		int i, value = 0;
                		while (sub != 0) {
                    			if (sub % 10 == 1) {
                        			subsetArr[i] = value;
                        			i++;
                    			}
                    			sub = sub / 10;
                    			value++;
                		}
			}
			ifstream read("solutions.txt");
			for (int j = 0; j < variations; j++) {
				char input[3];
				read >> input;
				int temp = atoi(input);
				string password = "";
				for (int h = 0; h < passwordLength; h++) {
					int index = temp % 10;
					temp = temp / 10;
                        		password = itos(subsetArr[index],results) + password;
				}
				const char* potential = password.c_str();
				char *answer = (char*)potential;

				if(pass(answer)==0){
					cout <<"Found password = "<<password <<endl;
                		}
			}
			read.close();
		}
	}
	return 0;
}































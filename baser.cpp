//recursive base conversion

#include <iostream>
using namespace std;
#include <cstdlib>

int a[10],i;
string convert(int number){//converts the size of the password to binary
	//if(number > 10) return "Exceeds allowable password size";//if size is greater than allowable size	
	string binaryResult = "";
	for(i=0;number>0;i++){
		a[i] = number % 2;
		number = number / 2;
	}
	for(int i=i; i>=0; i--){
		binaryResult += to_string(a[i]);
	}
	return binaryResult;
}

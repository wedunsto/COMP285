#include<iostream>
using namespace std;

void CountToTen(int start){
	if(start>10)return;
	cout<<start<<endl;
	return CountToTen(start+1);
}

int main(){
	CountToTen(0);
	return 0;
}

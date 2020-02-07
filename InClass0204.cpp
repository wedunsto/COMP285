#include<iostream>
using namespace std;

int r(int n){
	if(n<0) return -1;//base case less than 0
	if(n<1) return 1;//base case r0 = 1
	if(n<2) return 2;//base case r1 = r0 + n = 1+1=2

	if(n%2 == 0) return r(n-1) + r(n-2);//even values rn = r(n-1) + r(n-2)
	return r(n-1) + n;//odd values rn = r(n-1) + n
}

int main(){
	cout<<r(5)<<endl;
}

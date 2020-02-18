#include <iostream>
#include <cstdlib>
using namespace std;

const int MaxN=50;
static int knownF[MaxN];

int F(int i)
{
	if (i < 0) return 0;
	if(knownF[i] != 0) return knownF[i];
	int t = i;
	if(i > 1) t = F(i-1) + F(i-2);
	return knownF[i] = t;
}


int main(int argc, char* argv[])
{
	int n = atoi(argv[1]), i;
	//cout << "Fibonacci number to calculate: " << endl;
	//cin >> n;
	cout <<" answer "<< F(n) << endl;
	for(i = 2; i<n; i++) cout << knownF[i] << endl;
	return 0;
}


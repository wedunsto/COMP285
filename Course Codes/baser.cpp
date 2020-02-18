//recursive base conversion

#include <iostream>
using namespace std;
#include <cstdlib>

void convert(int b, int n)
{
	if(n==0) return;
	convert(b,n/b);
	cout << n%b;

}


int main(int argc, char *argv[])
{
	int b = atoi(argv[2]), n = atoi(argv[1]);
	convert(b,n);
	cout << endl;
}

//Objective: Modify Shell sort so that DFib.cpp is used instead of h = 3h+1
#include<iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

long comparisons = 0;
long exchanges = 0;
ofstream fout("output.txt");

void ran(int a[], int N)
{
	int i;
	srand((unsigned)time(NULL));  //Give us a random array that will be fixed for all sorts
	for(i = 0; i<N; i++)
		a[i] = int(1000*(1.0*rand()/RAND_MAX));
}

void initial(int a[], int b[], int N)
{
	int i;
	for(i =0 ; i < N; i++) a[i] = b[i];
}

void output( int a[], int l, int r)
{
	int i;
	for( i = l; i <= r; i++) fout << a[i] << " ";
	fout << endl;
}

const int size = 50;//limits how big a number can be calculated
static int knownValues[size];//declares the array that will hold calculated fibonnaci values

int F(int n){
	if(n < 2) return knownValues[n] = n;
	if(knownValues[n] != 0) return knownValues[n];//F(n) has been calculated
	return knownValues[n] = F(n-1) + F(n-2);//calculate the fibonacci sequence
}

void shellsort(int arr[], int lowerLimit, int upperLimit){//performs shell sort on input array
	int gap;//declare gap variable for array sublists
	for(gap = 0; F(gap) < upperLimit-1; gap++);//increment gap variable
	for(gap;gap>0;gap--){//insertion sort the segments
		for(int i = lowerLimit + gap;i <= upperLimit;i++){
			int j = i;//stores the current index in a variable
			int temp = arr[i];//temporarily stores the current value
			while(j >= lowerLimit + gap && temp < arr[j - gap]){//either the gap is reached or temp is bigger than earlier values
				arr[j] = arr[j-gap];//swap the earlier value with the current value
				j -= gap;//reduce temp index
			}
			arr[j] = temp;//stores the value in temp at index j
		}
	}
}
int main(int argc, char *argv[])
{
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int *a = new int[N], *b = new int[N];
	string filename;
	int choice = 0;
	if(sw)
		ran(a, N);
	else
	{
		cout << "enter file name" << endl;
		cin >> filename;
		ifstream fin(filename.c_str());
		for(i = 0; i < N; i++) fin >> a[i];
	}
	for( i = 0; i < N; i++)
	{
		 fout << a[i] << " ";
	}
	fout << endl;
	shellsort(a, 0 , N-1); 
	for(int i=0; i<N; i++){
		cout<<a[i]<<endl;
	}
	fout << "Shell Sort " << endl; 
	output(a, 0, N-1);
	return 0;
}

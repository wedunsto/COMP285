//Objective: Modify Shell sort so that DFib.cpp is used instead of h = 3h+1
#include<iostream>
#include "DFib.cpp"
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

/*void shellsort(int arr[], int lowerLimit, int upperLimit){//performs shell sort on input array
	int gap;//declare gap variable for array sublists
	for(gap = 1; gap<= upperLimit/9; gap=3*gap+1);//increment gap variable
	for(gap;gap>0;gap/=3){//insertion sort the segments
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
}*/

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

int main(){
	int arr[] = {12,34,54,2,3};
	int n = 5;
	shellsort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	cout<<F(4)<<endl;
	return 0;
}

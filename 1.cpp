//Programming assignment 1: Problem 1:
#include<iostream>
#include"cstdlib"

using namespace std;

int arrayRow;//keep track of array row
int arrayCol;//keep track of array column

int gcd(int row, int col){//determine the greatest common denominator of two numbers
	int swap;//used when the row index is less than the column index
	while(row>0){//Find GCD of non-zero number
		if(row < col){
			swap = row;
			row = col;
			col = swap;
		}
		row = row - col;
	}
	return col;//return GCD
}

int main(int argc, char* argv[]){
	arrayRow = arrayCol = atoi(argv[1]);
	int array[arrayRow][arrayCol];//dynamically create 2D array

	for(int i = arrayRow;i>=0;i--){//set all horizonal elements to 0 
		array[i][0] = 0;
	}
	for(int j = arrayCol;j>=0;j--){
		array[0][j] = 0;
	}

	for(int i=arrayRow;i>=1;i--){
		for(int j=arrayCol;j>=1;j--){
			int temp = gcd(i,j);
			array[i][j] = temp;
			if(temp == 1) array[i][j] = temp;
			else array[i][j] = 0;
		}
	}

	for(int i=0;i<arrayRow;i++){
		for(int j=0;j<arrayCol;j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>//used to access file cann
using namespace std;

int stoi1(string values){//convert characters in a string to an integer
	int result = 0;
	stringstream temp(values);
	temp >> result;
	return result;
}

int main(int argc, char* argv[]){
	bool tree = false; //determines if graph is a tree or not
	int i,j,size, totalVertices = 0;
	fstream file;//object that holds the input file
	string fileName;
	string values;//temporary variable to hold the string values from the file
	int control = 0;

	if(argc > 1){
		fileName = argv[1];//stores the file name in a variable
		file.open(fileName.c_str());//opens the input file
		file>>values;//stores the first value in the file in a variable
		size = stoi1(values);//stores the size of the 2D array
		int graph[size][size];//create a 2D matrix that hold the vertice connections
		int summedGraph[size];//create an array that sums up all the values

		for(int i=0; i<size; i++){//traverse rows
			for(int j=0; j<size; j++){//traverse columns
				file >> values;//stores the next value in file in a variable
				graph[i][j] = stoi1(values);//stores the value in the 2D array
				totalVertices += stoi1(values);//adds the edges
				summedGraph[i] = 0;
			}
		}
		totalVertices /= 2;//calculate N-1 vertices

		if(totalVertices < size) tree = true;
		
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				if(i == j & graph[i][j] == 1) tree = false;//if diagonals are 1
				control += graph[i][j];//sum up all values in the matrix
			}
			summedGraph[i] = control;//stores the summations
			control = 0;//resets the sum variable
		}

		for(int i=0; i<size; i++){
			if(summedGraph[i] < 1) tree = false;//confirms if a node is diconnected
		}

	}
	if(tree == true) cout<<"The graph is a tree!"<<endl;//prints out if the graph is a tree or not
	else cout<<"The graph is not a tree!"<<endl;//prints out if the graph is a tree or not
	return 0;
}

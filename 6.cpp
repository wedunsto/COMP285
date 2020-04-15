#include<iostream>
using namespace std;
 
#include<bits/stdc++.h>

#define Size 6

int stoi1(string values){
	int result = 0;
	stringstream temp(values);
	temp >> result;
	return result;
}

int SmallestPath(int weight[], bool Selected[]){//Needs fixing
	int path = INT_MAX, nextInPath; 
	for (int i=0; i<Size; i++) 
		if (Selected[i] == false && weight[i] <= path) 
			path = weight[i], nextInPath = i; 
	return nextInPath; 
}

int OutPut(int weight[]) {
	ofstream outputToFile;
	outputToFile.open("results.txt");
	char temp = 'B';	
	for(int i = 1; i<Size; i++){
		outputToFile<<"Shortest path from A to: "<<temp<<" is: "<<weight[i]<<endl;
		temp = temp + 1;
	}
	outputToFile.close();
}

void Solution(int graph[Size][Size], int currentNode) 
{ 
	char temp = 'A';
	char path[Size];
	int weight[Size];
	bool Selected[Size];
	for(int i=0;i<Size;i++){
		path[i] = temp;
		temp = temp + 1; 
	}

	for (int i=0; i < Size; i++) 
		weight[i] = INT_MAX, Selected[i] = false; 
	weight[currentNode] = 0; 
	for (int i=0; i < Size - 1; i++) { 
		int newlyFound = SmallestPath(weight, Selected);
		Selected[newlyFound] = true; 
		for (int i=0; i < Size; i++){
			if (Selected[i] != true && (graph[newlyFound][i] && weight[newlyFound] != INT_MAX) && weight[newlyFound] + graph[newlyFound][i] < weight[i]){
				weight[i] = weight[newlyFound] + graph[newlyFound][i];
			}
		}
	} 
	OutPut(weight);
} 

int main(int argc, char* argv[]){
	fstream file;
	string fileName;
	string values;
	if(argc>1){
		fileName = argv[1];
		file.open(fileName.c_str());
		file>>values;
		int graph[Size][Size];
		for(int i=0; i<Size; i++){
			for(int j=0; j<Size; j++){
				file >> values;
				graph[i][j] = stoi1(values);
			}
		}
		Solution(graph, 0); 
	}
	else cout<<"Please enter the filename"<<endl;
	return 0;
}

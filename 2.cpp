//Programming assignment 1: Problem 2:
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{//structure used to create nodes for the linked list
	int key;//holds the node's value
	node *next;//points to the next node in the linked list
};

void TraverseLinkedList(node *traverse){//used to traverse the linked list
	if(traverse != NULL){//ensure the linked list is not empty
		node *temp = traverse->next;//create a temp node to keep head where its at
		while(temp != traverse){//if the circle hasnt been completed
			cout<<temp->key<<" -> ";//print out the current key
			temp = temp -> next;//traverse to the next node in the linked list
		}
		cout<<endl;
	}
}

int main(int argc, char* argv[]){
	if(argc > 3){//if a size and killer value have been entered
		int evenOdd = 0;//iterated variable that determines if the even or odd incrementor should be used
		int killer = 0;//mutable killer that actually removes linked list nodes
		int size = atoi(argv[1]);//store the size of the linked list
		int oddKiller = atoi(argv[2]);//store the rate at which nodes are removed when iterator is odd
		int evenKiller = atoi(argv[3]);//store the rate at which nodes are removed when iterator is even

		node *head, *dead, *traversal;//create the nodes to start the linked list
		head = new node;//instantiate the head of the linked list
		head -> key = 1;//stores the first value in the linked list
		dead = traversal = head;//force the dead to copy the linked list

		for(int i=2;i<=size;i++){//iteratively populate the linked list
			node *temp = new node;//creates the next node in the linked list
			temp -> key = i;//give the node a value
			head -> next = temp;//points the head to the next node
			head = head -> next;//points to the next node in the linked list
		}

		head -> next = dead;//points the tail back to the head

		while(head != head -> next){
			if(evenOdd % 2 == 0) killer = evenKiller;
			else killer = oddKiller;
			for(int i=1;i<=killer;i++){
				head = head -> next;//skips over safe nodes
			}
			dead = head->next;//store removing node in dead
			head -> next = dead -> next;//continue the linked list
			delete dead;//remove dead node from linked list
			TraverseLinkedList(traversal);
			evenOdd++;//increments even odd variable
		}
		cout<<"The winner is: "<<head->key<<endl;//state the remaining node
	}
}

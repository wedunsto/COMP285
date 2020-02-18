#include<iostream>
#include "Node.cpp"

using namespace std;

void Kill(Node *head, Node *dead, int node){
	if(head == NULL) return;//if empty linked list
	if(head -> next == head) return;//if the linked list has wrapped around
	head = head -> next;//rotate to next node in linked list
	cout<<head->next->key<<" has died"<<endl;//report the node being removed
	//dead = head -> next;//store the removed node
	//head -> next = dead -> next;//point the head to the next live node
	//delete dead;//delete the head node
	Kill(head,dead,node+1);
}

int main(int argc, char* argv[]){
	Node *head = new Node;//create the head of the linked list
	Node *dead = head;//create a node to make the linked list circular
	if(argc > 2){//if a size and delete order have been defined
		int size = atoi(argv[1]);//store the size in a variable
		int killer = atoi(argv[2]);//store the delete iterator in  varibable
		head->key = 1;//assign a value to the head of the linked list
		Create(head,size);//recursively create nodes and assign values
		head -> next = dead;//make linked list circular
		head = head -> next;//return head to the beginning of the linked list
		Kill(head,dead,0);
		cout<<"The winner is: "<<head->key<<endl;
	}
	return 0;
}

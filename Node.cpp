#include<iostream>
using namespace std;

struct Node{
	int key;
	Node *next;
};

int i=2;
void Create(Node *head, int size){
	if(head == NULL) return;
	if(i>size) return;
	Node *temp = new Node;
	temp -> key = i;
	head -> next = temp;
	i++;
	Create(temp, size);
}
		
void traversal(Node *head){
	if(head == NULL) return;
	if(head -> next == NULL) cout<<head->key;
	if(head -> next == head) return;
	else{
		cout<<head->key<<" -> ";
		traversal(head -> next);
	}
}

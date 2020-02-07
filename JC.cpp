#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	int key;
	node *next;};

int main(int argc, char* argv[]){
	if(argc >2) {
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	node *t, *x;
	t = new node;
	t->key = 1;
	x = t;
	for(i = 2; i<=N; i++){
		t->next = new node;
		t = t->next;
		t->key = i;
	}
	t->next = x;
	while(t != t->next){
		for(i = 1; i<M; i++){}
		t = t->next;
		cout << t->next->key<<" has dropped out "<< endl;
		x = t->next;
		t->next = x->next;
		delete x;
	}
	cout << "winner is " << t->key << endl;
	}
	return 0;
}

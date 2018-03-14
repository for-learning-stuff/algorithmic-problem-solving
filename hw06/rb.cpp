#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, t) for (int i = (s); i < (t); i++)

struct Node
{
	Node(char color = '\0') : color(color){};
	int n;
	Node *parent = this;
	int rank = 1;
	char color;
};

Node *nodes[10000];
Node *opposite[10000];



void insert(int n)
{
	Node *node = new Node();
	nodes[n] = node;
	Node *oppnode = new Node();
	opposite[n] = oppnode;
}

Node *find(Node *n)
{
	if (n->parent != n){
		n->parent = find(n->parent); //path compression
	}

	return n->parent;
}

void un(Node *a, Node *b)
{
	Node *aroot = find(a);
	Node *broot = find(b);

	if (aroot == broot)
	{
		return;
	}

	if (broot->rank > aroot->rank)
	{
		Node *temp = aroot;
		aroot = broot;
		broot = temp;
	}

	aroot->rank += broot->rank;
	broot->parent = aroot;
}

void uncolor(Node *a, Node *b){
	Node *broot = find(b);

	if (a == broot)
	{
		return;
	}
	a->rank += broot->rank;
	broot->parent = a;
}

int main()
{
	Node* red = new Node('r');
	red->rank = 0;
	Node* black = new Node('b');
	black->rank = 0;
	
	int n, q;
	cin >> n >> q;

	REP(i, 0, n){
		insert(i);
	}

	char op;
	int a, b;
	REP(i, 0, q){
		cin >> op;
		if (op == 'd'){
			cin >> a >> b;
			a--;
			b--;
			if (find(nodes[a]) == find(nodes[b])){
				printf("Q%d: ?\n", i + 1);
			} else{
				un(nodes[a], opposite[b]);
				un(opposite[a], nodes[b]);
			}
		}

		else if (op == 's'){
			cin >> a >> b;
			a--;
			b--;
			if (find(opposite[a]) == find(nodes[b])){
				printf("Q%d: ?\n", i + 1);
			} else {
				un(nodes[a], nodes[b]);
				un(opposite[a], opposite[b]);
			}
		}

		else if (op == 'r'){
			cin >> a;
			a--;
			if (find(nodes[a])->color == 'b' || find(opposite[a])->color == 'r'){
				printf("Q%d: ?\n", i + 1);
			} else{
				uncolor(red, nodes[a]);
				uncolor(black, opposite[a]);
			}
		}

		else if (op == 'b'){
			cin >> a;
			a--;
			if (find(nodes[a])->color == 'r'|| find(opposite[a])->color == 'b'){
				printf("Q%d: ?", i + 1);
			} else{
				uncolor(black, nodes[a]);
				uncolor(red, opposite[a]);
			}
		}
		if(red->rank == n) {
			printf("Q%d: I know\n", i + 1);
			break;
		}
	}

	if (red->rank == n){
		REP(i, 0, n)
		{
			// cout << i;
			// cout << nodes[i]->color;
			cout << find(nodes[i])->color;
		}
	} else {
		cout << "I am not sure";
	}

}
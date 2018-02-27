#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)

struct Node{
  Node(string name): min(name), max(name), name(name){};
  string name;
  Node* parent;
  int rank = 0;
  string min;
  string max;
};

unordered_map<string,Node*> nton;
unordered_map<string,int> ntoa;

void insert(string n){
  nton.insert(pair<string,Node*>(n, new Node(n)));
}

Node* find(Node* n)
{
  if(n->parent){
    n->parent = find(n->parent); //path compression
  } else{
    return n;
  }

  return n->parent;
}

void un(Node* a, Node* b){
  Node* aroot = find(a);
  Node* broot = find(b);

  if (aroot == broot){
    return;
  }

  if (broot->rank > aroot->rank){
    Node* temp = aroot;
    aroot = broot;
    broot = temp;
  }
  else if(a->rank == b->rank){
    a->rank++;
  }

  broot->parent = aroot;

  if(ntoa[aroot->min] > ntoa[broot->min]){
    aroot->min = broot->min;
  }
  else if(ntoa[aroot->min] == ntoa[broot->min]){
    if(aroot->min > broot->min){
      aroot->min = broot->min;
    }
  }

  if(ntoa[aroot->max] < ntoa[broot->max]){
    aroot->max = broot->max;
  }
  else if(ntoa[aroot->max] == ntoa[broot->max]){
    if(aroot->max > broot->max){
      aroot->max = broot->max;
    }
  }
}

int main(){
  int n;
  cin >> n;
  string name;
  int age;
  REP(i,0,n){
    cin >> name >> age;
    ntoa.insert(pair<string,int>(name, age));
    insert(name);
  }

  int q;
  string a;
  string b;
  cin >> q;
  REP(i,0,q){
    cin >> a >> b;
    un(nton[a], nton[b]);
    Node* root = find(nton[a]);
    Node* root2 = find(nton[b]);
    cout << "roots: " << root->name << " " << root2->name << endl;
    cout << root->min << " " << root->max << endl;
  }
}
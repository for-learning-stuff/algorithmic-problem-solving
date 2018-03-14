#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)

struct Node{
  Node(int row, int col): row(row), col(col){};
  int row;
  int col;
  Node* parent;
  int rank = 0;
};

unordered_map<int,vector<Node*>> land;
vector<vector<Node*>> grid;
vector<vector<bool>> showing;

void insert(int n, int r){
  Node* node = new Node(r, grid[r].size()); //size before push should be index
  node->parent = node;
  land[n].push_back(node);
  grid[r].push_back(node);
}

Node* find(Node* n)
{
  if(n->parent != n){
    n->parent = find(n->parent); //path compression
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
}

int main(){
  //insert everything
  //count down from n and access Node*, get node*'s positions, and get surrounding nodes
  //if above water union them
  //+1 when processing a node
  //-1 when union with a neighbor
  //do nothing when union with neighbor in same union
}
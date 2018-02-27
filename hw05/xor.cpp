#include <bits/stdc++.h>
using namespace std;

#define MAXL 100000
#define INT_SIZE 32
#define REP(i,s,t) for(int i=(s);i<(t);i++)

struct Node{
    Node* children[2];
    int value = 0;
};

void print(Node* root, string prefix){
    if(root->value != 0){
        cout << "path:" << prefix << " " << root->value << endl;
    }
    for (int i=0; i<2; ++i){
        Node* n = root->children[i];
        if(n){
            print(n, prefix+to_string(i));
        }
    }
}

void insert(Node* root, int n){
    for (int i=INT_SIZE-1; i>=0; --i){
        bool b = n & (1<<i);
        if(!root->children[b]){
            root->children[b] = new Node();
        }
        root = root->children[b];
    }
    root->value = n;
}


//https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/
int complement(Node* root, int n){
    for (int i=INT_SIZE-1; i>=0; --i)
    {
        bool b = n & (1<<i);
 
        if (root->children[1-b])
            root = root->children[1-b];
 
        else if (root->children[b])
            root = root->children[b];
    }
    return root->value;
}

int main(){
    int n;
    int tree[MAXL];
    cin >> n;
    
    int a,b,w;
    REP(i,1,n){
        cin >> a >> b >> w;
        if (a>b){
            tree[a-1] = w;
        }
        else{
            tree[b-1] = w;
        }
    }

    // REP(i,0,n){
    //     cout << tree[i];
    // }

    //all the xors
    Node* trie = new Node();
    insert(trie, 0);

    int result = INT_MIN;
    int xr = 0;
    REP(i,0,n){
        xr = xr^tree[i];
        // cout << xr << " ";
        insert(trie, xr);

        // cout << complement(trie,xr) << endl;
        result = max(result, xr^complement(trie,xr));
    }

    // print(trie, "");
    cout << result;
}
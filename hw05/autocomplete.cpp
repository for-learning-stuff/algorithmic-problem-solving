#include <bits/stdc++.h>
using namespace std;

#define MAXL 100000
#define MAXF 10000
#define REP(i,s,t) for(int i=(s);i<(t);i++)

// int f[MAXF]
map<string, int> wordfreq;

struct Node{
    Node* children[26];
    bool end = false;
    string frequent;
};

void print(Node* root, string prefix){
    for (int i=0; i<26; ++i){
        Node* n = root->children[i];
        if(n){
            cout << "path:" << prefix+(char)(i + 'a');
            cout << " freq:" << n->frequent;
            cout << " isend:" << n->end << endl;
            print(n, prefix+(char)(i + 'a'));
        }
    }
}

void insert(Node* root, string s){
    for(int j=0; j<s.length(); ++j){
        int c = s[j] - 'a';
        if(!root->children[c]){
            root->children[c] = new Node();
        }
        root = root->children[c];
    }
    root->end = true;

}

string process(Node* root, string s){
    string freq;
    for(int j=0; j<26; ++j){
        if(root->children[j]){
            string f = process(root->children[j], s+(char)(j + 'a'));
            if (wordfreq[f] > wordfreq[freq]){
                freq = f;
            }
        }
    }
    root->frequent = freq;
    if (root->end && wordfreq[s] > wordfreq[freq]) freq = s;
    return freq;
}

void search(Node* root, string s){
    // https://stackoverflow.com/questions/5891610/how-to-remove-certain-characters-from-a-string-in-c
    string clean = s;
    clean.erase(remove(clean.begin(),clean.end(), '#'), clean.end());
    for(int j=0; j<s.length(); ++j){
        if (s[j] == '#'){
            if (root->frequent == ""){
                cout << clean << endl; //reached a leaf, no words with prefix
            }
            else{
                cout << root->frequent << endl;
            }
        }
        else{
            int c = s[j] - 'a';
            if(!root->children[c]){
                cout << clean << endl;
                break;
            }
            root = root->children[c];
        }
    }
}

int main(){
    int n;
    cin >> n;
    Node* root = new Node();

    string s;
    int f;
    REP(i,0,n){
        cin >> s >> f;
        wordfreq.insert(pair<string,int>(s,f));
        insert(root, s);
    }

    process(root, "");
    int q;
    cin >> q;
    REP(i,0,q){
        cin >> s;
        search(root, s);
    }
}
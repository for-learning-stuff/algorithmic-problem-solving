#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> collection;
    collection.insert(pair<int,int>(3,3));
    collection.insert(pair<int,int>(2,2));
    collection.insert(pair<int,int>(2,2));
    char c = 's';
    //beginning
    cout << (*collection.begin()).first << endl;
    //end
    cout << (*collection.end()).first << endl;
    for (auto p: collection){
        cout << p.first;
    }
}
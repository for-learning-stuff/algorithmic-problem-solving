// Read and print unique chars, sorted
#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

int main(){
    set<int> s = {4,3,6,7};
    int n;
    cin >> n;
    s.insert(n); // Sets automatically sort    

    for(int i: s){
        cout << i;
    }
}
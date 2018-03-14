#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, t) for (int i = (s); i < (t); i++)

map<int, int> exist;

int main(){
    int n;
    cin >> n;

    int t = 0;
    int s;
    REP(i,0,n){
        cin >> s;
        if (!exist[s] && s){
            exist[s] = 1;
            ++t;
        }
    }
    cout << t;
}
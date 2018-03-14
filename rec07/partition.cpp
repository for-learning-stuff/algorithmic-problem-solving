#include <bits/stdc++.h>
using namespace std;
#define REP(i,s,t) for(int i=(s);i<(t);i++)

int main(){
    int n;
    cin >> n;

    int negative = 0;
    int positive = 0;
    int l;
    REP(i,0,n){
        cin >> l;
        if (l < 0){
            negative += l;
        }
        else {
            positive += l;
        }
    }
    cout << positive - negative;
}
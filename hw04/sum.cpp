#include<bits/stdc++.h>
using namespace std;
#define REP(i,s,t) for(int i=(s);i<(t);i++)

//snippets taken from Professor Yu's code
int main(){
    int n, q;
    cin >> n >> q;
    unordered_map<int, int> count;

    int x;
    REP(i,0,n){
        cin >> x;
        count[x]++;
        // cin >> l[i];
    }
    cout << endl;

    REP(i,0,q){
        cin >> x;
        int total = 0;
        for(pair<int,int> j: count){
            // cout << "j " << j.first << endl; 
            // cout << !(x%2) << (j.first == x/2) << endl;
            if (!(x%2) && j.first == x/2) continue;
            if (count.count(x - j.first))
                total += count[x - j.first] * count[j.first];
        }
        total /= 2;
        // handle half
        if (!(x%2) && count.count(x/2)){
            int f = 0;
            for (int j = count[x/2]-1; j > 0; --j){
                f += j;
            }
            total += f;
        }
        //
        cout << total << endl;
        // cin >> l[i];
    }
    // for (int i = 0; i < n; ++i){
        // cout << l[i];
    // }
}
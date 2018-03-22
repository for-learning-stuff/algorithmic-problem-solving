#include<bits/stdc++.h>
using namespace std;
#define REP(i,s,t) for(int i=(s);i<(t);i++)

//snippets taken from Professor Yu's code
int main(){
    int n, q;
    cin >> n >> q;
    map<long long, int> bst;

    long long x;
    while(cin >> x){
        bst[x]++;
        long long sum = 0;
        map<long long,int>::reverse_iterator it = bst.rbegin();
        int i = 0;
        while(i < q && it != bst.rend()) {
            sum += min(it->second, q-i)*it->first;
            i+=it->second;
            ++it;
        }
        cout << sum << endl;
    }
}
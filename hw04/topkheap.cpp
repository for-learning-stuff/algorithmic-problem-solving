#include<bits/stdc++.h>
using namespace std;
#define REP(i,s,t) for(int i=(s);i<(t);i++)

//snippets taken from Professor Yu's code
int main(){
    int n, q;
    cin >> n >> q;
    priority_queue<long long,vector<long long>,greater<long long> > min;

    long long sum = 0;
    long long x;
    while(cin >> x){
        sum += x;
        min.push(x);
        if (min.size() > q){
            sum -= min.top();
            min.pop();
        }
        cout << sum << endl;
    }

}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d, r;
    string s;
    while (cin >> n >> d >> r) {
        if (!(n && d && r)) break;
        priority_queue<int,vector<int>,greater<int> > morning;
        priority_queue<int> evening;

        int t;
        for (int i=0; i < n; ++i){
            cin >> t;
            morning.push(t);
        }
        for (int i=0; i < n; ++i){
            cin >> t;
            evening.push(t);
        }

        int fine = 0;
        while(morning.size()){
            if(morning.top() + evening.top() > d){
                fine += (morning.top() + evening.top()-d) * r;
            }
            morning.pop();
            evening.pop();
        }
        cout << fine << endl;
    }
}
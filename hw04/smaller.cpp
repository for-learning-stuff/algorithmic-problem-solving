#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    deque<int> smallest;

    int queries;
    cin >> queries;
    char op;
    int n;
    while (queries--){
        cin >> op >> n;
        q.push(n);
        // if()
        if(op == 'a'){
            if (smallest.size()){
                if (n > smallest.back()){
                    cout << smallest.back(); 
                    smallest.push_back(n);
                }
                else{
                    while(smallest.size() && smallest.back() >= n){
                        smallest.pop_back();
                    }
                    cout << smallest.back();
                }
            } else{
                cout << -1;
                smallest.push_back(n);
            }
        }

    }

    // while(q.size()){
    //     cout << q.front();
    //     q.pop();
    // }
    // cout << endl;
    // while(smallest.size()){
    //     cout << smallest.front();
    //     smallest.pop_front();
    // }
}
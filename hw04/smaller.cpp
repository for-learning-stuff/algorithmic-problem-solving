#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<long long> q;
    deque<long long> s;

    unordered_map<long long,int> count;

    int queries;
    cin >> queries;
    char op;
    long long n;
    while (queries--){
        cin >> op;
        // if()
        if(op == 'a'){
            cin >> n;
            q.push(n);
            if (s.size()){ //not empty
                if (n > s.back()){ //push if greater than top
                    cout << s.back() << endl; 
                    s.push_back(n);
                    count[n]++;
                }
                else{ //if less than top
                    while(s.size() && s.back() >= n){
                        if(s.back() > n)
                            count[s.back()]--;
                        s.pop_back();
                    } 
                    if(s.size()) // print smaller
                        cout << s.back() << endl;
                    else cout << -1 << endl; // no smaller
                    count[n]++;
                    s.push_back(n);
                    // cout << "topstack" << s.back() << endl;
                }
            } else{ // nothing in list
                cout << -1 << endl;
                count[n]++;
                s.push_back(n);
            }
        } else {  
            if (q.size()){
                if (q.front() == s.front()){
                    count[q.front()]--;
                    if (!count[q.front()]) s.pop_front(); //duplicate
                }
                cout << q.front() << endl;
                q.pop();
            } else cout << -1 << endl;
        }

    }

    // while(q.size()){
    //     cout << q.front();
    //     q.pop();
    // }
    // cout << endl;
    // while(s.size()){
    //     cout << s.front();
    //     s.pop_front();
    // }
}
#include<bits/stdc++.h>
using namespace std;

bool test(int goal){
    if (goal % 3 == 0) return true;
    if (goal % 7 == 0) return true;
    for(int t = 3; t <= 21; t=t+3){
        if (t > goal) return false;
        if ((goal - t) % 7 == 0) {
            return true;
        }
    }
    return false;
}


int main(){
    int testcases;
    cin >> testcases;
    int goal;
    for (int i = 0; i < testcases; ++i){
        cin >> goal;
        // 7a + 3b = 
        if (test(goal)) {
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
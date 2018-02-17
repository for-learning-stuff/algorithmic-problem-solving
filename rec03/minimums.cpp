#include <bits/stdc++.h>
using namespace std;

int main(){
    int size; // 2 ≤ n ≤ 105
    cin >> size;
    // 1 ≤ ai ≤ 109
    int minspace = (int)1E9;
    int currspace = 0;
    int min;
    cin >> min;
    int next;
    for (int i = 1; i < size; ++i){
        cin >> next;
        ++currspace;
        if (next == min){
            if (currspace < minspace){
                minspace = currspace;
                currspace = 0;
            }
        }
        if(next < min){
            minspace = (int)1E9;
            currspace = 0;
            min = next;
        }
    }
    cout << minspace;
}
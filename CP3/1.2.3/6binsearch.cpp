// Find element in sorted list
// Solution: use binary search

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4};
    // jk this would be linear
    // bool inList = find(v.begin(), v.end(), 3) != v.end();
    // cout << inList;

    //It is called binary search
    cout << binary_search(v.begin(), v.end(), 3);
}



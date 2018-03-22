// Generate all subsets of a set of numbers

#include <bits/stdc++.h>
#include <vector>
using namespace std;

// https://stackoverflow.com/a/9430993
int main(){
    int n = 4;

    vector<int> numbers(n);
    iota(numbers.begin(), numbers.end(), 0);

    // cout << sizeof(int);
    for (int m = 0; m < (1 << n); ++m){
        for (int k = 0; k < 32; ++k){
            if ((m >> k) & 1){ // bit at k
                cout << numbers[n-k]; // Start enumerating from left end
            }
        }
        cout << "\n";
    }
}


